    .file "setjmp.S"
    .section .text
    .align 1
    .global setjmp
    .type setjmp,@function
setjmp:
    ld.w    4[r6], r1
    stsr    sr5, r1
    ld.w    0[r6], r1
    ld.w    8[r6], r2
    ld.w    12[r6], r3
    ld.w    16[r6], r4
    ld.w    20[r6], r5
    ld.w    24[r6], r6
    ld.w    28[r6], r7
    ld.w    32[r6], r8
    ld.w    36[r6], r9
    ld.w    40[r6], r10
    ld.w    44[r6], r11
    ld.w    48[r6], r12
    ld.w    52[r6], r13
    ld.w    56[r6], r14
    ld.w    60[r6], r15
    ld.w    64[r6], r16
    ld.w    68[r6], r17
    ld.w    72[r6], r18
    ld.w    76[r6], r19
    ld.w    80[r6], r20
    ld.w    84[r6], r21
    ld.w    88[r6], r22
    ld.w    92[r6], r23
    ld.w    96[r6], r24
    ld.w    100[r6], r25
    ld.w    104[r6], r26
    ld.w    108[r6], r27
    ld.w    112[r6], r28
    ld.w    116[r6], r29
    ld.w    120[r6], r30
    ld.w    124[r6], r31
    jmp     [r31]

    .global longjmp
    .type longjmp,@function
longjmp:
    ld.w    0[r6], r1
    ldsr    r1, sr5
    ld.w    4[r6], r1
    ld.w    8[r6], r2
    ld.w    12[r6], r3
    ld.w    16[r6], r4
    ld.w    20[r6], r5
    ld.w    24[r6], r6
    ld.w    28[r6], r7
    ld.w    32[r6], r8
    ld.w    36[r6], r9
    ld.w    40[r6], r10
    ld.w    44[r6], r11
    ld.w    48[r6], r12
    ld.w    52[r6], r13
    ld.w    56[r6], r14
    ld.w    60[r6], r15
    ld.w    64[r6], r16
    ld.w    68[r6], r17
    ld.w    72[r6], r18
    ld.w    76[r6], r19
    ld.w    80[r6], r20
    ld.w    84[r6], r21
    ld.w    88[r6], r22
    ld.w    92[r6], r23
    ld.w    96[r6], r24
    ld.w    100[r6], r25
    ld.w    104[r6], r26
    ld.w    108[r6], r27
    ld.w    112[r6], r28
    ld.w    116[r6], r29
    ld.w    120[r6], r30
    ld.w    124[r6], r31
    cmp     r7, r0
    bne     __fixedcode
    mov     1, r7
__fixedcode:
    mov     r7, r10
    jmp     [r31]
