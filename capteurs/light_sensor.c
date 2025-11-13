#include <light_sensor.h>

bool LS, CLS, CRS, RS;

void setup() {
	//
}

void loop() {

	// ATTRIBUTION DES CAPTEURS A LEUR VARIABLES

	LS= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9); // left_sensor
	CLS= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8); // central_left_censor
	CRS= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7); // central_right_sensor
	RS= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6); // right_sensor

	// TEST AVEC PRINTF
	if(CLS && CRS)
		printf("The system is centered\r\n");
	else if(!CLS && !CRS)
		printf("The system is out of track\r\n");
	else if(!CRS)
		printf("The system must go left to remain on track\r\n");
	else if(!CLS)
		printf("The system must go right to remain on track\r\n");
}

// Réalisé en collaboration avec gotaga (coco)
