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
* File Name     : r_fsl_praxis01_boot_main.c
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
/* (#pragma) Expanded functions                                              */
/*---------------------------------------------------------------------------*/
#pragma sfr                             /*  */
#pragma DI                              /*  */
#pragma EI                              /*  */
#pragma NOP                             /*  */


/*---------------------------------------------------------------------------*/
/* (#pragma) interrupt function                                              */
/*---------------------------------------------------------------------------*/
/*  */
#pragma interrupt INTWDTI prIntComWdt               /*  */
#pragma interrupt INTP0   prIntComSwIntp0           /*  */


/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
/*    */
#include "r_fsl_praxis01_BranchTable.h"

/*    */
#include "r_fsl_praxis01_BootSection.h"

/*    */
#include "r_fsl_praxis01_com.h"

/*    */
#include <string.h>
#include "r_cg_cgc.h"
#include "pfdl.h"
#include "pfdl_types.h"
#include "r_pfdl.h"

/*---------------------------------------------------------------------------*/
/* Parameter                                                                 */
/*---------------------------------------------------------------------------*/
/*  */
UB prDubBootMode = PR_BOOT_MODE_UNKNOWN;        /*   */
extern uint8_t  g_write_value[WRITE_SIZE];
extern uint16_t g_write_address;
extern uint8_t  g_read_value[WRITE_SIZE];
boolean updata_finsh;
/*---------------------------------------------------------------------------*/
/* Prototypes                                                                */
/*---------------------------------------------------------------------------*/
/*  */
void prBootTargetStart( void );                 /*   */
void prBootTargetEnd  ( UB   );                 /*   */
void UserApp_Main(void);
void Delay(void);
/*############################################################################*/
/******************************************************************************
* Outline           : hdwinit
* Include           : none
* Declaration       : void hdwinit(void)
* Function Name     : main
* Description       : Main function and set some SFR registers.
* Argument          : none
* Return Value      : none
* Calling Functions : start-up routine( boot project )
******************************************************************************/
void hdwinit( void )
{
	
    CMC = _00_CGC_HISYS_PORT | _00_CGC_SYSOSC_DEFAULT;
    MSTOP = 1U;
    /* Set fMAIN */
    MCM0 = 0U;
    OSMC = 0x00U;
    /* Set fIH */
    HIOSTOP = 0U;
    /******************************/
    /* UART                       */
    /******************************/
    PR_UART_PORT_INIT();
    
    /*****************/
    /* LED           */
    /*****************/
//    PR_LED_INIT();
    
    /****************/
    /* SW           */
    /****************/
    PR_SW_INIT();
    
    /*****************/
    /* A/D           */
    /*****************/
    PR_AD_INIT();
    
    /************************************/
    /* WDT                              */
    /************************************/
    PR_WD_INT_ON();
}


/*----------------------------------------------------------------------------*/
/* functions                                                                  */
/*----------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : boot_main
* Include           : none
* Declaration       : void boot_main(void)
* Function Name     : boot_main
* Description       : none
* Argument          : none
* Return Value      : none
* Calling Functions : start-up routine( boot project )
******************************************************************************/
void boot_main(void)
{
	unsigned char buf[]={0x31,0x32,0x33,0x34};
	
    g_write_address = TARGET_BLOCK * BLOCK_SIZE;
    g_read_value[0] = 0xff;
    g_read_value[1] = 0xff;
    g_read_value[2] = 0xff;
    g_read_value[3] = 0xff;
    g_read_value[4] = 0xff;
    R_FDL_ExecuteRead(); 
    
    if ((g_read_value[0] == 0x11)&&(g_read_value[1] == 0x22)&&(g_read_value[2] == 0x44)&&(g_read_value[3] == 0x66)&&(g_read_value[4] == 0x88))
    {
	UB dubRetCode;
	updata_finsh = 1;
	prBootTargetStart();              
        
	dubRetCode = prBootWriteProgram();
        
	prBootTargetEnd( dubRetCode );     
    }
}

/******************************************************************************
* Outline           : prBootTargetStart
* Include           : none
* Declaration       : void prBootTargetStart(void)
* Function Name     : prBootTargetStart
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : boot_main
******************************************************************************/
void prBootTargetStart( void )
{
    /*****************/
    /* LED           */
    /*****************/
//    PR_LED2_ON();
    
    /**************/
    /*            */
    /**************/
    prDubBootMode = PR_BOOT_MODE_WRITE;
    
    /************************/
    /*                      */
    /************************/
    EI();
}



void Delay(void)
{
	unsigned int duw_i;
	for( duw_i = 0 ; duw_i < 1000 ; duw_i++ )
        {
            prWait10clcok();
        }
}
/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prBootTargetEnd(void)
* Function Name     : prBootTargetEnd
* Description       : 
*                     
* Argument          : none
* Return Value      : none
* Calling Functions : boot_main
******************************************************************************/
void prBootTargetEnd( UB dubEndMode )
{
    UH  duh_i;
    UB  dubLed1flag = false;
    
    /*  */
    if( dubEndMode == false )
    {
        while( 1 )
        {
            if( dubLed1flag == false )
            {
                dubLed1flag = true;
                PR_LED1_ON();
            }
            else {
                dubLed1flag = false;
                PR_LED1_OFF();
            }
            
            for( duh_i = 0 ; duh_i < 65000 ; duh_i++ )
            {
                prWait10clcok();
            }
        }
    }
    /*  */
    else {
        PR_LED1_ON();
        
        while( 1 )
        {
            NOP();
            NOP();
        }
    }
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prWait10clcok(void)
* Function Name     : prWait10clcok
* Description       : none
* Argument          : none
* Return Value      : none
* Calling Functions : prBootTargetEnd, main( flash project )
******************************************************************************/
void prWait10clcok( void )
{
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
}

/*----------------------------------------------------------------------------*/
/* Common interrupt functions                                                 */
/*----------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : WDT
* Include           : none
* Declaration       : void prIntComWdt(void)
* Function Name     : prIntComWdt
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : vector table
******************************************************************************/
void prIntComWdt( void )
{
    WDTE = 0xAC;                    /*  */
}


/******************************************************************************
* Outline           : SW1
* Include           : none
* Declaration       : void prIntComSwIntp0(void)
* Function Name     : prIntComSwIntp0
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : vector table
******************************************************************************/
void prIntComSwIntp0( void )
{
    if( prDubBootMode == PR_BOOT_MODE_USER )
    {
        prSendMsgAsciiData();
    }
}

