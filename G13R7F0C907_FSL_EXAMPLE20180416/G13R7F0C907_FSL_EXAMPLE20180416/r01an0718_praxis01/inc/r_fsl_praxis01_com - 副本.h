/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* 
* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : r_fsl_praxis01_com.h
* Version       : 1.00
* Device(s)     : RL78/G13( R5F100LEA )
* Tool-Chain    : CubeSuite+ ( V1.01 )
* OS            : none
* H/W Platform  : QB-R5F100LE-TB
* Description   : 
* Operation     : 
* Limitations   : FSL AN-sample.
******************************************************************************/
/******************************************************************************
* History       : Version Description
*               : 09.29.2011 1.00 First Release
******************************************************************************/

/******************************************************************************
Include <System Includes>, "Project Includes"
******************************************************************************/
/**************************/
/*                        */
/**************************/
/* C99 */
typedef   signed char        int8_t;        /* C99:   signed  8 */
typedef unsigned char       uint8_t;        /* C99: unsigned 32 */
typedef   signed short       int16_t;       /* C99:   signed  8 */
typedef unsigned short      uint16_t;       /* C99: unsigned 32 */
typedef   signed long        int32_t;       /* C99:   signed  8 */
typedef unsigned long       uint32_t;       /* C99: unsigned 32 */
typedef unsigned int         _Bool;         /* C99: bool        */

/* */
#define bool                 _Bool          /*  */

/*  */
#define  B                   int8_t         /*  */
#define UB                  uint8_t         /*  */
#define  H                   int16_t        /*  */
#define UH                  uint16_t        /*  */
#define  W                   int32_t        /*  */
#define UW                  uint32_t        /*  */
#define BOOL                 _Bool          /*  */

/*  */
#define false               0               /*  */
#define true                1               /*  */
#define FALSE               false           /*  */
#define TRUE                true            /*  */
#define OFF                 false           /*  */
#define ON                  true            /*  */
#define LOW                 0               /*  */
#define HIGH                1               /*  */

/**********************/
/*                    */
/**********************/
/*  */
#define PR_MAX_BLOCK_NUM            64      /*  */
#define PR_BLOCK_SIZE               0x400   /*  */
#define PR_WORD_SIZE                4       /*  */

/*  */
#define PR_SW_ON                    0       /*  */

/*  */
#define PR_BOOT_MODE_UNKNOWN        0       /*  */
#define PR_BOOT_MODE_WRITE          1       /*  */
#define PR_BOOT_MODE_USER           2       /*  */


/******************/
/*                */
/******************/
/*  */
#define PR_MSG_FRAME_SOH            0x01    /*  */
#define PR_MSG_FRAME_STX            0x02    /*  */
#define PR_MSG_FRAME_ETB            0x17    /*  */
#define PR_MSG_FRAME_ETX            0x03    /*  */

#define PR_MSG_DFRAME_LEN           5       /*  */
#define PR_MSG_DFRAME_COMD          3       /*  */
#define PR_MSG_DFRAME_DATA          4       /*  */

#define PR_MSG_PACKET_SIZE          0x100   /*  */
#define PR_WRITE_SIZE               ( PR_MSG_PACKET_SIZE / PR_WORD_SIZE )     
                                            /*  */

/*  */
#define PR_MSG_BLOCK_NUM            0       /*  */
#define PR_MSG_ADDR_HI              1       /*  */
#define PR_MSG_ADDR_MID             2       /*  */
#define PR_MSG_ADDR_LOW             3       /*  */
#define PR_MSG_SIZE_HI              4       /*  */
#define PR_MSG_SIZE_LOW             5       /*  */
#define PR_MSG_IVERIFY_BLOCK        0       /*  */
#define PR_MSG_ERASE_BLOCK          0       /*  */
#define PR_MSG_FSW_START_HI         0       /*  */
#define PR_MSG_FSW_START_LOW        1       /*  */
#define PR_MSG_FSW_END_HI           2       /*  */
#define PR_MSG_FSW_END_LOW          3       /*  */


/*  */
#define PR_MSG_COMM_ERASE           0x04    /*  */
#define PR_MSG_COMM_WRITE           0x05    /*  */
#define PR_MSG_COMM_DATA            0x06    /*  */
#define PR_MSG_COMM_RESET           0x07  //0x07  /* wyf  */
#define PR_MSG_COMM_BOOTSWAP        0x08  //0x08  /* wyf */
#define PR_MSG_COMM_IVERIFY         0x0B    /*  */
#define PR_MSG_COMM_FSW_SET         0x0C    /*  */
#define PR_MSG_COMM_WRITE_END       0xF0    /*  */


