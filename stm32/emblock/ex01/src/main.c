 /**********************************************************
 *  File:    main.c
 *  Purpose: Blink LD2 on NUCLEO-103RB( Internal 36MHz CLK )
 *  Date:    31 December 2014
 *  Info:    Replace code to non-use SPL Code
 **********************************************************/
​
 #define SYSCLK  36  // ------------------------------------
​
 #include "stm32md_reg.h"
 #include "stm32md_init.h"
 #include "stm32md_delay.h"

 #ifndef __NO_SYSTEM_INIT  // ------------------------------
 void SystemInit()
 {
     flash_latency();
​     set_clk();
 }
 #endif
​
 void init_GPIO(void)  // ----------------------------------
 {
     RCC_APB2ENR |=    1 << IOPAEN;
     GPIOA_CRL   &= 0x00 << CNF5;
     GPIOA_CRL   |= 0x03 << MODE5;
 }
​
 int main(void)  // ----------------------------------------
 {
     init_GPIO();
​
     while(1)
     {
         GPIOA_ODR ^= 1 << B05;
         delay_ms(1000);
     }
 }
