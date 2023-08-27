	.file	"strength_reduction.cpp"
	.text
	.globl	_Z9divido_32j
	.type	_Z9divido_32j, @function
_Z9divido_32j:
.LFB0:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	shrl	$5, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z9divido_32j, .-_Z9divido_32j
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
