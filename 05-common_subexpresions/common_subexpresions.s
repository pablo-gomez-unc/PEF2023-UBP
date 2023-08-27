	.file	"common_subexpresions.cpp"
	.text
	.p2align 4
	.globl	_Z7computeddddd
	.type	_Z7computeddddd, @function
_Z7computeddddd:
.LFB0:
	.cfi_startproc
	endbr64
	addsd	%xmm0, %xmm1
	mulsd	%xmm1, %xmm2
	mulsd	.LC0(%rip), %xmm1
	subsd	%xmm1, %xmm2
	movapd	%xmm2, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	_Z7computeddddd, .-_Z7computeddddd
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1071644672
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
