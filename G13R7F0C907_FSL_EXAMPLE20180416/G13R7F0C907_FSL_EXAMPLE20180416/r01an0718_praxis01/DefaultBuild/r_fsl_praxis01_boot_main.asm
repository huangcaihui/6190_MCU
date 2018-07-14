; 78K0R C Compiler V2.72 Assembler Source        Date:19 Apr 2016 Time:17:25:25

; Command   : -cf100le -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile src\boot\r_fsl_praxis01_boot_main.c -oDefaul
;             tBuild -_msgoff -qx2 -iinc -iFSLT01_V220_R5F100xE_REN110 -iFSLT01
;             _V220_R5F100xE_REN110\lib -iFSLT01_V220_R5F100xE_REN110\smp -zps 
;             -mm -zz02000h -zt02000h -mi0 -xDefaultBuild -g2
; In-file   : src\boot\r_fsl_praxis01_boot_main.c
; Asm-file  : DefaultBuild\r_fsl_praxis01_boot_main.asm
; Para-file : 

$PROCESSOR(F100LE)
$DEBUG
$NODEBUGA
$KANJICODE SJIS
$TOL_INF	03FH, 0272H, 02H, 04000H, 02000H, 02000H, 00H

$DGS	FIL_NAM, .file,		072H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_fsl_praxis01_boot_main.c
$DGS	MOD_NAM, r_fsl_praxis01_boot_main,	00H,	0FFFEH,	00H,	077H,	00H,	00H
$DGS	SEC_NAM, @@BITS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CNST,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@R_INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, BOOT_DAT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@R_INIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, BOOT_CNS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@RLINIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INITL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATAL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CALT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CODE,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, BOOT_COD,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@BASE,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@VECT04,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@VECT08,	U,	U,	00H,	078H,	00H,	00H
$DGS	GLV_SYM, _hdwinit,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01BH,	01H,	00H
$DGS	BEG_FUN, ??bf_hdwinit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 064H,		00H,	01BH
$DGS	END_FUN, ??ef_hdwinit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0C7H
$DGS	GLV_SYM, _boot_main,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	029H,	01H,	00H
$DGS	BEG_FUN, ??bf_boot_main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 013BH,		06H,	021H
$DGS	AUT_VAR, _buf,		02H,	0FFFFH,	0CH,	01H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	04H,	04H,	00H,	00H,	00H,	00H
$DGS	BEG_BLK, ??bb00_boot_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	00H
$DGS	AUT_VAR, _dubRetCode,	01H,	0FFFFH,	0CH,	01H,	01H,	00H
$DGS	AUX_STR, 00H,		07H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	END_BLK, ??eb00_boot_main,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EH
$DGS	END_FUN, ??ef_boot_main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	GLV_SYM, _UserApp_Main,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02FH,	01H,	00H
$DGS	BEG_FUN, ??bf_UserApp_Main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 014EH,		00H,	02FH
$DGS	END_FUN, ??ef_UserApp_Main,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	GLV_SYM, _prBootTargetStart,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	035H,	01H,	00H
$DGS	BEG_FUN, ??bf_prBootTargetStart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0160H,		00H,	035H
$DGS	END_FUN, ??ef_prBootTargetStart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	GLV_SYM, _prBootTargetEnd,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	05AH,	01H,	00H
$DGS	BEG_FUN, ??bf_prBootTargetEnd,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 017EH,		06H,	03CH
$DGS	FUN_ARG, _dubEndMode,	04H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	AUT_VAR, _duh_i,	02H,	0FFFFH,	0DH,	01H,	00H,	00H
$DGS	AUT_VAR, _dubLed1flag,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	03EH
$DGS	BEG_BLK, ??bb01_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	040H
$DGS	BEG_BLK, ??bb02_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	044H
$DGS	END_BLK, ??eb02_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EH
$DGS	BEG_BLK, ??bb03_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FH,		00H,	048H
$DGS	END_BLK, ??eb03_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	BEG_BLK, ??bb04_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 015H,		00H,	050H
$DGS	END_BLK, ??eb04_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 017H
$DGS	END_BLK, ??eb01_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 018H
$DGS	END_BLK, ??eb00_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 019H
$DGS	BEG_BLK, ??bb05_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01BH,		00H,	052H
$DGS	BEG_BLK, ??bb06_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01FH,		00H,	00H
$DGS	END_BLK, ??eb06_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 022H
$DGS	END_BLK, ??eb05_prBootTargetEnd,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 023H
$DGS	END_FUN, ??ef_prBootTargetEnd,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 024H
$DGS	GLV_SYM, _prWait10clcok,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	060H,	01H,	00H
$DGS	BEG_FUN, ??bf_prWait10clcok,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 01AFH,		00H,	060H
$DGS	END_FUN, ??ef_prWait10clcok,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _prIntComWdt,	U,	U,	0E001H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	066H,	00H,	00H
$DGS	BEG_FUN, ??bf_prIntComWdt,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 01CAH,		00H,	066H
$DGS	END_FUN, ??ef_prIntComWdt,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _prIntComSwIntp0,	U,	U,	0E001H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	070H,	00H,	00H
$DGS	BEG_FUN, ??bf_prIntComSwIntp0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 01DAH,		016H,	06AH
$DGS	BEG_BLK, ??bb00_prIntComSwIntp0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb00_prIntComSwIntp0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	END_FUN, ??ef_prIntComSwIntp0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	STA_SYM, L0005,		?L0005,	U,	05002H,	03H,	00H,	03H
$DGS	IDE_FUN, @prSendMsgAsciiData,	00H,	00H,	00H,	07DH,	00H,	00H
$DGS	GLV_SYM, _prDubBootMode,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _@vect04,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _@vect08,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _prBootWriteProgram,	U,	U,	0CH,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _@RTARG0,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG2,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG4,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, @@lscmp,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGAX,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGDE,	U,	U,	00H,	02H,	00H,	00H

	EXTRN	_prBootWriteProgram
	EXTRN	_@RTARG0
	EXTRN	_@RTARG2
	EXTRN	_@RTARG4
	EXTRN	@@lscmp
	EXTRN	_@SEGAX
	EXTRN	_@SEGDE
	PUBLIC	_prIntComSwIntp0
	PUBLIC	_prIntComWdt
	PUBLIC	_prDubBootMode
	PUBLIC	_hdwinit
	PUBLIC	_boot_main
	PUBLIC	_UserApp_Main
	PUBLIC	_prBootTargetStart
	PUBLIC	_prBootTargetEnd
	PUBLIC	_prWait10clcok
	PUBLIC	_@vect04
	PUBLIC	_@vect08

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP
	DB	00H	; 0
	DB	(1)

