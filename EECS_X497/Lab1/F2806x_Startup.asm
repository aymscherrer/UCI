;****************************************************************************************
;* Copyright:  	GoldenMaple Technologies (C) 2013
;* Project:		EECS X497.19 Course Project
;* File Name:	F2806x_Startup.asm
;* Description:	Startup code
;* Language:    TI TMS320F2806x C
;* Arthor:		Louis Zhu
;* Created:		9/20/2013
;* Special Notes:
;*     1 - _code_start is the first code that is executed after	exiting the boot ROM code
;* 	   2 - The codestart section in the linker cmd file is used to physically place
;* 		this code at the correct memory location.  This section should be placed 
;* 		at the location the BOOT ROM will re-direct the code to.  For example, 
;* 		for boot to FLASH this code will be located at 0x3f7ff6. 
;
;* 		In addition, the F2806x projects are setup such that the codegen
;* 		entry point is also set to the _code_start label.  This is done by linker 
;* 		option -e in the project build options.  When the debugger loads the code,
;* 		it will automatically set the PC to the "entry point" address indicated by
;* 		the -e linker option.  In this case the debugger is simply assigning the PC, 
;* 		it is not the same as a full reset of the device. 
;* 
;* 		The compiler may warn that the entry point for the project is other then
;* 		 _c_init00.  _c_init00 is the C environment setup and is run before 
;* 		main() is entered. The _code_start code will re-direct the execution 
;* 		to _c_init00 and thus there is no worry and this warning can be ignored. 
;
;* Mod History: V1.0: Initial version
;****************************************************************************************
 

;****************************************************************************
;* assemble options                                                         *
;****************************************************************************
WD_DISABLE	.set	1		;set to 1 to disable on-chip watchdog, else set to 0
                            

;****************************************************************************
;* external symbol reference                                                *
;****************************************************************************
	.ref _main, cinit

    .global _c_int00

;****************************************************************************
;* Global symbol definition                                                 *
;****************************************************************************
    .def _code_start

;****************************************************************************
;* Declare the stack.  Size is determined by the linker option -stack.  The *
;* default value is 1K words.                                               *
;****************************************************************************
__stack:	.usect	".stack",0,0,1

;****************************************************************************
;*  INITIALIZE RESET VECTOR TO POINT AT _code_start                         *
;****************************************************************************
	.sect .reset
	.long _code_start

;***********************************************************************
;* Function: codestart section
;*
;* Description: Branch to code starting point
;***********************************************************************

    .sect ".codestart"

_code_start:
    .if WD_DISABLE == 1
        LB wd_disable       ;Branch to watchdog disable code
    .else
        LB _c_int00         ;Branch to _c_int00
    .endif

;end codestart section


;***********************************************************************
;* Function: wd_disable
;*
;* Description: Disables the watchdog timer
;***********************************************************************
    .if WD_DISABLE == 1

    .text
wd_disable:
    SETC OBJMODE        ;Set OBJMODE for 28x object code
    EALLOW              ;Enable EALLOW protected register access
    MOVZ DP, #7029h>>6  ;Set data page for WDCR register
    MOV @7029h, #0068h  ;Set WDDIS bit in WDCR to disable WD
    EDIS                ;Disable EALLOW protected register access
    LB _c_int00         ;Branch to start of boot.asm in RTS library

    .endif

;end wd_disable

	.text
;****************************************************************************
;* FUNCTION DEF : _c_int00                                                  *
;*                                                                          *
;****************************************************************************

_c_int00:
;****************************************************************************
;*  INITIALIZE STACK POINTER.                                               *
;****************************************************************************
	MOV SP, #__stack		; set to beginning of stack space

;****************************************************************************
;* INITIALIZE STATUS BIT FIELDS *NOT* INITIALIZED AT RESET                  *
;****************************************************************************
	SPM	0			; set product shift to 0

;****************************************************************************
;* SET C28x MODES                                                           *
;****************************************************************************
    C28OBJ          ; select C28x object mode
    C28ADDR         ; clear the addressing mode
    C28MAP          ; set block M0 and M1 mode

