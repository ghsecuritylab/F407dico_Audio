/*
 * This file provides template for all exceptions handler and 
 * peripherals interrupt service routine.
 */  

#include "main.h"

/* Timer used for LED blinking (defined in main.c */
extern TIM_HandleTypeDef hTimLed;

extern I2S_HandleTypeDef       hAudioOutI2s;

extern I2S_HandleTypeDef       hAudioInI2s;
 __IO uint32_t TimeRecBase = 0;  /* Time Recording base variable */
extern __IO uint32_t CmdIndex;
extern HCD_HandleTypeDef hHCD;

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

/* This function handles SysTick Handler */
void SysTick_Handler(void)
{
  HAL_IncTick();

  /* Test on the command: Recording */
  if (CmdIndex == CMD_RECORD)
  {
    /* Increments the time recording base variable */
    TimeRecBase ++; 
  }
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s).                                              */
/******************************************************************************/

/**
  * This function handles External line 0 interrupt request.
  */
void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

/**
  * @brief  This function handles External line 1 interrupt request.
  */
void EXTI1_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

/**
  * @brief  This function handles main I2S interrupt. 
  */
void I2S3_IRQHandler(void)
{ 
  HAL_DMA_IRQHandler(hAudioOutI2s.hdmatx);
}

/**
  * @brief  This function handles DMA Stream interrupt request.
  */
void I2S2_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hAudioInI2s.hdmarx);
}

/**
  * This function handles TIM4 global interrupt request.
  */
void TIM4_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&hTimLed);
}

/**
  * This function handles USB-On-The-Go FS global interrupt request.
  */
void OTG_FS_IRQHandler(void)
{
  HAL_HCD_IRQHandler(&hHCD);
}

