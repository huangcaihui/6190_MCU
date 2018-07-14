/*================================================================================================*/
/* Project      = Flash Data Library T04 (PicoFDL)                                                */
/* Module       = pfdl_types.h                                                                    */
/* Device:      = RL78/G12,G13,G14                                                                */
/* Version      = V1.04                                                                           */
/* Date         = 21.03.2012                                                                      */
/*================================================================================================*/
/*                                  COPYRIGHT                                                     */
/*================================================================================================*/
/* Copyright (c) 2011-2012 by Renesas Electronics Europe GmbH, a company of the Renesas           */
/* Electronics Corporation. All rights reserved.                                                  */
/*================================================================================================*/
/*                                                                                                */
/* Purpose:     contains the type definitias used by the library.                                 */
/*                                                                                                */
/*================================================================================================*/
/*                                                                                                */
/* Warranty Disclaimer                                                                            */
/*                                                                                                */
/* Because the Product(s) is licensed free of charge, there is no warranty of any kind whatsoever */
/* and expressly disclaimed and excluded by Renesas, either expressed or implied, including but   */
/* not limited to those for non-infringement of intellectual property, merchantability and/or     */
/* fitness for the particular purpose.                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the        */
/* supplied Product(s) and/or the Application.                                                    */
/*                                                                                                */
/* Each User is solely responsible for determining the appropriateness of using the Product(s)    */
/* and assumes all risks associated with its exercise of rights under this Agreement, including,  */
/* but not limited to the risks and costs of program errors, compliance with applicable laws,     */
/* damage to or loss of data, programs or equipment, and unavailability or interruption of        */
/* operations.                                                                                    */
/*                                                                                                */
/* Limitation of Liability                                                                        */
/*                                                                                                */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect,   */
/* or punitive damage (including but not limited to lost profits) regardless of whether such      */
/* liability is based on breach of contract, tort, strict liability, breach of warranties,        */
/* failure of essential purpose or otherwise and even if advised of the possibility of such       */
/* damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in            */
/* connection with the Product(s) and/or the Application.                                         */
/*                                                                                                */
/*================================================================================================*/


#ifndef __PFDL_TYPES_H_INCLUDED
#define __PFDL_TYPES_H_INCLUDED


/*==============================================================================================*/
/* unsigned type definitions                                                                    */
/*==============================================================================================*/
typedef unsigned char                       pfdl_u08;
typedef unsigned int                        pfdl_u16;
typedef unsigned long int                   pfdl_u32;


/*==============================================================================================*/
/* global constant definitions                                                                  */
/*==============================================================================================*/



/*==============================================================================================*/
/* global type definitions                                                                      */
/*==============================================================================================*/


/* PFDL command code set */
typedef   enum  {                                               /* ---------------------------------------------- */
                  PFDL_CMD_READ_BYTES          = (0x00),        /* 0x00, reads data from flash memory             */
                  PFDL_CMD_IVERIFY_BYTES       = (0x06),        /* 0x06, verifies data if flash content is stable */
                  PFDL_CMD_BLANKCHECK_BYTES    = (0x08),        /* 0x08, checks if flash content is blank         */
                  PFDL_CMD_WRITE_BYTES         = (0x04),        /* 0x04, writes data into flash memory            */
                  PFDL_CMD_ERASE_BLOCK         = (0x03)         /* 0x03, erases one flash block                   */
                } pfdl_command_t;                               /* ---------------------------------------------- */


/* PFDL error code set */
typedef   enum  {
                  /* operation related status               */  /* ---------------------------------------------- */
                  PFDL_IDLE                     = (0x30),       /* 0x30, PFDL ready to receive requests           */
                  PFDL_OK                       = (0x00),       /* 0x00, command finished without problems        */
                  PFDL_BUSY                     = (0xFF),       /* 0xFF, command is being processed               */
                  /* flash related status                   */  /* ---------------------------------------------- */
                  PFDL_ERR_PROTECTION           = (0x10),       /* 0x10, protection error (access right conflict) */
                  PFDL_ERR_ERASE                = (0x1A),       /* 0x1A, erase error                              */
                  PFDL_ERR_MARGIN               = (0x1B),       /* 0x1B, blankcheck or verify margin violated     */
                  PFDL_ERR_WRITE                = (0x1C),       /* 0x1C, write error                              */
                  PFDL_ERR_PARAMETER            = (0x05)        /* 0x05, parameter error                          */
                } pfdl_status_t;                                /* ---------------------------------------------- */


/* PFDL request type (base type for any PFDL access) */
typedef struct {                                                /* ---------------------------------------------- */
                  pfdl_u16              index_u16;              /* 2, W, virt. byte/block index inside PFDL-pool  */
                  __near pfdl_u08*      data_pu08;              /* 2, W, pointer to the 1'st byte of data buffer  */
                  pfdl_u16              bytecount_u16;          /* 2, W, number of bytes to be transfered         */
                  pfdl_command_t        command_enu;            /* 1, W, command code                             */
                } pfdl_request_t;                               /*------------------------------------------------*/
                                                                /* 7 bytes in total                               */
                                                                /*------------------------------------------------*/

/* PFDL descriptor type */
typedef struct {                                                /* ---------------------------------------------- */
                  pfdl_u08      fx_MHz_u08;                     /* 1, system frequency expressed in MHz           */
                  pfdl_u08      wide_voltage_mode_u08;          /* 1, programming voltage mode ( full/wide )      */
                } pfdl_descriptor_t;                            /*------------------------------------------------*/
                                                                /* 2 bytes in total                               */


#endif
