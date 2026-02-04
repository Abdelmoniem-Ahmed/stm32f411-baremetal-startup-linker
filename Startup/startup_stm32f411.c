/**
 * @file    startup_stm32f411.c
 * @author  Abdelmoniem Ahmed
 * @brief   ARM Cortex-M4 startup code for STM32F411
 *
 * This file contains:
 *  - Vector table definition
 *  - Reset_Handler implementation
 *  - Initialization of .data and .bss sections
 *  - Transfer of control to main()
 */


typedef unsigned int uint32_t;
#define NULL 0

extern uint32_t _estack , _etext , _edata , _sdata , _sbss , _ebss , _sidata;

uint32_t * const MSP_Init = (uint32_t*)&_estack;

extern int main(void)																			;
void Reset_Handler(void)																		;
void Non_MaskableInt_Handler(void)			__attribute__((weak , alias("Default_Handler")))    ;
void HardFault_Handler(void)				__attribute__((weak , alias("Default_Handler")))    ;
void Mem_Manage(void)						__attribute__((weak , alias("Default_Handler")))	;
void Bus_Fault(void)						__attribute__((weak , alias("Default_Handler")))	;
void Usage_Fault(void)						__attribute__((weak , alias("Default_Handler")))	;
void System_Service_Call(void)				__attribute__((weak , alias("Default_Handler")))	;
void Debug_Monitor(void)					__attribute__((weak , alias("Default_Handler")))	;
void Pend_SV(void)							__attribute__((weak , alias("Default_Handler")))	;
void Sys_Tick(void)							__attribute__((weak , alias("Default_Handler")))	;
void Window_WatchDog_Int(void)				__attribute__((weak , alias("Default_Handler")))	;
void PVD_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void TAMP_STAMP_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void RTC_WKUP_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void FLASH_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void RCC_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void EXTI0_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void EXTI1_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void EXTI2_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void EXTI3_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void EXTI4_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream0_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream1_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream2_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream3_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream4_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream5_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream6_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void ADC_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void CAN1_TX_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN1_RX0_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN1_RX1_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN1_SCE_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void EXTI9_5_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void TIM1_BRK_TIM9_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__((weak , alias("Default_Handler")))	;
void TIM1_CC_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void TIM2_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void TIM3_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void TIM4_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void I2C1_EV_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void I2C1_ER_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void I2C2_EV_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void I2C2_ER_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void SPI1_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void SPI2_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void USART1_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void USART2_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void USART3_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void EXTI15_10_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void RTC_Alarm_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void OTG_FS_WKUP_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void TIM8_BRK_TIM12_IRQHandler(void)		__attribute__((weak , alias("Default_Handler")))	;
void TIM8_UP_TIM13_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__((weak , alias("Default_Handler")))	;
void TIM8_CC_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void DMA1_Stream7_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void FSMC_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void SDIO_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void TIM5_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void SPI3_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void UART4_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void UART5_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void TIM6_DAC_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void TIM7_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream0_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream1_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream2_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream3_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream4_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void ETH_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void ETH_WKUP_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN2_TX_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN2_RX0_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN2_RX1_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void CAN2_SCE_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void OTG_FS_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream5_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream6_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void DMA2_Stream7_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void USART6_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void I2C3_EV_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void I2C3_ER_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void OTG_HS_EP1_OUT_IRQHandler(void)		__attribute__((weak , alias("Default_Handler")))	;
void OTG_HS_EP1_IN_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void OTG_HS_WKUP_IRQHandler(void)			__attribute__((weak , alias("Default_Handler")))	;
void OTG_HS_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void DCMI_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;
void HASH_RNG_IRQHandler(void)				__attribute__((weak , alias("Default_Handler")))	;
void FPU_IRQHandler(void)					__attribute__((weak , alias("Default_Handler")))	;


