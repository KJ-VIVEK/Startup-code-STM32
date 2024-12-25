/** ******************************************************************************
  * @file   	 Led-Blink.c
  * @brief  	 Default main function.
  * @reference 	 https://youtu.be/qWqlkCLmZoE
  *******************************************************************************/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Include header file
#include <stdio.h>
#include <stdint.h>

// Define boolean
#define TRUE       				1
#define FALSE      				0

// Define LED
#define LED_GREEN  				12
#define LED_ORANGE 				13
#define LED_RED    				14
#define LED_BLUE   				15

// Define delay count
#define DELAY_COUNT_1MS 		1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)


// Initialize LED
void led_on (uint8_t led_no)
{
  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
  *pGpiodDataReg |= ( 1 << led_no);

}

// Initialize LED
void led_off (uint8_t led_no)
{
	  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
	  *pGpiodDataReg &= ~( 1 << led_no);

}

// Initialize LED
void delay (uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

//	Initialize LED
void Led_Toggle(void)
{
	while(TRUE)
	{
		led_on (LED_GREEN); // Turn on LED
		led_on (LED_ORANGE);
		led_on (LED_BLUE);
		led_on (LED_RED);

		delay (DELAY_COUNT_1S); // Delay 1 second

		led_off (LED_GREEN); // Turn off LED
		led_off (LED_ORANGE);
		led_off (LED_BLUE);
		led_off (LED_RED);

		delay (DELAY_COUNT_1S);
	}

}

// Initialize LED
void led_init (void)
{

	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	uint32_t *pGpiodModeReg = (uint32_t*)0x40020C00;

	*pRccAhb1enr |= ( 1 << 3);

	//configure LED_GREEN
	*pGpiodModeReg |= ( 1 << (2 * LED_GREEN));
	*pGpiodModeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpiodModeReg |= ( 1 << (2 * LED_RED));
	*pGpiodModeReg |= ( 1 << (2 * LED_BLUE));
}

// main function
int main(void)
{
	led_init (); // Initialize LED

	Led_Toggle (); // Toggle LED

	while (TRUE); // Infinite loop

	return 0;
}