/***************************************************************
* @file      Startup_stm32.c
* @author    K J Vivek
* @brief     This module performs:
                - Set the initial SP
                - Set the initial PC == Reset_Handler,
                - Set the vector table entries with the exceptions ISR address
                - Branches to main in the C library (which eventually calls main()).
* @reference https://youtu.be/qWqlkCLmZoE
**************************************************************/
#include<stdint.h>

/*start address for the .data section. defined in linker script */
extern uint32_t _sdata;
/*end address for the .data section. defined in linker script */
extern uint32_t _edata;
/* Start address for initialisation values of .data section*/
extern uint32_t _la_data;
/*start address for the .bss section. defined in linker script */
extern uint32_t _sbss;
/*end address for the .bss section. defined in linker script */
extern uint32_t _ebss;
/*Address of User stack */
extern uint32_t _Stack_Start;


/* prototype of main */
int main(void);
void __libc_init_array(void);
/* function prototypes of STM32F407x system exception and IRQ handlers */
void Reset_Handler(void);

/*******************************************************************************
* @brief Provide weak aliases for each Exception handler to the Default_Handler.
  		 As they are weak aliases, any function with the same name will override
 		 this definition.
*******************************************************************************/
void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));                               
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void CAN1_TX_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void CAN1_RX0_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_RX1_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_SCE_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void USART3_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void OTG_FS_WKUP_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_TIM12_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler      	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void CRYP_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));                          


uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
	(uint32_t)&_Stack_Start,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler,
	(uint32_t)HardFault_Handler,
	(uint32_t)MemManage_Handler,
	(uint32_t)BusFault_Handler,
	(uint32_t)UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)SVC_Handler,
	(uint32_t)DebugMon_Handler,
	0,
	(uint32_t)PendSV_Handler,
	(uint32_t)SysTick_Handler,
	(uint32_t)WWDG_IRQHandler,
	(uint32_t)PVD_IRQHandler,         
	(uint32_t)TAMP_STAMP_IRQHandler,  
	(uint32_t)RTC_WKUP_IRQHandler,    
	0,                      
	(uint32_t)RCC_IRQHandler,         
	(uint32_t)EXTI0_IRQHandler,       
	(uint32_t)EXTI1_IRQHandler,       
	(uint32_t)EXTI2_IRQHandler,       
	(uint32_t)EXTI3_IRQHandler,       
	(uint32_t)EXTI4_IRQHandler,       
	(uint32_t)DMA1_Stream0_IRQHandler,
	(uint32_t)DMA1_Stream1_IRQHandler,
	(uint32_t)DMA1_Stream2_IRQHandler,
	(uint32_t)DMA1_Stream3_IRQHandler,
	(uint32_t)DMA1_Stream4_IRQHandler,
	(uint32_t)DMA1_Stream5_IRQHandler,
	(uint32_t)DMA1_Stream6_IRQHandler,
	(uint32_t)ADC_IRQHandler,         
	(uint32_t)CAN1_TX_IRQHandler,     
	(uint32_t)CAN1_RX0_IRQHandler,    
	(uint32_t)CAN1_RX1_IRQHandler,    
	(uint32_t)CAN1_SCE_IRQHandler,    
	(uint32_t)EXTI9_5_IRQHandler,     
	(uint32_t)TIM1_BRK_TIM9_IRQHandler,
	(uint32_t)TIM1_UP_TIM10_IRQHandler,
	(uint32_t)TIM1_TRG_COM_TIM11_IRQHandler,
	(uint32_t)TIM1_CC_IRQHandler,     
	(uint32_t)TIM2_IRQHandler,        
	(uint32_t)TIM3_IRQHandler,        
	(uint32_t)TIM4_IRQHandler,        
	(uint32_t)I2C1_EV_IRQHandler,     
	(uint32_t)I2C1_ER_IRQHandler,     
	(uint32_t)I2C2_EV_IRQHandler,     
	(uint32_t)I2C2_ER_IRQHandler,     
	(uint32_t)SPI1_IRQHandler,        
	(uint32_t)SPI2_IRQHandler,        
	(uint32_t)USART1_IRQHandler,      
	(uint32_t)USART2_IRQHandler,      
	(uint32_t)USART3_IRQHandler,      
	(uint32_t)EXTI15_10_IRQHandler,   
	(uint32_t)RTC_Alarm_IRQHandler,   
	(uint32_t)OTG_FS_WKUP_IRQHandler, 
	(uint32_t)TIM8_BRK_TIM12_IRQHandler,
	(uint32_t)TIM8_UP_TIM13_IRQHandler,
	(uint32_t)TIM8_TRG_COM_TIM14_IRQHandler,
	(uint32_t)TIM8_CC_IRQHandler,     
	(uint32_t)DMA1_Stream7_IRQHandler,
	(uint32_t)FSMC_IRQHandler,        
	(uint32_t)SDIO_IRQHandler,        
	(uint32_t)TIM5_IRQHandler,        
	(uint32_t)SPI3_IRQHandler,        
	(uint32_t)UART4_IRQHandler,       
	(uint32_t)UART5_IRQHandler,       
	(uint32_t)TIM6_DAC_IRQHandler,    
	(uint32_t)TIM7_IRQHandler,        
	(uint32_t)DMA2_Stream0_IRQHandler,
	(uint32_t)DMA2_Stream1_IRQHandler,
	(uint32_t)DMA2_Stream2_IRQHandler,
	(uint32_t)DMA2_Stream3_IRQHandler,
	(uint32_t)DMA2_Stream4_IRQHandler,
	(uint32_t)ETH_IRQHandler,         
	(uint32_t)ETH_WKUP_IRQHandler,    
	(uint32_t)CAN2_TX_IRQHandler,     
	(uint32_t)CAN2_RX0_IRQHandler,    
	(uint32_t)CAN2_RX1_IRQHandler,    
	(uint32_t)CAN2_SCE_IRQHandler,    
	(uint32_t)OTG_FS_IRQHandler,      
	(uint32_t)DMA2_Stream5_IRQHandler,
	(uint32_t)DMA2_Stream6_IRQHandler,
	(uint32_t)DMA2_Stream7_IRQHandler,
	(uint32_t)USART6_IRQHandler,      
	(uint32_t)I2C3_EV_IRQHandler,     
	(uint32_t)I2C3_ER_IRQHandler,     
	(uint32_t)OTG_HS_EP1_OUT_IRQHandler,
	(uint32_t)OTG_HS_EP1_IN_IRQHandler,
	(uint32_t)OTG_HS_WKUP_IRQHandler, 
	(uint32_t)OTG_HS_IRQHandler,      
	(uint32_t)DCMI_IRQHandler,        
	(uint32_t)CRYP_IRQHandler,        
	(uint32_t)HASH_RNG_IRQHandler,    
	(uint32_t)FPU_IRQHandler,         
};

