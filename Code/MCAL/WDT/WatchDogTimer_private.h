#ifndef WATCH_DOG_PRIVATE_H
#define WATCH_DOG_PRIVATE_H

#include "../../STD_LIBRARIES/STD_TYPES.h"


#define		WDT_SYS_CONTROL_BASE_ADDRESS				0x400FE000
#define		WDT_RCGCWD													0x600
#define		WDT_R0													0
#define		WDT_R1													1

#define		WDT_WDT0_BASE_ADDRESS				0x40000000
#define		WDT_WDT1_BASE_ADDRESS				0x40001000

#define		WDTLOAD											0x000
#define		WDTVALUE										0x004

#define		WDTCTL											0x008
#define		WDT_INTEN_INDEX							0
#define		WDT_RESEN_INDEX							1
#define		WDT_INTTYPE_INDEX						2
#define		WDT_WRC_INDEX								31

#define		WDTICR											0x00C

#define		WDTRIS											0x010
#define		WDT_WDTRIS_INDEX						0


#define		WDTMIS											0x014
#define		WDT_WDTMIS_INDEX						0

#define  	WDTTEST											0x418
#define		WDT_STALL_INDEX							8

#define  	WDTLOCK											0xC00
#define  	WDTPeriphID4								0xFD0
#define  	WDTPeriphID5								0xFD4
#define  	WDTPeriphID6								0xFD8
#define  	WDTPeriphID7								0xFDC
#define  	WDTPeriphID0								0xFE0
#define  	WDTPeriphID1								0xFE4
#define  	WDTPeriphID2								0xFE8
#define  	WDTPeriphID3								0xFEC
#define  	WDTPCellID0									0xFF0
#define  	WDTPCellID1									0xFF4
#define  	WDTPCellID2									0xFF8
#define  	WDTPCellID3									0xFFC
/*
typedef struct{
    volatile uint32_t GPIOx_MODER;
    volatile uint32_t GPIOx_OTYPER;
    volatile uint32_t GPIOx_OSPEEDER;
    volatile uint32_t GPIOx_PUPDR;
    volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_LCKR;
    volatile uint32_t GPIOx_AFRL;
    volatile uint32_t GPIOx_AFRH;
}dio_str_gpiox_register_t;*/
#endif