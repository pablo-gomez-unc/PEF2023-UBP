	.file	"array-triad.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1565:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1565:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Tamanio array: "
.LC3:
	.string	" - "
.LC4:
	.string	"Tiempo: "
.LC5:
	.string	" ms"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2715:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movl	$4, 20(%rsp)
	movl	$1000, 16(%rsp)
.L12:
	movslq	16(%rsp), %rbp
	movq	%rbp, %r15
	salq	$2, %rbp
	movq	%rbp, %rdi
	subl	$1, %r15d
	call	_Znam@PLT
	movq	%rbp, %rdi
	movq	%rax, %r14
	movq	%rax, 8(%rsp)
	call	_Znam@PLT
	movq	%rbp, %rdi
	movq	%r14, %r12
	movq	%rax, %rbx
	call	_Znam@PLT
	movq	%rbp, %rdi
	movq	%rax, %r13
	call	_Znam@PLT
	leaq	0(,%r15,4), %rcx
	movq	%rcx, (%rsp)
	movq	%rax, %rbp
	leaq	4(%r14,%rcx), %r15
.L4:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	addq	$4, %r14
	cvtsi2ssl	%eax, %xmm0
	mulss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%r14)
	cmpq	%r15, %r14
	jne	.L4
	movq	(%rsp), %rax
	movq	%rbx, %rcx
	movq	%rbx, 24(%rsp)
	movq	%r12, %r14
	movq	%rbp, %r12
	movq	%rcx, %rbp
	leaq	4(%rbx,%rax), %rax
	movq	%rax, %rbx
.L5:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	addq	$4, %rbp
	cvtsi2ssl	%eax, %xmm0
	mulss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	cmpq	%rbx, %rbp
	jne	.L5
	movq	(%rsp), %rax
	movq	%r12, %rbp
	movq	%rbp, %r12
	movq	%r13, %rbp
	leaq	4(%r13,%rax), %rax
	movq	%rax, %rbx
.L6:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	addq	$4, %rbp
	cvtsi2ssl	%eax, %xmm0
	mulss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	cmpq	%rbp, %rbx
	jne	.L6
	movq	(%rsp), %rax
	movq	24(%rsp), %rbx
	movq	%r12, %rbp
	movq	%rbp, %r12
	leaq	4(%rbp,%rax), %rax
	movq	%rbx, (%rsp)
	movq	%rax, %rbx
.L7:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	addq	$4, %rbp
	cvtsi2ssl	%eax, %xmm0
	mulss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	cmpq	%rbp, %rbx
	jne	.L7
	movq	(%rsp), %rbx
	movq	%r12, %rbp
	movq	%r14, %r12
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, %r14
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movss	0(%r13,%rax), %xmm0
	mulss	0(%rbp,%rax), %xmm0
	addq	$4, %r12
	addss	(%rbx,%rax), %xmm0
	addq	$4, %rax
	movss	%xmm0, -4(%r12)
	cmpq	%r15, %r12
	jne	.L8
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	pxor	%xmm0, %xmm0
	movl	$15, %edx
	leaq	.LC2(%rip), %rsi
	subq	%r14, %rax
	leaq	_ZSt4cout(%rip), %rdi
	leaq	_ZSt4cout(%rip), %r14
	cvtsi2sdq	%rax, %xmm0
	mulsd	.LC1(%rip), %xmm0
	movsd	%xmm0, (%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r14), %rax
	movl	16(%rsp), %esi
	movq	%r14, %rdi
	movq	-24(%rax), %rax
	movq	$10, 16(%r14,%rax)
	call	_ZNSolsEi@PLT
	movl	$3, %edx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.LC4(%rip), %rsi
	movq	%r14, %rdi
	movl	$8, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r14), %rax
	movsd	(%rsp), %xmm0
	movq	%r14, %rdi
	movq	-24(%rax), %rdx
	movq	$10, 16(%r14,%rdx)
	movq	-24(%rax), %rdx
	addq	%r14, %rdx
	movl	24(%rdx), %eax
	movq	$2, 8(%rdx)
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$3, %edx
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r14), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r14
	testq	%r14, %r14
	je	.L21
	cmpb	$0, 56(%r14)
	je	.L10
	movsbl	67(%r14), %esi
.L11:
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	8(%rsp), %rdi
	call	_ZdaPv@PLT
	movq	%rbx, %rdi
	call	_ZdaPv@PLT
	movq	%r13, %rdi
	call	_ZdaPv@PLT
	movq	%rbp, %rdi
	call	_ZdaPv@PLT
	movl	16(%rsp), %eax
	subl	$1, 20(%rsp)
	leal	(%rax,%rax,4), %ebx
	leal	(%rbx,%rbx), %eax
	movl	%eax, 16(%rsp)
	jne	.L12
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	movq	%r14, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r14), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L11
	movq	%r14, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L11
.L21:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE2715:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB3268:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE3268:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	805306368
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	-1598689907
	.long	1051772663
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
