/*
	Copyright 2018 Benjamin Vedder	benjamin@vedder.se
	This file is part of the VESC firmware.
	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
	
#ifndef HW_MY75100
#define HW_MY75100

// CL: updated
#define HW_NAME					"My_75100"

// HW properties
#define HW_HAS_3_SHUNTS
//#define HW_HAS_PHASE_SHUNTS
//#define INVERTED_SHUNT_POLARITY

// Macros  
#define LED_GREEN_GPIO			GPIOB
#define LED_GREEN_PIN			5
#define LED_RED_GPIO			GPIOB
#define LED_RED_PIN				7

#define LED_GREEN_ON()			palSetPad(LED_GREEN_GPIO, LED_GREEN_PIN)
#define LED_GREEN_OFF()			palClearPad(LED_GREEN_GPIO, LED_GREEN_PIN)
#define LED_RED_ON()			palSetPad(LED_RED_GPIO, LED_RED_PIN)
#define LED_RED_OFF()			palClearPad(LED_RED_GPIO, LED_RED_PIN)

// CL: as in MKS 75_100 V2
/*
// Shutdown pin
#define HW_SHUTDOWN_GPIO		GPIOC
#define HW_SHUTDOWN_PIN			5
#define HW_SHUTDOWN_HOLD_ON()   palSetPad(HW_SHUTDOWN_GPIO, HW_SHUTDOWN_PIN)
#define HW_SHUTDOWN_HOLD_OFF()  palClearPad(HW_SHUTDOWN_GPIO, HW_SHUTDOWN_PIN)
#define HW_SAMPLE_SHUTDOWN()    hw_sample_shutdown_button()
// Hold shutdown pin early to wake up on short pulses
#define HW_EARLY_INIT()			palSetPadMode(HW_SHUTDOWN_GPIO, HW_SHUTDOWN_PIN, PAL_MODE_OUTPUT_PUSHPULL); \
					            HW_SHUTDOWN_HOLD_ON();
*/


//#define HW_HAS_PHASE_FILTERS
//#define PHASE_FILTER_GPIO		GPIOC
//#define PHASE_FILTER_PIN		9
//#define PHASE_FILTER_ON()		palSetPad(PHASE_FILTER_GPIO, PHASE_FILTER_PIN)
//#define PHASE_FILTER_OFF()	palClearPad(PHASE_FILTER_GPIO, PHASE_FILTER_PIN)

// Suggested defaults
#undef MCCONF_FOC_PHASE_FILTER_ENABLE
//#ifndef MCCONF_FOC_PHASE_FILTER_ENABLE
#define MCCONF_FOC_PHASE_FILTER_ENABLE  false // phase voltage filters
//#endif


//disabled as current filtering can't be done with low side measurement 
//#define CURRENT_FILTER_GPIO		    GPIOD
//#define CURRENT_FILTER_ON()		palSetPad(CURRENT_FILTER_GPIO, 2)
//#define CURRENT_FILTER_OFF()	palClearPad(CURRENT_FILTER_GPIO, 2)

// AUX Pin
//#define AUX_GPIO				GPIOC
//#define AUX_PIN					12
//#define AUX_ON()				palSetPad(AUX_GPIO, AUX_PIN)
//#define AUX_OFF()				palClearPad(AUX_GPIO, AUX_PIN)

/*
 * ADC Vector
 *
 * 0  (1):	IN10	CURR1		ADC1_1		PIN_8
 * 1  (2):	IN11	CURR2		ADC2_1		PIN_9
 * 2  (3):	IN12	CURR3		ADC3_1		PIN_10
 * 3  (1):	IN0		SENS1		ADC1_2		PIN_14
 * 4  (2):	IN1		SENS2		ADC2_2		PIN_15
 * 5  (3):	IN2		SENS3		ADC3_2		PIN_16
 * 6  (1):	IN5		ADC_EXT1	ADC1_3		PIN_21(ADC 1 2)
 * 7  (2):	IN6		ADC_EXT2	ADC2_3		PIN_22(ADC 1 2)
 * 8  (3):	IN13	AN_IN(Vsens)ADC3_3		PIN_11
 * 9  (1):	Vrefint				ADC1_4
 * 10 (2):	IN14	TEMP_MOTOR	ADC2_4		PIN_24(ADC 1 2)
 * 11 (3):	IN3		TEMP_MOS	ADC3_4		PIN_17
 * 
 * 10 (2):	IN15	SHUTDOWN	ADC1_2		PIN_25(ADC 1 2)
 * 13 (2):	IN4					ADC3_4		PIN_20(ADC 1 2)
 * 14 (3):	IN7					ADC1_4		PIN_23(ADC 1 2)
 * 15 (1):  IN8		TEMP_MOS_2	ADC2_4		PIN_26(ADC 1 2)
 * 16 (2):  IN9		TEMP_MOS_3				PIN_27(ADC 1 2)
 * 17 (3):
 */