uint32_t * const vector_table[] __attribute__ ((section(".isr_vector"))) = { 
		
		(uint32_t *)MSP_Init , // Initial Stack Pointer
		(uint32_t*)Reset_Handler , // Reset Handler
		(uint32_t*)Non_MaskableInt_Handler , // NMI Handler
		(uint32_t*)HardFault_Handler , // Hard Fault Handler
		(uint32_t*)Mem_Manage ,
		(uint32_t*)Bus_Fault ,
		(uint32_t*)Usage_Fault ,
		0 ,
		0 ,
		0 ,
		0 ,
		(uint32_t*)System_Service_Call ,
		(uint32_t*)Debug_Monitor ,
		0 ,
		(uint32_t*)Pend_SV ,
		(uint32_t*)Sys_Tick ,
		(uint32_t*)Window_WatchDog_Int ,
		(uint32_t*) PVD_IRQHandler  			  ,
		(uint32_t*) TAMP_STAMP_IRQHandler		  ,
		(uint32_t*) RTC_WKUP_IRQHandler			  ,
		(uint32_t*) FLASH_IRQHandler			  ,
		(uint32_t*) RCC_IRQHandler				  ,
		(uint32_t*) EXTI0_IRQHandler			  ,
		(uint32_t*) EXTI1_IRQHandler			  ,
		(uint32_t*) EXTI2_IRQHandler			  ,
		(uint32_t*) EXTI3_IRQHandler			  ,
		(uint32_t*) EXTI4_IRQHandler			  ,
		(uint32_t*) DMA1_Stream0_IRQHandler		  ,
		(uint32_t*) DMA1_Stream1_IRQHandler		  ,
		(uint32_t*) DMA1_Stream2_IRQHandler		  ,
		(uint32_t*) DMA1_Stream3_IRQHandler		  ,
		(uint32_t*) DMA1_Stream4_IRQHandler		  ,
		(uint32_t*) DMA1_Stream5_IRQHandler		  ,
		(uint32_t*) DMA1_Stream6_IRQHandler		  ,
		(uint32_t*) ADC_IRQHandler				  ,
		(uint32_t*) CAN1_TX_IRQHandler			  ,
		(uint32_t*) CAN1_RX0_IRQHandler			  ,
		(uint32_t*) CAN1_RX1_IRQHandler			  ,
		(uint32_t*) CAN1_SCE_IRQHandler			  ,
		(uint32_t*) EXTI9_5_IRQHandler			  ,
		(uint32_t*) TIM1_BRK_TIM9_IRQHandler	  ,
		(uint32_t*) TIM1_UP_TIM10_IRQHandler	  ,
		(uint32_t*) TIM1_TRG_COM_TIM11_IRQHandler ,
		(uint32_t*) TIM1_CC_IRQHandler			  ,
		(uint32_t*) TIM2_IRQHandler				  ,
		(uint32_t*) TIM3_IRQHandler				  ,
		(uint32_t*) TIM4_IRQHandler				  ,
		(uint32_t*) I2C1_EV_IRQHandler			  ,
		(uint32_t*) I2C1_ER_IRQHandler			  ,
		(uint32_t*) I2C2_EV_IRQHandler			  ,
		(uint32_t*) I2C2_ER_IRQHandler			  ,
		(uint32_t*) SPI1_IRQHandler				  ,
		(uint32_t*) SPI2_IRQHandler				  ,
		(uint32_t*) USART1_IRQHandler			  ,
		(uint32_t*) USART2_IRQHandler			  ,
		(uint32_t*) USART3_IRQHandler			  ,
		(uint32_t*) EXTI15_10_IRQHandler		  ,
		(uint32_t*) RTC_Alarm_IRQHandler		  ,
		(uint32_t*) OTG_FS_WKUP_IRQHandler		  ,
		(uint32_t*) TIM8_BRK_TIM12_IRQHandler	  ,
		(uint32_t*) TIM8_UP_TIM13_IRQHandler	  ,
		(uint32_t*) TIM8_TRG_COM_TIM14_IRQHandler ,
		(uint32_t*) TIM8_CC_IRQHandler			  ,
		(uint32_t*) DMA1_Stream7_IRQHandler		  ,
		(uint32_t*) FSMC_IRQHandler				  ,
		(uint32_t*) SDIO_IRQHandler				  ,
		(uint32_t*) TIM5_IRQHandler				  ,
		(uint32_t*) SPI3_IRQHandler				  ,
		(uint32_t*) UART4_IRQHandler			  ,
		(uint32_t*) UART5_IRQHandler			  ,
		(uint32_t*) TIM6_DAC_IRQHandler			  ,
		(uint32_t*) TIM7_IRQHandler				  ,
		(uint32_t*) DMA2_Stream0_IRQHandler		  ,
		(uint32_t*) DMA2_Stream1_IRQHandler		  ,
		(uint32_t*) DMA2_Stream2_IRQHandler		  ,
		(uint32_t*) DMA2_Stream3_IRQHandler		  ,
		(uint32_t*) DMA2_Stream4_IRQHandler		  ,
		(uint32_t*) ETH_IRQHandler				  ,
		(uint32_t*) ETH_WKUP_IRQHandler			  ,
		(uint32_t*) CAN2_TX_IRQHandler			  ,
		(uint32_t*) CAN2_RX0_IRQHandler			  ,
		(uint32_t*) CAN2_RX1_IRQHandler			  ,
		(uint32_t*) CAN2_SCE_IRQHandler			  ,
		(uint32_t*) OTG_FS_IRQHandler			  ,
		(uint32_t*) DMA2_Stream5_IRQHandler		  ,
		(uint32_t*) DMA2_Stream6_IRQHandler		  ,
		(uint32_t*) DMA2_Stream7_IRQHandler		  ,
		(uint32_t*) USART6_IRQHandler			  ,
		(uint32_t*) I2C3_EV_IRQHandler			  ,
		(uint32_t*) I2C3_ER_IRQHandler			  ,
		(uint32_t*) OTG_HS_EP1_OUT_IRQHandler	  ,
		(uint32_t*) OTG_HS_EP1_IN_IRQHandler	  ,
		(uint32_t*) OTG_HS_WKUP_IRQHandler 		  ,
		(uint32_t*) OTG_HS_IRQHandler			  ,
		(uint32_t*) DCMI_IRQHandler				  ,
		(uint32_t*) HASH_RNG_IRQHandler			  ,
		(uint32_t*) FPU_IRQHandler				  ,
	};


	void SystemInit(void) {
		/* Clock Initialization */
	}

