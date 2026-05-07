
#ifndef __DISPLAY_DRIVER_H
#define __DISPLAY_DRIVER_H

#include "stm32c0xx_hal.h"
#include "stm32c0xx_nucleo.h"
#include "stm32c0xx_hal_i2c.h"

#define D_I2C_ADDR 0x3D

#define DD_CONT_CTRL 0x81
#define DD_ON_RAM 0xA4
#define DD_ON_NORAM 0xA5
#define DD_INV_OFF 0xA6
#define DD_INV_ON 0xA7
#define DD_DISP_OFF 0xAE
#define DD_DISP_ON 0xAF

#define DD_R_H_SCRL 0x26
#define DD_L_H_SCRL 0x27
#define DD_STOP_SCRL 0x2E
#define DD_START_SCRL 0X2F

#define DD_MEM_ADDR_MODE 0x20
#define DD_MEM_ADDR_HOR 0x00
#define DD_MEM_ADDR_VER 0x01
#define DD_MEM_ADDR_PAGE 0x10
#define DD_SET_COL_ADDR 0x21

#define DD_SET_PAGE_ADDR 0x22

#define DD_SET_SEG_MAP0 0xA0
#define DD_SET_SEG_MAP127 0xA1
#define DD_MUX_RATIO 0xA8
#define DD_SCAN_DIR_NOR 0xC0
#define DD_SCAN_DIR_REMAP 0xC8
#define DD_DISP_OFFSET 0xD3
#define DD_COM_PINS 0xDA

#define DD_DISP_CLK 0xD5
#define DD_PRE_CHARGE 0xD9
#define DD_VD_LVL 0xDB
#define DD_VD_065 0x00
#define DD_VD_077 0x20
#define DD_VD_083 0x30

//TODO: CHOOSE IO PINS
// DC Pin is SA0 for I2C
#define DD_DC_COM 0x00
#define DD_DC_DATA 0x01
#define DD_RW_WRITE 0x00
#define DD_RW_READ 0x01

/*
 *  GND goes to ground (black wire on STEMMA QT version)
Vin goes to 5V (red wire on STEMMA QT version)
Data to I2C SDA (on the Uno, this is A4 on the Mega it is 20 and on the Leonardo digital 2) (blue wire on STEMMA QT version)
Clk to I2C SCL (on the Uno, this is A5 on the Mega it is 21 and on the Leonardo digital 3) (yellow wire on STEMMA QT version)
RST to digital 4 (you can change this pin in the code, later) (Not necessary on 0.96" STEMMA QT version)
 */


 void dd_displayInit(void);
 void dd_resetDisplay(I2C_HandleTypeDef *I2cHandle);
 void dd_i2c_start(I2C_HandleTypeDef *I2cHandle);
 void dd_i2c_stop(I2C_HandleTypeDef *I2cHandle);
 void dd_i2c_send_byte(I2C_HandleTypeDef *I2cHandle, uint8_t byte);
 void dd_show(I2C_HandleTypeDef *I2cHandle, uint8_t framebuffer, size_t count);


#endif
