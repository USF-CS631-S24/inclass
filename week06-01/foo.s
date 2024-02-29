	.file	"foo.c"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	foo
	.type	foo, @function
foo:
	slliw	a0,a0,2
	addw	a0,a0,a1
	ret
	.size	foo, .-foo
	.align	1
	.globl	main
	.type	main, @function
main:
	li	a0,16
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-1ubuntu1~23.04) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
