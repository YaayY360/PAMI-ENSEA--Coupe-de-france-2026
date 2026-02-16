/*
 * mcp3208_line.c
 */

#include "mcp3208_line.h"

// Fonction interne pour lire UN seul canal (privée)
static uint16_t Read_Single_Channel(LineSensor_t *sensor, uint8_t channel) {
    uint8_t txData[3];
    uint8_t rxData[3];

    // Protocole MCP3208 standard
    txData[0] = 0x06 | ((channel & 0x04) >> 2);
    txData[1] = (channel & 0x03) << 6;
    txData[2] = 0x00;

    HAL_GPIO_WritePin(sensor->CsPort, sensor->CsPin, GPIO_PIN_RESET); // CS Low
    HAL_SPI_TransmitReceive(sensor->hspi, txData, rxData, 3, 10);     // SPI Rapide
    HAL_GPIO_WritePin(sensor->CsPort, sensor->CsPin, GPIO_PIN_SET);   // CS High

    return ((rxData[1] & 0x0F) << 8) | rxData[2];
}

// Initialisation
void Line_Init(LineSensor_t *sensor, SPI_HandleTypeDef *hspi, GPIO_TypeDef *port, uint16_t pin, uint8_t numSensors) {
    sensor->hspi = hspi;
    sensor->CsPort = port;
    sensor->CsPin = pin;
    // On limite à 8 capteurs max (limite du MCP3208)
    sensor->activeSensors = (numSensors > 8) ? 8 : numSensors;

    // CS à l'état haut par défaut
    HAL_GPIO_WritePin(sensor->CsPort, sensor->CsPin, GPIO_PIN_SET);
}

// Lit TOUS les capteurs d'un coup
void Line_ReadAll(LineSensor_t *sensor) {
    for (uint8_t i = 0; i < sensor->activeSensors; i++) {
        // On stocke le résultat directement dans le tableau
        sensor->sensorValues[i] = Read_Single_Channel(sensor, i);
    }
}

// (Bonus) Calcul de position simple pour PID
// Retourne une valeur estimée de la position de la ligne noire
// Exemple : -3000 (Tout à gauche) ... 0 (Centré) ... +3000 (Tout à droite)
int Line_GetPosition(LineSensor_t *sensor) {
    long weightedSum = 0;
    long totalIntensity = 0;

    for(int i=0; i < sensor->activeSensors; i++) {
        uint16_t val = sensor->sensorValues[i];

        // On suppose que Ligne Noire = Valeur Élevée (> 2000 par exemple)
        // On ignore le bruit de fond (< 500)
        if (val > 500) {
            // Formule du barycentre
            // i*1000 permet de donner un "poids" à chaque capteur (0, 1000, 2000...)
            weightedSum += (long)val * (i * 1000);
            totalIntensity += val;
        }
    }

    if (totalIntensity == 0) return -1; // Ligne perdue ou non trouvée

    return (int)(weightedSum / totalIntensity);
}
