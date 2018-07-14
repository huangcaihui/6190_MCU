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
* File Name     : r_fsl_praxis01_boot_write.c
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

/*----------------------------------------------------------------------------*/
/* (#pragma) Expanded functions                                               */
/*----------------------------------------------------------------------------*/
#pragma sfr                             /*  */
#pragma DI                              /*  */
#pragma EI                              /*  */
#pragma NOP                             /*  */


/*----------------------------------------------------------------------------*/
/* Include files                                                              */
/*----------------------------------------------------------------------------*/
/*  */
#include "r_fsl_praxis01_bootSection.h"

/*  */
#include "r_fsl_praxis01_com.h"

/*  */
#include <string.h>

/*  */
#include "fsl.h"                /*  */
#include "fsl_types.h"          /*  */

#include "pfdl.h"
#include "pfdl_types.h"
#include "r_pfdl.h"
/*----------------------------------------------------------------------------*/
/* Parameter                                                                  */
/*----------------------------------------------------------------------------*/
/*  */
static __far const fsl_descriptor_t fsl_descriptor_pstr = { 0x00, 0x10, 0x01 };

/*  */
static UB prDubWriteBuffer[ PR_MSG_PACKET_SIZE ];  /*  */
static UB prDubMsgBuffer  [ PR_MSG_PACKET_SIZE ];  /*  */

/*  */
static UB prDubLedBrinkFlag = FALSE;
extern uint8_t  g_write_value[WRITE_SIZE];
extern uint16_t g_write_address;
extern uint8_t  g_read_value[WRITE_SIZE];
extern boolean updata_finsh;
extern void R_SAU0_Create(void);

