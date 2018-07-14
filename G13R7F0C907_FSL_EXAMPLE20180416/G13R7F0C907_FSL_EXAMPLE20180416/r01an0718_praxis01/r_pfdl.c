/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2010, 2011 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_pfdl.c
* Version      : CodeGenerator for RL78/G13 V1.03.01 [11 Oct 2011]
* Device(s)    : R5F100LE
* Tool-Chain   : CA78K0R
* Description  : This file implements main function.
* Creation Date: 2012/07/11
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_macrodriver.h"
#include "pfdl.h"
#include "pfdl_types.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"
#include "r_pfdl.h"
/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t  g_write_value[WRITE_SIZE];
uint16_t g_write_address;
uint8_t  g_read_value[WRITE_SIZE];

/***********************************************************************************************************************
* Function Name: R_FDL_Init
* Description  : This function initializes RAM used by flash data library.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_FDL_Init(void)
{
    pfdl_descriptor_t descriptor;   
    /* ---- Setting for PFDL_Open ---- */
    descriptor.fx_MHz_u08            = FDL_FRQ;
    descriptor.wide_voltage_mode_u08 = FDL_VOL;
    PFDL_Open(&descriptor);                                                            /* Initialize RAM */
}


/***********************************************************************************************************************
* Function Name: R_FDL_Erase
* Description  : This function erases block data.
* Arguments    : None
* Return Value : PFDL_OK - 
                     Success erases data
                 PFDL_NG -
                     Failure erases data
***********************************************************************************************************************/
uint8_t R_FDL_Erase(void)
{
    pfdl_request_t requester;
    pfdl_status_t  ret;  
    /* ---- Setting for erase ---- */
    requester.command_enu = PFDL_CMD_ERASE_BLOCK;
    requester.index_u16   = TARGET_BLOCK;    
    ret                   = PFDL_Execute(&requester);                                  /* Erase block data */
    /* ---- Waiting for command finish ---- */
    while(ret == PFDL_BUSY)
    {
        ret = PFDL_Handler();                                                          /* Status check process */
    }
    return ret;
}


/***********************************************************************************************************************
* Function Name: R_FDL_Read
* Description  : This function read from flash data.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void  R_FDL_Read(void)
{
    pfdl_request_t requester;
    pfdl_status_t  ret;    
    /* ---- Setting for read ---- */
    requester.command_enu   = PFDL_CMD_READ_BYTES;
    requester.index_u16     = g_write_address;
    requester.bytecount_u16 = WRITE_SIZE;
    requester.data_pu08     = &g_read_value[0];    
    PFDL_Execute(&requester);  

}

/***********************************************************************************************************************
* Function Name: R_FDL_Write
* Description  : This function write to flash data.
* Arguments    : None
* Return Value : PFDL_OK - 
                     Success write data
                 PFDL_NG -
                     Failure write data
***********************************************************************************************************************/
uint8_t R_FDL_Write(void)
{
    pfdl_request_t requester;
    pfdl_status_t  ret;
    
    /* ---- Setting for write ---- */
    requester.command_enu   = PFDL_CMD_WRITE_BYTES;
    requester.index_u16     = g_write_address;
    requester.bytecount_u16 = WRITE_SIZE;
    requester.data_pu08     = &g_write_value[0];    
    ret                     = PFDL_Execute(&requester);                                /* Execute write */
    
    /* ---- Waiting for command finish ---- */
    while(ret == PFDL_BUSY)
    {
        ret = PFDL_Handler();                                                          /* Status check process */
	}

    return ret;
}



/***********************************************************************************************************************
* Function Name: R_FDL_ExecuteWrite
* Description  : This function execute series of write to flash data.
* Arguments    : None
* Return Value : PFDL_OK - 
                     Success write data
                 PFDL_NG -
                     Failure write data
***********************************************************************************************************************/
void R_FDL_ExecuteWrite(void)
{
	R_FDL_Init();    	
	R_FDL_Write(); 
	PFDL_Close();    
}

/***********************************************************************************************************************
* Function Name: R_FDL_ClearDataFlash
* Description  : This function clear data flash.
* Arguments    : None
* Return Value : PFDL_OK - 
                     Success clear data flash
                 PFDL_NG -
                     Failure clear data flash
***********************************************************************************************************************/
void  R_FDL_ExecuteErase(void)
{

    R_FDL_Init();                                                                      /* FDL initialization */
    R_FDL_Erase();                                                              /* Erase data of target block */
    PFDL_Close();                                                                      /* Close FDL */
}
    
void R_FDL_ExecuteRead(void)
{
	R_FDL_Init();
	R_FDL_Read();
	PFDL_Close();
}

void R_FDL_Write_E2Prom(void)
{
    g_write_address = TARGET_BLOCK * BLOCK_SIZE;
    g_write_value[0]   = 0x11;
    g_write_value[1]   = 0x22;
    g_write_value[2]   = 0x44;
    g_write_value[3]   = 0x66;
    g_write_value[4]   = 0x88;
    R_FDL_ExecuteWrite();
}
/* End user code. Do not edit comment generated here */