@@INIT	DSEG	BASEP
_prDubBootMode:	DS	(1)
	DS	(1)

BOOT_DAT	DSEG	BASEP

@@R_INIS	CSEG	UNIT64KP

@@INIS	DSEG	SADDRP

@@DATS	DSEG	SADDRP

BOOT_CNS	CSEG	PAGE64KP
?L0005:
	DB	031H	; 49
	DB	032H	; 50
	DB	033H	; 51
	DB	034H	; 52

@@RLINIT	CSEG	UNIT64KP

@@INITL	DSEG	UNIT64KP

@@DATAL	DSEG	UNIT64KP

@@CALT	CSEG	CALLT0

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
; line   268
; line    13
; line    14
; line    16
; line    18
; line    19
; line    20
; line    21
; line    22
; line    23
; line    24
; line    25
; line    26
; line    27
; line    28
; line    29
; line    30
; line    31
; line    32
; line    33
; line    35
; line    37
; line    38
; line    39
; line    40
; line    43
; line    45
; line    46
; line    47
; line    48
; line    49
; line    50
; line    51
; line    52
; line    53
; line    54
; line    55
; line    56
; line    57
; line    58
; line    59
; line    60
; line    62
; line    64
; line    65
; line    66
; line    69
; line    71
; line    72
; line    73
; line    74
; line    75
; line    76
; line    77
; line    78
; line    79
; line    80
; line    81
; line    82
; line    83
; line    84
; line    85
; line    86
; line    88
; line    90
; line    91
; line    92
; line    77
; line   100

BOOT_COD	CSEG
_hdwinit:
$DGL	1,21
??bf_hdwinit:
; line   104
$DGL	0,5
	clrb	!LVIM						;[INF] 3, 1
; line   105
$DGL	0,6
	clrb	!LVIS						;[INF] 3, 1
