typedef float f32;

typedef struct {
    int unk0;   
    int unk4;
    int unk8;
    void* unkC; 
    char padding[0x28 - 0x10];
} lbl_80459278_struct;

extern f32 func_8026B1D4(int);
extern lbl_80459278_struct lbl_80459278;
extern unsigned int lbl_804D6558;
extern f32 lbl_804D82E0;

f32 func_8007BBCC(struct _HSD_GObj *) {
    f32 var_f31 = lbl_804D82E0;
    if (lbl_804D6558 != 0) {
        lbl_80459278_struct* var_r31 = (lbl_80459278_struct*)&lbl_80459278;
        unsigned int var_r30 = 0;
        while (var_r30 < lbl_804D6558) {
            int temp_r0 = var_r31->unk0;
            switch (temp_r0) {
            case 1: {
                void* temp_r4 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                    var_f31 += *(f32*)((char*)temp_r4 + 0x0C);
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
            }
            var_r31 = (lbl_80459278_struct*)((char*)var_r31 + 0x28);
            var_r30++;
        }
    }
    return var_f31;
}
