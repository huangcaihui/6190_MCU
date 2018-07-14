; 78K0R C Compiler V2.72 Assembler Source        Date:19 Apr 2016 Time:17:59:19

; Command   : -cf100le -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile src\flash\r_fsl_praxis01_flash_main.c -oDefa
;             ultBuild -_msgoff -nq -iinc -zpsf -mm -zz02000h -zt02000h -mi0 -x
;             DefaultBuild -g2
; In-file   : src\flash\r_fsl_praxis01_flash_main.c
; Asm-file  : DefaultBuild\r_fsl_praxis01_flash_main.asm
; Para-file : 

$PROCESSOR(F100LE)
$DEBUG
$NODEBUGA
$KANJICODE SJIS
$TOL_INF	03FH, 0272H, 02H, 04200H, 02000H, 02000H, 00H

$DGS	FIL_NAM, .file,		058H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_fsl_praxis01_flash_main.c
$DGS	MOD_NAM, r_fsl_praxis01_flash_main,	00H,	0FFFEH,	00H,	077H,	00H,	00H
$DGS	SEC_NAM, @EBITS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, FLAS_CNN,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @ER_INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EINIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, FLAS_DAT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @ER_INIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EINIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EDATS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, FLAS_CNF,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @ERLINIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EINITL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EDATAL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @ECALT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @ECODE,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, FLAS_COD,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EBASE,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @EXT00,	U,	U,	00H,	078H,	00H,	00H
$DGS	STA_SYM, _prFcubSendMsgData,	U,	U,	0D00CH,	03H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	01FH,	01FH,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _main,		U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	032H,	01H,	00H
$DGS	BEG_FUN, ??bf_main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 074H,		06H,	01CH
$DGS	AUT_VAR, _dubLed2flag,	05H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _duw_i,	00H,	0FFFFH,	0FH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	01EH
$DGS	BEG_BLK, ??bb01_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	022H
$DGS	END_BLK, ??eb01_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 011H
$DGS	BEG_BLK, ??bb02_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 012H,		00H,	026H
$DGS	END_BLK, ??eb02_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 016H
$DGS	BEG_BLK, ??bb03_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01AH,		00H,	02AH
$DGS	END_BLK, ??eb03_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01CH
$DGS	BEG_BLK, ??bb04_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01EH,		00H,	00H
$DGS	END_BLK, ??eb04_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 024H
$DGS	END_BLK, ??eb00_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 025H
$DGS	END_FUN, ??ef_main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 028H
$DGS	GLV_SYM, _prFlashTargetStart,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	038H,	01H,	00H
$DGS	BEG_FUN, ??bf_prFlashTargetStart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A9H,		00H,	038H
$DGS	END_FUN, ??ef_prFlashTargetStart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 015H
$DGS	GLV_SYM, _prFlashTargetEnd,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	042H,	01H,	00H
$DGS	BEG_FUN, ??bf_prFlashTargetEnd,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0CBH,		00H,	03CH
$DGS	BEG_BLK, ??bb00_prFlashTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb00_prFlashTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	END_FUN, ??ef_prFlashTargetEnd,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	GLV_SYM, _prSendMsgAsciiData,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	057H,	01H,	00H
$DGS	BEG_FUN, ??bf_prSendMsgAsciiData,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0E0H,		08H,	049H
$DGS	AUT_VAR, _duh_i,	06H,	0FFFFH,	0DH,	01H,	00H,	00H
$DGS	AUT_VAR, _dubSendData,	01H,	0FFFFH,	0CH,	01H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	05H,	05H,	00H,	00H,	00H,	00H
$DGS	BEG_BLK, ??bb00_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	04DH
$DGS	END_BLK, ??eb00_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb01_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FH,		00H,	051H
$DGS	END_BLK, ??eb01_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 011H
$DGS	BEG_BLK, ??bb02_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01CH,		00H,	00H
$DGS	END_BLK, ??eb02_prSendMsgAsciiData,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01EH
$DGS	END_FUN, ??ef_prSendMsgAsciiData,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 02CH
$DGS	IDE_FUN, @prSendMsgAsciiData,	00H,	00H,	00H,	07DH,	00H,	00H
$DGS	GLV_SYM, _prDuwLedTime,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _prDuhSwNum,	U,	U,	0DH,	026H,	00H,	00H
$DGS	GLV_SYM, _prWait10clcok,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _prUartInit,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _prDubBootMode,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _prUartSendData,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, @@divuw,	U,	U,	00H,	02H,	00H,	00H

	EXTRN	_prWait10clcok
	EXTRN	_prUartInit
	EXTRN	_prDubBootMode
	EXTRN	_prUartSendData
	EXTRN	@@divuw
	PUBLIC	_prDuwLedTime
	PUBLIC	_prDuhSwNum
	PUBLIC	_main
	PUBLIC	_prFlashTargetStart
	PUBLIC	_prFlashTargetEnd
	PUBLIC	_prSendMsgAsciiData

