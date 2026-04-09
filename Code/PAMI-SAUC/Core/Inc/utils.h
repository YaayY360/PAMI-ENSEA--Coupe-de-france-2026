#include <stm32h5xx.h>
#include <stdbool.h>
#include <stdio.h>
#include "mcp3208_line.h"
#include "VL53L0X.h"

#define VITESSE_MOTEUR 2000

extern TIM_HandleTypeDef htim1;

void Moteurs(bool M1, bool M2);
