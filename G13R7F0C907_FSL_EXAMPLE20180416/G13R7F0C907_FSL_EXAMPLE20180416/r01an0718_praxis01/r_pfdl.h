
#define FLASH_START_ADDRESS    (0xF1000)                               /* Start address of data flash                */
#define TARGET_BLOCK           (0)                                     /* 2k Block number of target(0 ~ 1)    4k Block number of target(0 ~ 3)          */
#define BLOCK_SIZE             (0x400)                                 /* Block size                                 */
#define WRITE_SIZE             (5)                                     /* Size of data to be written at once   (5 ~ 1024)     */
#define MAX_VALUE              (0xFF)                                  /* Maximum value of writing                   */
#define MAX_ADDRESS            ((TARGET_BLOCK + 1) * BLOCK_SIZE - 1)   /* Maximum address of writing                 */
#define PFDL_NG                (1)                                     /* Failure to Data Flash                      */
#define FDL_FRQ                (20)                                    /* Setting frequency (MHz)                    */
#define FDL_VOL                (0x00)                                  /* Voltage mode                               */

void    R_FDL_Init(void);
uint8_t R_FDL_Erase(void);
void    R_FDL_Read(void);
uint8_t R_FDL_Write(void);
void    R_FDL_ChangeAddress(void);
void R_FDL_ExecuteWrite(void);
void  R_FDL_ExecuteErase(void);
void R_FDL_ExecuteRead(void);
void R_FDL_FindAddress(void);
void R_FDL_Write_E2Prom(void);

#if    TARGET_BLOCK > 1
#error target_block error!!
#endif