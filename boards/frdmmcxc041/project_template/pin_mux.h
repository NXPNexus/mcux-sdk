/*
 * Copyright 2024 NXP
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

/*! @name PORTB10 (number 9), PTB10/J2[2]/J6[2]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_RED_FGPIO FGPIOB              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO_PIN_MASK (1U << 10U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_RED_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_RED_PIN 10U                   /*!<@brief PORT pin number */
#define BOARD_LED_RED_PIN_MASK (1U << 10U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTB11 (number 10), PTB11/J2[4]/J5[2]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_GREEN_FGPIO FGPIOB              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO_PIN_MASK (1U << 11U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_GREEN_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_GREEN_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_LED_GREEN_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*! @name PORTB13 (number 21), PTB13/J5[1]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_BLUE_FGPIO FGPIOB              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_BLUE_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_BLUE_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_LED_BLUE_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void);

#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!<@brief LPUART0 Receive Data Source Select: LPUART_RX pin */

/*! @name PORTB1 (number 13), PTB1/J1[4]/J5[4]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART_TX_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART_TX_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART_TX_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                     /* @} */

/*! @name PORTB2 (number 14), PTB2/J1[2]/J5[3]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART_RX_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART_RX_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART_RX_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                     /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSCPins(void);

/*! @name PORTB5 (number 19), PTB5/J1[14]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW3_FGPIO FGPIOB             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW3_GPIO GPIOB               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW3_GPIO_PIN_MASK (1U << 5U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW3_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW3_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_SW3_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*! @name PORTB0 (number 12), PTB0/J2[12]/J6[4]/J7[7]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW2_FGPIO FGPIOB             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW2_GPIO GPIOB               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW2_GPIO_PIN_MASK (1U << 0U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW2_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW2_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_SW2_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONSPins(void);

/*! @name PORTA8 (number 15), PTA8/J4[4]/J6[1]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_THER_A_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_THER_A_PIN 8U                   /*!<@brief PORT pin number */
#define BOARD_THER_A_PIN_MASK (1U << 8U)      /*!<@brief PORT pin mask */
                                              /* @} */

/*! @name PORTA9 (number 16), PTA9/J4[2]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_THER_B_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_THER_B_PIN 9U                   /*!<@brief PORT pin number */
#define BOARD_THER_B_PIN_MASK (1U << 9U)      /*!<@brief PORT pin mask */
                                              /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTHERMISTORPins(void);

/*! @name PORTB3 (number 17), PTB3/J2[20]/J5[5]/J7[6]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_ACCEL_I2C_SCL_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_ACCEL_I2C_SCL_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_ACCEL_I2C_SCL_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                                     /* @} */

/*! @name PORTB4 (number 18), PTB4/J2[18]/J5[6]/J7[8]
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_ACCEL_I2C_SDA_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_ACCEL_I2C_SDA_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_ACCEL_I2C_SDA_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                                     /* @} */

/*! @name PORTA12 (number 20), PTA12/J4[6]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_ACCEL_INT_FGPIO FGPIOA              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_ACCEL_INT_GPIO GPIOA                /*!<@brief GPIO peripheral base pointer */
#define BOARD_ACCEL_INT_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_ACCEL_INT_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_ACCEL_INT_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_ACCEL_INT_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
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
