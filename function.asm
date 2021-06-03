section .text
   global  encode
   global  decode

encode:
	push	rbp 		;init stack 
 	mov	rbp,rsp
 	mov	ax,[rdi] 	;take(rdi) first  parameter in c file  into ax
	push	rsi 		;take(rsi) second value in c file into stack
	mov	cl,[rbp - 8] 	;take value of rsi in to cl  
	ror	ax,cl 		;rotate  right with number of bit in cl
	mov	[r13],ax 	;take value of ax into r13
	mov	rax,r13 	;take value of r13 into rax
	leave 			;free stack 
	ret

	
decode:
 	push    rbp             ;init stack 
        mov     rbp,rsp
        push    rsi             ;take(rsi) second value in c file into stack
        mov     cl,[rbp - 8]    ;take value of rsi in to cl  
        mov     ax,[rdi]        ;take(rdi) first  parameter in c file  into ax
        rol     ax,cl           ;rotate left  with number of bit in cl
        mov     [r13],ax        ;take value of ax into r13
        mov     rax,r13         ;take value of r13 into rax
        leave                   ;free stack 
        ret
	