/*****************************************************************
* @brief  This is the code that gets called when the processor receives an
*         unexpected interrupt.  This simply enters an infinite loop, preserving
*         the system state for examination by a debugger.
****************************************************************/
void Default_Handler(void)
{
	__asm volatile(
		"LoopForever:\n\t"
			"B LoopForever\n\t"
	);
}

/****************************************************************
* @brief   This is the code that gets called after reset. After which the application
*          main() routine is called.
***************************************************************/
void Reset_Handler(void)
{
	__asm volatile(
		"LDR R0, =_Stack_Start \n\t"
		"MOV SP, R0 \n\t"
		/*Copying .data section to SRAM */
		"LDR R0, =_sdata \n\t"
		"LDR R1, =_edata \n\t" 
		"LDR R2, =_la_data \n\t"  
		"MOVS R3, #0 \n\t"
		"B CopyDataLoop \n\t"

		"CopyDataInit: \n\t"
			"LDR R4, [R2, R3]\n\t"
  			"STR R4, [R0, R3] \n\t"
  			"ADDS R3, R3, #4 \n\t"

		"CopyDataLoop:\n\t"
			"ADDS R4, R0, R3 \n\t"
  			"cmp R4, R1 \n\t"
  			"BCC CopyDataInit \n\t"

		/* Initialising .bss section to 0 in SRAM*/
		"LDR R2, =_sbss \n\t"
		"LDR R4, =_ebss \n\t" 
		"MOVS R3, #0 \n\t"
		"B FillZerosLoop \n\t"

		"FillZeros: \n\t"
			"STR R3, [R2] \n\t"
			"ADDS R2, R2, #4 \n\t"
			
		"FillZerosLoop: \n\t"
			"CMP R2, R4 \n\t"
			"BCC FillZeros \n\t"

	);
	
	/*
	//copy .data section to SRAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata; //sram
	uint8_t *pSrc = (uint8_t*)&_la_data; //flash
	
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = *pSrc++;
	}
	
	//Init. the .bss section to zero in SRAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = 0;
	}
*/
	__libc_init_array();
	
	main();
	
}