;****************************************************************************
;* SETTING THESE STATUS BITS/REGISTER TO RESET VALUES.  IF YOU RUN          *
;* _c_int00 FROM RESET, YOU CAN REMOVE THIS CODE                            *
;****************************************************************************
	CLRC    PAGE0	; use stack addressing mode
    MOVW    DP, #0	; initialize DP to point at low 64K
	CLRC    OVM     ; turn off overflow mode

	ASP				; ensure SP is aligned

;****************************************************************************
;* Disable Global interrupt INTM and realtime interrupt DBGM                *
;****************************************************************************
    SETC INTM
;    SETC DBGM

;****************************************************************************
;* SET THE EALLOW BIT BEFORE THE CINIT TABLE IS COPIED.                     *
;****************************************************************************
L1:	EALLOW

;****************************************************************************
;*  IF cinit IS NOT -1, PROCESS CINIT INITIALIZATION TABLE	                *
;****************************************************************************
	MOV	AL, #cinit
	MOV	AH, #hi16(cinit)
	ADDB	ACC, #1
	B	CINIT_DONE, EQ		; if cinit < 0 (-1) no init tables

;****************************************************************************
;*  PROCESS CINIT INITIALIZATION TABLE.  TABLE IS IN PROGRAM MEMORY IN THE  *
;*  FOLLOWING FORMAT:                                                       *
;*                                                                          *
;*       .word  <length of init data in words>                              *
;*       .word  or .long <address of variable to initialize>                *
;*       .word  <init data>                                                 *
;*       .word  ...                                                         *
;*                                                                          *
;*  If the variable's address is greater than 65535 (located in 'far'       *
;*  memory), then the address field of the cinit record will be 32-bits     *
;*  instead of the default 16-bits. The length value is negated to tag      *
;*  cinit records for those variables located in far memory.                *
;*                                                                          *
;*  The init table is terminated with a zero length                         *
;*                                                                          *
;****************************************************************************
	MOVL	XAR7, #cinit	; point XAR7 at start of table	
	CLRC    TC		        ; reset TC bit used as far flag 
	B 	START, UNC			; jump to start processing
LOOP:
	MOVB    AH, #0		    ; zero out upper addr bits
	PREAD   AL, *XAR7		; load address of variable to be inited
	ADDB    XAR7, #1		; point to initialization data
    B	GET_DATA, NTC	    ; get data if variable is not far 
	CLRC    TC		        ; reset TC bit used as far flag 
	PREAD   AH, *XAR7	    ; otherwise, get hi bits of 22-bit addr
	ADDB    XAR7, #1
GET_DATA:	
	MOVL	XAR6, ACC	    ; address
	RPT	AR1			        ; repeat length + 1 times
||	PREAD   *XAR6++, *XAR7	; copy data from table to memory
	
	MOVL	ACC, XAR7		; using ACC as temp, point XAR7 to 
	ADD  	ACC, AR1		; next cinit record since PREAD 
	ADDB	ACC, #1			; doesn't change value of XAR7. 
	MOVL	XAR7, ACC	
START:
	PREAD	AL, *XAR7		; load length
	B	GET_ADDR, GEQ	    ; a length < 0 denotes far data	 
    NEG     AL		        ; negate value to get real length	
	SETC    TC		        ; flag that the address field is 32-bits
GET_ADDR:	
	MOVZ	AR1, AL		    ; copy length value to loop register
	NOP			            ; nops required for AR/BANZ pipeline bug
	NOP			            ; in C1 core
    ADDB    XAR7, #1		; point to address field
	BANZ	LOOP, AR1--		; if (length-- != 0) continue 

CINIT_DONE:
;****************************************************************************
;* CLEAR THE EALLOW BIT AFTER THE CINIT TABLE IS COPIED.                    *
;****************************************************************************
    EDIS

;****************************************************************************
;*  CALL USER'S PROGRAM                                                     *
;****************************************************************************
;	add user code here before calling main
L3:
	LCR     _main			; execute main()

L4: B   L4, UNC             ;wait here until watchdog resets
                            ;should main ever returns

	.end
	
;******************************************************
; End of file.
;******************************************************


