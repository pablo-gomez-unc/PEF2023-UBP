	.file	"invariantes_bucles.cpp"
	.text
	.p2align 4
	.globl	_Z7computePfPKfffRfS_ii
	.type	_Z7computePfPKfffRfS_ii, @function
_Z7computePfPKfffRfS_ii:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdx, %r10
	testl	%r9d, %r9d
	jle	.L2
	leaq	4(%rsi), %rdx
	mulss	%xmm1, %xmm0
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L3
	cmpl	$1, %r9d
	je	.L3
	leal	-1(%r9), %eax
	movl	%r9d, %r11d
	cmpl	$2, %eax
	jbe	.L11
	movl	%r9d, %edx
	movaps	%xmm0, %xmm2
	xorl	%eax, %eax
	shrl	$2, %edx
	shufps	$0, %xmm2, %xmm2
	salq	$4, %rdx
	.p2align 4,,10
	.p2align 3
.L5:
	movups	(%rsi,%rax), %xmm1
	addps	%xmm2, %xmm1
	movups	%xmm1, (%rdi,%rax)
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L5
	movl	%r9d, %edx
	andl	$-4, %edx
	movl	%edx, %eax
	cmpl	%edx, %r9d
	je	.L2
	movl	%r9d, %r11d
	subl	%edx, %r11d
	cmpl	$1, %r11d
	je	.L7
.L4:
	movq	(%rsi,%rdx,4), %xmm1
	movaps	%xmm0, %xmm2
	shufps	$0xe0, %xmm2, %xmm2
	addps	%xmm2, %xmm1
	movlps	%xmm1, (%rdi,%rdx,4)
	movl	%r11d, %edx
	andl	$-2, %edx
	addl	%edx, %eax
	cmpl	%edx, %r11d
	je	.L2
.L7:
	cltq
	addss	(%rsi,%rax,4), %xmm0
	movss	%xmm0, (%rdi,%rax,4)
.L2:
	movslq	%r8d, %r8
	movss	(%rcx,%r8,4), %xmm0
	movss	%xmm0, (%r10)
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	movslq	%r9d, %r9
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L9:
	movss	(%rsi,%rax,4), %xmm1
	addss	%xmm0, %xmm1
	movss	%xmm1, (%rdi,%rax,4)
	addq	$1, %rax
	cmpq	%r9, %rax
	jne	.L9
	movslq	%r8d, %r8
	movss	(%rcx,%r8,4), %xmm0
	movss	%xmm0, (%r10)
	ret
.L11:
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L4
	.cfi_endproc
.LFE0:
	.size	_Z7computePfPKfffRfS_ii, .-_Z7computePfPKfffRfS_ii
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