@EBITS	BSEG

FLAS_CNN	CSEG	MIRRORP

@ER_INIT	CSEG	UNIT64KP
	DW	0FFFFH,00000H	; 65535
	DW	00H	; 0

@EINIT	DSEG	BASEP
_prDuwLedTime:	DS	(4)
_prDuhSwNum:	DS	(2)

FLAS_DAT	DSEG	BASEP

@ER_INIS	CSEG	UNIT64KP

@EINIS	DSEG	SADDRP

@EDATS	DSEG	SADDRP

FLAS_CNF	CSEG	PAGE64KP
_prFcubSendMsgData:	DB	'Test=Ver.1.00'
	DB	0AH
	DB	0DH
	DB	'OCD test mode'
	DB	0AH
	DB	0DH
	DB	00H
	DB	(1)

@ERLINIT	CSEG	UNIT64KP

@EINITL	DSEG	UNIT64KP

@EDATAL	DSEG	UNIT64KP

@ECALT	CSEG

; line    47
; line    48
; line    49
; line    50
; line    51
; line    52
; line    53
; line   254
; line   257
; line   258
; line   259
; line   260
; line   261
; line   262
; line   265
; line   271
; line    71
; line    93
; line    94
; line   116

FLAS_COD	CSEG
_main:
$DGL	1,22
	push	hl						;[INF] 1, 1
	subw	sp,#06H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_main:
; line   120
$DGL	0,5
	call	!!_prFlashTargetStart				;[INF] 4, 3
; line   121
$DGL	0,6
	mov	[hl+5],#01H	; dubLed2flag,1 		;[INF] 3, 1
; line   124
?L0003:
; line   125
??bb00_main:
; line   127
$DGL	0,12
	mov	a,[hl+5]	; dubLed2flag 			;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0005						;[INF] 2, 4
; line   128
??bb01_main:
; line   129
$DGL	0,14
	mov	[hl+5],#01H	; dubLed2flag,1 		;[INF] 3, 1
; line   130
$DGL	0,15
	clr1	P6.3						;[INF] 3, 2
; line   131
$DGL	0,16
	set1	P6.2						;[INF] 3, 2
??eb01_main:
; line   133
$DGL	0,18
	br	$?L0006						;[INF] 2, 3
?L0005:
??bb02_main:
; line   134
$DGL	0,19
	mov	[hl+5],#00H	; dubLed2flag,0 		;[INF] 3, 1
; line   135
$DGL	0,20
	set1	P6.3						;[INF] 3, 2
??eb02_main:
; line   137
?L0006:
; line   140
$DGL	0,25
	clrw	ax						;[INF] 1, 1
	movw	[hl],ax	; duw_i 				;[INF] 1, 1
	movw	[hl+2],ax	; duw_i 			;[INF] 2, 1
?L0007:
	movw	ax,[hl+2]	; duw_i 			;[INF] 2, 1
	cmpw	ax,!_prDuwLedTime+2				;[INF] 3, 1
	movw	ax,[hl]	; duw_i 				;[INF] 1, 1
	sknz							;[INF] 2, 1
	cmpw	ax,!_prDuwLedTime				;[INF] 3, 1
?L0010:
	bnc	$?L0008						;[INF] 2, 4
; line   141
??bb03_main:
; line   142
$DGL	0,27
	call	!!_prWait10clcok				;[INF] 4, 3
??eb03_main:
; line   143
$DGL	0,28
?L0009:
	incw	[hl+0]	; duw_i 				;[INF] 3, 2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,[hl+0]	; duw_i 			;[INF] 3, 1
	sknz							;[INF] 2, 1
	incw	[hl+2]	; duw_i 				;[INF] 3, 2
