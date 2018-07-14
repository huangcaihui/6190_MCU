/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

#include "pfdl.h"
#include "pfdl_types.h"
#include "r_pfdl.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
__far pfdl_u08 *pfdl_version;
extern uint8_t  g_write_value[WRITE_SIZE];
extern uint16_t g_write_address;
extern uint8_t  g_read_value[WRITE_SIZE];

char flag_ram_clash;
void r_pfdl_user(void)
{
	unsigned int i;
	unsigned int j;
	pfdl_version = PFDL_GetVersionString();
	R_FDL_ExecuteErase(); 
    for(i=0; i<8; i++)
    {
	   g_write_address = TARGET_BLOCK * BLOCK_SIZE + i*0x10;
	    g_write_value[0]   = 0x10;
	    g_write_value[1]   = 0x12;
	    g_write_value[2]   = 0x14;
	    g_write_value[3]   = 0x16;
	    g_write_value[4]   = 0x18;
	    R_FDL_ExecuteWrite();



	    g_write_address = TARGET_BLOCK * BLOCK_SIZE + i*0x10;
	    g_read_value[0] = 0xff;
	    g_read_value[1] = 0xff;
	    g_read_value[2] = 0xff;
	    g_read_value[3] = 0xff;
	    g_read_value[4] = 0xff;
	    R_FDL_ExecuteRead(); 

    }
}

/* End user code. Do not edit comment generated here */
