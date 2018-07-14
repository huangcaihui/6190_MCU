;=================================================================================================
; Project      = Flash self-programming library, MF3 single voltage flash
; Module       = fsl.inc
; Device:      = RL78
; Version      = V2.20
;=================================================================================================
;                                  COPYRIGHT
;=================================================================================================
; Copyright(c) 2010,2011,2012 Renesas Electronics Corporation
;=================================================================================================
; Purpose:
;              implementation module of low-level flash memory access
;              CAUTION: Please comment out unused function prototypes 
;                       for code size reduction.
;
;=================================================================================================
;
; RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
; This program must be used solely for the purpose for which it was furnished
; by Renesas Electronics Corporation. No part of this program may be reproduced or
; disclosed to others, in any form, without the prior written permission of
; Renesas Electronics Corporation.
;
;=================================================================================================

$IF (__FSL_INC_INCLUDED)

$ELSE
$SET (__FSL_INC_INCLUDED)


;=================================================================================================
; constant definitions
;=================================================================================================

;status code definitions returned by the FSL functions
FSL_OK                    EQU  (000H)   ; no problems
FSL_ERR_PARAMETER         EQU  (005H)   ; parameter error
FSL_ERR_PROTECTION        EQU  (010H)   ; protection error (access right conflict)
FSL_ERR_ERASE             EQU  (01AH)   ; erase error
FSL_ERR_BLANKCHECK        EQU  (01BH)   ; blankcheck error (MRG11)
FSL_ERR_IVERIFY           EQU  (01BH)   ; internal verify error (MRG11)
FSL_ERR_WRITE             EQU  (01CH)   ; write error
FSL_ERR_FLOW              EQU  (01FH)   ; flow error (wrong timing calling)
FSL_IDLE                  EQU  (030H)   ; idle state (any action is not running)
FSL_SUSPEND               EQU  (043H)   ; previous flash action is suspended
FSL_BUSY                  EQU  (0FFH)   ; command is being processed


;=================================================================================================
; global function prototypes
;=================================================================================================


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      initialization of flash environment                                            
;                                                                                              
; Input:        AX,C - pointer to FSL descriptor                                               
; Output:       -                                                                              
; Returned:     C, status_code                                                                 
;                   = 0x00(FSL_OK), normal and means initialization OK                         
;                   = 0x05(FSL_ERR_PARAMETER), parameter error or HOCO isn't started           
;----------------------------------------------------------------------------------------------
EXTRN _FSL_Init


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      opens flash environment                                                        
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_Open


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      closes flash environment                                                       
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_Close


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      prepares following functions to be called                                      
;               FSL_BlankCheck, FSL_Erase, FSL_Write, FSL_IVerify, FSL_StatusCheck             
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_PrepareFunctions


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      prepares following functions to be called                                      
;               FSL_Set*ProtectFlag, FSL_InvertBootFlag, FSL_SetFlashShieldWindow,             
;               FSL_SwapBootCluster, FSL_SwapActiveBootCluster                                 
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_PrepareExtFunctions


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      changes all vector addresses to specified address in RAM                       
; Input:        AX - vector address in RAM (Lower 16 bits address)                             
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_ChangeInterruptTable


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      restores all vector addresses to initial vector addresses                      
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_RestoreInterruptTable


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      checks if specified block is blank                                             
; Input:        AX - block number has to be checked                                            
; Output:       -                                                                              
; Returned:     C, status_code                                                                 
;                   = 0x00(FSL_OK), normal and means "block is blank"                          
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x1B(FSL_ERR_BLANKCHECK), blank-check error, means "block is not blank"  
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_BlankCheck