; line   115
$DGL	0,16
	clrb	!CMC						;[INF] 3, 1
; line   143
$DGL	0,44
	mov	CSC,#0C0H	; 192 				;[INF] 3, 1
; line   161
$DGL	0,62
	mov	!OSMC,#080H	; 128 				;[INF] 4, 1
; line   179
$DGL	0,80
	clrb	!CKC						;[INF] 3, 1
; line   210
$DGL	0,111
	clrb	!PER0						;[INF] 3, 1
; line   245
$DGL	0,146
	oneb	!ADPC						;[INF] 3, 1
; line   277
$DGL	0,178
	clr1	P1.1						;[INF] 3, 2
	set1	PM1.1						;[INF] 3, 2
	set1	P1.2						;[INF] 3, 2
	clr1	PM1.2						;[INF] 3, 2
; line   282
$DGL	0,183
	set1	P6.2						;[INF] 3, 2
	clr1	PM6.2						;[INF] 3, 2
	set1	P6.3						;[INF] 3, 2
	clr1	PM6.3						;[INF] 3, 2
; line   287
$DGL	0,188
	clr1	EGP0.0						;[INF] 3, 2
	set1	EGN0.0						;[INF] 3, 2
	clr1	PR00L.2						;[INF] 3, 2
	set1	PR10L.2						;[INF] 3, 2
	clr1	IF0L.2						;[INF] 3, 2
	clr1	MK0L.2						;[INF] 3, 2
; line   297
$DGL	0,198
	clr1	MK0L.0						;[INF] 3, 2
	mov	WDTE,#0ACH	; 172 				;[INF] 3, 1
; line   298
$DGL	0,199
??ef_hdwinit:
	ret							;[INF] 1, 6
??ee_hdwinit:
; line   315
_boot_main:
$DGL	1,27
	push	hl						;[INF] 1, 1
	subw	sp,#06H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_boot_main:
; line   316
$DGL	0,2
	push	hl						;[INF] 1, 1
	movw	ax,hl						;[INF] 1, 1
	addw	ax,#02H						;[INF] 3, 1
	movw	hl,ax						;[INF] 1, 1
	clrw	bc						;[INF] 1, 1
	mov	ES,#highw (?L0005)				;[INF] 2, 1
?L0006:
	mov	a,ES:?L0005[bc]					;[INF] 4, 2
	mov	[hl],a						;[INF] 1, 1
	incw	bc						;[INF] 1, 1
	incw	hl						;[INF] 1, 1
	mov	a,#04H	; 4 					;[INF] 2, 1
	cmp	a,c						;[INF] 2, 1
	bnz	$?L0006						;[INF] 2, 4
	pop	hl						;[INF] 1, 1
; line   319
$DGL	0,5
	bf	P13.7,$?L0007					;[INF] 4, 5
; line   320
??bb00_boot_main:
; line   323
$DGL	0,9
	call	!!_prBootTargetStart				;[INF] 4, 3
; line   325
$DGL	0,11
	call	!!_prBootWriteProgram				;[INF] 4, 3
	mov	a,c						;[INF] 1, 1
	mov	[hl+1],a	; dubRetCode 			;[INF] 2, 1
; line   327
$DGL	0,13
	shrw	ax,8						;[INF] 2, 1
	call	!!_prBootTargetEnd				;[INF] 4, 3
??eb00_boot_main:
; line   328
?L0007:
; line   332
$DGL	0,18
??ef_boot_main:
	addw	sp,#06H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_boot_main:
; line   334
_UserApp_Main:
$DGL	1,41
??bf_UserApp_Main:
; line   335
$DGL	0,3
 EXTRN _@cstarte
$DGL	0,4
 BR	!_@cstarte
$DGL	0,5
 ; Br  !_@cstarte
; line   340
$DGL	0,7
??ef_UserApp_Main:
	ret							;[INF] 1, 6
??ee_UserApp_Main:
; line   352
_prBootTargetStart:
$DGL	1,47
??bf_prBootTargetStart:
; line   356
$DGL	0,5
	clr1	P6.3						;[INF] 3, 2
; line   361
$DGL	0,10
	oneb	!_prDubBootMode					;[INF] 3, 1
; line   367
$DGL	0,16
??ef_prBootTargetStart:
	ei							;[INF] 3, 4
	ret							;[INF] 1, 6
