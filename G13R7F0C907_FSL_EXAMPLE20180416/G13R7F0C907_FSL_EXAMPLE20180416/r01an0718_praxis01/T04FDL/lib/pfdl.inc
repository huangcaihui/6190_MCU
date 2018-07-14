;=================================================================================================
; Project      = Flash Data Library T04 (PicoFDL)
; Module       = pfdl.inc
; Device:      = RL78/G12,G13,G14
; Version      = V1.04
; Date         = 21.03.2012
;=================================================================================================
;                                  COPYRIGHT
;=================================================================================================
; Copyright (c) 2011-2012 by Renesas Electronics Europe GmbH, a company of the Renesas Electronics
; Corporation. All rights reserved.
;=================================================================================================
;
; Purpose:      contains the assembler language API definition of the Flash Data Library.
;
;=================================================================================================
;
; Warranty Disclaimer
;
; Because the Product(s) is licensed free of charge, there is no warranty of any kind whatsoever
; and expressly disclaimed and excluded by Renesas, either expressed or implied, including but
; not limited to those for non-infringement of intellectual property, merchantability and/or
; fitness for the particular purpose.
; Renesas shall not have any obligation to maintain, service or provide bug fixes for the
; supplied Product(s) and/or the Application.
;
; Each User is solely responsible for determining the appropriateness of using the Product(s)
; and assumes all risks associated with its exercise of rights under this Agreement, including,
; but not limited to the risks and costs of program errors, compliance with applicable laws,
; damage to or loss of data, programs or equipment, and unavailability or interruption of
; operations.
;
; Limitation of Liability
;
; In no event shall Renesas be liable to the User for any incidental, consequential, indirect,
; or punitive damage (including but not limited to lost profits) regardless of whether such
; liability is based on breach of contract, tort, strict liability, breach of warranties,
; failure of essential purpose or otherwise and even if advised of the possibility of such
; damages. Renesas shall not be liable for any services or products provided by third party
; vendors, developers or consultants identified or referred to the User by Renesas in
; connection with the Product(s) and/or the Application.
;
; ==============================================================================================



$IF (__PFDL_INC_INCLUDED)

$ELSE
$SET (__PFDL_INC_INCLUDED)




;==============================================================================================
; constant definitions
;==============================================================================================


; PFDL command code definitions
; -----------------------------------------------------
PFDL_CMD_READ_BYTES                     EQU      00H
PFDL_CMD_IVERIFY_BYTES                  EQU      06H
PFDL_CMD_BLANKCHECK_BYTES               EQU      08H
PFDL_CMD_WRITE_BYTES                    EQU      04H
PFDL_CMD_ERASE_BLOCK                    EQU      03H


; status code definitions returned by the PFDL functions

; operation related status code
PFDL_OK                                 EQU       000H
PFDL_IDLE                               EQU       030H
PFDL_BUSY                               EQU       0FFH
; flash access related status code
PFDL_ERR_PROTECTION                     EQU       010H
PFDL_ERR_ERASE                          EQU       01AH
PFDL_ERR_MARGIN                         EQU       01BH
PFDL_ERR_WRITE                          EQU       01CH
PFDL_ERR_PARAMETER                      EQU       005H



; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
; Purpose:      Unconditional activation of the Data Flash Library.
;               Based on the descriptor data:
;               - the flash firmware will be initialized for data-flash access only
;               - the internal timing and low-voltage capability will be configured according to the descriptor
;               After successful initialization the flash clock is ON and the PFDL is ready to use.
;
;               CAUTION:
;               Due to the code size minimization no plausibility checks are done by the PicoFDL.
;               Neither configuration, frequency range nor data flash size will be checked by the library.
;
;  Input:        AX = address of the PFDL descriptor variable
;  Output:       -
;  Return:       C = PFDL status
; ---------------------------------------------------------------------------------------------------------------
EXTRN PFDL_Open


; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Disable data flash access unconditionally.
;                If any command is just executed, PFDL_Close will stop it immediately.
;                After return the flash clock is switched OFF.
;  Input:        -
;  Output:       -
;  Return:       -
; ---------------------------------------------------------------------------------------------------------------
EXTRN PFDL_Close


; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Initiating execution of the PFDL request related to the data flash.
;                The corresponding request variable has to be parametrized before.
;
;                request_pstr->index_u16        :   byte-index or block-number within PFDL-pool
;                request_pstr->data_pu08        :   start address of the RAM data that should be read/written
;                request_pstr->bytecount_u16    :   number of bytes has to be read/written
;                request_pstr->command_enu      :   command code
;
;                CAUTION:
;                Due to the code size minimization no plausibility checks are done by the PFDL.
;
;  Input:        AX = pointer to PFDL request variable
;  Output:       -
;  Return:       C = status of the request
; ---------------------------------------------------------------------------------------------------------------
EXTRN PFDL_Execute


; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Continuation of command execution and status update of requests being under execution.
;  Input:        -
;  Output:       -
;  Return:       C = PFDL status
; ---------------------------------------------------------------------------------------------------------------
EXTRN PFDL_Handler



; ---------------------------------------------------------------------------------------------------------------
;  Block type:   standard function
; ---------------------------------------------------------------------------------------------------------------
;  Purpose:      Returns the start address of the library version string
;
;  Input:        -
;  Output:       -
;  Return:       DE = HIGH-word of starting address of the zero-terminated version string
;                BC = LOW-word of that address
; ---------------------------------------------------------------------------------------------------------------
EXTRN  PFDL_GetVersionString



$ENDIF