/*----------------------------------------------------------------------------*/
/* Prototype declarations                                                     */
/*----------------------------------------------------------------------------*/
/*  */
UB      prFslErrorCheck( fsl_u08 );         /*  */
fsl_u08 prFslStart ( void );                /*  */
void    prFslEnd   ( void );                /*  */
void    prLED1brink( UB   );                /*  */
void Reset_Force(void);
/*----------------------------------------------------------------------------*/
/* main functions                                                             */
/*----------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prBootWriteProgram(void)
* Function Name     : prBootWriteProgram
* Description       : 
* Argument          : none
* Return Value      : processing result
* Calling Functions : boot_main
******************************************************************************/
UB prBootWriteProgram( void )
{
    /*  */
    UH      duhSelfLoop = true;                 /*  */
    UB      dubMsgResult;                       /*  */
    UB      dubReturn;
    fsl_u08 dubSelfResult;                      /*  */
    
    /*  */
    UB      dubCommnad;                         /*  */
    
    /*  */
    UW          duwEndWriteAddress   = 0;       /*  */
    UW          duwWriteAdressIndex  = 0;       /*  */
    UW          duwWriteSize         = 0;       /*  */
    fsl_write_t dtyWriteBuff;                   /*  */
    
    /*  */
    dtyWriteBuff.fsl_data_buffer_p_u08 = prDubWriteBuffer;
    dtyWriteBuff.fsl_word_count_u08    = PR_WRITE_SIZE;
    
    /*  */
    dubSelfResult = prFslStart();
    
    if( dubSelfResult == FSL_OK )
    {
        /*-- Initialize UART1 ports for communication, 115200bps --*/
        prUartInit();
        
        /* When using memset on the RL78 assuming that flash area is located below 2000H, */
        /* it must be specified as a far standard function. Consequently, */
        /* memset_f needs to be used instead of memset. */
        memset_f( prDubWriteBuffer, 0x00, PR_MSG_PACKET_SIZE );
        
        /* Communication loop */
        while( duhSelfLoop == true )
        {
            /*-- Receive from SelfFlashWriter --*/
            do
            {   /* Receive Uart command message */
                dubMsgResult = prUartRcvMsg( &prDubMsgBuffer[0], &dubCommnad );
                
                if( dubMsgResult != PR_MSG_RET_NORM_END )
                {   /* Send error to SelfFlashWriter if an error is found in the command. */
                    prUartSendMsg( dubCommnad, dubMsgResult );
                }
            }
            while( dubMsgResult != PR_MSG_RET_NORM_END );
            
            /*-- Process according to the type of the command. --*/
            switch( dubCommnad )
            {
                /*-- WRITE Command --*/
                case PR_MSG_COMM_WRITE:
                {
                    UB  dub_i;
                    UB  dubStartEraseBlock;
                    UW  duwStartWriteAddress;
                    UB  dubBlockLength;
                    
                    /*-- Store received data (Block to program, address, size) from buffer. --*/
                    dubStartEraseBlock    = prDubMsgBuffer[ PR_MSG_BLOCK_NUM ];
                    duwStartWriteAddress  = ( (UW)( prDubMsgBuffer[ PR_MSG_ADDR_HI  ] ) ) << 16;
                    duwStartWriteAddress |= ( (UW)( prDubMsgBuffer[ PR_MSG_ADDR_MID ] ) ) <<  8;
                    duwStartWriteAddress |= ( (UW)( prDubMsgBuffer[ PR_MSG_ADDR_LOW ] ) ); 
                    duwWriteSize          = ( (UW)( prDubMsgBuffer[ PR_MSG_SIZE_HI  ] ) ) << 8;
                    duwWriteSize         |= ( (UW)( prDubMsgBuffer[ PR_MSG_SIZE_LOW ] ) );
                    duwEndWriteAddress    = duwStartWriteAddress + duwWriteSize  - 1;
                    dubBlockLength        = (UB)( ( duwWriteSize - 1 ) / PR_BLOCK_SIZE ) + 1;
                    
                    /* Parameter check (blocks 0-3 protection, inhibit 0 size writing, etc.) */
                    if( ( dubStartEraseBlock >= 4                ) &&   /*  */
                        ( dubStartEraseBlock <  PR_MAX_BLOCK_NUM ) &&   /*  */
                        ( duwWriteSize       != 0                ) )    /*  */
                    {
                        /* Check state of blocks subject to programming and erase processing */
                        for( dub_i = 0 ; dub_i < dubBlockLength ; dub_i++ )
                        {
#ifdef PR_USE_OCD_MODE      /* Do nothing on monitor area in OCD mode. */
                            if( ( dubStartEraseBlock + dub_i ) != PR_OCD_MONITOR_BLOCK )
                            {
#endif
                                DI();
                                dubSelfResult = FSL_BlankCheck( dubStartEraseBlock + dub_i );
                                
                                /* If the target block is nonblank. */
                                if( dubSelfResult == FSL_ERR_BLANKCHECK )
                                {
                                    
                                    dubSelfResult = FSL_Erase( dubStartEraseBlock + dub_i );
                                }
                                
                                EI();

#ifdef PR_USE_OCD_MODE      /* Do nothing on monitor area in OCD mode. */
                            }
                            else {
                                dubSelfResult = FSL_OK;
                            }
#endif
                        }
                        
                        /* Set address to write. */
                        duwWriteAdressIndex = duwStartWriteAddress;
                        
                        /* Convert flash self programming result to a transmit parameter. */
                        dubMsgResult = prFslErrorCheck( dubSelfResult );
                    }
                    else {
                        dubMsgResult = PR_MSG_RET_PRM_ERR;
                    }
                    
                    /* Send result. */
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
                }
                
                
                /*-- DATA command --*/
                case PR_MSG_COMM_DATA:
                    
                    /* Check whether the target write address is smaller than the end address */
                    if( duwWriteAdressIndex <= duwEndWriteAddress )
                    {
#ifdef PR_USE_OCD_MODE  /* Do nothing on monitor area in OCD mode. */
                        if( duwWriteAdressIndex < PR_OCD_MONITOR_ADDR )
                        {
#endif
                            /* Copy write data into data buffer. */
                            memcpy_f( &prDubWriteBuffer[0], &prDubMsgBuffer[0], PR_MSG_PACKET_SIZE );
                            
                            dtyWriteBuff.fsl_destination_address_u32 = duwWriteAdressIndex;
                            
                            DI();
                            dubSelfResult = FSL_Write( &dtyWriteBuff );
                            EI();
                        
#ifdef PR_USE_OCD_MODE  /* Do nothing on monitor area in OCD mode. */
                        }
                        else {
				if(updata_finsh==1)
				{
				    updata_finsh = 0;
    				    g_write_address = TARGET_BLOCK * BLOCK_SIZE;
				    g_write_value[0]   = 0xff;
				    g_write_value[1]   = 0xff;
				    g_write_value[2]   = 0xff;
				    g_write_value[3]   = 0xff;
				    g_write_value[4]   = 0xff;
				    R_FDL_ExecuteWrite();			
				}
                            dubSelfResult = FSL_OK;
                        }
#endif
                        
                        /* Convert flash self programming result to a transmit parameter. */
                        dubMsgResult = prFslErrorCheck( dubSelfResult );
                        
                        /* Increment target write address by write size */
                        duwWriteAdressIndex += PR_MSG_PACKET_SIZE;
                    }
                    else {
					
                        dubMsgResult = PR_MSG_RET_ERR_END;
                    }
                    if( duwWriteAdressIndex >= 0x7C00 )//huangcaihui
			if(updata_finsh==1)
			{
                R_FDL_ExecuteErase();
			    updata_finsh = 0;
			    g_write_address = TARGET_BLOCK * BLOCK_SIZE;
			    g_write_value[0]   = 0xff;
			    g_write_value[1]   = 0xff;
			    g_write_value[2]   = 0xff;
			    g_write_value[3]   = 0xff;
			    g_write_value[4]   = 0xff;
			    R_FDL_ExecuteWrite();
			}				
                    /* Send result. */
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
                    
                /*-- IVERIFY command --*/
                case PR_MSG_COMM_IVERIFY:
                    
                    /* Verify processing */
                    DI();
                    dubSelfResult = FSL_IVerify( prDubMsgBuffer[ PR_MSG_IVERIFY_BLOCK ] );
                    EI();
                    
                    /* Convert flash self programming result to a transmit parameter and send result. */
                    dubMsgResult = prFslErrorCheck( dubSelfResult );
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
                
                /*-- BOOTSWAP command --*/
                case PR_MSG_COMM_BOOTSWAP:
                if(updata_finsh==1)
		{
		    updata_finsh = 0;
		    g_write_address = TARGET_BLOCK * BLOCK_SIZE;
		    g_write_value[0]   = 0xff;
		    g_write_value[1]   = 0xff;
		    g_write_value[2]   = 0xff;
		    g_write_value[3]   = 0xff;
		    g_write_value[4]   = 0xff;
		    R_FDL_ExecuteWrite();			
		}	
                /* Disabled in OCD mode. */
		//R_FDL_ExecuteErase();
#ifdef PR_USE_OCD_MODE
                    /* Do nothing and end normally in OCD mode. */
                    prUartSendMsg( dubCommnad, PR_MSG_RET_NORM_END );
#else
                    /* Perform processing if not in OCD mode. */
                    /* Boot flag rewrite processing */
                    DI();
                    dubSelfResult = FSL_InvertBootFlag();
                    EI();
                    
                    /* Convert flash self programming result to a transmit parameter and send result. */
                    dubMsgResult  = prFslErrorCheck( dubSelfResult );
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    
                    /* Upon completion, perform forced reset processing. */
                    if( dubMsgResult == PR_MSG_RET_NORM_END )
                    {
                        /* UART communication termination processing */
                        prUartEnd();
                        
                        /* Forced reset processing */
                        FSL_ForceReset();
                    }
#endif
                    break;
                
                /*-- RESET command --*/
                case PR_MSG_COMM_RESET:
                /* Disabled in OCD mode. */
#ifdef PR_USE_OCD_MODE
                    /* Do nothing and end normally in OCD mode. */
                    prUartSendMsg( dubCommnad, PR_MSG_RET_NORM_END );
#else
                    /* Perform processing if not in OCD mode. */
                    /* Send result of reception. */
                    dubMsgResult = PR_MSG_RET_NORM_END;
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    
                    /* UART communication termination processing */
                    prUartEnd();
                    
                    /* Formced reset processing */
                    FSL_ForceReset();
#endif
                    break;

                /*-- ERASE command --*/
                case PR_MSG_COMM_ERASE:
                    DI();
                    dubSelfResult = FSL_Erase( prDubMsgBuffer[ PR_MSG_ERASE_BLOCK ] );
                    EI();
                    
                    /* Convert flash self programming result to a transmit parameter and send result. */
                    dubMsgResult = prFslErrorCheck( dubSelfResult );
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
                    
                /*-- FSW command --*/
                case PR_MSG_COMM_FSW_SET:
                {
                    fsl_fsw_t   dtyFslFsw;
                    
                    /*  */
                    dtyFslFsw.fsl_start_block_u16  = ( (UH)( prDubMsgBuffer[ PR_MSG_FSW_START_HI  ] ) ) << 8;
                    dtyFslFsw.fsl_start_block_u16 |= ( (UH)( prDubMsgBuffer[ PR_MSG_FSW_START_LOW ] ) );
                    dtyFslFsw.fsl_end_block_u16    = ( (UH)( prDubMsgBuffer[ PR_MSG_FSW_END_HI    ] ) ) << 8;
                    dtyFslFsw.fsl_end_block_u16   |= ( (UH)( prDubMsgBuffer[ PR_MSG_FSW_END_LOW   ] ) );
                    
                    /*  */
                    DI();
                    dubSelfResult = FSL_SetFlashShieldWindow( &dtyFslFsw );
                    EI();
                    
                    /* Convert flash self programming result to a transmit parameter and send result. */
                    dubMsgResult = prFslErrorCheck( dubSelfResult );
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
                }
                    
                /* Discard any irrelevant command. */
                default:
                    /*  */
                    dubMsgResult = PR_MSG_RET_PRM_ERR;
                    prUartSendMsg( dubCommnad, dubMsgResult );
                    break;
            }
        }
        
        dubReturn = true;
    }
    else {
        dubReturn = false;
    }
    
    /* Terminate flash self programming. */
    prFslEnd();
    
    return dubReturn;
}