??ee_prBootTargetStart:
; line   382
_prBootTargetEnd:
$DGL	1,53
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	subw	sp,#04H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_prBootTargetEnd:
; line   384
$DGL	0,3
	mov	[hl+1],#00H	; dubLed1flag,0 		;[INF] 3, 1
; line   387
$DGL	0,6
	mov	a,[hl+4]	; dubEndMode 			;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0015						;[INF] 2, 4
; line   388
??bb00_prBootTargetEnd:
; line   389
?L0017:
; line   390
??bb01_prBootTargetEnd:
; line   391
$DGL	0,10
	mov	a,[hl+1]	; dubLed1flag 			;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0019						;[INF] 2, 4
; line   392
??bb02_prBootTargetEnd:
; line   393
$DGL	0,12
	mov	[hl+1],#01H	; dubLed1flag,1 		;[INF] 3, 1
; line   394
$DGL	0,13
	clr1	P6.2						;[INF] 3, 2
??eb02_prBootTargetEnd:
; line   396
$DGL	0,15
	br	$?L0020						;[INF] 2, 3
?L0019:
??bb03_prBootTargetEnd:
; line   397
$DGL	0,16
	mov	[hl+1],#00H	; dubLed1flag,0 		;[INF] 3, 1
; line   398
$DGL	0,17
	set1	P6.2						;[INF] 3, 2
??eb03_prBootTargetEnd:
; line   399
?L0020:
; line   401
$DGL	0,20
	clrw	ax						;[INF] 1, 1
	movw	[hl+2],ax	; duh_i 			;[INF] 2, 1
?L0021:
	movw	ax,[hl+2]	; duh_i 			;[INF] 2, 1
	movw	_@RTARG0,ax					;[INF] 2, 1
	clrw	ax						;[INF] 1, 1
	movw	_@RTARG2,ax					;[INF] 2, 1
	movw	_@RTARG4,#0FDE8H	; -536 			;[INF] 4, 1
	call	!@@lscmp					;[INF] 3, 3
	bnc	$?L0017						;[INF] 2, 4
; line   402
??bb04_prBootTargetEnd:
; line   403
$DGL	0,22
	call	!!_prWait10clcok				;[INF] 4, 3
??eb04_prBootTargetEnd:
; line   404
$DGL	0,23
	incw	[hl+2]	; duh_i 				;[INF] 3, 2
	br	$?L0021						;[INF] 2, 3
??eb01_prBootTargetEnd:
; line   405
??eb00_prBootTargetEnd:
; line   408
?L0015:
??bb05_prBootTargetEnd:
; line   409
$DGL	0,28
	clr1	P6.2						;[INF] 3, 2
; line   411
?L0024:
; line   412
??bb06_prBootTargetEnd:
; line   413
$DGL	0,32
	nop							;[INF] 1, 1
; line   414
$DGL	0,33
	nop							;[INF] 1, 1
??eb06_prBootTargetEnd:
; line   415
$DGL	0,34
	br	$?L0024						;[INF] 2, 3
??eb05_prBootTargetEnd:
; line   416
; line   417
$DGL	0,36
??ef_prBootTargetEnd:
	addw	sp,#06H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_prBootTargetEnd:
; line   431
_prWait10clcok:
$DGL	1,90
??bf_prWait10clcok:
; line   432
$DGL	0,2
	nop							;[INF] 1, 1
; line   433
$DGL	0,3
	nop							;[INF] 1, 1
; line   434
$DGL	0,4
	nop							;[INF] 1, 1
; line   435
$DGL	0,5
	nop							;[INF] 1, 1
; line   436
$DGL	0,6
	nop							;[INF] 1, 1
; line   437
$DGL	0,7
	nop							;[INF] 1, 1
; line   438
$DGL	0,8
	nop							;[INF] 1, 1
; line   439
$DGL	0,9
	nop							;[INF] 1, 1
; line   440
$DGL	0,10
	nop							;[INF] 1, 1
; line   441
$DGL	0,11
	nop							;[INF] 1, 1
; line   442
$DGL	0,12
??ef_prWait10clcok:
	ret							;[INF] 1, 6
??ee_prWait10clcok:
; line   458

