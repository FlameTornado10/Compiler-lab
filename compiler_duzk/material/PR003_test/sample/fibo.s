.text
.align   1
.globl   fibonacci
.type    fibonacci, @function
fibonacci:
#frame size: 64
        addi  sp, sp, -64
        sd    ra, 56(sp)
        sd    s0, 48(sp)
        addi  s0, sp, 64
        sd    a0, -72(sp)
        sd    a4, -64(sp)
        sd    s1, -56(sp)
        sd    a3, -48(sp)
        sd    a7, -40(sp)
        sd    a2, -32(sp)
        sd    a1, -24(sp)
        sd    a6, -16(sp)
        sd    a5, -8(sp)
        li     a1, 0
        li     a2, 1
        li     a3, 0
        li     a4, 0
label1:
        slt    a5, a3, a0
        beqz  a5, label2
        addw  a6,a1, a2
        mv     a4, a6
        sw    a0, -20(s0)
        mv     a0, a4
        call  print_int
        lw    a0, -20(s0)
        mv     a1, a2
        mv     a2, a4
        li     a7, 1
        addw  s1,a3, a7
        mv     a3, s1
        j     label1
label2:
        sw    a0, -20(s0)
        mv     a0, a4
        ld    a5, -8(sp)
        ld    a6, -16(sp)
        ld    a1, -24(sp)
        ld    a2, -32(sp)
        ld    a7, -40(sp)
        ld    a3, -48(sp)
        ld    s1, -56(sp)
        ld    a4, -64(sp)
        ld    ra, 56(sp)
        ld    s0, 48(sp)
        addi  sp, sp, 64
        jr    ra
        .size    fibonacci,  .-fibonacci


.text
.align   1
.globl   fibonacci
.type    fibonacci, @function
fibonacci:
#frame size: 64
        addi  sp, sp, -64
        sd    ra, 56(sp)
        sd    s0, 48(sp)
        addi  s0, sp, 64
        li     a1, 0
        li     a2, 1
        li     a3, 0
        li     a4, 0
label1:
        slt    a5, a3, a0
        beqz  a5, label2
        addw  a6,a1, a2
        mv     a4, a6
        sw    a0, -20(s0)
        mv     a0, a4
        call  print_int
        lw    a0, -20(s0)
        mv     a1, a2
        mv     a2, a4
        li     a7, 1
        addw  s1,a3, a7
        mv     a3, s1
        j     label1
label2:
        sw    a0, -20(s0)
        mv     a0, a4
        ld    ra, 56(sp)
        ld    s0, 48(sp)
        addi  sp, sp, 64
        jr    ra
        .size    fibonacci,  .-fibonacci