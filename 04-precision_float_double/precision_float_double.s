	.file	"precision_float_double.cpp"
# GNU C++17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O3 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.p2align 4
	.type	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, @function
_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0:
.LFB2305:
	.cfi_startproc
	pushq	%r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/11/ostream:685:     { return flush(__os.put(__os.widen('\n'))); }
	movq	(%rdi), %rax	# __os_1(D)->_vptr.basic_ostream, __os_1(D)->_vptr.basic_ostream
	movq	-24(%rax), %rax	# MEM[(long int *)_2 + -24B], MEM[(long int *)_2 + -24B]
	movq	240(%rdi,%rax), %r12	# MEM[(const struct __ctype_type * *)_5 + 240B], _14
# /usr/include/c++/11/bits/basic_ios.h:49:       if (!__f)
	testq	%r12, %r12	# _14
	je	.L7	#,
# /usr/include/c++/11/bits/locale_facets.h:877: 	if (_M_widen_ok)
	cmpb	$0, 56(%r12)	#, MEM[(const struct ctype *)_14]._M_widen_ok
	movq	%rdi, %rbp	# tmp99, __os
	je	.L3	#,
# /usr/include/c++/11/bits/locale_facets.h:878: 	  return _M_widen[static_cast<unsigned char>(__c)];
	movsbl	67(%r12), %esi	# MEM[(const struct ctype *)_14]._M_widen[10],
.L4:
# /usr/include/c++/11/ostream:685:     { return flush(__os.put(__os.widen('\n'))); }
	movq	%rbp, %rdi	# __os,
	call	_ZNSo3putEc@PLT	#
# /usr/include/c++/11/ostream:685:     { return flush(__os.put(__os.widen('\n'))); }
	addq	$8, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp	#
	.cfi_def_cfa_offset 16
# /usr/include/c++/11/ostream:685:     { return flush(__os.put(__os.widen('\n'))); }
	movq	%rax, %rdi	# tmp101, _8
# /usr/include/c++/11/ostream:685:     { return flush(__os.put(__os.widen('\n'))); }
	popq	%r12	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/11/ostream:707:     { return __os.flush(); }
	jmp	_ZNSo5flushEv@PLT	#
.L3:
	.cfi_restore_state
# /usr/include/c++/11/bits/locale_facets.h:879: 	this->_M_widen_init();
	movq	%r12, %rdi	# _14,
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT	#
# /usr/include/c++/11/bits/locale_facets.h:880: 	return this->do_widen(__c);
	movq	(%r12), %rax	# MEM[(const struct ctype *)_14].D.38122._vptr.facet, MEM[(const struct ctype *)_14].D.38122._vptr.facet
	movl	$10, %esi	#,
	movq	%r12, %rdi	# _14,
	call	*48(%rax)	# MEM[(int (*) () *)_24 + 48B]
	movsbl	%al, %esi	# tmp100,
	jmp	.L4	#
.L7:
# /usr/include/c++/11/bits/basic_ios.h:50: 	__throw_bad_cast();
	call	_ZSt16__throw_bad_castv@PLT	#
	.cfi_endproc
.LFE2305:
	.size	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, .-_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Precisi\303\263n de float: "
.LC1:
	.string	" d\303\255gitos"
.LC2:
	.string	"Precisi\303\263n de double: "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1812:
	.cfi_startproc
	endbr64	
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movl	$21, %edx	#,
	leaq	.LC0(%rip), %rsi	#, tmp85
	leaq	.LC1(%rip), %r13	#, tmp88
# precision_float_double.cpp:4: int main() {
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	leaq	_ZSt4cout(%rip), %rbp	#, tmp86
	movq	%rbp, %rdi	# tmp86,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# precision_float_double.cpp:21:     std::cout << "Precisión de float: " << floatPrecision << " dígitos" << std::endl;
	movq	%rbp, %rdi	# tmp86,
	movl	$8, %esi	#,
	call	_ZNSolsEi@PLT	#
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movq	%r13, %rsi	# tmp88,
	movl	$9, %edx	#,
# precision_float_double.cpp:21:     std::cout << "Precisión de float: " << floatPrecision << " dígitos" << std::endl;
	movq	%rax, %r12	# tmp94, _11
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movq	%rax, %rdi	# _11,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# /usr/include/c++/11/ostream:113: 	return __pf(*this);
	movq	%r12, %rdi	# _11,
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0	#
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movl	$22, %edx	#,
	movq	%rbp, %rdi	# tmp86,
	leaq	.LC2(%rip), %rsi	#, tmp89
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# precision_float_double.cpp:22:     std::cout << "Precisión de double: " << doublePrecision << " dígitos" << std::endl;
	movq	%rbp, %rdi	# tmp86,
	movl	$16, %esi	#,
	call	_ZNSolsEi@PLT	#
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movq	%r13, %rsi	# tmp88,
	movl	$9, %edx	#,
# precision_float_double.cpp:22:     std::cout << "Precisión de double: " << doublePrecision << " dígitos" << std::endl;
	movq	%rax, %rbp	# tmp95, _13
# /usr/include/c++/11/ostream:616: 	__ostream_insert(__out, __s,
	movq	%rax, %rdi	# _13,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# /usr/include/c++/11/ostream:113: 	return __pf(*this);
	movq	%rbp, %rdi	# _13,
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0	#
# precision_float_double.cpp:25: }
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax	#
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE1812:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2302:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
# /usr/include/c++/11/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rbp	#, tmp82
	movq	%rbp, %rdi	# tmp82,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi	#,
	movq	%rbp, %rsi	# tmp82,
# precision_float_double.cpp:25: }
	popq	%rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/11/iostream:74:   static ios_base::Init __ioinit;
	leaq	__dso_handle(%rip), %rdx	#, tmp83
	jmp	__cxa_atexit@PLT	#
	.cfi_endproc
.LFE2302:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
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