#define HW_ADC_INJ_CHANNELS		3
#define HW_ADC_NBR_CONV			4
#define HW_ADC_CHANNELS			(HW_ADC_NBR_CONV * 3)

// ADC Indexes
#define ADC_IND_SENS1			0
#define ADC_IND_SENS2			1
#define ADC_IND_SENS3			2
#define ADC_IND_CURR1			3
#define ADC_IND_CURR2			4
#define ADC_IND_CURR3			5
#define ADC_IND_EXT				6
#define ADC_IND_EXT2			7
#define ADC_IND_VIN_SENS		8
#define ADC_IND_VREFINT			9
#define ADC_IND_TEMP_MOTOR		10
#define ADC_IND_TEMP_MOS		11
//#define ADC_IND_TEMP_MOS_2		15
//#define ADC_IND_TEMP_MOS_3		16
// CL: as in MKS 75_100 V2
//#define ADC_IND_SHUTDOWN		10

/* 
#define HW_ADC_CHANNELS			18
#define HW_ADC_INJ_CHANNELS		3
#define HW_ADC_NBR_CONV			6

// ADC Indexes
#define ADC_IND_SENS1			0
#define ADC_IND_SENS2			1
#define ADC_IND_SENS3			2
#define ADC_IND_CURR1			3
#define ADC_IND_CURR2			4
#define ADC_IND_CURR3			5
#define ADC_IND_EXT				6
#define ADC_IND_EXT2			7
#define ADC_IND_TEMP_MOS		8
#define ADC_IND_TEMP_MOTOR		9
#define ADC_IND_EXT3			10
#define ADC_IND_VIN_SENS		11
#define ADC_IND_VREFINT			12
//#define ADC_IND_TEMP_MOS_2		15
//#define ADC_IND_TEMP_MOS_3		16
*/

// ADC macros and settings

// Component parameters (can be overridden)
#ifndef V_REG
#define V_REG					3.338 // MK use 3.34
#endif
#ifndef VIN_R1
#define VIN_R1					56000.0 //
#endif
#ifndef VIN_R2
#define VIN_R2					2200.0 //
#endif
#ifndef CURRENT_AMP_GAIN
#define CURRENT_AMP_GAIN		20.0 //
#endif
#ifndef CURRENT_SHUNT_RES
#define CURRENT_SHUNT_RES		0.0005 //(0.0005 / 3.0)
#endif

// Input voltage
#define GET_INPUT_VOLTAGE()		((V_REG / 4095.0) * (float)ADC_Value[ADC_IND_VIN_SENS] * ((VIN_R1 + VIN_R2) / VIN_R2))

// NTC Termistors
#define NTC_RES(adc_val)		((4095.0 * 10000.0) / adc_val - 10000.0)

// (jaykup) 273 is C to K conversion
#define NTC_TEMP(adc_ind)		(1.0 / ((logf(NTC_RES(ADC_Value[adc_ind]) / 10000.0) / 3380.0) + (1.0 / 298.15)) - 273.15) 

#define NTC_RES_MOTOR(adc_val)	(10000.0 / ((4095.0 / (float)adc_val) - 1.0)) // Motor temp sensor on low side
#define NTC_TEMP_MOTOR(beta)	(1.0 / ((logf(NTC_RES_MOTOR(ADC_Value[ADC_IND_TEMP_MOTOR]) / 10000.0) / beta) + (1.0 / 298.15)) - 273.15)

// Voltage on ADC channel
#define ADC_VOLTS(ch)			((float)ADC_Value[ch] / 4096.0 * V_REG)