/*----------------------------------------------------------------------------*/
/* FSL functions                                                              */
/*----------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prFslStart(void)
* Function Name     : prFslStart
* Description       : 
* Argument          : none
* Return Value      : processing result
* Calling Functions : prBootWriteProgram
******************************************************************************/
fsl_u08 prFslStart( void )
{
    fsl_u08 dubRetCode;
    
    /*  */
    dubRetCode = FSL_Init( &fsl_descriptor_pstr );
    
    /*  */
    if( dubRetCode == FSL_OK )
    {
        /*  */
        FSL_Open();
        
        /*  */
        FSL_PrepareFunctions();
        FSL_PrepareExtFunctions();
    }
    
    return dubRetCode;
}

/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prFslEnd(void)
* Function Name     : prFslEnd
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : prBootWriteProgram
******************************************************************************/
void prFslEnd( void )
{
    /*  */
    FSL_Close();
}

/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prFslErrorCheck( fsl_u08 dubSelfResult )
* Function Name     : prFslErrorCheck
* Description       : 
* Argument          : dubSelfResult : 
* Return Value      : UB            : 
* Calling Functions : prBootWriteProgram
******************************************************************************/
UB prFslErrorCheck( fsl_u08 dubSelfResult )
{
    UB  dubMsgErrCode;          /*  */
    
    /*  */
    switch( dubSelfResult )
    {
        case FSL_OK:
            dubMsgErrCode = PR_MSG_RET_NORM_END;    /*  */
            break;
        
        case FSL_ERR_PROTECTION:
            dubMsgErrCode = PR_MSG_RET_PROTECT_ERR; /*  */
            break;
        
        case FSL_ERR_ERASE:
            dubMsgErrCode = PR_MSG_RET_ERASE_ERR;   /*  */
            break;
        
        case FSL_ERR_WRITE:
            dubMsgErrCode = PR_MSG_RET_WRITE_ERR;   /*  */
            break;
        
        case FSL_ERR_IVERIFY:
            dubMsgErrCode = PR_MSG_RET_IVERIFY_ERR; /*  */
            break;
        
        default:
            dubMsgErrCode = PR_MSG_RET_ERR_END;     /*  */
            break;
    }
    
    return dubMsgErrCode;
}


