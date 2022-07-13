	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p0"
	.file	"20.c"
	.section	.sdata,"aw",@progbits
	.p2align	3                               # -- Begin function foo
.LCPI0_0:
	.quad	0x4000000000000000              # double 2
	.text
	.globl	foo
	.p2align	1
	.type	foo,@function
foo:                                    # @foo
# %bb.0:
	addi	sp, sp, -112
	sd	ra, 104(sp)                     # 8-byte Folded Spill
	sd	s0, 96(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 112
	ld	t0, 16(s0)
	ld	t1, 8(s0)
	ld	t2, 0(s0)
	sw	a0, -20(s0)
	sw	a1, -24(s0)
	sw	a2, -28(s0)
	sw	a3, -32(s0)
	fsd	fa0, -40(s0)
	fsd	fa1, -48(s0)
	fsd	fa2, -56(s0)
	fsd	fa3, -64(s0)
	sw	a4, -68(s0)
	sw	a5, -72(s0)
	sw	a6, -76(s0)
	sw	a7, -80(s0)
	sw	t2, -84(s0)
	sw	t1, -88(s0)
	sw	t0, -92(s0)
	fld	ft0, -40(s0)
	lui	a0, %hi(.LCPI0_0)
	fld	ft1, %lo(.LCPI0_0)(a0)
	fadd.d	ft0, ft0, ft1
	fsd	ft0, -104(s0)
	fmv.d.x	fa0, zero
	ld	ra, 104(sp)                     # 8-byte Folded Reload
	ld	s0, 96(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 112
	ret
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo
                                        # -- End function
	.globl	foo1                            # -- Begin function foo1
	.p2align	1
	.type	foo1,@function
foo1:                                   # @foo1
# %bb.0:
	addi	sp, sp, -48
	sd	ra, 40(sp)                      # 8-byte Folded Spill
	sd	s0, 32(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 48
	sw	a0, -20(s0)
	sw	a1, -24(s0)
	fsd	fa0, -32(s0)
	lw	a0, -20(s0)
	addiw	a0, a0, 2
	sw	a0, -36(s0)
	lw	a0, -36(s0)
	addiw	a0, a0, 1
	ld	ra, 40(sp)                      # 8-byte Folded Reload
	ld	s0, 32(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 48
	ret
.Lfunc_end1:
	.size	foo1, .Lfunc_end1-foo1
                                        # -- End function
	.section	.sdata,"aw",@progbits
	.p2align	3                               # -- Begin function double_array_vector_add
.LCPI2_0:
	.quad	0x4000000000000000              # double 2
.LCPI2_1:
	.quad	0x4008000000000000              # double 3
.LCPI2_2:
	.quad	0x4010000000000000              # double 4
	.text
	.globl	double_array_vector_add
	.p2align	1
	.type	double_array_vector_add,@function
double_array_vector_add:                # @double_array_vector_add
# %bb.0:
	addi	sp, sp, -96
	sd	ra, 88(sp)                      # 8-byte Folded Spill
	sd	s0, 80(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 96
	lui	a0, %hi(double_array_a)
	addi	a0, a0, %lo(double_array_a)
	fld	ft0, 8(a0)
	lui	a0, %hi(double_array_b)
	addi	a0, a0, %lo(double_array_b)
	fld	ft1, 8(a0)
	fadd.d	ft0, ft0, ft1
	fld	ft1, 16(a0)
	fadd.d	ft0, ft0, ft1
	fld	ft1, 24(a0)
	fadd.d	ft0, ft0, ft1
	fld	ft1, 32(a0)
	fadd.d	ft0, ft0, ft1
	fsd	ft0, -56(s0)
	fld	fa0, -24(s0)
	li	a0, 14
	sd	a0, 16(sp)
	li	a0, 13
	sd	a0, 8(sp)
	li	a0, 12
	sd	a0, 0(sp)
	lui	a0, %hi(.LCPI2_0)
	fld	fa1, %lo(.LCPI2_0)(a0)
	lui	a0, %hi(.LCPI2_1)
	fld	fa2, %lo(.LCPI2_1)(a0)
	lui	a0, %hi(.LCPI2_2)
	fld	fa3, %lo(.LCPI2_2)(a0)
	li	a0, 2
	li	a1, 3
	li	a2, 4
	li	a3, 5
	li	a4, 8
	li	a5, 9
	li	a6, 10
	li	a7, 11
	call	foo
	ld	ra, 88(sp)                      # 8-byte Folded Reload
	ld	s0, 80(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 96
	ret
.Lfunc_end2:
	.size	double_array_vector_add, .Lfunc_end2-double_array_vector_add
                                        # -- End function
	.globl	foo2                            # -- Begin function foo2
	.p2align	1
	.type	foo2,@function
foo2:                                   # @foo2
# %bb.0:
	addi	sp, sp, -32
	sd	ra, 24(sp)                      # 8-byte Folded Spill
	sd	s0, 16(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 32
	sw	a0, -20(s0)
	ld	ra, 24(sp)                      # 8-byte Folded Reload
	ld	s0, 16(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 32
	ret
.Lfunc_end3:
	.size	foo2, .Lfunc_end3-foo2
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	1
	.type	main,@function
main:                                   # @main
# %bb.0:
	addi	sp, sp, -96
	sd	ra, 88(sp)                      # 8-byte Folded Spill
	sd	s0, 80(sp)                      # 8-byte Folded Spill
	addi	s0, sp, 96
	sw	zero, -20(s0)
	lui	a0, %hi(.L__const.main.fffddd)
	addi	a1, a0, %lo(.L__const.main.fffddd)
	lw	a2, 16(a1)
	sw	a2, -24(s0)
	lwu	a2, 8(a1)
	lwu	a3, 12(a1)
	slli	a3, a3, 32
	or	a2, a2, a3
	sd	a2, -32(s0)
	lwu	a0, %lo(.L__const.main.fffddd)(a0)
	lwu	a1, 4(a1)
	slli	a1, a1, 32
	or	a0, a0, a1
	sd	a0, -40(s0)
	sd	zero, -48(s0)
	sd	zero, -56(s0)
	sd	zero, -64(s0)
	sd	zero, -72(s0)
	sd	zero, -80(s0)
	li	a0, 1
	sw	a0, -80(s0)
	sw	a0, -76(s0)
	lw	a0, -40(s0)
	sw	a0, -84(s0)
	li	a0, 0
	ld	ra, 88(sp)                      # 8-byte Folded Reload
	ld	s0, 80(sp)                      # 8-byte Folded Reload
	addi	sp, sp, 96
	ret
.Lfunc_end4:
	.size	main, .Lfunc_end4-main
                                        # -- End function
	.type	double_array_a,@object          # @double_array_a
	.data
	.globl	double_array_a
	.p2align	3
double_array_a:
	.quad	0x3ff3333333333333              # double 1.2
	.quad	0x4002666666666666              # double 2.2999999999999998
	.quad	0x400b333333333333              # double 3.3999999999999999
	.quad	0x4012000000000000              # double 4.5
	.quad	0x4016666666666666              # double 5.5999999999999996
	.quad	0x401acccccccccccd              # double 6.7000000000000002
	.size	double_array_a, 48

	.type	double_array_b,@object          # @double_array_b
	.section	.rodata,"a",@progbits
	.globl	double_array_b
	.p2align	3
double_array_b:
	.quad	0x401f333333333333              # double 7.7999999999999998
	.quad	0x4021cccccccccccd              # double 8.9000000000000004
	.quad	0x4022333333333333              # double 9.0999999999999996
	.quad	0x4024666666666666              # double 10.199999999999999
	.quad	0x402699999999999a              # double 11.300000000000001
	.quad	0x0000000000000000              # double 0
	.size	double_array_b, 48

	.type	n,@object                       # @n
	.globl	n
	.p2align	2
n:
	.word	6                               # 0x6
	.size	n, 4

	.type	.L__const.main.fffddd,@object   # @__const.main.fffddd
	.p2align	2
.L__const.main.fffddd:
	.word	2                               # 0x2
	.word	3                               # 0x3
	.word	0                               # 0x0
	.word	0                               # 0x0
	.word	0                               # 0x0
	.size	.L__const.main.fffddd, 20

	.type	ffloat,@object                  # @ffloat
	.section	.sbss,"aw",@nobits
	.globl	ffloat
	.p2align	2
ffloat:
	.word	0x00000000                      # float 0
	.size	ffloat, 4

	.ident	"clang version 15.0.0 (https://mirrors.tuna.tsinghua.edu.cn/git/llvm-project.git/ 8717b492dfcd12d6387543a2f8322e0cf9059982)"
	.section	".note.GNU-stack","",@progbits
