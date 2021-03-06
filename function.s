.globl lineFinder
/*
//stack:
//	0 : height
//	8 : width
//	16 : array pointer
*/
lineFinder: 
	push %rcx
	push %rdx
	push %r8
	
	xor %rcx, %rcx
	xor %rdx, %rdx
	xor %r9, %r9
// rcx - horisontal iteration
// rdx - vertical iteration
width_loop:
	xor %rcx, %rcx
height_loop:
	call get_element
	add %rax, %r9

	inc %rcx
	cmp 8(%rsp), %rcx
	jl height_loop
	
	inc %rdx
	cmp  (%rsp), %rdx
	jl width_loop
	
	mov %r9, %rax
	
	add $24, %rsp
	ret
// rcx, rdx - iterators for position
// rax - result
get_element:
	push %rbx
	xor %rax, %rax
	mov 32(%rsp), %rbx
	mov 24(%rsp), %rax
	push %rdx
	mul %rdx
	pop %rdx
	add %rcx, %rax
	add %rax, %rbx
	xor %rax, %rax
	movb (%rbx), %al
	pop %rbx
	ret
	

	