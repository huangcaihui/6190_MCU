/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_timer_user.c
* Version      : CodeGenerator for RL78/G13 V2.03.04.01 [11 Nov 2016]
* Device(s)    : R5F100BC
* Tool-Chain   : CA78K0R
* Description  : This file implements device driver for TAU module.
* Creation Date: 2017/9/8
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt INTTM00 r_tau0_channel0_interrupt
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_serial.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"
#include "r_cg_intc.h"
/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern uint32_t volatile vga2_det;
extern uint32_t volatile vga1_det;
extern volatile uint16_t  g_uart1_rx_count;
extern volatile uint16_t  g_uart2_rx_count;
extern unsigned char debug_gpio[2];
extern unsigned char tx_0_data[];
extern unsigned char rx_1_data[];
extern unsigned char rx_2_data[];
extern unsigned char tx_2_data[];
extern uint16_t Uart0Alive;
extern boolean updata_comflag;

int8_t timer1 = 0;
int8_t timer2 = 0;
int8_t vga2_state=0;
int8_t pre_vga2_state=0;
uint32_t pre_vga2_det;
int8_t vga1_state=0;
int8_t pre_vga1_state=0;
uint32_t pre_vga1_det;
uint16_t Pre_Uart0Alive = 0;
int8_t pre_pin13_state = 1;
int8_t pin13_state = 1;
int8_t pre_pin25_state = 1;
int8_t pin25_state = 1;
/* End user code. Do not edit comment generated here */

static void r_tau1_timer(void)
{
	    r_uart1_header_init();
	    R_UART0_Send(rx_1_data,g_uart1_rx_count);
	    r_uart1_reset();
}

/***********************************************************************************************************************
* Function Name: r_tau0_channel0_interrupt
* Description  : This function is INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
__interrupt static void r_tau0_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    timer1++;
    timer2++;
    if(timer1 == 10){
	    if(vga2_det > pre_vga2_det ){
		 pre_vga2_det = vga2_det;
		 vga2_state = 1;
		 if(vga2_state != pre_vga2_state){
			pre_vga2_state = vga2_state;
		 	//debug_gpio[1] = 1;
			tx_0_data[0] = 0x85;
			tx_0_data[1] = 0x00;
			tx_0_data[2] = 0x02;
			tx_0_data[3] = 0x10;
			tx_0_data[4] = 0x01;
			tx_0_data[5] = 0x98;
		 	R_UART0_Send(tx_0_data,6);
		 }
		 if(vga2_det == 0xffff)
		 	vga2_det = 0;
	    }else if(vga2_det == pre_vga2_det){
		  vga2_state = 0;
		  if(vga2_state != pre_vga2_state){
			pre_vga2_state = vga2_state;
			//debug_gpio[1] = 0;
	    	tx_0_data[0] = 0x85;
			tx_0_data[1] = 0x00;
			tx_0_data[2] = 0x02;
			tx_0_data[3] = 0x10;
			tx_0_data[4] = 0x00;
			tx_0_data[5] = 0x97;
		 	R_UART0_Send(tx_0_data,6);
		    }
	    
	    }
	  
	    if(vga1_det > pre_vga1_det ){
		 pre_vga1_det = vga1_det;
		 vga1_state = 1;
		 if(vga1_state != pre_vga1_state){
			pre_vga1_state = vga1_state;
		 	//debug_gpio[1] = 1;
			tx_0_data[0] = 0x85;
			tx_0_data[1] = 0x00;
			tx_0_data[2] = 0x02;
			tx_0_data[3] = 0x0f;
			tx_0_data[4] = 0x01;
			tx_0_data[5] = 0x97;
		 	R_UART0_Send(tx_0_data,6);
		 }
		 if(vga1_det == 0xffff)
		 	vga1_det = 0;
	    }else if(vga1_det == pre_vga1_det){
		  vga1_state = 0;
		  if(vga1_state != pre_vga1_state){
			pre_vga1_state = vga1_state;
			//debug_gpio[1] = 0;
	    	tx_0_data[0] = 0x85;
			tx_0_data[1] = 0x00;
			tx_0_data[2] = 0x02;
			tx_0_data[3] = 0x0f;
			tx_0_data[4] = 0x00;
			tx_0_data[5] = 0x96;
		 	R_UART0_Send(tx_0_data,6);
		    }
	    }
	    
    timer1 = 0;
    }
    if(timer2 == 15){
    	if(Uart0Alive >Pre_Uart0Alive){
		if(Uart0Alive == 0xffff){
		    Uart0Alive = 0;
		    Pre_Uart0Alive = 0;
		}
	    	Pre_Uart0Alive = Uart0Alive;
	    }else{
	    	r_uart0_reset();
	    }
	 timer2 = 0;
    }

	if(g_uart1_rx_count > 0x06)
	{
	    r_uart1_header_init();
        if(rx_1_data[6] == 0x55 && rx_1_data[7] == 0x00 && rx_1_data[8] == 0x81 )
        {
            switch(rx_1_data[9])
                {
                    case 0x05: 
                        updata_comflag = 1;
                        break;
                    default:
                        break;
        	}
        }
	    R_UART0_Send(rx_1_data,g_uart1_rx_count);
	    r_uart1_reset();
    }
	
	
	if(g_uart2_rx_count > 0x06){
	    r_uart2_header_init();
	    R_UART0_Send(rx_2_data,g_uart2_rx_count);
	    r_uart2_reset();
	}
    
    pre_pin13_state = pin13_state;
    pin13_state = P7.0;
    if(pre_pin13_state != pin13_state){
    	tx_0_data[0] = 0x85;
	tx_0_data[1] = 0x00;
	tx_0_data[2] = 0x02;
	tx_0_data[3] = 0x0d;
	tx_0_data[4] = pin13_state;
	tx_0_data[5] = 0x94+tx_0_data[4];
	R_UART0_Send(tx_0_data,6);
    }
    
    pre_pin25_state = pin25_state;
    pin25_state = P14.7;
    if(pre_pin25_state != pin25_state){
    	tx_0_data[0] = 0x85;
	tx_0_data[1] = 0x00;
	tx_0_data[2] = 0x02;
	tx_0_data[3] = 0x19;
	tx_0_data[4] = pin25_state;
	tx_0_data[5] = 0xA0+tx_0_data[4];
	R_UART0_Send(tx_0_data,6);
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