// Double samples in beginning and end for positive current measurement.
// Useful when the shunt sense traces have noise that causes offset.
// just used in BLDC mode
#ifndef CURR1_DOUBLE_SAMPLE
#define CURR1_DOUBLE_SAMPLE		0
#endif
#ifndef CURR2_DOUBLE_SAMPLE
#define CURR2_DOUBLE_SAMPLE		0
#endif
#ifndef CURR3_DOUBLE_SAMPLE
#define CURR3_DOUBLE_SAMPLE		0
#endif

// COMM-port ADC GPIOs
#define HW_ADC_EXT_GPIO			GPIOA
#define HW_ADC_EXT_PIN			5
#define HW_ADC_EXT2_GPIO		GPIOA
#define HW_ADC_EXT2_PIN			6

// UART Peripheral
#define HW_UART_DEV				SD3
#define HW_UART_GPIO_AF			GPIO_AF_USART3
#define HW_UART_TX_PORT			GPIOB
#define HW_UART_TX_PIN			10
#define HW_UART_RX_PORT			GPIOB
#define HW_UART_RX_PIN			11

// Permanent UART Peripheral - UART2 port (for NRF51)
#define HW_UART_P_BAUD			115200
#define HW_UART_P_DEV			SD4
#define HW_UART_P_GPIO_AF		GPIO_AF_UART4
#define HW_UART_P_TX_PORT		GPIOC
#define HW_UART_P_TX_PIN		10
#define HW_UART_P_RX_PORT		GPIOC
#define HW_UART_P_RX_PIN		11

// should be disabled as this unit has no bluetooth module to program
// NRF SWD
//#define NRF5x_SWDIO_GPIO		GPIOA
//#define NRF5x_SWDIO_PIN			15
//#define NRF5x_SWCLK_GPIO		GPIOB
//#define NRF5x_SWCLK_PIN			3

// ICU Peripheral for servo decoding
#define HW_USE_SERVO_TIM4
#define HW_ICU_TIMER			TIM4
#define HW_ICU_TIM_CLK_EN()		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE)
#define HW_ICU_DEV				ICUD4
#define HW_ICU_CHANNEL			ICU_CHANNEL_1
#define HW_ICU_GPIO_AF			GPIO_AF_TIM4
#define HW_ICU_GPIO				GPIOB
#define HW_ICU_PIN				6

// I2C Peripheral
#define HW_I2C_DEV				I2CD2
#define HW_I2C_GPIO_AF			GPIO_AF_I2C2
#define HW_I2C_SCL_PORT			GPIOB
#define HW_I2C_SCL_PIN			10
#define HW_I2C_SDA_PORT			GPIOB
#define HW_I2C_SDA_PIN			11

// Hall/encoder pins
#define HW_HALL_ENC_GPIO1		GPIOC
#define HW_HALL_ENC_PIN1		6
#define HW_HALL_ENC_GPIO2		GPIOC
#define HW_HALL_ENC_PIN2		7
#define HW_HALL_ENC_GPIO3		GPIOC
#define HW_HALL_ENC_PIN3		8
#define HW_ENC_TIM				TIM3
#define HW_ENC_TIM_AF			GPIO_AF_TIM3
#define HW_ENC_TIM_CLK_EN()		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE)
#define HW_ENC_EXTI_PORTSRC		EXTI_PortSourceGPIOC
#define HW_ENC_EXTI_PINSRC		EXTI_PinSource8
#define HW_ENC_EXTI_CH			EXTI9_5_IRQn
#define HW_ENC_EXTI_LINE		EXTI_Line8
#define HW_ENC_EXTI_ISR_VEC		EXTI9_5_IRQHandler
#define HW_ENC_TIM_ISR_CH		TIM3_IRQn
#define HW_ENC_TIM_ISR_VEC		TIM3_IRQHandler

// SPI pins
#define HW_SPI_DEV				SPID1
#define HW_SPI_GPIO_AF			GPIO_AF_SPI1
#define HW_SPI_PORT_NSS			GPIOA
#define HW_SPI_PIN_NSS			4
#define HW_SPI_PORT_SCK			GPIOA
#define HW_SPI_PIN_SCK			5
#define HW_SPI_PORT_MOSI		GPIOA
#define HW_SPI_PIN_MOSI			7
#define HW_SPI_PORT_MISO		GPIOA
#define HW_SPI_PIN_MISO			6

