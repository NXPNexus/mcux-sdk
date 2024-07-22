/*
 * Copyright 2021-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*! @name PORTA19 (number 14), Q1[1]/J1[5]/LED_G/TPM0_CH2
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_GREEN_GPIO GPIOA                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_GREEN_GPIO_PIN_MASK (1U << 19U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITLEDSPINS_LED_GREEN_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_GREEN_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_GREEN_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTA20 (number 17), Q4[1]/J1[7]/LED_B/RF_GPO_2/TPM0_CH1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_BLUE_GPIO GPIOA                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_BLUE_GPIO_PIN_MASK (1U << 20U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITLEDSPINS_LED_BLUE_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_BLUE_PIN 20U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_BLUE_PIN_MASK (1U << 20U)      /*!<@brief PORT pin mask */
                                                              /* @} */

/*! @name PORTA21 (number 18), Q3[1]/J1[8]/LED_R/TPM0_CH0
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_RED_GPIO GPIOA                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_RED_GPIO_PIN_MASK (1U << 21U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITLEDSPINS_LED_RED_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_RED_PIN 21U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_RED_PIN_MASK (1U << 21U)      /*!<@brief PORT pin mask */
                                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void);

/*! @name PORTC2 (number 39), U23[3]/J4[6]/UART1_RX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                                        /* @} */

/*! @name PORTC3 (number 40), U23[4]/J4[5]/UART1_TX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                                                        /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void);

/*! @name PORTD1 (number 24), J4[1]/J13[2]/SW2/NMI_b/ADC0_B5
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITBUTTONSPINS_SW2_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW2_GPIO_PIN_MASK (1U << 1U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITBUTTONSPINS_SW2_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW2_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INITBUTTONSPINS_SW2_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*! @name PORTC6 (number 44), J5[5]/SW3/LPSPI1_PCS1/WUU0_P11
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITBUTTONSPINS_SW3_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW3_GPIO_PIN_MASK (1U << 6U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITBUTTONSPINS_SW3_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW3_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_INITBUTTONSPINS_SW3_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*! @name PORTA4 (number 10), JP25[3]/J4[4]/U18[12]/SW4/SWO/BOOT_CFG
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITBUTTONSPINS_SW4_GPIO GPIOA               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW4_GPIO_PIN_MASK (1U << 4U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITBUTTONSPINS_SW4_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITBUTTONSPINS_SW4_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_INITBUTTONSPINS_SW4_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitButtonsPins(void);

/*! @name PORTB1 (number 47), U4[2]/J2[5]/J5[9]/J12[5]/U24[4]/LPSPI1_SIN
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITFLASHPINS_FLASH_SIN_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_SIN_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INITFLASHPINS_FLASH_SIN_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTB3 (number 1), U4[5]/J2[4]/J5[7]/J12[6]/U24[5]/LPSPI1_SOUT
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITFLASHPINS_FLASH_SOUT_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_SOUT_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_INITFLASHPINS_FLASH_SOUT_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                                                /* @} */

/*! @name PORTB0 (number 46), U4[1]/Q2[1]/J1[6]/LPSPI1_PCS0/TPM1_CH0
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITFLASHPINS_FLASH_CS_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_CS_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_INITFLASHPINS_FLASH_CS_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                              /* @} */

/*! @name PORTB2 (number 48), U4[6]/J2[6]/J5[11]/J12[4]/U24[3]/LPSPI1_SK
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITFLASHPINS_FLASH_SCK_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_SCK_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_INITFLASHPINS_FLASH_SCK_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTB4 (number 2), U4[7]/J2[3]/J12[3]/U24[6]/LPSPI1_PCS3
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITFLASHPINS_FLASH_RST_GPIO GPIOB               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_RST_GPIO_PIN_MASK (1U << 4U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITFLASHPINS_FLASH_RST_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITFLASHPINS_FLASH_RST_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_INITFLASHPINS_FLASH_RST_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitFlashPins(void);

/*! @name PORTC0 (number 37), U12[4]/J2[9]/J13[6]/I2C1_SCL
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITACCELPINS_ACCEL_SCL_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITACCELPINS_ACCEL_SCL_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_INITACCELPINS_ACCEL_SCL_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTC1 (number 38), U12[6]/J2[10]/J13[5]/I2C1_SDA
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITACCELPINS_ACCEL_SDA_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITACCELPINS_ACCEL_SDA_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INITACCELPINS_ACCEL_SDA_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitACCELPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
