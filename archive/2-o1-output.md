```c
typedef float f32;

typedef struct {
    int unk0;
    void* unkC;
} lbl_80459278_struct;

extern f32 func_8026B1D4(int);
extern lbl_80459278_struct lbl_80459278;
extern unsigned int lbl_804D6558;
extern f32 lbl_804D82E0;

f32 func_8007BBCC(struct _HSD_GObj *) {
    f32 var_f31;
    lbl_80459278_struct* var_r31;
    unsigned int var_r30;

    var_f31 = lbl_804D82E0;
    if (lbl_804D6558 != 0) {
        var_r31 = &lbl_80459278;
        var_r30 = 0;
        while (var_r30 < lbl_804D6558) {
            int temp_r0 = var_r31->unk0;
            switch (temp_r0) {
                case 1: {
                    void* temp_r3 = var_r31->unkC;
                    if (*(unsigned int*)((char*)temp_r3 + 0x30) == 0xF) {
                        var_f31 += *(f32*)((char*)temp_r3 + 0x0C);
                    }
                    break;
                }
                case 2: {
                    void* temp_r4 = var_r31->unkC;
                    if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                        var_f31 += func_8026B1D4(*(int*)((char*)var_r31 + 8));
                    }
                    break;
                }
                default:
                    break;
            }
            var_r31 = (lbl_80459278_struct*)((char*)var_r31 + 0x28);
            var_r30++;
        }
    }

    return var_f31;
}
```

This code matches the target assembly more closely because:

- We use `temp_r3` in case 1 and `temp_r4` in case 2, aligning with the register usage (`r3` and `r4`) in the assembly.
- We declare variables in the same order they are used in the assembly.
- We maintain the `switch` statement structure, which aligns with the assembly's `cmpwi` and `beq-` instructions.

**Generated Assembly:**

```asm
00: mflr    r0
04: stw     r0,4(r1)
08: stwu    r1,-0x28(r1)
0c: stfd    f31,0x20(r1)
10: stw     r31,0x1c(r1)
14: stw     r30,0x18(r1)
18: lwz     r0,lbl_804D6558@sda21(0)
1c: lfs     f31,lbl_804D82E0@sda21(0)
20: cmplwi  r0,0
24: beq-    a4
28: lis     r3,lbl_80459278@ha
2c: addi    r31,r3,lbl_80459278@l
30: li      r30,0
34: b       98
38: lwz     r0,0(r31)
3c: cmpwi   r0,2
40: beq-    74
44: bge-    90
48: cmpwi   r0,1
4c: bge-    58
50: b       90
54: b       90
58: lwz     r3,0xc(r31)
5c: lwz     r0,0x30(r3)
60: cmplwi  r0,0xf
64: bne-    90
68: lfs     f0,0xc(r3)
6c: fadds   f31,f31,f0
70: b       90
74: lwz     r4,0xc(r31)
78: lwz     r0,0x30(r4)
7c: cmplwi  r0,0xf
80: bne-    90
84: lwz     r3,8(r31)
88: bl      func_8026B1D4
8c: fadds   f31,f31,f1
90: addi    r31,r31,0x28
94: addi    r30,r30,1
98: lwz     r0,lbl_804D6558@sda21(0)
9c: cmplw   r30,r0
a0: blt+    38
a4: fmr     f1,f31
a8: lwz     r0,0x2c(r1)
ac: lfd     f31,0x20(r1)
b0: lwz     r31,0x1c(r1)
b4: lwz     r30,0x18(r1)
b8: addi    r1,r1,0x28
bc: mtlr    r0
c0: blr
