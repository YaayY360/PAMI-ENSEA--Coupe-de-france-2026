#include "utils.h"

void Moteurs(bool M1, bool M2)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, M1*VITESSE_MOTEUR); // Moteur de droite
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, M2*VITESSE_MOTEUR); // Moteur de gauche
}