void Reset_Handler(void) {
	
	uint32_t Section_Size = 0 ;
	uint32_t* MemSourceAddress = NULL ;
	uint32_t* MemDestAddress = NULL;

/* 
 * Copy .data section from FLASH to SRAM
 * Required because variables with initial values
 * must reside in RAM at runtime
 */
	 
	Section_Size = (uint32_t*)&_edata - (uint32_t*)&_sdata;
	MemSourceAddress = (uint32_t*)&_sidata;
	MemDestAddress = (uint32_t*)&_sdata;

	Section_Size = Section_Size / 4;

	for (uint32_t MemCount = 0 ; MemCount < Section_Size; MemCount++)
	{
		*MemDestAddress++ = *MemSourceAddress++ ;
	}

	/* 2) Initialize the .bss segment with zero */

	Section_Size = (uint32_t*)&_ebss - (uint32_t*)&_sbss;
	MemDestAddress = (uint32_t*)&_sbss;
	Section_Size = Section_Size / 4;

	for (uint32_t MemCount = 0; MemCount < Section_Size; MemCount++)
	{
		*MemDestAddress++ = 0;
	}

	/* 3) call the system initialization function */
	SystemInit();
	/* 4) call the main function */
	main();
}



void Default_Handler(void)
{
	while (1) {
		/* Trap CPU */
	}
}
