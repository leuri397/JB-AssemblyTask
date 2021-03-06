.globl lineFinder
lineFinder: 
	push %rcx
	push %rdx
	push %r8
	xor %rcx, %rcx
	xor %rdx, %rdx
	xor %r9, %r9
	xor %r10, %r10
	
	width_loop:
		xor %rcx, %rcx
		height_loop:
			mov 8(%rsp), %rax
			mov 16(%rsp), %rbx
			call get_element
			cmp $0, %rax
			jne continue
			mov 8(%rsp), %rax
			mov (%rsp), %rbx
			mov 16(%rsp), %r8
			call follow_line
			cmp %r10, %rax
			jl continue
			mov %rax, %r10
		continue:
			inc %rcx
			cmp 8(%rsp), %rcx
			jl height_loop
	
		inc %rdx
		cmp  (%rsp), %rdx
		jl width_loop
	
	mov %r10, %rax
	add $24, %rsp
	ret
	
	
// rcx, rdx - iterators for position
// rax - width
// rbx - address
// rax - result
get_element:
	push %rdx
	mul %rdx
	pop %rdx
	add %rcx, %rax
	add %rax, %rbx
	xor %rax, %rax
	movb (%rbx), %al
	ret
	
	
// rcx, rdx - start position
// rax - width
// rbx - height
// r8 - address
// rax - result	
follow_line:
	push %rdx
	push %rax
	push %rbx
	push %r8
	mov $0, %r9
	cmp 8(%rsp), %rdx
	jge finish
	
	downloop:
		mov (%rsp), %rbx
		mov 16(%rsp), %rax
		call get_element
		cmp $0, %rax
		jne finish
		inc %r9

		inc %rdx
		cmp 8(%rsp), %rdx
	jl downloop
	
	finish:
	add $24, %rsp
	pop %rdx
	mov %r9, %rax
		ret
	

	