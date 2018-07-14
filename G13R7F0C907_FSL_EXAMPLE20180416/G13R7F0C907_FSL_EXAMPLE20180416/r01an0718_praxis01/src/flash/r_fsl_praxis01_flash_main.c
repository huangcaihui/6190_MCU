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
* File Name     : r_fsl_praxis01_flash_main.c
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


/*---------------------------------------------------------------------------*/
/* Include common files                                                      */
/*---------------------------------------------------------------------------*/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_fsl_praxis01_FlashSection.h"
#include "r_fsl_praxis01_BranchTable.h"

#include "r_cg_macrodriver.h"
#include "r_fsl_praxis01_com.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_intc.h"
#include "r_cg_serial.h"
#include "r_cg_timer.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"



/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
unsigned char tx_2_data[TX2_BUFFER_LENTH];
unsigned char rx_2_data[RX2_BUFFER_LENTH];
unsigned char tx_1_data[TX1_BUFFER_LENTH];
unsigned char rx_1_data[RX1_BUFFER_LENTH];
unsigned char tx_0_data[TX1_BUFFER_LENTH];
unsigned char rx_0_data[RX1_BUFFER_LENTH];
boolean Uart2IsSending ;//= TRUE;

void delay1ms(void);
/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);
extern void R_Systeminit(void);

/*---------------------------------------------------------------------------*/
/* Parameters                                                                */
/*---------------------------------------------------------------------------*/
#define PR_LED_DEFAULT_WAIT     0x0000FFFFl
#define PR_LED_WAIT_MAG         3l


/*---------------------------------------------------------------------------*/
/* Parameters                                                                */
/*---------------------------------------------------------------------------*/
UW  prDuwLedTime = PR_LED_DEFAULT_WAIT;         /*                */
UH  prDuhSwNum   = 0;                           /* */
extern volatile uint16_t  g_uart0_rx_count;            /* uart0 receive data number */
extern volatile uint16_t  g_uart0_rx_length;  
extern volatile uint16_t  g_uart0_tx_count; 
extern boolean updata_comflag;
/*---------------------------------------------------------------------------*/
/* prototypes                                                                */
/*---------------------------------------------------------------------------*/
extern void Reset_Force(void);
extern void  R_FDL_ExecuteErase(void);
extern void  R_FDL_Write_E2Prom(void);

/*---------------------------------------------------------------------------*/
/* main functions                                                            */
/*---------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prBootTargetStart(void)
* Function Name     : main
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : start-up routine(flash project)
******************************************************************************/
void main( void )
{
    UB dubLed2flag;
    UW duw_i;
    UB u8RetuenList[5] = {0x53, 0x00, 0x81, 0x01, 0xD7};
                            
    DI();
    R_Systeminit();
    dubLed2flag  = true;
    R_MAIN_UserInit();
    //R_UART0_Start();
    P1.5 = 0;
    P2.1 = 1;
    P2.2 = 0;
    P3.0 = 0;
    P3.1 = 0;
    P6.2 = 0;
    P14.7 = 1;
    R_UART1_Receive(rx_0_data,RX0_BUFFER_LENTH);
    R_UART1_Receive(rx_1_data,RX1_BUFFER_LENTH);
    R_UART2_Receive(rx_2_data,RX2_BUFFER_LENTH);
    //PR_LED1_ON();
    g_uart0_rx_count = 0;
    g_uart0_rx_length = 11;
    updata_comflag = 0;
   
    /* Main loop */
    while(1)
    {
        /* LED turn-on processing */
	R_WDT_Restart();
        if( dubLed2flag == false )
        {
            dubLed2flag = true;
//            PR_LED2_ON();
		//PR_LED1_OFF();	
        }
        else {
            dubLed2flag = false;
  //          PR_LED2_OFF();
			//PR_LED1_ON();
        }
        #if 0
        for( duw_i = 0 ; duw_i < prDuwLedTime ; duw_i++ )
        {
            prWait10clcok();
        }
        #endif

        
	if(updata_comflag)
	{
		R_FDL_ExecuteErase();
        R_FDL_Write_E2Prom();
		Reset_Force();
	}
    }
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    Uart2IsSending = FALSE;
    R_UART0_Start();
    R_UART1_Start();
    R_UART2_Start();
    R_INTC1_Start();
    R_INTC2_Start();
    R_TAU0_Channel0_Start();//chg by huangcaihui 180417
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void delay1ms(void)
{
    unsigned char i,j;
    for(i=0;i<=100;i++)
        for(j=0;j<=72;j++)
    	{       
    	   NOP();
	   NOP();
    	}	
}
/* End user code. Do not edit comment generated here */