// BMI 160							   
//#define BMI160_SDA_GPIO			GPIOB
//#define BMI160_SDA_PIN			4
//#define BMI160_SCL_GPIO			GPIOB
//#define BMI160_SCL_PIN			12
//#define IMU_FLIP			
	  
// Measurement macros
#define ADC_V_L1				ADC_Value[ADC_IND_SENS1]
#define ADC_V_L2				ADC_Value[ADC_IND_SENS2]
#define ADC_V_L3				ADC_Value[ADC_IND_SENS3]
#define ADC_V_ZERO				(ADC_Value[ADC_IND_VIN_SENS] / 2)

// Macros
#define READ_HALL1()			palReadPad(HW_HALL_ENC_GPIO1, HW_HALL_ENC_PIN1)
#define READ_HALL2()			palReadPad(HW_HALL_ENC_GPIO2, HW_HALL_ENC_PIN2)
#define READ_HALL3()			palReadPad(HW_HALL_ENC_GPIO3, HW_HALL_ENC_PIN3)

// Override dead time. See the stm32f4 reference manual for calculating this value.
#define HW_DEAD_TIME_NSEC		        660.0

// Default setting overrides
#ifndef MCCONF_L_MIN_VOLTAGE
#define MCCONF_L_MIN_VOLTAGE			10.0	// Minimum input voltage
#endif
#ifndef MCCONF_L_MAX_VOLTAGE
#define MCCONF_L_MAX_VOLTAGE			90.0	// Maximum input voltage
#endif
#ifndef MCCONF_DEFAULT_MOTOR_TYPE
#define MCCONF_DEFAULT_MOTOR_TYPE		MOTOR_TYPE_FOC
#endif
#ifndef MCCONF_FOC_F_ZV
#define MCCONF_FOC_F_ZV					32000.0 //switching frequency in Hz
#endif
// FOC control loop frequency divider.
//#define FOC_CONTROL_LOOP_FREQ_DIVIDER	1 (ADC ISR calls)
#ifndef MCCONF_L_MAX_ABS_CURRENT
#define MCCONF_L_MAX_ABS_CURRENT		150.0	// The maximum absolute current above which a fault is generated
#endif
#ifndef MCCONF_FOC_SAMPLE_V0_V7
#define MCCONF_FOC_SAMPLE_V0_V7			false	// unit has 3 battery shunts so this needs to be off - Run control loop in both v0 and v7 (requires phase shunts)
#endif
#ifndef MCCONF_L_IN_CURRENT_MAX
#define MCCONF_L_IN_CURRENT_MAX			60.0	// Input current limit in Amperes (Upper)
#endif
#ifndef MCCONF_L_IN_CURRENT_MIN
#define MCCONF_L_IN_CURRENT_MIN			-60.0	// Input current limit in Amperes (Lower)
#endif
#ifndef MCCONF_L_RPM_MAX
#define MCCONF_L_RPM_MAX				150000.0	// The motor speed limit (Upper)
#endif
#ifndef MCCONF_L_RPM_MIN
#define MCCONF_L_RPM_MIN				-150000.0	// The motor speed limit (Lower)
#endif
#ifndef MCCONF_SI_BATTERY_CELLS
#define MCCONF_SI_BATTERY_CELLS			12 // Battery Cells
#endif
#ifndef MCCONF_SI_BATTERY_AH
#define MCCONF_SI_BATTERY_AH			10.0 // Battery amp hours
#endif

// Setting limits
#define HW_LIM_CURRENT			-80.0, 80.0 // phase amps
#define HW_LIM_CURRENT_IN		-75.0, 75.0 // battery amps
#define HW_LIM_CURRENT_ABS		0.0, 175 // abs phase amps
#define HW_LIM_VIN				6.0, 100.0
#define HW_LIM_ERPM				-150e3, 150e3
#define HW_LIM_DUTY_MIN			0.0, 0.1
#define HW_LIM_DUTY_MAX			0.0, 0.99
#define HW_LIM_TEMP_FET			-40.0, 90.0

#endif /* HW_MY75100 */