/*----------------------------------------------------------------------------*/
/* uart functions                                                             */
/*----------------------------------------------------------------------------*/
/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prUartInit( void )
* Function Name     : prUartinit
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : prBootWriteProgram, 
******************************************************************************/
void prUartInit( void )
{ 
#if 0
    /**********************************************************/
    /* PER0                                                   */
    /* (SAU0EN)                                               */ /**********************************************************/
    SAU0EN = 1;
    /*  */
    NOP();
    NOP();
    NOP();
    NOP();
    /**********************************/
    /*                                */ /**********************************/
    SPS0 = 0b0000000000000011; /*          - ||||++++------- PRS003-PRS000
            - ++++----------- PRS013-PRS010[] 0000 : fCLK 0001 : fCLK/2 0010 : fCLK/2^2 0011 : fCLK/2^3
                                 *  0100 : fCLK/2^4 0101 : fCLK/2^5 0110 : fCLK/2^6 0111 : fCLK/2^7 1000 : fCLK/2^8 1001 : fCLK/2^9 1010 : fCLK/2^10 1011 : fCLK/2^11 1111 : INTTM02 :  */
    /****************************************/
    /*                                      */
    /* (SMR00)                              */ /****************************************/
    SMR02 = 0b0000000000100010; /*          - |||||||||||||||+ MD000[]
            - |||||||||||||||   0 : 
            - |||||||||||||||   1 : 
            - |||||||||||||||
            - |||||||||||||++- MD002,MD001[]
            - |||||||||||||     00 : 
            - |||||||||||||     01 : 
            - |||||||||||||     10 : 
            - |||||||||||||     11 : 
            - |||||||||||||
            - ||||||||+++++--- 00100
            - ||||||||
            - |||||||+-------- STS00[]
            - |||||||           0 : 
            - |||||||           1 : 
            - |||||||
            - ||+++++--------- 0
            - ||
            - |+-------------- CCS00[]
            - |                 0 : 
            - |                 1 : 
            - |
            - +--------------- CKS00[] 0 : 1 :  */
    /****************************************/
    /*                                      */
    /* (SMR01)                              */ /****************************************/
    SMR03 = 0b0000000100100010; /*          - |||||||||||||||+ MD010[]
            - |||||||||||||||   0 : 
            - |||||||||||||||   1 : 
            - |||||||||||||||
            - |||||||||||||++- MD012,MD011[]
            - |||||||||||||     00 : 
            - |||||||||||||     01 : 
            - |||||||||||||     10 : 
            - |||||||||||||     11 : 
            - |||||||||||||
            - ||||||||||+++--- 100
            - ||||||||||
            - |||||||||+------ SIS010[
            - |||||||||               ]
            - |||||||||         0 : 
            - |||||||||             
            - |||||||||         1 : 
            - |||||||||             
            - |||||||||
            - ||||||||+------- 0
            - ||||||||
            - |||||||+-------- STS01[]
            - |||||||           0 : 
            - |||||||           1 : 
            - |||||||
            - ||+++++--------- 0
            - ||
            - |+-------------- CCS01[]
            - |                 0 : 
            - |                 1 : 
            - |
            - +--------------- CKS01[] 0 : 1 :  */
    /****************************************/
    /*                                      */
    /* (SCR00)                              */ /****************************************/
    SCR02 = 0b1000000010010111; /*          - ||||||||||||||++ DLS001-DLS000[]
            - ||||||||||||||    01 : 
            - ||||||||||||||    10 : 
            - |||||||||||||| *  11 : 
            - ||||||||||||||       :
            - ||||||||||||||
            - |||||||||||||+-- 1
            - ||||||||||||+--- 0
            - ||||||||||||
            - ||||||||||++---- SLC001,SLC000[]
            - ||||||||||        00 : 
            - ||||||||||     *  01 : 
            - ||||||||||        10 : 
            - ||||||||||        11 : 
            - ||||||||||
            - |||||||||+------ 0
            - |||||||||
            - ||||||||+------- DIR00[]
            - ||||||||          0 : MSB
            - ||||||||       *  1 : LSB
            - ||||||||
            - ||||||++-------- PTC001,PTC000[]
            - ||||||         *  00 : 
            - ||||||            01 : 
            - ||||||            10 : 
            - ||||||            11 : 
            - ||||||
            - |||||+---------- EOC00[]
            - |||||          *  0 : 
            - |||||             1 : 
            - |||||
            - ||||+----------- 0
            - ||||
            - ||++------------ DAP00,CKP00[]
            - ||                00 : 
            - ||
            - ++-------------- TXE00,RXE00[] 00 : 01 : 
                             *  10 : 11 :  */
    /****************************************/
    /*                                      */
    /* (SCR01)                              */ /****************************************/
    SCR03 = 0b0100010010010111; /*          - ||||||||||||||++ DLS011-DLS010[]
            - ||||||||||||||    01 : 
            - ||||||||||||||    10 : 
            - |||||||||||||| *  11 : 
            - ||||||||||||||       :
            - ||||||||||||||
            - |||||||||||||+-- 1
            - ||||||||||||+--- 0
            - ||||||||||||
            - ||||||||||++---- SLC011,SLC010[]
            - ||||||||||        00 : 
            - ||||||||||     *  01 : 
            - ||||||||||        10 : 
            - ||||||||||        11 : 
            - ||||||||||
            - |||||||||+------ 0
            - |||||||||
            - ||||||||+------- DIR01[]
            - ||||||||          0 : MSB
            - ||||||||       *  1 : LSB
            - ||||||||
            - ||||||++-------- PTC011,PTC010[]
            - ||||||         *  00 : 
            - ||||||            01 : 
            - ||||||            10 : 
            - ||||||            11 : 
            - |||||+---------- EOC01[]
            - |||||             0 : 
            - |||||          *  1 : 
            - |||||
            - ||||+----------- 0
            - ||||
            - ||++------------ DAP01,CKP01[]
            - ||                00 : 
            - ||
            - ++-------------- TXE01,RXE01[] 00 : 
                             *  01 : 10 : 11 :  */
    /********************************/
    /*                              */
    /*                              */ /********************************/
    SDR02 = 0b1000100000000000; /*
            - |||||||+-------- 0
            - |||||||
            - +++++++--------- SDR00[15:9][ ] 0000000 : MCK/2 0000001 : MCK/4 0000010 : MCK/6 :     :
                                    :     : 1111110 : MCK/254 1111111 : MCK/256 0100010:MCK/70 = 8MHz/70 = 114285.7bps
               */
    /********************************/
    /*                              */
    /*                              */ /********************************/
    SDR03 = 0b1000100000000000;  /*
            - |||||||+-------- 0
            - |||||||
            - +++++++--------- SDR01[15:9][ ] 0000000 : MCK/2 0000001 : MCK/4 0000010 : MCK/6 :     :
                                    :     : 1111110 : MCK/254 1111111 : MCK/256 1100111:MCK/208 = 8MHz/70 = 114285.7bps
              */
    /****************************************/
    /*                                      */
    /* (SOL0L)                              */ /****************************************/
    SOL0 = 0b0000000000000000; /* 
            -        +---SOL00[] 0 : 1 :  */
    /******************************/
    /*                            */
    /* (SO0)                      */
    /******************************/
    SO0 = 0b0000000000000100;//  0b0000000100000011; /*      -                +---SO00: 0 : 1 :  */
    /***********************************/
    /*                                 */
    /* (SOE0)                          */ /***********************************/
    SOE0 = 0b0000000000000100; /*
            -        +---SOE00: 0 : 1 :  */
    /****************************************/
    /* (SS0)                                */ /****************************************/
    SS0 = 0b0000000000001100;  /* 
           - ||||++++------- SS0n (n=0-3)[]
           - ||||           0:
           - ||||           1:
           - ||||
           - ++++----------- 0 */ 
#else 
    SAU0EN = 1U;    /* supply SAU0 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS0 = 0x0011;//_0001_SAU_CK00_FCLK_1 | _0010_SAU_CK01_FCLK_1;
    ST0 |= 0x000C;//_0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON;    /* disable UART1 receive and transmit */
    STMK1 = 1U;    /* disable INTST1 interrupt */
    STIF1 = 0U;    /* clear INTST1 interrupt flag */
    SRMK1 = 1U;    /* disable INTSR1 interrupt */
    SRIF1 = 0U;    /* clear INTSR1 interrupt flag */
    SREMK1 = 1U;   /* disable INTSRE1 interrupt */
    SREIF1 = 0U;   /* clear INTSRE1 interrupt flag */
    /* Set INTST1 low priority */
    STPR11 = 1U;
    STPR01 = 1U;
    /* Set INTSR1 low priority */
    SRPR11 = 1U;
    SRPR01 = 1U;
    SMR02 = 0x0022;//_0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_TRIGGER_SOFTWARE |
            //_0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR02 = 0x8097;//_8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            //_0007_SAU_LENGTH_8;
    SDR02 = 0x8800;
    NFEN0 |= 0x04;//_04_SAU_RXD1_FILTER_ON;
    SIR03 = 0x0007;//_0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR03 = 0x0122;//_0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL |
           // _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR03 = 0x4097;//_4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            //_0007_SAU_LENGTH_8;
    SDR03 = 0x8800;;
    SO0 |= 0x0004;//_0004_SAU_CH2_DATA_OUTPUT_1;
    SOL0 |= 0x0000;//_0000_SAU_CHANNEL2_NORMAL;    /* output level normal */
    SOE0 |= 0x0004;//_0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART1 output */
    /* Set RxD1 pin */
    PMC0 &= 0xFDU;
    PM0 |= 0x02U;
    /* Set TxD1 pin */
    PMC0 &= 0xFEU;
    P0 |= 0x01U;
    PM0 &= 0xFEU;
    SO0 |= 0x0004;//_0004_SAU_CH2_DATA_OUTPUT_1;    /* output level normal */
    SOE0 |= 0x0004;//_0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART1 output */
    SS0 |= 0x000C;//_0008_SAU_CH3_START_TRG_ON | _0004_SAU_CH2_START_TRG_ON;    /* enable UART1 receive and transmit */

#endif
}