?L0011:
	br	$?L0007						;[INF] 2, 3
?L0008:
; line   144
$DGL	0,29
	bf	P13.7,$$+8					;[INF] 4, 5
	br	!!?L0012					;[INF] 4, 3
; line   145
??bb04_main:
; line   146
$DGL	0,31
?L0014:
	bt	P13.7,$?L0015					;[INF] 4, 5
	br	$?L0014						;[INF] 2, 3
?L0015:
; line   147
$DGL	0,33
	 EXTRN _@cstart
$DGL	0,34
	 BR	!!_@cstart
??eb04_main:
; line   151
?L0012:
?L0013:
??eb00_main:
; line   152
$DGL	0,37
	br	!!?L0003					;[INF] 4, 3
?L0004:
; line   154
$DGL	0,39
	call	!!_prFlashTargetEnd				;[INF] 4, 3
; line   155
$DGL	0,40
??ef_main:
	addw	sp,#06H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_main:
; line   169
_prFlashTargetStart:
$DGL	1,50
??bf_prFlashTargetStart:
; line   173
$DGL	0,5
	clr1	P6.2						;[INF] 3, 2
; line   178
$DGL	0,10
	call	!!_prUartInit					;[INF] 4, 3
; line   183
$DGL	0,15
	mov	!_prDubBootMode,#02H	; 2 			;[INF] 4, 1
; line   189
$DGL	0,21
??ef_prFlashTargetStart:
	ei							;[INF] 3, 4
	ret							;[INF] 1, 6
??ee_prFlashTargetStart:
; line   203
_prFlashTargetEnd:
$DGL	1,56
??bf_prFlashTargetEnd:
; line   204
?L0020:
; line   205
??bb00_prFlashTargetEnd:
; line   206
$DGL	0,4
	nop							;[INF] 1, 1
; line   207
$DGL	0,5
	nop							;[INF] 1, 1
??eb00_prFlashTargetEnd:
; line   208
$DGL	0,6
	br	$?L0020						;[INF] 2, 3
?L0021:
; line   209
$DGL	0,7
??ef_prFlashTargetEnd:
	ret							;[INF] 1, 6
??ee_prFlashTargetEnd:
; line   224
_prSendMsgAsciiData:
$DGL	1,66
	push	hl						;[INF] 1, 1
	subw	sp,#08H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_prSendMsgAsciiData:
; line   229
$DGL	0,6
	clrw	ax						;[INF] 1, 1
	movw	[hl+6],ax	; duh_i 			;[INF] 2, 1
?L0024:
	movw	ax,[hl+6]	; duh_i 			;[INF] 2, 1
	cmpw	ax,#01FH	; 31 				;[INF] 3, 1
	bnc	$?L0025						;[INF] 2, 4
; line   230
??bb00_prSendMsgAsciiData:
; line   231
$DGL	0,8
	movw	ax,[hl+6]	; duh_i 			;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	mov	ES,#highw (_prFcubSendMsgData)			;[INF] 2, 1
	mov	a,ES:_prFcubSendMsgData[bc]			;[INF] 4, 2
	mov	[hl+1],a	; dubSendData 			;[INF] 2, 1
; line   232
$DGL	0,9
	movw	ax,hl						;[INF] 1, 1
	incw	ax						;[INF] 1, 1
	call	!!_prUartSendData				;[INF] 4, 3
??eb00_prSendMsgAsciiData:
; line   233
$DGL	0,10
?L0026:
	incw	[hl+6]	; duh_i 				;[INF] 3, 2
	br	$?L0024						;[INF] 2, 3
?L0025:
; line   236
$DGL	0,13
	incw	!_prDuhSwNum					;[INF] 3, 2
; line   237
$DGL	0,14
	movw	ax,!_prDuhSwNum					;[INF] 3, 1
	cmpw	ax,#03E8H	; 1000 				;[INF] 3, 1
	bc	$?L0027						;[INF] 2, 4
; line   238
??bb01_prSendMsgAsciiData:
; line   239
$DGL	0,16
	clrw	ax						;[INF] 1, 1
	movw	!_prDuhSwNum,ax					;[INF] 3, 1