;----------------------------------------------------------------------------------------------
;  Block type:  FSL command function                                                           
;----------------------------------------------------------------------------------------------
;  Purpose:     erase specified block                                                          
;  Input:       AX - block number has to be erase                                              
;  Output:      -                                                                              
;  Returned:    C, status_code                                                                 
;                   = 0x00(FSL_OK), normal and means "block erased successfully"               
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_Erase


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      performs internal verify on specified block                                    
; Input:        AX - block number has to be verified                                           
; Output:       -                                                                              
; Returned:     C, status_code                                                                 
;                   = 0x00(FSL_OK), normal and means "block is verified"                       
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_IVerify


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      writes N words from the data buffer into flash                                 
; Input:        AX - pointer to struct fsl_write_str to write                                  
; Output:       -                                                                              
; Condition:    1) (fsl_destination_address_u32 MOD 4 == 0)                                    
;               2) most significant byte (MSB) of fsl_destination_address_u32 has to be 0x00   
;                  Means: 0x00abcdef 24 bit flash address allowed                              
;               3) (0 < fsl_word_count_u08 <= 64)                                              
;               4) (fsl_word_count_u08 <= sizeof(data buffer))                                 
;                  NOT CHECKED BY FSL                                                          
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_Write


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      controls the flash action start/continue/check for the last called function    
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_BLANKCHECK), blank-check error, means "block not blank"     
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0x30(FSL_IDLE), any action is not running                                
;                   = 0xFF(FSL_BUSY), normal and means "process was not finished"              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_StatusCheck


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      susdends the flash action                                                      
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), previous flash action is OK.                               
;                                   And the state is suspended.                                
;                   = 0x1A(FSL_ERR_ERASE), previous flash action is Erase error.               
;                                   And the state is suspended.                                
;                   = 0x1B(FSL_ERR_BLANKCHECK), previous flash action is Blank error.          
;                                   And the state is suspended.                                
;                   = 0x1B(FSL_ERR_IVERIFY), previous flash action is IVerify error.           
;                                   And the state is suspended.                                
;                   = 0x1C(FSL_ERR_WRITE), previous flash action is Write error.               
;                                   And the state is suspended.                                
;                   = 0x1F(FSL_ERR_FLOW), violates the precondition.                           
;                                      or has been already suspending.                         
;                   = 0x30(FSL_IDLE), any action are not running.                              
;                                   And the state is suspended.                                
;                   = 0x43(FSL_SUSPEND), OK, previous flash action is suspended.               
;----------------------------------------------------------------------------------------------
EXTRN _FSL_StandBy


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      resumes the flash action                                                       
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), resumed flash action is OK.                                
;                                   And the state is resumed from the suspended state.         
;                   = 0x1A(FSL_ERR_ERASE), resumed flash action is Erase error.                
;                                   And the state is resumed from the suspended state.         
;                   = 0x1F(FSL_ERR_FLOW), violates the precondition.                           
;                                      or FSL is not suspending.                               
;                   = 0xFF(FSL_BUSY), resumed flash action is BUSY.                            
;                                   And the state is resumed from the suspended state.         
;----------------------------------------------------------------------------------------------
EXTRN _FSL_WakeUp


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the security information into the destination address                     
; Input:        AX - destination address of the security info                                  
;               The format of the security info is: "unsigned char"                            
;                                                                                              
;               Format of the security info:                                                   
;               bit_1 = 0 -> boot-area re-programming disabled, otherwise enabled              
;               bit_2 = 0 -> block erase command disabled, otherwise enabled                   
;               bit_4 = 0 -> write command disabled, otherwise enabled                         
;               other bits = 1                                                                 
; Output:       data_destination_pu08 - security info                                          
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetSecurityFlags


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the boot flag into the destination address                                
; Input:        AX - destination address of the boot flag                                      
;               The format of the boot flag info is: "unsigned char"                           
;               The value of the boot info is 0x00 for cluster 0 and 0x01 for cluster 1.       
; Output:       data_destination_pu08 - the boot flag info                                     
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetBootFlag


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the state of swap boot clusters into the destination address              
; Input:        AX - destination address of the state of boot info                             
;               The format of the state of boot info is: "unsigned char"                       
;               The value of the state of boot info is 0x00 for cluster 0                      
;               and 0x01 for cluster 1.                                                        
; Output:       data_destination_pu08 - the state of boot info                                 
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetSwapState


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the last address of the specified block into fsl_destination_address_u32  
; Input:        AX - pointer to struct fsl_getblockendaddr_str to get the last address         
; Output:       fsl_destination_address_u32 - the last address                                 
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                      
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                  
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetBlockEndAddr


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the information about the protected flash area into fsl_*_block_u16       
; Input:        AX - pointer to struct fsl_fsw_str to get FSW                                  
; Output:       fsl_start_block_u16 - the start block of FSW                                   
;               fsl_end_block_u16 - the end block of FSW                                       
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetFlashShieldWindow


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      sets specified security flag by dedicated command-function.                    
;                                                                                              
;               There are following security levels:                                           
;               a) block-erase protection                                                      
;               b) write protection                                                            
;               c) boot-cluster protection                                                     
;                                                                                              
;               CAUTION:                                                                       
;               Each security flag can be written by the application only once                 
;                                                                                              
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_SetBlockEraseProtectFlag
EXTRN _FSL_SetWriteProtectFlag
EXTRN _FSL_SetBootClusterProtectFlag


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      inverts the boot flag.                                                         
;                                                                                              
;               CAUTION:                                                                       
;               After reset, the boot clusters will be switched regarding this boot flag       
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_InvertBootFlag


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      defines a new Flash Shield Window inside the flash memory                      
; Input:        AX - pointer struct fsl_fsw_str to set FSW                                     
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_SetFlashShieldWindow


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      swaps boot cluster 0 and boot cluster 1 physically without setting             
;               the boot flag. After swap the library jumps to the address of the              
;               reset vector.                                                                  
;                                                                                              
;               CAUTION:                                                                       
;               After reset, the boot cluster will be switched regarding the boot flag         
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_SwapBootCluster


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      inverts the boot flag and swaps boot cluster 0 and boot cluster 1 physically   
;                                                                                              
;               CAUTION:                                                                       
;               After reset, the boot clusters will be switched regarding this boot flag       
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     C, status code                                                                 
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_FLOW), last operation has not finished, yet.                
;                                      or violates the precondition.                           
;                                      or FSL is suspending.                                   
;                   = 0xFF(FSL_BUSY), normal and means "process was started"                   
;----------------------------------------------------------------------------------------------
EXTRN _FSL_SwapActiveBootCluster


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      forces a hardware reset via illegal instruction                                
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     -                                                                              
;----------------------------------------------------------------------------------------------
EXTRN _FSL_ForceReset


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      gets the internal version information of the used FSL                          
; Input:        -                                                                              
; Output:       -                                                                              
; Returned:     BC, pointer to version string(L)                                               
;               DE, pointer to version string(H)                                               
;----------------------------------------------------------------------------------------------
EXTRN _FSL_GetVersionString



$ENDIF