/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prUartEnd( void )
* Function Name     : prUartEnd
* Description       : 
* Argument          : none
* Return Value      : none
* Calling Functions : prBootWriteProgram
******************************************************************************/
void prUartEnd( void )
{
    /****************************************/
    /* SS0                                  */
    /****************************************/
    SS0 = 0b0000000000000000;  /* 
           - ||||++++------- SS0n (n=0-3)[]
           - ||||            0:
           - ||||            1:
           - ||||
           - ++++----------- 0 */
    
    /**********************************************************/
    /*                                                        */
    /*                                                        */
    /**********************************************************/
    SAU0EN = 0;
    
    /*  */
    NOP();
    NOP();
    NOP();
    NOP();
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prUartRcvMsg( UB *, UB * )
* Function Name     : prUartRcvMsg
* Description       : 
* Argument          : UB *pubDataBuffer : 
*                   : UB *pubCommand    : 
* Return Value      : UB                : 
* Calling Functions : prBootWriteProgram
******************************************************************************/
UB   prUartRcvMsg( UB *pubDataBuffer, UB *pubCommand )
{
    UH  duh_i;                          /*  */
    UB  dubRetCode;                     /*  */
    UH  duhDataSize;                    /*  */
    UB  dubCheckSum = PR_MSG_FRAME_SOH; /*  */
    
    /*  */
    while( prUartRcvData() != PR_MSG_FRAME_SOH );
    
    /*  */
    *pubDataBuffer  =  prUartRcvData();
     dubCheckSum   += *pubDataBuffer;
     duhDataSize    =  ( (UH)*pubDataBuffer ) << 8;
    
    /*  */
    *pubDataBuffer  =  prUartRcvData();
     dubCheckSum   += *pubDataBuffer;
     duhDataSize   |=  ( (UH)*pubDataBuffer );
    
    /*  */
    *pubCommand  =  prUartRcvData();
    dubCheckSum += *pubCommand;
    
    /*  */
    for( duh_i = 0 ; duh_i < ( duhDataSize - 2 ) ; duh_i++ )
    {
        pubDataBuffer[ duh_i ]  = prUartRcvData();
        dubCheckSum            += pubDataBuffer[ duh_i ];
    }
    
    /*  */
    if( dubCheckSum == prUartRcvData() )
    {
        dubRetCode = PR_MSG_RET_NORM_END;       /*  */
    }
    else {
        dubRetCode = PR_MSG_RET_CHKSUM_ERR;     /*  */
    }
    
    /*  */
    prLED1brink( OFF );
    
    return dubRetCode;
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prUartRcvData( void )
* Function Name     : prUartRcvData
* Description       : 
* Argument          : none
* Return Value      : UB                : 
* Calling Functions : prUartRcvMsg
******************************************************************************/
UB   prUartRcvData( void )
{
    UB dubRcvData;
    
    while( SRIF1 != 1 );    /*  */
    
    dubRcvData = RXD1;      /*  */
    SRIF1 = 0;              /*  */
    
    prLED1brink( ON );      /*  */
    
    return dubRcvData;
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prUartSendMsg( UB , UB )
* Function Name     : prUartSendMsg
* Description       : 
* Argument          : UB dubCommand : 
*                   : UB dubRetMsg  : 
* Return Value      : none
* Calling Functions : prBootWriteProgram
******************************************************************************/
void prUartSendMsg( UB dubCommand, UB dubRetMsg )
{
    UH  duhSendLength;          /*  */
    UB  dubCheckSum   = 0;      /*  */
    
    /*  */
    static UB dubDataFrame[ PR_MSG_DFRAME_LEN ] = { PR_MSG_FRAME_SOH, 0x00, 0x03, 0x00, 0x00 };
    
    /*  */
    dubDataFrame[ PR_MSG_DFRAME_COMD ] = dubCommand;
    dubDataFrame[ PR_MSG_DFRAME_DATA ] = dubRetMsg;
    
    /*  */
    for( duhSendLength = 0 ; duhSendLength < PR_MSG_DFRAME_LEN ; duhSendLength++ )
    {
        dubCheckSum +=   dubDataFrame[ duhSendLength ];
        prUartSendData( &dubDataFrame[ duhSendLength ] );
    }
    
    /*  */
    prUartSendData( &dubCheckSum );
    
    /*  */
    prLED1brink( OFF );
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : UB prUartSendData( UB * )
* Function Name     : prUartSendData
* Description       : 
* Argument          : UB *pubSendData : 
* Return Value      : none
* Calling Functions : prUartSendMsg, prSendMsgAsciiData(flash project)
******************************************************************************/
void prUartSendData( UB *pubSendData )
{
    TXD1 = *pubSendData;        /*  */
    
    while( STIF1 != 1 );        /*  */
        
    STIF1 = 0;                  /*  */
    
    prLED1brink( ON );          /*  */
}


/******************************************************************************
* Outline           : 
* Include           : none
* Declaration       : void prLED1brink( void )
* Function Name     : prLED1brink
* Description       : 
* Argument          : UB dubBlinkSetFlag : ON
*                                          OFF
* Return Value      : none
* Calling Functions : prUartSendMsg, prUartSendData, prUartRcvMsg, prUartRcvData
******************************************************************************/
void prLED1brink( UB dubBlinkSetFlag )
{
    /*  */
    if( prDubBootMode == PR_BOOT_MODE_WRITE )
    {
        /*  */
        if( dubBlinkSetFlag == OFF )
        {
            PR_LED1_OFF();
            prDubLedBrinkFlag = FALSE;
        }
        /*  */
        else {
            if( prDubLedBrinkFlag == FALSE )
            {
                PR_LED1_ON();
                prDubLedBrinkFlag = TRUE;
            }
            else {
                PR_LED1_OFF();
                prDubLedBrinkFlag = FALSE;
            }
        }
    }
}

void Reset_Force(void)
{
UB Result;
	Result = prFslStart();
	if(Result == FSL_OK)
	{
		FSL_ForceReset();
	}
	prFslEnd();
}
