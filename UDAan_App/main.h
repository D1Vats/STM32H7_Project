#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SDRAM_DQMH_Pin GPIO_PIN_1
#define SDRAM_DQMH_GPIO_Port GPIOE
#define ATEC_SCL_Pin GPIO_PIN_6
#define ATEC_SCL_GPIO_Port GPIOB
#define EXT_FLASH_IO2_Pin GPIO_PIN_2
#define EXT_FLASH_IO2_GPIO_Port GPIOE
#define SDRAM_DQML_Pin GPIO_PIN_0
#define SDRAM_DQML_GPIO_Port GPIOE
#define SDRAM_CAS__Pin GPIO_PIN_15
#define SDRAM_CAS__GPIO_Port GPIOG
#define SDRAM_DQ3_Pin GPIO_PIN_0
#define SDRAM_DQ3_GPIO_Port GPIOD
#define SDRAM_DQ2_Pin GPIO_PIN_1
#define SDRAM_DQ2_GPIO_Port GPIOD
#define SDRAM_CLK_Pin GPIO_PIN_8
#define SDRAM_CLK_GPIO_Port GPIOG
#define SDRAM_A2_Pin GPIO_PIN_2
#define SDRAM_A2_GPIO_Port GPIOF
#define SDRAM_A1_Pin GPIO_PIN_1
#define SDRAM_A1_GPIO_Port GPIOF
#define SDRAM_A0_Pin GPIO_PIN_0
#define SDRAM_A0_GPIO_Port GPIOF
#define SDRAM_BA1_Pin GPIO_PIN_5
#define SDRAM_BA1_GPIO_Port GPIOG
#define EXT_FLASH_NCS_Pin GPIO_PIN_6
#define EXT_FLASH_NCS_GPIO_Port GPIOG
#define BOOT_BTN_Pin GPIO_PIN_13
#define BOOT_BTN_GPIO_Port GPIOC
#define BOOT_BTN_EXTI_IRQn EXTI15_10_IRQn
#define LED_BLUE_Pin GPIO_PIN_3
#define LED_BLUE_GPIO_Port GPIOE
#define LED_RED_Pin GPIO_PIN_12
#define LED_RED_GPIO_Port GPIOI
#define SDRAM_A3_Pin GPIO_PIN_3
#define SDRAM_A3_GPIO_Port GPIOF
#define SDRAM_BA0_Pin GPIO_PIN_4
#define SDRAM_BA0_GPIO_Port GPIOG
#define SDRAM_A12_Pin GPIO_PIN_2
#define SDRAM_A12_GPIO_Port GPIOG
#define SDRAM_A5_Pin GPIO_PIN_5
#define SDRAM_A5_GPIO_Port GPIOF
#define SDRAM_A4_Pin GPIO_PIN_4
#define SDRAM_A4_GPIO_Port GPIOF
#define EXT_FLASH_IO3_Pin GPIO_PIN_6
#define EXT_FLASH_IO3_GPIO_Port GPIOF
#define EXT_FLASH_SCK_Pin GPIO_PIN_10
#define EXT_FLASH_SCK_GPIO_Port GPIOF
#define SDRAM_CKE_Pin GPIO_PIN_2
#define SDRAM_CKE_GPIO_Port GPIOH
#define SDRAM_DQ7_Pin GPIO_PIN_10
#define SDRAM_DQ7_GPIO_Port GPIOE
#define SDRAM_CS__Pin GPIO_PIN_3
#define SDRAM_CS__GPIO_Port GPIOH
#define SDRAM_WE__Pin GPIO_PIN_5
#define SDRAM_WE__GPIO_Port GPIOH
#define SDRAM_A7_Pin GPIO_PIN_13
#define SDRAM_A7_GPIO_Port GPIOF
#define SDRAM_A8_Pin GPIO_PIN_14
#define SDRAM_A8_GPIO_Port GPIOF
#define SDRAM_DQ8_Pin GPIO_PIN_11
#define SDRAM_DQ8_GPIO_Port GPIOE
#define SDRAM_DQ1_Pin GPIO_PIN_15
#define SDRAM_DQ1_GPIO_Port GPIOD
#define SDRAM_DQ0_Pin GPIO_PIN_14
#define SDRAM_DQ0_GPIO_Port GPIOD
#define SDRAM_A6_Pin GPIO_PIN_12
#define SDRAM_A6_GPIO_Port GPIOF
#define SDRAM_A9_Pin GPIO_PIN_15
#define SDRAM_A9_GPIO_Port GPIOF
#define SDRAM_DQ9_Pin GPIO_PIN_12
#define SDRAM_DQ9_GPIO_Port GPIOE
#define SDRAM_DQ12_Pin GPIO_PIN_15
#define SDRAM_DQ12_GPIO_Port GPIOE
#define ATEC_SDA_Pin GPIO_PIN_12
#define ATEC_SDA_GPIO_Port GPIOH
#define EXT_FLASH_IO0_Pin GPIO_PIN_11
#define EXT_FLASH_IO0_GPIO_Port GPIOD
#define EXT_FLASH_IO1_Pin GPIO_PIN_12
#define EXT_FLASH_IO1_GPIO_Port GPIOD
#define SDRAM_RAS__Pin GPIO_PIN_11
#define SDRAM_RAS__GPIO_Port GPIOF
#define SDRAM_A10_Pin GPIO_PIN_0
#define SDRAM_A10_GPIO_Port GPIOG
#define SDRAM_DQ5_Pin GPIO_PIN_8
#define SDRAM_DQ5_GPIO_Port GPIOE
#define SDRAM_DQ10_Pin GPIO_PIN_13
#define SDRAM_DQ10_GPIO_Port GPIOE
#define SDRAM_DQ15_Pin GPIO_PIN_10
#define SDRAM_DQ15_GPIO_Port GPIOD
#define SDRAM_DQ14_Pin GPIO_PIN_9
#define SDRAM_DQ14_GPIO_Port GPIOD
#define SDRAM_A11_Pin GPIO_PIN_1
#define SDRAM_A11_GPIO_Port GPIOG
#define SDRAM_DQ4_Pin GPIO_PIN_7
#define SDRAM_DQ4_GPIO_Port GPIOE
#define SDRAM_DQ11_Pin GPIO_PIN_14
#define SDRAM_DQ11_GPIO_Port GPIOE
#define SDRAM_DQ13_Pin GPIO_PIN_8
#define SDRAM_DQ13_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
