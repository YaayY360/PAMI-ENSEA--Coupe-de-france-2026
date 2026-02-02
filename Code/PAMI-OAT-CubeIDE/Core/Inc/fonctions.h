#include <stm32l4xx_hal.h>

#define VITESSE_BASE 1250

#define IN1_PORT GPIOA
#define IN1_PIN GPIO_PIN_1
#define IN2_PORT GPIOA
#define IN2_PIN GPIO_PIN_4
#define IN3_PORT GPIOC
#define IN3_PIN GPIO_PIN_1
#define IN4_PORT GPIOC
#define IN4_PIN GPIO_PIN_0

#define X1_PORT GPIOB
#define X1_PIN GPIO_PIN_4
#define X2_PORT GPIOB
#define X2_PIN GPIO_PIN_5
#define X3_PORT GPIOB
#define X3_PIN GPIO_PIN_3
#define X4_PORT GPIOA
#define X4_PIN GPIO_PIN_10

#define ECHO_PORT GPIOB
#define ECHO_PIN GPIO_PIN_10

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

void Moteurs(void);
void Ligne(void);
void UltraSon(void);
