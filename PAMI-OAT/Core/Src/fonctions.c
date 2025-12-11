#include "fonctions.h"
#include <stdio.h>
#include <stdbool.h>

bool LS, CLS, CRS, RS;
bool EN = 0;
bool SENS = 1; // 1 avance, 0 recule
bool currentECHO, lastECHO;

float vitesse_moteur_droite, vitesse_moteur_gauche;
float rapport_gauche_droite = 1; // entre 0.7 et 1.3 en fonction de si ça tourne à droite ou à gauche, à 1.0 s'il avance tout droit
float startECHO, durationECHO, distance;

void Moteurs(void) {
	// PARTIE MOTEUR | VITESSE_BASE est à 1250
	HAL_GPIO_WritePin(IN1_PORT, IN1_PIN, 1); HAL_GPIO_WritePin(IN2_PORT, IN2_PIN, 0);
	HAL_GPIO_WritePin(IN3_PORT, IN3_PIN, 1); HAL_GPIO_WritePin(IN4_PORT, IN4_PIN, 0);
	vitesse_moteur_droite = VITESSE_BASE* (2 - rapport_gauche_droite);  // Calcul de la vitesse du moteur de droite avec le rapport
	vitesse_moteur_gauche = VITESSE_BASE * rapport_gauche_droite;        // Calcul de la vitesse du moteur de gauche avec le rapport
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, EN*vitesse_moteur_droite); // Moteur de droite
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, EN*vitesse_moteur_gauche); // Moteur de gauche
}

void Ligne(void) {
	// PARTIE CAPTEUR POUR LA LIGNE
	LS = HAL_GPIO_ReadPin(X2_PORT, X2_PIN); // left_sensor
	CLS = HAL_GPIO_ReadPin(X1_PORT, X1_PIN); // central_left_censor
	CRS = HAL_GPIO_ReadPin(X3_PORT, X3_PIN); // central_right_sensor
	RS = HAL_GPIO_ReadPin(X4_PORT, X4_PIN); // right_sensor
	// TEST AVEC PRINTF
	if(CLS && CRS) { // Le système est centré
		EN = 1; rapport_gauche_droite = 1;
		//printf("The system is centered | %.3f \r\n", rapport_gauche_droite);
	}
	else if(!CLS && !CRS)  {
		EN = 0; rapport_gauche_droite = 1;
		//printf("The system is out of track %.3f \r\n", rapport_gauche_droite);
	}
	else if(!CRS) { // Doit tourner à gauche (diminue le rapport)
		EN = 1; if(rapport_gauche_droite > 0.7) rapport_gauche_droite -= 0.002;
		//printf("The system must go left to remain on track | %.3f \r\n", rapport_gauche_droite);
	}
	else if(!CLS) { // Doit tourner à droite (augmente le rapport)
		EN = 1; if(rapport_gauche_droite < 1.3) rapport_gauche_droite += 0.002;
		//printf("The system must go right to remain on track | %.3f \r\n", rapport_gauche_droite);
	}
}

void UltraSon(void) {
	// PARTIE CAPTEUR ULTRASON (ECHO)
	currentECHO = HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN);
	if(currentECHO && !lastECHO) {
		startECHO = HAL_GetTick();
	}
	if(!currentECHO && lastECHO) {
		durationECHO = HAL_GetTick() - startECHO;
		distance = 170.0*durationECHO;
		//printf("%.4f\r\n", distance);
	}
	lastECHO = currentECHO;
	// DISTANCE A MODIFIER SI BESOIN
	if(distance<10.0) EN = 0;
	else              EN = 1;
}
