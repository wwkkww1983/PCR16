#ifndef __BSP_W25QXX_H__
#define __BSP_W25QXX_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "spi.h"
#include "stm32l4xx_hal.h"  
/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup W25Q64FV
  * @{
  */

/** @defgroup W25Q64FV_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup W25Q64FV_Exported_Constants
  * @{
  */

/**
  * @brief  W25Q64FV Configuration
  */
//#define W25Q64FV_FLASH_SIZE                  0x800000 /* 64 MBits => 8MBytes = 8*1024*1024 */
//#define W25Q64FV_SECTOR_SIZE                 0x10000   /*128  sectors of 64KBytes */
//#define W25Q64FV_SUBSECTOR_SIZE              0x1000    /* 2048 subsectors of 4kBytes */
//#define W25Q64FV_PAGE_SIZE                   0x100     /* 32,768 pages of 256 bytes */
//使用W25Q128芯片
#define W25Q64FV_FLASH_SIZE                  0x1000000 /* 128 MBits => 16MBytes = 16*1024*1024 */
#define W25Q64FV_SECTOR_SIZE                 0x10000   /*16  sectors of 64KBytes */
#define W25Q64FV_SUBSECTOR_SIZE              0x1000    /* 256 subsectors of 4kBytes */
#define W25Q64FV_PAGE_SIZE                   0x100     /* 32,768 pages of 256 bytes */

#define W25Q64FV_DUMMY_CYCLES_READ           4
#define W25Q64FV_DUMMY_CYCLES_READ_QUAD      10

#define W25Q64FV_BULK_ERASE_MAX_TIME         250000
#define W25Q64FV_SECTOR_ERASE_MAX_TIME       300
#define W25Q64FV_SUBSECTOR_ERASE_MAX_TIME    800
#define W25Qx_TIMEOUT_VALUE 100
#define W25QXX_MANUFACTURER_ID			0XEF
#define W25Q64_DEVICE_ID		0X13
#define W25Q128_DEVICE_ID		0X17
/**
  * @brief  W25Q64FV Commands
  */
/* Reset Operations */
#define RESET_ENABLE_CMD                     0x66
#define RESET_MEMORY_CMD                     0x99

#define ENTER_QPI_MODE_CMD                   0x38
#define EXIT_QPI_MODE_CMD                    0xFF

/* Identification Operations */
#define READ_ID_CMD                          0x90
#define DUAL_READ_ID_CMD                     0x92
#define QUAD_READ_ID_CMD                     0x94
#define READ_JEDEC_ID_CMD                    0x9F

/* Read Operations */
#define READ_CMD                             0x03
#define FAST_READ_CMD                        0x0B
#define DUAL_OUT_FAST_READ_CMD               0x3B
#define DUAL_INOUT_FAST_READ_CMD             0xBB
#define QUAD_OUT_FAST_READ_CMD               0x6B
#define QUAD_INOUT_FAST_READ_CMD             0xEB

/* Write Operations */
#define WRITE_ENABLE_CMD                     0x06
#define WRITE_DISABLE_CMD                    0x04

/* Register Operations */
#define READ_STATUS_REG1_CMD                  0x05
#define READ_STATUS_REG2_CMD                  0x35
#define READ_STATUS_REG3_CMD                  0x15

#define WRITE_STATUS_REG1_CMD                 0x01
#define WRITE_STATUS_REG2_CMD                 0x31
#define WRITE_STATUS_REG3_CMD                 0x11


/* Program Operations */
#define PAGE_PROG_CMD                        0x02
#define QUAD_INPUT_PAGE_PROG_CMD             0x32


/* Erase Operations */
#define SECTOR_ERASE_CMD                     0x20
#define CHIP_ERASE_CMD                       0xC7

#define PROG_ERASE_RESUME_CMD                0x7A
#define PROG_ERASE_SUSPEND_CMD               0x75


/* Flag Status Register */
#define W25Q64FV_FSR_BUSY                    ((uint8_t)0x01)    /*!< busy */
#define W25Q64FV_FSR_WREN                    ((uint8_t)0x02)    /*!< write enable */
#define W25Q64FV_FSR_QE                      ((uint8_t)0x02)    /*!< quad enable */


#define W25Qx_Enable() 			HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET)
#define W25Qx_Disable() 		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET)

#define W25Qx_OK            ((uint8_t)0x00)
#define W25Qx_ERROR         ((uint8_t)0x01)
#define W25Qx_BUSY          ((uint8_t)0x02)
#define W25Qx_TIMEOUT				((uint8_t)0x03)

struct EPRROM
{
    uint8_t wData[100];
    uint8_t rData[100];
};
extern struct EPRROM  eprrom;  //控制器结构体申明

uint8_t BSP_W25Qx_Init(void);
void	BSP_W25Qx_Reset(void);
uint8_t BSP_W25Qx_GetStatus(void);
uint8_t BSP_W25Qx_WriteEnable(void);
void BSP_W25Qx_Read_ID(uint8_t *ID);
uint8_t BSP_W25Qx_Read(uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
uint8_t BSP_W25Qx_Write(uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
uint8_t BSP_W25Qx_Erase_Sector(uint32_t Address);
uint8_t BSP_W25Qx_Erase_Chip(void);

/**
  * @}
  */

/** @defgroup W25Q64FV_Exported_Functions
  * @{
  */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __W25Qx_H */