@@BASE	CSEG	BASE
_prIntComWdt:
$DGL	1,96
??bf_prIntComWdt:
; line   459
$DGL	0,2
	mov	WDTE,#0ACH	; 172 				;[INF] 3, 1
; line   460
$DGL	0,3
??ef_prIntComWdt:
	reti							;[INF] 2, 6
??ee_prIntComWdt:
; line   474
_prIntComSwIntp0:
$DGL	1,102
	push	ax						;[INF] 1, 1
	push	bc						;[INF] 1, 1
	push	de						;[INF] 1, 1
	push	hl						;[INF] 1, 1
	mov	c,#0CH						;[INF] 2, 1
	dec	c						;[INF] 1, 1
	dec	c						;[INF] 1, 1
	movw	ax,_@SEGAX[c]					;[INF] 3, 1
	push	ax						;[INF] 1, 1
	bnz	$$-6						;[INF] 2, 4
	mov	a,ES						;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,CS						;[INF] 2, 1
	push	ax						;[INF] 1, 1
??bf_prIntComSwIntp0:
; line   475
$DGL	0,2
	cmp	!_prDubBootMode,#02H	; 2 			;[INF] 4, 1
	sknz							;[INF] 2, 1
; line   476
??bb00_prIntComSwIntp0:
; line   477
$DGL	0,4
	call	!02100H						;[INF] 3, 3
??eb00_prIntComSwIntp0:
; line   478
?L0032:
; line   479
$DGL	0,6
??ef_prIntComSwIntp0:
	pop	ax						;[INF] 1, 1
	mov	CS,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov	ES,a						;[INF] 2, 1
	movw	de,#_@SEGAX					;[INF] 3, 1
	mov	c,#06H						;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	[de],ax						;[INF] 1, 1
	incw	de						;[INF] 1, 1
	incw	de						;[INF] 1, 1
	dec	c						;[INF] 1, 1
	bnz	$$-5						;[INF] 2, 4
	pop	hl						;[INF] 1, 1
	pop	de						;[INF] 1, 1
	pop	bc						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	reti							;[INF] 2, 6
??ee_prIntComSwIntp0:

@@VECT04	CSEG	AT    0004H
_@vect04:
	DW	_prIntComWdt

@@VECT08	CSEG	AT    0008H
_@vect08:
	DW	_prIntComSwIntp0

@@CODE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE F:\A&F group\RL78\RL78 Bootloader\test\G13_FSL_EXAMPLE\r01an0718_praxis
;	01\src\boot\r_fsl_praxis01_boot_main.c
;
; $FUNC hdwinit(100)
;	void=(void)
;	CODE SIZE= 74 bytes, CLOCK_SIZE= 45 clocks, STACK_SIZE= 0 bytes
;
; $FUNC boot_main(315)
;	void=(void)
;	CODE SIZE= 54 bytes, CLOCK_SIZE= 46 clocks, STACK_SIZE= 12 bytes
;
; $CALL prBootTargetStart(323)
;	void=(void)
;
; $CALL prBootWriteProgram(325)
;	bc=(void)
;
; $CALL prBootTargetEnd(327)
;	void=(int:ax)
;
; $FUNC UserApp_Main(334)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC prBootTargetStart(352)
;	void=(void)
;	CODE SIZE= 10 bytes, CLOCK_SIZE= 13 clocks, STACK_SIZE= 0 bytes
;
; $FUNC prBootTargetEnd(382)
;	void=(unsigned char dubEndMode:x)
;	CODE SIZE= 73 bytes, CLOCK_SIZE= 63 clocks, STACK_SIZE= 12 bytes
;
; $CALL prWait10clcok(403)
;	void=(void)
;
; $FUNC prWait10clcok(431)
;	void=(void)
;	CODE SIZE= 11 bytes, CLOCK_SIZE= 16 clocks, STACK_SIZE= 0 bytes
;
; $FUNC prIntComWdt(458)
;	void=(void)
;	CODE SIZE= 5 bytes, CLOCK_SIZE= 7 clocks, STACK_SIZE= 0 bytes
;
; $FUNC prIntComSwIntp0(474)
;	void=(void)
;	CODE SIZE= 53 bytes, CLOCK_SIZE= 47 clocks, STACK_SIZE= 26 bytes
;
; $CALL prSendMsgAsciiData(477)
;	void=(void)

; Target chip : R5F100LE
; Device file : V1.14 
