/*
 * mcp3208_line.h
 * Pilote pour Suiveur de Ligne (Array IR) via MCP3208
 */

#ifndef MCP3208_LINE_H
#define MCP3208_LINE_H

#include "main.h"

// Structure pour gérer une barrette de capteurs (ex: 8 capteurs)
typedef struct {
    SPI_HandleTypeDef *hspi;       // Handle SPI
    GPIO_TypeDef *CsPort;          // Port Chip Select
    uint16_t CsPin;                // Pin Chip Select
    uint16_t sensorValues[8];      // Tableau pour stocker les valeurs brutes (0-4095)
    uint8_t activeSensors;         // Nombre de capteurs utilisés (ex: 5 ou 8)
} LineSensor_t;

// Fonctions
void Line_Init(LineSensor_t *sensor, SPI_HandleTypeDef *hspi, GPIO_TypeDef *port, uint16_t pin, uint8_t numSensors);
void Line_ReadAll(LineSensor_t *sensor);
int Line_GetPosition(LineSensor_t *sensor); // Optionnel : calcule la position de la ligne (-1000 à 1000)

#endif // MCP3208_LINE_H