??eb01_prSendMsgAsciiData:
; line   240
?L0027:
?L0028:
; line   243
$DGL	0,20
	movw	ax,!_prDuhSwNum					;[INF] 3, 1
	mov	c,#064H	; 100 					;[INF] 2, 1
	call	!!@@divuw					;[INF] 4, 3
	mov	a,x						;[INF] 1, 1
	or	a,#030H	; 48 					;[INF] 2, 1
	mov	[hl+1],a	; dubSendData 			;[INF] 2, 1
; line   244
$DGL	0,21
	movw	ax,!_prDuhSwNum					;[INF] 3, 1
	mov	c,#064H	; 100 					;[INF] 2, 1
	call	!!@@divuw					;[INF] 4, 3
	movw	ax,bc						;[INF] 1, 1
	clrb	a						;[INF] 1, 1
	mov	c,#0AH	; 10 					;[INF] 2, 1
	call	!!@@divuw					;[INF] 4, 3
	mov	a,x						;[INF] 1, 1
	or	a,#030H	; 48 					;[INF] 2, 1
	mov	[hl+2],a	; dubSendData 			;[INF] 2, 1
; line   245
$DGL	0,22
	movw	ax,!_prDuhSwNum					;[INF] 3, 1
	mov	c,#0AH	; 10 					;[INF] 2, 1
	call	!!@@divuw					;[INF] 4, 3
	movw	ax,bc						;[INF] 1, 1
	clrb	a						;[INF] 1, 1
	mov	a,x						;[INF] 1, 1
	or	a,#030H	; 48 					;[INF] 2, 1
	mov	[hl+3],a	; dubSendData 			;[INF] 2, 1
; line   246
$DGL	0,23
	mov	[hl+4],#0AH	; dubSendData,10 		;[INF] 3, 1
; line   247
$DGL	0,24
	mov	[hl+5],#0DH	; dubSendData,13 		;[INF] 3, 1
; line   250
$DGL	0,27
	clrw	ax						;[INF] 1, 1
	movw	[hl+6],ax	; duh_i 			;[INF] 2, 1
?L0029:
	movw	ax,[hl+6]	; duh_i 			;[INF] 2, 1
	cmpw	ax,#05H	; 5 					;[INF] 3, 1
	bnc	$?L0030						;[INF] 2, 4
; line   251
??bb02_prSendMsgAsciiData:
; line   252
$DGL	0,29
	movw	ax,[hl+6]	; duh_i 			;[INF] 2, 1
	addw	ax,hl						;[INF] 1, 1
	incw	ax						;[INF] 1, 1
	call	!!_prUartSendData				;[INF] 4, 3
??eb02_prSendMsgAsciiData:
; line   253
$DGL	0,30
?L0031:
	incw	[hl+6]	; duh_i 				;[INF] 3, 2
	br	$?L0029						;[INF] 2, 3
?L0030:
; line   267
$DGL	0,44
??ef_prSendMsgAsciiData:
	addw	sp,#08H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_prSendMsgAsciiData:

@EXT00	CSEG	AT    02100H
	br	!!_prSendMsgAsciiData

@ECODE	CSEG	BASE

@EBASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE F:\A&F group\RL78\RL78 Bootloader\G13bootlead_V10\G13_FSL_EXAMPLE\r01an
;	0718_praxis01\src\flash\r_fsl_praxis01_flash_main.c
;
; $FUNC main(116)
;	void=(void)
;	CODE SIZE= 96 bytes, CLOCK_SIZE= 79 clocks, STACK_SIZE= 12 bytes
;
; $CALL prFlashTargetStart(120)
;	void=(void)
;
; $CALL prWait10clcok(142)
;	void=(void)
;
; $CALL prFlashTargetEnd(154)
;	void=(void)
;
; $FUNC prFlashTargetStart(169)
;	void=(void)
;	CODE SIZE= 15 bytes, CLOCK_SIZE= 16 clocks, STACK_SIZE= 4 bytes
;
; $CALL prUartInit(178)
;	void=(void)
;
; $FUNC prFlashTargetEnd(203)
;	void=(void)
;	CODE SIZE= 5 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 0 bytes
;
; $FUNC prSendMsgAsciiData(224)
;	void=(void)
;	CODE SIZE= 138 bytes, CLOCK_SIZE= 98 clocks, STACK_SIZE= 14 bytes
;
; $CALL prUartSendData(232)
;	void=(pointer:ax)
;
; $CALL prUartSendData(252)
;	void=(pointer:ax)

; Target chip : R5F100LE
; Device file : V1.14 