/*  */
#define PR_MSG_RET_NORM_END         0x00    /*  */
#define PR_MSG_RET_ERR_END          0x01    /*  */
#define PR_MSG_RET_PRM_ERR          0x05    /*  */
#define PR_MSG_RET_PROTECT_ERR      0x10    /*  */
#define PR_MSG_RET_ERASE_ERR        0x1A    /*  */
#define PR_MSG_RET_B_CHK_ERR        0x1B    /*  */
#define PR_MSG_RET_IVERIFY_ERR      0x1B    /*  */
#define PR_MSG_RET_WRITE_ERR        0x1C    /*  */
#define PR_MSG_RET_INT_ERR          0x1F    /*  */
#define PR_MSG_RET_READ_ERR         0x20    /*  */
#define PR_MSG_RET_CHKSUM_ERR       0xFF    /*  */


/******************************************************/
/*                                                    */
/******************************************************/
/* QB-R5F100LE-TB */
#if 1
#define __QB_R5F100LE_TB__                  /*  */
//#define PR_USE_OCD_MODE                 /* wyf*/

/*  */
#else 
#define __NON_TARGET__
#endif

/*  */
#ifdef PR_USE_OCD_MODE
    #define PR_OCD_MONITOR_BLOCK    0x1F    /*  */
    #define PR_OCD_MONITOR_ADDR     0x7C00  /*  */
#endif


/*----------------------------------------------------------------------------*/
/* QB-R5F100LE-TB                                                             */
/*----------------------------------------------------------------------------*/
#ifdef __QB_R5F100LE_TB__

/*  */
#define PR_TBLED1_INIT()    P6.2 = 1, PM6.2 = 0
                                        /*  */
#define PR_TBLED1_ON()      P6.2 = 0    /*  */
#define PR_TBLED1_OFF()     P6.2 = 1    /*  */

#define PR_TBLED2_INIT()    P6.3 = 1, PM6.3 = 0
                                        /*  */
#define PR_TBLED2_ON()      P6.3 = 0    /*  */
#define PR_TBLED2_OFF()     P6.3 = 1    /*  */

/*   */
#define PR_SW1_INTP0_INIT() EGP0.0 = 0, EGN0.0 = 1, PPR00  = 0, PPR10  = 1,\
                            PIF0   = 0, PMK0   = 0
                                        /*  */
#define PR_SW1_P137         P13.7       /*  */

/*  */
#define PR_UART0_INIT()     P1.1 = 0, PM1.1 = 1,PU1.1 = 1,\
                            P1.2 = 1, PM1.2 = 0
                                        /*  */
/************/
/*  */
/************/
#define PR_LED_INIT()       PR_TBLED1_INIT(), PR_TBLED2_INIT()
#define PR_SW_INIT()        PR_SW1_INTP0_INIT()
#define PR_AD_INIT()        
#define PR_UART_PORT_INIT() PR_UART0_INIT()

/******************************************************************************/
/* For r_fsl_praxis01_flash.hex                                               */
#define PR_LED1_ON()        PR_TBLED1_ON()
#define PR_LED1_OFF()       PR_TBLED1_OFF()
#define PR_LED2_ON()        PR_TBLED2_ON() 
#define PR_LED2_OFF()       PR_TBLED2_OFF()
/******************************************************************************/
/*For r_fsl_praxis01_write_test.hex                                           */
/*
#define PR_LED1_ON()        PR_TBLED2_ON()                
#define PR_LED1_OFF()       PR_TBLED2_OFF()                
#define PR_LED2_ON()        PR_TBLED1_ON()           
#define PR_LED2_OFF()       PR_TBLED1_OFF()
*/
/*******************************************************************************/
/*  */
#define PR_BOOT_SW          PR_SW1_P137 /*  */


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
#else

/************/
/*          */
/************/
#define PR_LED_INIT()
#define PR_SW_INIT()
#define PR_AD_INIT()
#define PR_UART_PORT_INIT()

#define PR_LED1_ON()
#define PR_LED1_OFF()
#define PR_LED2_ON()
#define PR_LED2_OFF()

/*  */
#define PR_BOOT_SW
#endif

/*  */
#define PR_WD_INT_ON()      WDTIMK = 0, WDTE = 0xAC
#define PR_WD_INT_OFF()     WDTIMK = 1, WDTE = 0xAC
                                    
/*----------------------------------------------------------------------------*/
/* common prototype declarations ( public function )                          */
/*----------------------------------------------------------------------------*/
/*  */
UB   prBootWriteProgram( void );    /*  */

/*  */
void prUartInit    ( void );        /*  */
void prUartEnd     ( void );        /*  */
UB   prUartRcvData ( void );        /*  */
void prUartSendData( UB * );        /*  */
UB   prUartRcvMsg  ( UB *, UB * );  /*  */
void prUartSendMsg ( UB  , UB   );  /*  */

/*  */
void prWait10clcok ( void );        /*  */

/*  */
void prSendMsgAsciiData( void );    /*  */

/*  */
extern UB prDubBootMode;

