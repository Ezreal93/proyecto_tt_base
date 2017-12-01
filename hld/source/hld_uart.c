#include "hld_uart.h"

#include <stdbool.h>

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_usart.h"

void uart2_init(uint32_t baudrate){
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_GPIO_InitTypeDef gpio;
    LL_GPIO_StructInit(&gpio);
    gpio.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
    gpio.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio.Alternate = LL_GPIO_AF_7;
    LL_GPIO_Init(GPIOA, &gpio);
  
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
    LL_USART_InitTypeDef usart;
    LL_USART_StructInit(&usart);
    usart.BaudRate = baudrate;
    usart.DataWidth = LL_USART_DATAWIDTH_8B;
    usart.OverSampling = LL_USART_OVERSAMPLING_8;
    usart.Parity =  LL_USART_PARITY_NONE;
    usart.StopBits =LL_USART_STOPBITS_1;
    usart.TransferDirection = LL_USART_DIRECTION_TX_RX;
    LL_USART_Init(USART2, &usart);
    LL_USART_Enable(USART2);
 }

void uart2_puts(const char* string){
    char c;
    while((c = *string++)){
        uart2_putc(c);
    }
}

void uart2_putc(char c){
    LL_USART_TransmitData8(USART2, c);
    while(!LL_USART_IsActiveFlag_TXE(USART2)){};
}
