	.file   "01_print_float.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16

.text
.align   1
.globl   main
.type    main, @function
main:
#frame size: 32
        addi  sp, sp, -32
        sd    ra, 24(sp)
        sd    s0, 16(sp)
        addi  s0, sp, 32
        sd     a0, -16(sp)
        sd     a1, -8(sp)
        li     a0, 1
        call   print_bool
        li     a1, 0
        sw     a0, -20(s0)
        mv     a0, a1
        ld     a1, -8(sp)
        ld    ra, 24(sp)
        ld    s0, 16(sp)
        addi  sp, sp, 32
        jr    ra
        .size    main,  .-main
