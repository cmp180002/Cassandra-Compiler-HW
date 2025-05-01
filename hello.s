#
# Data section
#
	.section	.rodata
.SC0:
	.string	"Arg val is: %d\n"
.SC1:
	.string	"\nPrinting a pattern\n"
.SC2:
	.string	"*"
.SC3:
	.string	"\n"
.SC4:
	.string	"arr[%d]=%d\n"
.SC5:
	.string	"array sum = %d\n"
.SC6:
	.string	"Enter value for x: \n"
.SC7:
	.string	"x is over 100!\n"
.SC8:
	.string	"x is 100 or less!\n"
.SC9:
	.string	"hello"
.SC10:
	.string	"goodbye"
.SC11:
	.string	"Enter starting array value: \n"
.SC12:
	.string	"Program done.\n"
	.comm	x, 4, 4
	.comm	ynotused, 4, 4
	.comm	arr, 800, 32

#
# Code section
#
	.text
	.globl	makePattern
makePattern:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$128, %rsp
	movq	%rbx, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	leaq	.SC0(%rip), %rax
	mov		%rax, %rdi
	movl	-32(%rbp), %eax
	mov		%rax, %rsi
	call	printf@PLT
	movq	%rax, %rdx
	leaq	.SC1(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
LL100:
	movl	x(%rip), %eax
	pushq	%rax
	movl	$0, %eax
	popq	%rcx
	cmpl	%eax, %ecx
	je		LL101
	movl	$0, %eax
	movl	%eax, -40(%rbp)
LL102:
	movl	-40(%rbp), %eax
	pushq	%rax
	movl	x(%rip), %eax
	popq	%rcx
	cmpl	%eax, %ecx
	jge		LL103
	leaq	.SC2(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	movl	-40(%rbp), %eax
	pushq	%rax
	movl	$1, %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -40(%rbp)
	jmp		LL102
LL103:
	leaq	.SC3(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	movl	$1, %eax
	pushq	%rax
	movl	x(%rip), %eax
	popq	%rcx
	subl	%ecx, %eax
	movl	%eax, x(%rip)
	jmp		LL100
LL101:
	movq	-8(%rbp), %rbx
	leave
	ret

	.globl	arrayFun
arrayFun:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$128, %rsp
	movq	%rbx, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movl	$0, %eax
	movl	%eax, -32(%rbp)
LL104:
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	-16(%rbp), %eax
	popq	%rcx
	cmpl	%eax, %ecx
	jge		LL105
	movl	-24(%rbp), %eax
	pushq	%rbx
	pushq	%rax
	movl	-24(%rbp), %eax
	cltq
	leaq	arr(%rip), %rcx
	popq	%rbx
	movl	%ebx, 0(%rcx,%rax,4)
	movl	-24(%rbp), %eax
	pushq	%rax
	movl	$1, %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -24(%rbp)
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	$1, %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -32(%rbp)
	jmp		LL104
LL105:
	movl	$0, %eax
	movl	%eax, -32(%rbp)
LL106:
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	-16(%rbp), %eax
	popq	%rcx
	cmpl	%eax, %ecx
	jge		LL107
	leaq	.SC4(%rip), %rax
	mov		%rax, %rdi
	movl	-32(%rbp), %eax
	mov		%rax, %rsi
	movl	-32(%rbp), %eax
	cltq
	leaq	arr(%rip), %rcx
	movl	0(%rcx,%rax,4), %eax
	mov		%rax, %rdx
	call	printf@PLT
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	$1, %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -32(%rbp)
	jmp		LL106
LL107:
	movl	$0, %eax
	movl	%eax, -32(%rbp)
	movl	$0, %eax
	movl	%eax, -40(%rbp)
LL108:
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	-16(%rbp), %eax
	popq	%rcx
	cmpl	%eax, %ecx
	jge		LL109
	movl	-40(%rbp), %eax
	pushq	%rax
	movl	-32(%rbp), %eax
	cltq
	leaq	arr(%rip), %rcx
	movl	0(%rcx,%rax,4), %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -40(%rbp)
	movl	-32(%rbp), %eax
	pushq	%rax
	movl	$1, %eax
	popq	%rcx
	addl	%ecx, %eax
	movl	%eax, -32(%rbp)
	jmp		LL108
LL109:
	leaq	.SC5(%rip), %rax
	mov		%rax, %rdi
	movl	-40(%rbp), %eax
	mov		%rax, %rsi
	call	printf@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rbx
	leave
	ret

	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.SC6(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	call	readInt@PLT
	movq	%rax, %rdx
	movq	%rdx, %rax
	movl	%eax, x(%rip)
	movl	x(%rip), %eax
	pushq	%rax
	movl	$100, %eax
	popq	%rcx
	cmpl	%eax, %ecx
	jle		LL110
	leaq	.SC7(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	jmp		LL111
LL110:
	leaq	.SC8(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
LL111:
	leaq	.SC9(%rip), %rax
	mov		%rax, %rdi
	leaq	.SC10(%rip), %rax
	mov		%rax, %rsi
	movl	$42, %eax
	mov		%rax, %rdx
	call	makePattern@PLT
	movq	%rax, %rdx
	leaq	.SC11(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	call	readInt@PLT
	movq	%rax, %rdx
	movq	%rdx, %rax
	movl	%eax, x(%rip)
	movl	$20, %eax
	mov		%rax, %rdi
	movl	x(%rip), %eax
	mov		%rax, %rsi
	call	arrayFun@PLT
	movq	%rax, %rdx
	leaq	.SC12(%rip), %rax
	mov		%rax, %rdi
	call	printf@PLT
	movq	%rax, %rdx
	movl	$0, %eax
	leave
	ret
	.section	.note.GNU-stack,"",@progbits
#
# Library function readInt()
	.section	.rodata
.LC0:	.string	"%d"
	.text
	.globl	readInt
	.type	readInt, @function
readInt:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	leaq	-12(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	scanf@PLT
	movl	-12(%rbp), %eax
	leave
	ret

