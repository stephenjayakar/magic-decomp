You are a decompilation and optimization assistant. The provided C code now compiles, but the generated assembly must be made to match a given target assembly as closely as possible.

I will give you:
1. The current C code.
2. Context used to compile the C code.
3. The generated assembly.
4. The target assembly.

I will also be providing a record of all your tries, as well as how close it is. Note that you want to ideally not regress

Your task is to modify the provided C code slightly to minimize or eliminate these differences. Remember that this uses an old compiler, so even small changes can lead to substantial differences in the ASM output. You must maintain the logic of the original code as closely as possible.

Do not include any header files or external dependencies. You also cannot use `asm` directives

# 1. Current C code

```c
typedef float f32;

typedef struct {
    int unk0;    // Presumed structure based on assembly instructions
    void* unkC;  // Presumed component of a struct based on pattern in assembly
} lbl_80459278_struct;

extern f32 func_8026B1D4(int);  
extern lbl_80459278_struct lbl_80459278;
extern unsigned int lbl_804D6558;
extern f32 lbl_804D82E0;

f32 func_8007BBCC(struct _HSD_GObj *) {
    lbl_80459278_struct* var_r31;
    f32 var_f31;
    unsigned int var_r30 = 0;
    int temp_r0;

    var_f31 = lbl_804D82E0;
    if (lbl_804D6558 != 0) {
        var_r31 = &lbl_80459278;
        while (var_r30 < lbl_804D6558) {
            temp_r0 = var_r31->unk0;
            switch (temp_r0) {
            case 1: {
                void* temp_r3 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r3 + 0x30) == 0xF)
                    var_f31 += *(f32*)((char*)temp_r3 + 0x0C);
                break;
            }
            case 2: {
                void* temp_r3 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r3 + 0x30) == 0xF)
                    var_f31 += func_8026B1D4(*(int*)((char*)var_r31 + 8));
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

# 2. Context used to compile the C code

```c
#define FIGHTER_UNK_0x2227 0x8000000
#define ROOT_TEXEDGE (1 << 30)
#define M_PI_2 1.57079632679489655799
#define HSD_A_T_TRAV 3
#define RENDER_NO_ZUPDATE (1 << 29)
#define RENDER_ALPHA_VTX (2 << RENDER_ALPHA_SHIFT)
#define FIGHTER_GFX_PRESERVE 0x2
#define __GXTRANSFORM_H__ 
#define _list_h_ 
#define GX_GM_1_0 0
#define GX_GM_1_7 1
#define FIGHTER_MATANIM_NOUPDATE 0x80
#define HSD_A_T_TEV0_A 19
#define HSD_A_T_TEV0_B 18
#define HSD_A_T_TEV0_G 17
#define HSD_A_T_TEV0_R 16
#define TOBJ_TEV_CA_TEX1_A (0x01 << 6 | 5)
#define _aobj_h_ 
#define TRUE 1
#define GX_FIFO_OBJSIZE 128
#define FIGHTER_METALB_NOUPDATE 0x800000
#define USER_DEF_MTX (1 << 23)
#define RENDER_CONSTANT (1 << 0)
#define TEX_BUMP (0x1 << 24)
#define GX_PF_RGBA6_Z24 1
#define MOBJ_ANIM 0x4
#define HSD_A_M_AMBIENT_B 3
#define HSD_A_M_AMBIENT_G 2
#define HSD_A_M_AMBIENT_R 1
#define GX_MAX_Z24 0x00ffffff
#define HSD_A_FRAC_S8 (3 << 5)
#define HSD_A_FRAC_U8 (4 << 5)
#define M_PI 3.14159265358979323846
#define HSD_A_M_SPECULAR_R 7
#define GX_VA_MAXATTR 26
#define PTCL (1 << 5)
#define GX_PF_RGB8_Z24 0
#define FIGHTER_UNK_0x1000 0x1000
#define SPECULAR (1 << 16)
#define TEX_LIGHTMAP_AMBIENT (0x1 << 6)
#define HSD_OBJECT_INFO(o) (o.parent.parent)
#define TEX_ALPHAMAP_MASK (0x0f << 20)
#define _GXTYPES_h_ 
#define TYPE_ROBJ 1
#define fpclassify(x) ((sizeof(x) == sizeof(float)) ? __fpclassifyf((float)(x)) : __fpclassifyd((double)(x)))
#define MAX_GXLIGHT 9
#define TEX_LIGHTMAP_SHADOW (0x1 << 8)
#define HSD_A_T_LOD_BIAS 11
#define HSD_A_M_PE_REF0 11
#define TOBJ_TEV_CC_KONST_BBB (0x01 << 7 | 3)
#define COLL_AIR 0x8000
#define __asm__(...) 
#define TOBJ_TEVREG_ACTIVE_KONST (TOBJ_TEVREG_ACTIVE_KONST_R | TOBJ_TEVREG_ACTIVE_KONST_G | TOBJ_TEVREG_ACTIVE_KONST_B | TOBJ_TEVREG_ACTIVE_KONST_A)
#define GX_PF_RGB565_Z16 2
#define TEX_COLORMAP_BLEND (3 << 16)
#define RENDER_TEX3 (1 << 7)
#define RENDER_TEX4 (1 << 8)
#define RENDER_TEX5 (1 << 9)
#define RENDER_TEX6 (1 << 10)
#define RENDER_TEX7 (1 << 11)
#define HSD_MOBJ(o) ((HSD_MObj*)(o))
#define TEX_COLORMAP_RGB_MASK (2 << 16)
#define PROJ_ORTHO 3
#define JOBJ_INSTANCE(o) ((o->flags & INSTANCE) == 0)
#define HSD_A_T_BLEND 9
#define GX_ZC_MID 2
#define HSD_DOBJ(o) ((HSD_DObj*)(o))
#define GX_VA_NBT 25
#define TEX_ALPHAMAP_PASS (5 << 20)
#define TOBJ_TEVREG_ACTIVE_TEV1_A (0x01 << 11)
#define TOBJ_TEVREG_ACTIVE_TEV1_B (0x01 << 10)
#define TOBJ_TEVREG_ACTIVE_TEV1_G (0x01 << 9)
#define TOBJ_TEVREG_ACTIVE_TEV1_R (0x01 << 8)
#define SPLINE (1 << 14)
#define TEX_ALPHAMAP_MODULATE (3 << 20)
#define HSD_A_M_DIFFUSE_B 6
#define HSD_A_M_DIFFUSE_G 5
#define _common_structs_h_ 
#define HSD_A_M_DIFFUSE_R 4
#define HSD_A_FRAC_FLOAT (0 << 5)
#define TYPE_JOBJ 12
#define HSD_A_OP_SLP 5
#define TEX_LIGHTMAP_SPECULAR (0x1 << 5)
#define RENDER_DIFFUSE (1 << 2)
#define FIGHTER_HITSTATUS_COLANIM_PRESERVE 0x4
#define FIGHTER_CMD_UPDATE 0x4000
#define HSD_A_OP_SPL 4
#define PBILLBOARD (1 << 13)
#define RENDER_DIFFUSE_BITS (3 << RENDER_DIFFUSE_SHIFT)
#define RENDER_SPECULAR (1 << 3)
#define TEX_LIGHTMAP_DIFFUSE (0x1 << 4)
#define _id_h_ 
#define GX_ZC_FAR 3
#define GROUND 0
#define FIGHTER_UNK_0x100000 0x100000
#define GX_VA_CLR0 11
#define GX_VA_CLR1 12
#define HSD_A_J_SETBYTE0 20
#define HSD_A_J_SETBYTE1 21
#define HSD_A_J_SETBYTE2 22
#define HSD_A_J_SETBYTE3 23
#define HSD_A_J_SETBYTE4 24
#define HSD_A_J_SETBYTE5 25
#define HSD_A_J_SETBYTE6 26
#define HSD_A_J_SETBYTE8 28
#define HSD_A_J_SETBYTE9 29
#define TOBJ_ANIM 0x10
#define RENDER_DIFFUSE_VTX (2 << RENDER_DIFFUSE_SHIFT)
#define RENDER_ALPHA_SHIFT 13
#define HSD_A_OP_LIN 2
#define FIGHTER_RUMBLE_UNK 0x800
#define HSD_A_T_TCLT 10
#define _object_h_ 
#define TEX_ALPHAMAP_NONE (0 << 20)
#define TEX_COLORMAP_MASK (0x0f << 16)
#define SCRIPT(...) {}
#define FIGHTER_PART_HITSTATUS_COLANIM_PRESERVE 0x10000
#define _jobj_h_ 
#define FIGHTER_UNK_0x20 0x20
#define GX_GM_2_2 2
#define HSD_A_T_TEV1_A 23
#define HSD_A_T_TEV1_B 22
#define HSD_A_T_TEV1_G 21
#define HSD_A_T_TEV1_R 20
#define TOBJ_TEVREG_ACTIVE_TEV0 (TOBJ_TEVREG_ACTIVE_TEV0_R | TOBJ_TEVREG_ACTIVE_TEV0_G | TOBJ_TEVREG_ACTIVE_TEV0_B | TOBJ_TEVREG_ACTIVE_TEV0_A)
#define TOBJ_TEVREG_ACTIVE_TEV1 (TOBJ_TEVREG_ACTIVE_TEV1_R | TOBJ_TEVREG_ACTIVE_TEV1_G | TOBJ_TEVREG_ACTIVE_TEV1_B | TOBJ_TEVREG_ACTIVE_TEV1_A)
#define JOBJ_USE_QUATERNION(o) ((o->flags & USE_QUATERNION))
#define HSD_BUTTON_A 0x100
#define HSD_BUTTON_B 0x200
#define HALF_PI64 1.5707963267948966
#define _random_h_ 
#define HSD_TOBJ_METHOD(o) HSD_TOBJ_INFO(HSD_OBJECT_METHOD(o))
#define FIGHTER_UNK_0x1000000 0x1000000
#define HSD_PARENT_INFO(o) ((o)->parent.head.parent)
#define SKELETON_ROOT (1 << 1)
#define HSD_A_M_PE_DSTALPHA 13
#define TEX_ALPHAMAP_ADD (6 << 20)
#define TEX_ALPHAMAP_SUB (7 << 20)
#define _PAD_H_ 
#define GX_VA_TEX6MTXIDX 7
#define TOBJ_TEV_CA_TEX0_A (0x01 << 6 | 4)
#define _fobj_h_ 
#define FIGHTER_UNK_0x200000 0x200000
#define HSD_A_T_TRAU 2
#define AOBJ_LOOP (1 << 29)
#define GX_ZC_NEAR 1
#define __TYPES_H__ 
#define GX_VA_TEX4MTXIDX 5
#define GX_TRUE 1
#define _dobj_h_ 
#define TEX_COLORMAP_PASS (6 << 16)
#define HSD_CLASS_INFO(o) ((HSD_ClassInfo*)o)
#define _gobjuserdata_h_ 
#define ENVELOPE_MODEL (1 << 2)
#define HIDDEN (1 << 4)
#define HSD_A_J_TRAX 5
#define HSD_A_J_TRAY 6
#define HSD_A_J_TRAZ 7
#define GX_VA_TEX2MTXIDX 3
#define HSD_ARCHIVE_DONT_FREE 1
#define TOBJ_TEV_CC_TEX1_RGB (0x01 << 7 | 7)
#define tobj_alphamap(T) ((T)->flags & TEX_ALPHAMAP_MASK)
#define COPY_ATTRS(gobj,attributeName) Fighter* ft = gobj->user_data; attributeName* sA2 = (attributeName*)ft->x2D4_specialAttributes; attributeName* ext_attr = (attributeName*)ft->x10C_ftData->ext_attr; *sA2 = *ext_attr;
#define TEX_ALPHAMAP_ALPHA_MASK (1 << 20)
#define FIGHTER_SKIP_UNK_0x2222 0x80000
#define FIGHTER_UNK_0x40000000 0x40000000
#define FIGHTER_HIT_REFRESH 0x100
#define F3DEX_GBI_2 1
#define GX_VA_TEX0MTXIDX 1
#define FLIP_IK (1 << 15)
#define FIGHTER_HITSTUN_BOOL_PRESERVE 0x10000000
#define HSD_OBJECT_PARENT_INFO(o) ((o)->parent.parent.head.parent)
#define RENDER_DIFFUSE_SHIFT 0
#define M2CTX 1
#define ROOT_XLU (1 << 29)
#define HSD_A_J_NODE 11
#define HSD_MOBJ_INFO(i) ((HSD_MObjInfo*)(i))
#define TOBJ_TEVREG_ACTIVE_ALPHA_TEV (0x01U << 31)
#define GX_VA_TEX0 13
#define GX_VA_TEX1 14
#define GX_VA_TEX2 15
#define GX_VA_TEX3 16
#define GX_VA_TEX4 17
#define GX_VA_TEX5 18
#define GX_VA_TEX6 19
#define GX_VA_TEX7 20
#define CHANNEL_FIELD (RENDER_CONSTANT | RENDER_VERTEX | RENDER_DIFFUSE | RENDER_SPECULAR)
#define union_type_ptcl(o) ((o->flags & PTCL) != 0)
#define GX_FALSE 0
#define RENDER_DIFFUSE_MAT0 (0 << RENDER_DIFFUSE_SHIFT)
#define GX_TEX_MTX_ARRAY 23
#define HSD_A_M_SPECULAR_B 9
#define HSD_A_M_SPECULAR_G 8
#define TOBJ_TEVREG_ACTIVE_TEV0_G (0x01 << 5)
#define TOBJ_TEV_CC_TEX0_RGB (0x01 << 7 | 5)
#define GX_PF_YUV420 7
#define GX_PF_Z24 3
#define TEX_COLORMAP_NONE (0 << 16)
#define TEX_COORD_SHADOW 3
#define PROJ_FRUSTRUM 2
#define INSTANCE (1 << 12)
#define FIGHTER_UNK_HAMMER 0x8
#define TEX_COORD_HILIGHT 2
#define HSD_WOBJ_METHOD(o) HSD_WOBJ_INFO(HSD_OBJECT_METHOD(o))
#define HSD_A_J_SETBYTE7 27
#define PUSH_ATTRS(ft,attributeName) do { void* backup = (ft)->x2D8_specialAttributes2; attributeName *src = (attributeName*)(ft)->x10C_ftData->ext_attr; void* *attr = &(ft)->x2D4_specialAttributes; *(attributeName *)(ft)->x2D8_specialAttributes2 = *src; *attr = backup; } while(0)
#define RENDER_XLU (1 << 30)
#define HSD_A_J_ROTY 2
#define HSD_A_J_ROTZ 3
#define ALL_ANIM 0x7FF
#define HSD_A_M_PE_REF1 12
#define GX_LIGHT_ARRAY 24
#define GX_NRM_MTX_ARRAY 22
#define _MTXTYPES_h_ 
#define SCALE_HEIGHT_ATTRS(num_attrs) { int i; for (i = 0; i < num_attrs; i++) { sA2->height_attributes[i] *= ft->x34_scale.y; } }
#define EFFECTOR (3 << 21)
#define TEX_LIGHTMAP_MASK (TEX_LIGHTMAP_DIFFUSE | TEX_LIGHTMAP_SPECULAR | TEX_LIGHTMAP_AMBIENT | TEX_LIGHTMAP_EXT | TEX_LIGHTMAP_SHADOW)
#define HSD_OBJECT_METHOD(o) (o->parent.parent.class_info)
#define _controller_h_ 
#define SKELETON (1 << 0)
#define _lbvector_h_ 
#define GX_VA_NRM 10
#define TOBJ_TEV_CA_KONST_A (0x01 << 6 | 3)
#define TOBJ_TEV_CA_KONST_B (0x01 << 6 | 2)
#define TOBJ_TEV_CA_KONST_G (0x01 << 6 | 1)
#define TOBJ_TEV_CC_KONST_GGG (0x01 << 7 | 2)
#define RENDER_ALPHA_MAT (1 << RENDER_ALPHA_SHIFT)
#define FIGHTER_UNK_0x400000 0x400000
#define TOBJ_TEV_CA_KONST_R (0x01 << 6 | 0)
#define TOBJ_TEV_CC_KONST_RGB (0x01 << 7 | 0)
#define FIGHTER_UNK_0x40 0x40
#define HSD_GOBJ_USER_DATA_NONE (u8)-1
#define TEX_COORD_UV 0
#define TEX_COORD_MASK (0x0f)
#define RENDER_SHADOW (1 << 26)
#define TEX_ALPHAMAP_BLEND (2 << 20)
#define _fighter_h_ 
#define HSD_A_J_PATH 4
#define TEX_COORD_REFLECTION 1
#define TEX_COLORMAP_MODULATE (4 << 16)
#define HSD_WOBJ_INFO(i) ((HSD_WObjInfo*)(i))
#define FIGHTER_UNK_0x8000 0x8000
#define TOBJ_TEV_CC_KONST_RRR (0x01 << 7 | 1)
#define HSD_A_FRAC_S16 (1 << 5)
#define TEX_ALPHAMAP_REPLACE (4 << 20)
#define RENDER_ALPHA_BOTH (3 << RENDER_ALPHA_SHIFT)
#define HSD_A_OP_NONE 0
#define GX_DISABLE 0
#define _player_h_ 
#define tobj_bump(T) ((T)->flags & TEX_BUMP)
#define GX_VA_NULL 0xff
#define GX_ENABLE 1
#define __MATH_H__ 
#define TEX_COORD_BACKLIGHT 6
#define HSD_TOBJ_INFO(i) ((HSD_TObjInfo*)(i))
#define _stage_h_ 
#define LIGHTING (1 << 7)
#define tobj_colormap(T) ((T)->flags & TEX_COLORMAP_MASK)
#define FIGHTER_UNK_0x80000000 0x80000000
#define MTX_INDEP_SRT (1 << 25)
#define HSD_A_T_SCAV 5
#define __attribute__(...) 
#define TEX_LIGHTMAP_EXT (0x1 << 7)
#define AOBJ_NO_UPDATE (1 << 28)
#define NULL ((void*)0)
#define HSD_A_J_SETFLOAT3 33
#define HSD_A_J_SETFLOAT4 34
#define HSD_A_T_KONST_A 15
#define HSD_A_T_KONST_B 14
#define HSD_A_T_KONST_G 13
#define HSD_A_T_KONST_R 12
#define AIR 1
#define AOBJ_NO_ANIM (1 << 30)
#define HSD_A_FRAC_U16 (2 << 5)
#define TOBJ_TEV_CC_TEX1_AAA (0x01 << 7 | 8)
#define FIGHTER_FASTFALL_PRESERVE 0x1
#define GX_PF_U8 5
#define GX_PF_V8 6
#define JOINT1 (1 << 21)
#define JOINT2 (2 << 21)
#define RENDER_DIFFUSE_MAT (1 << RENDER_DIFFUSE_SHIFT)
#define RENDER_VERTEX (1 << 1)
#define GX_PF_Y8 4
#define HSD_OBJ_NOREF -1
#define FIGHTER_UNK_0x20000 0x20000
#define HSD_DOBJ_INFO(i) ((HSD_DObjInfo*)(i))
#define GX_POS_MTX_ARRAY 21
#define TEX_COLORMAP_REPLACE (5 << 16)
#define _archive_h_ 
#define GX_ZC_LINEAR 0
#define FALSE 0
#define HSD_MOBJ_METHOD(o) HSD_MOBJ_INFO(HSD_CLASS_METHOD(o))
#define RENDER_ZMODE_ALWAYS (1 << 27)
#define _texp_h_ 
#define TEX_MTX_DIRTY (1U << 31)
#define _objalloc_h_ 
#define RENDER_TEX0 (1 << 4)
#define TOBJ_TEV_CC_TEX0_AAA (0x01 << 7 | 6)
#define _mobj_h_ 
#define RENDER_TEX1 (1 << 5)
#define HSD_A_J_BRANCH 12
#define HSD_DOBJ_METHOD(o) HSD_DOBJ_INFO(HSD_CLASS_METHOD(o))
#define _class_h_ 
#define HSD_GOBJ_OBJ_NONE 0xFF
#define _gobjgxlink_h_ 
#define FIGHTER_UNK_0x4000000 0x4000000
#define MTX_INDEP_PARENT (1 << 24)
#define GX_VA_POS 9
#define TEX_COLORMAP_ADD (7 << 16)
#define TEX_COLORMAP_SUB (8 << 16)
#define TEXGEN (1 << 8)
#define FIGHTER_NOCHANGEMODEL 0x10
#define CLASSICAL_SCALE (1 << 3)
#define FIGHTER_UNK_0x2000000 0x2000000
#define tobj_lightmap(T) ((T)->flags & TEX_LIGHTMAP_MASK)
#define HSD_A_M_ALPHA 10
#define tobj_coord(T) ((T)->flags & TEX_COORD_MASK)
#define FIGHTER_HALO_PRESERVE 0x2000
#define AOBJ_FIRST_PLAY (1 << 27)
#define GX_VA_TEX7MTXIDX 8
#define HSD_A_OP_SPL0 3
#define _gobj_h_ 
#define GX_VA_PNMTXIDX 0
#define HSD_A_OP_CON 1
#define next_p(p) (p != NULL ? p->next : NULL)
#define TOBJ_TEVREG_ACTIVE_COLOR_TEV (0x01 << 30)
#define GX_VA_TEX5MTXIDX 6
#define HSD_CLASS_METHOD(o) (((HSD_Class*)o)->class_info)
#define MACRO_ft_OnItemPickup(FTNAME,param1,param2) void FTNAME ##_OnItemPickup(HSD_GObj* fighterObj, BOOL bool) { Fighter *fighter = getFighter(fighterObj); if (!func_8026B2B4(fighter->x1974_heldItem)) { switch (func_8026B320(fighter->x1974_heldItem)) { case 1: func_80070FB4(fighterObj, param1, 1); break; case 2: func_80070FB4(fighterObj, param1, 0); break; case 3: func_80070FB4(fighterObj, param1, 2); break; case 4: func_80070FB4(fighterObj, param1, 3); break; } if (bool) { func_80070C48(fighterObj, param2); } } }
#define TOBJ_TEVREG_ACTIVE_KONST_A (0x01 << 3)
#define TOBJ_TEVREG_ACTIVE_KONST_B (0x01 << 2)
#define TOBJ_TEVREG_ACTIVE_KONST_G (0x01 << 1)
#define TOBJ_TEVREG_ACTIVE_KONST_R (0x01 << 0)
#define TOBJ_TEV_CC_KONST_AAA (0x01 << 7 | 4)
#define FIGHTER_ANIM_NOUPDATE 0x20000000
#define GX_VA_TEX3MTXIDX 4
#define RENDER_TOON (1 << 12)
#define _cobj_h_ 
#define HSD_A_J_SETFLOAT0 30
#define HSD_A_J_SETFLOAT1 31
#define HSD_A_J_SETFLOAT2 32
#define HSD_A_J_SETFLOAT5 35
#define HSD_A_J_SETFLOAT6 36
#define HSD_A_J_SETFLOAT7 37
#define HSD_A_J_SETFLOAT8 38
#define HSD_A_J_SETFLOAT9 39
#define NULL_OBJ (0 << 21)
#define HSD_A_T_SCAU 4
#define TEX_COORD_TOON 4
#define HSD_A_T_ROTX 6
#define HSD_A_T_ROTY 7
#define HSD_A_T_ROTZ 8
#define GX_VA_TEX1MTXIDX 2
#define PROJ_PERSPECTIVE 1
#define TEX_COORD_GRADATION 5
#define HSD_TOBJ(o) ((HSD_TObj*)(o))
#define HSD_A_T_TS_BLEND 24
#define AOBJ_REWINDED (1 << 26)
#define RENDER_TEXTURES (RENDER_TEX0 | RENDER_TEX1 | RENDER_TEX2 | RENDER_TEX3 | RENDER_TEX4 | RENDER_TEX5 | RENDER_TEX6 | RENDER_TEX7)
#define HSD_A_J_SCAX 8
#define HSD_A_J_SCAY 9
#define HSD_A_J_SCAZ 10
#define FIGHTER_SFX_PRESERVE 0x200
#define TOBJ_TEVREG_ACTIVE_TEV0_A (0x01 << 7)
#define TOBJ_TEVREG_ACTIVE_TEV0_B (0x01 << 6)
#define TOBJ_TEVREG_ACTIVE_TEV0_R (0x01 << 4)
#define HSD_A_J_ROTX 1
#define MTX_DIRTY (1 << 6)
#define _LANGUAGE_C 1
#define RENDER_ALPHA_COMPAT (0 << RENDER_ALPHA_SHIFT)
#define _hsd_tobj_h_ 
#define HSD_A_T_TIMG 1
#define FIGHTER_PARASOL_UNK 0x400
#define USE_QUATERNION (1 << 17)
#define FIGHTER_ITEMVIS_NOUPDATE 0x40000
#define _global_h_ 
#define RENDER_ALPHA_BITS (3 << RENDER_ALPHA_SHIFT)
#define _MIPS_SZLONG 32
#define ROOT_OPA (1 << 28)
#define TEX_COLORMAP_ALPHA_MASK (1 << 16)
#define RENDER_TEX2 (1 << 6)
#define assert_line(line,cond) ((cond) ? ((void) 0) : __assert(__FILE__, line, #cond))
#define union_type_dobj(o) ((o->flags & 0x4020) == 0)
#define _functions_h_ 
#define HSD_A_OP_KEY 6
#define FLT_MAX 3.4028235E38
#define RENDER_DIFFUSE_BOTH (3 << RENDER_DIFFUSE_SHIFT)
#define _wobj_h_ 

#define CLIFFCATCH_BOTH 0
#define CLIFFCATCH_LEFT -1
#define CLIFFCATCH_RIGHT 1

#define CLIFFCATCH_O(fp) \
(fp->x2C_facing_direction < 0.0f) ? CLIFFCATCH_LEFT : CLIFFCATCH_RIGHT \

// Ternary macro for fcmpu-based facing direction check

#define CLIFFCATCH_U(fp) \
(fp->x2C_facing_direction != 1.0f) ? CLIFFCATCH_LEFT : CLIFFCATCH_RIGHT \
       
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;
typedef int BOOL;
typedef int intptr_t;
typedef unsigned int uintptr_t;
typedef unsigned long size_t;
typedef struct
{
 f32 x, y, z;
} Vec, *VecPtr, Point3d, *Point3dPtr;
typedef struct
{
    s16 x, y, z;
} S16Vec, *S16VecPtr;
typedef struct
{
    s8 x, y, z;
} S8Vec, *S8VecPtr;
typedef struct
{
    s32 x, y, z;
} S32Vec, *S32VecPtr;
typedef struct
{
 f32 x, y, z, w;
} Quaternion, *QuaternionPtr, Qtrn, *QtrnPtr;
typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];
typedef f32 Mtx44[4][4];
typedef f32 (*Mtx44Ptr)[4];
typedef struct _HSD_GObj HSD_GObj;
typedef struct _Fighter Fighter;
typedef struct _Item Item;
typedef struct _Article Article;
void* HSD_JObjUnkMtxPtr();
s32 func_80008248(s32, struct ftHurt*, void*, f32, f32, f32);
void func_8000B1CC(struct _HSD_JObj*, Vec*, Vec*);
f32 func_8000BDB4(struct _HSD_JObj*);
void func_8000C1C0(struct _HSD_JObj*, struct _HSD_JObj*);
void func_8000C228(struct _HSD_JObj*, struct _HSD_JObj*);
void func_8000C420(struct _HSD_JObj*, u32, f32);
s32 func_8000D148(f32, f32, f32, f32, f32, f32, f32);
void func_8000E9F0(Vec*, s32, f32);
void func_8000ED54();
void func_8000EE8C();
void func_8001044C(void*, void*, s32, f32, s32, s32, s32, s32);
void func_800119DC(Vec*, s32, f32, f32, f32);
void func_80011A50(Vec*, s32, f32, f32, f32, f32, f32, f32, f32);
void func_80014574(u8, s32, s32, s32);
void func_800145C0(u8);
struct _HSD_Archive* func_80015BD0(s32, s32);
void func_80016C64(char*, void**, char*, s32, ...);
void* func_80016DBC(void*, ...);
s32 func_800171CC(void*, ...);
f32 func_8001E8F8(u32);
s32 func_80021C48();
f32 func_someCalcAngle_80022C30(f32, f32);
void func_800236B8(s32);
u32 func_800237A8(u32, u32, u32);
void func_80023F28();
void func_8002438C(s32);
void func_80024B1C(s32, s32);
void func_80024B58(s32, s32);
struct _CameraBox* func_80029020();
void func_800290D4();
void func_8002A278(f32 x, f32 y);
void func_8002E6FC(u8);
void func_8002E948(u32(*)(Vec*));
void func_8002EB5C(f32);
void func_8002EC7C(f32);
void func_8002ED9C(f32);
void func_8002EEC8(f32);
void func_8002EF14(void);
void func_8002F0E4(s32);
s32 func_8002F260(void);
void func_8002F274(void);
void func_8002F474(void);
void* func_80030A50(void);
BOOL func_80030CFC(struct _CameraBox*, f32);
f32 func_80031144();
s32 Player_GetPlayerSlotType(s32);
void func_80037C60();
void func_8003E058(s32, s32, s32, s32);
void func_8003EC9C(s32, s32, f32, f32);
void func_8003FAA8(s32 slot, s32 index, Vec* pos, Vec* prevPos);
void func_8003FE1C();
void func_8003FFDC(u8, s32, u8, s32, s32);
void func_80040048(u8, s32);
void func_80040330();
void func_80040B8C();
void func_800411C4();
void func_80041280();
void func_8004CBF4(struct _CollData*);
s32 func_80051EC8(Vec*, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
void func_80053DA4(u32, f32*);
void func_80053ECC(u32, f32*);
void func_80053FF4(s32, Vec*);
void func_80054158(s32, Vec*);
s32 func_800567C0(s32 , Vec* , Vec* result);
void func_8006737C(s8);
void func_80067624();
void func_80067688(void*);
void efAsync_Spawn(struct _HSD_GObj*, void*, u32, u32, void*, ...);
void Fighter_UnkProcessDeath_80068354(struct _HSD_GObj*);
u32 Fighter_NewSpawn_80068E40();
void Fighter_ActionStateChange_800693AC(struct _HSD_GObj* fighterObj, s32 newAction, s32 flags, struct _HSD_GObj* otherObj, f32 animStart, f32 animSpeed, f32 animBlend);
void func_8006E9B4();
void func_8006EBA4(struct _HSD_GObj*);
void func_8006EBE8(struct _HSD_GObj* fighterObj, f32, f32, f32);
void func_8006F0FC(struct _HSD_GObj* fighterObj, f32);
void ftAnim_SetAnimRate(struct _HSD_GObj*, f32);
BOOL ftAnim_IsFramesRemaining(struct _HSD_GObj*);
void func_8006FE48();
void func_80070308();
void func_800704F0(struct _HSD_GObj*, s32, f32);
void func_80070654();
void func_80070758();
void func_8007077C();
void ftAnim_ApplyPartAnim(struct _HSD_GObj*, s32, s32, f32);
void func_80070C48(struct _HSD_GObj*, s32);
void func_80070CC4(struct _HSD_GObj*, s32);
void func_80070E74();
void func_80070F28();
void func_80070FB4(struct _HSD_GObj*, s32, s32);
s32 func_80070FD0(struct _Fighter*);
void func_80073240();
void func_80073354();
void func_8007349C();
void func_80073758();
void func_80074148();
void func_80074170();
void func_800743E0();
void func_800749CC();
void func_80074A4C(struct _HSD_GObj*, u32, s32);
void func_80074A8C();
void func_80074E58();
s32 func_8007500C(struct _Fighter*, s32);
void func_8007584C();
void func_8007592C(struct _Fighter*, s32, f32);
void func_80075AF0(struct _Fighter*, s32, f32);
void func_80075CB4(struct _Fighter*, s32, f32);
void func_80076064(struct _Fighter*);
void func_800764DC();
void func_80076528(struct _HSD_GObj*);
void func_800765AC();
void func_800765E0();
void func_80078754();
void func_80078A2C();
void func_80078C70();
void func_8007925C();
void func_8007AB48();
void func_8007AB80();
void func_8007ABD0(struct _Hitbox*, u32, struct _HSD_GObj*);
void func_8007AE80();
void func_8007AEE0(struct _HSD_GObj*);
void func_8007AF28(struct _HSD_GObj* fighterObj);
void func_8007AFF8(struct _HSD_GObj*);
void func_8007B0C0(struct _HSD_GObj*, s32);
void func_8007B1B8(struct _HSD_GObj*, f32*, void (*)(struct _HSD_GObj*));
void func_8007B320();
void func_8007B4E0();
void func_8007B62C();
void func_8007B6EC();
void func_8007B760();
void func_8007B8CC();
void func_8007B8E8();
void func_getWindOffsetVec_8007B924(struct _HSD_GObj*, Vec* out_wind);
void func_8007BA0C();
void func_8007BAC0();
f32 func_8007BBCC(struct _HSD_GObj*);
void func_8007BC90();
void func_8007BE3C(struct _HSD_GObj*);
void func_8007C114();
void func_8007C17C(struct _HSD_GObj*);
void func_8007C224();
void func_8007C4BC();
void func_8007C630(struct _HSD_GObj*);
void func_8007C6DC();
void func_8007C77C();
void func_8007C930(struct _Fighter*, f32);
void func_8007CB74(struct _HSD_GObj*);
void func_8007CC78(f32, struct _Fighter*);
void func_8007CCA0(struct _Fighter*, f32);
f32 func_8007CD6C(f32 value, f32 decrement);
f32 func_8007CDA4(struct _Fighter*);
f32 func_8007CDF8(struct _Fighter*);
void func_8007CE4C(struct _Fighter*, f32);
void func_8007CE94(struct _Fighter*, f32);
BOOL func_8007CF58(struct _Fighter*);
void func_8007D344(struct _Fighter*, f32, f32, f32);
void func_8007D494(struct _Fighter*, f32, f32);
void func_8007D4B8(struct _Fighter*);
void func_8007D5BC();
void func_8007D5D4(struct _Fighter*);
void func_8007D6A4(struct _Fighter*);
void func_8007D780(struct _Fighter*);
void func_8007D7FC(struct _Fighter*);
void func_8007D92C(struct _HSD_GObj*);
void func_8007D9FC(struct _Fighter*);
f32 func_8007DA74(s32, u32, f32);
void func_8007DB24();
void func_8007DB58();
void func_8007E0E4();
void func_8007E2A4();
void func_8007E2D0(struct _Fighter*, s16, void (*)(struct _HSD_GObj*), void (*)(struct _HSD_GObj*), void (*)(struct _HSD_GObj*, struct _HSD_GObj*));
void func_8007E2F4(struct _Fighter*, s16);
void func_8007E2FC(struct _HSD_GObj*);
void func_8007E83C(struct _HSD_GObj*, s32, f32 div);
s32 ftGetParasolStatus(struct _HSD_GObj*);
void func_8007EA90(struct _Fighter*, s32);
void func_8007EBAC(struct _Fighter*, u32, u32);
void func_8007ECD4();
void func_8007ED50(struct _Fighter*, s32);
void func_8007EE0C();
void func_8007EFC0(struct _Fighter*, u32);
void func_8007F578();
f32 Fighter_GetModelScale(struct _Fighter*);
void func_8007F8E8();
void func_8007F9B4();
void func_8007FC7C(struct _HSD_GObj*, f32);
void func_8007FE84(struct _HSD_GObj*, struct _HSD_GObj*, s32, f32);
void func_8007FF74();
BOOL func_8007FFD8(struct _Fighter*, f32);
void func_8008021C();
void func_8008031C();
f32 func_800804EC(struct _Fighter*);
void func_800804FC();
void func_80080E18();
void func_80081938(struct _HSD_GObj*);
void func_800819A8();
void func_80081B38(struct _HSD_GObj*);
void func_80081C88(struct _HSD_GObj*, f32);
s32 func_80081D0C(struct _HSD_GObj*);
s32 func_800821DC();
s32 func_8008239C(HSD_GObj*, s32, f32*);
s32 func_80082708(struct _HSD_GObj*);
s32 func_800827A0(struct _HSD_GObj*);
s32 func_80082A68(struct _HSD_GObj*);
void func_80082B1C(struct _HSD_GObj*);
struct _HSD_GObj* func_80082E3C(struct _HSD_GObj*);
void func_800831CC(struct _HSD_GObj*, s32(*)(struct _HSD_GObj*), void (*)(struct _HSD_GObj*));
void func_80083B68(struct _HSD_GObj*);
void func_80083F88(struct _HSD_GObj*);
void func_80084104(struct _HSD_GObj*);
f32 func_80084A40(struct _Fighter*);
void func_80084EEC(struct _HSD_GObj*);
void func_80084F3C(struct _HSD_GObj*);
void func_80084FA8(struct _HSD_GObj*);
void func_80085134(struct _HSD_GObj*);
void func_80085154(struct _HSD_GObj*);
void func_80085204(struct _HSD_GObj*);
void func_800852B0();
void func_8008549C();
void func_800855C8();
void func_8008572C(u32);
void func_8008578C();
void func_800857E0(u32);
void func_80085820();
void func_800859A8();
void func_80085A14(u32);
void func_80085B10();
void func_80085CD8();
u32 func_80085E50(void*, u32);
struct _HSD_GObj* func_8008627C(Vec*, struct _HSD_GObj*);
void func_800866DC(struct _HSD_GObj*, Vec*);
void func_800867E8();
void func_8008688C();
s32 func_80086BE0(struct _HSD_GObj*);
s32 func_80087120(struct _HSD_GObj*);
s32 func_800872A4(struct _HSD_GObj*);
void func_800880D8();
void func_80088148(struct _Fighter*, u32, u32, u32);
void func_800881D8(struct _Fighter*, u32, u32, u32);
void func_80088640();
void func_800887CC();
void func_80088884();
void func_800888E0();
void func_80088A50(struct _Fighter*);
void func_80088C5C();
void func_800890BC(struct _Fighter*);
void func_800890D0();
void func_800892A0(struct _HSD_GObj*);
void func_800892D4(struct _Fighter*);
void func_800895E0();
void func_80089824(struct _HSD_GObj*);
void func_80089B08(struct _HSD_GObj* pPlayerEntityStruct);
void func_8008A2BC(struct _HSD_GObj* gobj);
f32 func_8008D7F0(struct _Fighter*);
void func_8008D930();
void func_8008E908(struct _HSD_GObj*, f32);
s32 func_8008E984(struct _Fighter*);
void func_8008E9D0();
void func_8008EB58();
void func_8008EC90();
void func_80090594();
u32 func_80090690(struct _Fighter*, struct _Vec2*);
void func_80090718();
f32 func_80092ED8(s32, void*, f32);
void func_80095744();
s32 func_800964FC(struct _Fighter*);
void func_800968C8();
void func_80096900(struct _HSD_GObj*, s32, s32, s32, f32, f32);
void func_8009750C(HSD_GObj*);
void func_80098B20();
void func_80098C9C();
void func_80099D9C();
void func_8009A804(struct _HSD_GObj*);
void func_8009CF84();
void func_8009E0A8();
void func_8009E0D4();
void func_8009E7B4();
s32 func_8009EF68(struct _HSD_GObj*);
void func_8009F4A4();
void func_8009F578();
void func_800A0DA4();
void func_800A101C(struct _Fighter*, s8, s8, s32);
f32 func_800A17E4(struct _Fighter*);
f32 func_800A1874(struct _Fighter*);
f32 func_800A1904(struct _Fighter*);
f32 func_800A1948(struct _Fighter*);
s32 func_800A198C(struct _Fighter*);
f32 func_800A1994(struct _Fighter*);
f32 func_800A1A24(struct _Fighter*);
s32 func_800A2040();
void func_800B3900();
void func_800BFD04();
void func_800BFFAC(struct _Fighter*);
void func_800BFFD0(struct _Fighter*, s32, s32);
void func_800C0074(struct _Fighter*);
void func_800C0134();
void func_800C0200();
void func_800C0408();
s32 func_800C0694();
void func_800C09B4(struct _HSD_GObj*);
void func_800C0A98(struct _HSD_GObj* fighterObj);
void func_800C1E64(struct _HSD_GObj* pPlayerEntityStruct, s32, s32, u8, f32);
void func_800C2FD8();
void func_800C37A0();
void func_800C511C();
void func_800C61B0();
void func_800C8064();
void func_800C8348(struct _HSD_GObj*, s32, s32);
void func_800C8438(struct _HSD_GObj*);
void func_800C8540();
void func_800C884C();
void func_800C88A0(struct _Fighter*);
void func_800C89A0(struct _HSD_GObj*);
void func_800C8A64();
s32 func_800C8B2C();
void func_800C8C84();
void func_800C8D00();
void func_800C8F6C();
void func_800C8FC4(struct _HSD_GObj*);
void func_800C9034();
s32 func_800CAE80();
void func_800CC730(struct _HSD_GObj*);
void func_800D0FA0();
void func_800D105C(struct _HSD_GObj*);
void func_800D14E4();
void func_800D1A8C();
void func_800D1E80();
void func_800D237C();
void func_800D3158(struct _HSD_GObj* fighterObj);
void func_800D4F24(struct _HSD_GObj*, s32);
void func_800D5CB0(struct _HSD_GObj*, s32, f32);
s32 func_800D67C4(struct _Fighter*);
s32 func_800D688C(struct _Fighter*);
s32 func_800D6928(struct _Fighter*);
void func_800D71D8();
void func_800D94D8(HSD_GObj*);
void func_800DA824(Fighter*);
void func_800DB368(Fighter*, Fighter*);
void func_800DB464(HSD_GObj*);
void func_800DC750(HSD_GObj*);
void func_800DD168(HSD_GObj*);
void func_800DE2A8(HSD_GObj*, HSD_GObj*);
void func_800DE508(HSD_GObj*);
void func_800DE7C0(struct _HSD_GObj*, s32, s32);
void func_800DEEA8(struct _HSD_GObj* fighterObj);
u32 func_800DEEE8(struct _Fighter*, struct _Vec2*);
void func_800DEF38();
void func_800DF0D0();
void ftCaptain_OnLoadForGanon(struct _Fighter*);
void ftCFalcon_LoadSpecialAttrs(struct _HSD_GObj*);
void ftFox_LoadSpecialAttrs(struct _HSD_GObj*);
void func_800E5EBC(struct _HSD_GObj*);
void func_800EC06C();
void func_800ECD04(HSD_GObj*);
void func_800ECD58(HSD_GObj*);
void func_800EED50(s32, s32);
void func_800F1D24();
void func_800F5BA4();
void func_800F5C34();
void ftNess_ItemNessBatRemove(struct _HSD_GObj*);
void ftNess_YoyoItemDespawn(struct _HSD_GObj*);
void ftNess_ItemPKFlushSetNULL(struct _HSD_GObj*);
void ftNess_SpecialHiTakeDamage(struct _HSD_GObj*);
void ftPikachu_LoadSpecialAttrs(struct _HSD_GObj*);
f32 ftSamus_80128AC8(HSD_GObj* fighterObj, f32 farg1, f32 farg2);
void ftSamus_80128B1C(HSD_GObj*, f32, f32, f32);
void ftMars_OnLoadForRoy(struct _Fighter*);
void ftMars_LoadSpecialAttrs(struct _HSD_GObj*);
void func_80149268(HSD_GObj*);
void func_8014FE10();
void func_8014FE58();
void func_80150144(struct _HSD_GObj*);
void func_80150C8C(struct _HSD_GObj*);
void func_80150D28(struct _HSD_GObj*);
void func_80150DC4(struct _HSD_GObj*, void*, Vec*);
void func_80151018(struct _HSD_GObj* gobj);
void func_801510B0(struct _HSD_GObj*);
void func_80151918(struct _HSD_GObj*);
void func_80151AC8(struct _HSD_GObj*);
void func_80151CA8(struct _HSD_GObj*);
void func_80151EB4(struct _HSD_GObj*);
void func_801520D8(struct _HSD_GObj*);
void func_8015247C(struct _HSD_GObj*);
void func_801525E0(struct _HSD_GObj*);
void func_80152880(struct _HSD_GObj*);
void func_80152CD8(struct _HSD_GObj*);
void func_80152F80(struct _HSD_GObj*);
void func_801530A4(struct _HSD_GObj*);
void func_801533CC(struct _HSD_GObj*);
void func_8015364C(struct _HSD_GObj*, struct _HSD_JObj*, f32, f32);
void func_80153730(struct _HSD_GObj*);
void func_80153820(struct _HSD_GObj*);
void func_80153910(struct _HSD_GObj*);
void func_80153A64(struct _HSD_GObj*);
void func_801541C8(struct _HSD_GObj*, void*);
void func_801542E0(struct _HSD_GObj*);
void func_801545A0(struct _HSD_GObj*);
void func_801546D8(HSD_GObj*);
void func_80154A78(HSD_GObj*);
void func_80154C78(struct _HSD_GObj*);
void func_80154CF8(struct _HSD_GObj*, struct _Fighter*);
void func_80154E78(struct _HSD_GObj*);
void func_80155014(struct _HSD_GObj*);
void func_80155818(HSD_GObj*);
void func_80155B80(struct _HSD_GObj*);
void func_80155D1C(struct _HSD_GObj*);
void func_80155D6C(HSD_GObj*, s32);
void func_80155FCC();
void func_80156014();
void func_8015A2B0(HSD_GObj*);
void func_8015A3F4(HSD_GObj*);
void func_8015BD20(struct _HSD_GObj*);
void func_8015BD24(s32, f32*, f32, s32, s32, s32);
void func_8015BDB4(struct _HSD_GObj*);
void func_8015BE40(struct _HSD_GObj* gobj, Vec*, f32*, f32, f32);
void func_8015BF74(struct _HSD_GObj*, f32);
void func_8015C010(struct _HSD_GObj*, f32);
void func_8015C09C(struct _HSD_GObj*, f32);
void func_8015C190(struct _HSD_GObj*);
void func_8015C208(struct _HSD_GObj*, Vec*);
struct _HSD_GObj* func_8015C244(struct _HSD_GObj*, Vec*);
BOOL func_8015C31C(void);
BOOL func_8015C3A0(void);
struct _HSD_GObj* func_8015C3E8(s32);
s32 func_8015C44C(s32);
s32 func_8015C4C4(void);
void func_8015C5F8(struct _HSD_GObj*);
s8* func_8015CE44(s32, s32);
void func_8015D888(u32);
void func_8015D8FC(u32);
s32 func_8015D94C(u32);
BOOL func_80164840(u8);
s32 func_8016AEDC(void);
s32 func_8016B0FC();
s32 func_8016B1C4();
s32 func_8016B238(void);
s32 func_8016B3A0(void);
s32 func_8016B41C();
s32 func_801A45E8(s32);
f32 func_801C0498(void);
struct _HSD_GObj* func_801C14D0(s32);
BOOL func_801C28AC(s32, u32, s32*);
struct _HSD_GObj* func_801C2BA4(s32);
struct _HSD_JObj* func_801C2CF4(s32);
BOOL func_801C2D24(s32, Vec*);
BOOL func_801C2ED0(struct _HSD_JObj*, s32);
void func_801C39C0();
void func_801C3BB4();
struct _HSD_JObj* func_801C3FA4(struct _HSD_GObj*, s32);
s32 func_801C4210(void);
void func_801C42AC();
void* func_801C49F8(void);
void func_801C5A84();
void func_801C5AA4();
void func_801C5DB0(struct _HSD_GObj*, s32);
void func_801C7FF8(struct _HSD_GObj*, s32, s32, s32, f32, f32);
void func_801C8138();
void func_801C95C4(struct _HSD_GObj*);
s32 Stage_80225194(void);
void func_8026A8EC();
void func_8026ABD8(struct _HSD_GObj*, Vec*, f32);
BOOL func_8026B2B4(struct _HSD_GObj*);
s32 itGetKind(struct _HSD_GObj*);
s32 func_8026B30C(struct _HSD_GObj*);
s32 func_8026B320(struct _HSD_GObj*);
void func_8026B3F8(struct _Article*, s32);
f32 func_8026B54C(struct _HSD_GObj*);
f32 func_8026B560(struct _HSD_GObj*);
f32 func_8026B574(struct _HSD_GObj*);
s32 func_8026B588();
BOOL func_8026B594(struct _HSD_GObj*);
void func_8026B7F8();
void func_8027B4A4();
void* func_8027B5B0(s32, s32, struct _HSD_JObj*, s32, s32);
void func_80294E78(struct _HSD_GObj*, f32);
struct _HSD_GObj* func_8029A748(struct _HSD_GObj*, Vec*, u8, f32);
void func_8029A89C(struct _HSD_GObj*, f32);
void func_8029A8F4(struct _HSD_GObj*, Vec*, f32);
s32 func_802B1DEC(u32);
u32 func_802B1DF8(HSD_GObj*, Vec*, Vec*, s32, s32, s32);
s32 func_802B1FC8(u32);
void func_802B1FE8(u32, Vec*);
void func_802B56E4(u32, Vec*, f32, f32, f32);
void* func_802C8B28(struct _HSD_GObj*, Vec*, u32, f32);
void func_802D8618(s32, Vec*, s32, s32);
u32 func_802F0340(struct _HSD_GObj*, Vec*, Vec*, u32, u32, f32);
void func_802F046C(s32);
void func_802F0AE0(struct _HSD_GObj*, Vec*, Vec*, s32, s32, f32, f32, f32);
s32 func_802FB6E8(u8);
s32 func_802FC998();
s32 func_80322258(f32 x);
void __cvt_sll_flt(void);
void __cvt_dbl_usll(void);
int __StringRead(void*, int, int);
char* strchr(const char*, int);
int strncmp(const char*, const char*, unsigned long);
int strcmp(const char*, const char*);
char* strncpy(char* __restrict, const char* __restrict, unsigned long);
char* strcpy(char* __restrict, const char* __restrict);
unsigned long strlen(const char*);
f32 tanf(f32);
f32 cosf(f32);
f32 sinf(f32);
struct _GXFifoObj* GXInit(void* fifo, u32 size);
void GXSetVtxDesc();
void GXSetVtxAttrFmt();
void GXInitLightAttn(struct _GXLightObj*, f32, f32, f32, f32, f32, f32);
void GXInitLightPos(struct _GXLightObj*, f32 x, f32 y, f32 z);
void GXInitLightDir(struct _GXLightObj*, f32 x, f32 y, f32 z);
void GXSetChanAmbColor();
void GXSetChanMatColor();
void GXSetChanCtrl();
void PSMTXIdentity(Mtx m);
void PSMTXCopy(Mtx src, Mtx dst);
void PSMTXConcat(Mtx, Mtx, Mtx);
void PSMTXTranspose(Mtx src, Mtx xPose);
u32 PSMTXInverse(const Mtx src, Mtx inv);
void PSMTXRotRad(Mtx m, u8 axis, f32 rad);
void PSMTXRotTrig(Mtx m, u8 axis, f32 sin, f32 cos);
void PSMTXRotAxisRad(Mtx m, const Vec* axis, f32 rad);
void PSMTXTrans(Mtx m, f32 x_trans, f32 y_trans, f32 z_trans);
void PSMTXScale(Mtx m, f32 x_scale, f32 y_scale, f32 z_scale);
void PSMTXQuat(Mtx m, const Quaternion* q);
void PSMTXMUltiVec(Mtx, Vec*, Vec*);
void PSVECAdd(Vec* a, Vec* b, Vec* result);
void PSVECSubtract(Vec* a, Vec* b, Vec* result);
void PSVECScale(Vec* src, Vec* dst, f32 scale);
void PSVECNormalize(Vec* src, Vec* unit);
f32 PSVECMag(Vec* v);
f32 PSVECDotProduct(Vec* a, Vec* b);
void PSVECCrossProduct(Vec* a, Vec* b, Vec* result);
void* OSAllocFromHeap(int, u32);
void OSReport(char*, ...);
BOOL OSDisableInterrupts();
void OSRestoreInterrupts(BOOL);
void __OSSetInterruptHandler(s32, void(*)());
void __OSUnmaskInterrupts(s32);
u32 OSGetConsoleSimulatedMemSize();
void VIWaitForRetrace(void);
struct _HSD_DObj* HSD_DObjLoadDesc(struct _HSD_DObjDesc*);
struct _HSD_TObj* allocShadowTObj();
struct _HSD_ImageDesc* HSD_ImageDescAlloc();
struct _HSD_MObj* HSD_MObjLoadDesc(struct _HSD_MObjDesc*);
void HSD_AObjRemove(struct _HSD_AObj* aobj);
void HSD_ForeachAnim(void*, ...);
void func_80366BD4();
struct _HSD_WObj* func_80366E78(struct _HSD_LObj*);
struct _HSD_WObj* func_80366E90(struct _HSD_LObj*);
f32 HSD_CObjGetNear(struct _HSD_CObj*);
f32 HSD_CObjGetFar(struct _HSD_CObj*);
void HSD_CObjSetScissorx4();
void HSD_CObjSetViewportfx4();
u32 HSD_CObjGetProjectionType(struct _HSD_CObj*);
void* func_8036A288(void);
struct _HSD_CObj* HSD_CObjAlloc();
struct _HSD_PObj* HSD_PObjLoadDesc(struct _HSD_PObjDesc*);
void HSD_JObjAddAnimAll(struct _HSD_JObj*, struct _HSD_AnimJoint*, struct _HSD_MatAnimJoint*, struct _HSD_ShapeAnimJoint*);
void HSD_JObjAnimAll(struct _HSD_JObj*);
struct _HSD_JObj* HSD_JObjLoadJoint(struct _HSD_Joint*);
void HSD_JObjUnref(struct _HSD_JObj* jobj);
void HSD_JObjRemoveAll(struct _HSD_JObj*);
void HSD_EraseRect();
void HSD_GXInit(void);
void HSD_OSInit(void);
int HSD_GetHeap(void);
void HSD_ObjInit(void);
void HSD_VIInit(struct _HSD_VIStatus* vi_status, void* xfb0, void* xfb1, void* xfb2);
void func_80378280(u8, int);
f32 splGetHelmite(f32, f32, f32, f32, f32, f32);
void splArcLengthPoint(Vec*, struct _HSD_Spline*, f32);
void func_80379310();
void func_8037A250();
void* func_8037ABC8(struct _HSD_ObjAllocData* data);
void func_8037AD20(struct _HSD_ObjAllocData* data, struct _HSD_ObjAllocLink* obj);
void HSD_ObjAllocInit(struct _HSD_ObjAllocData* data, u32 size, u32 align);
void HSD_RObjRemoveAnimAll(struct _HSD_RObj* robj);
void HSD_RObjReqAnimAll(struct _HSD_RObj* robj, f32 frame);
void HSD_IDSetup(void);
void* func_8037CF98(struct _HSD_IDTable* table, u32 id, u8* success);
void func_8037EE0C(Vec*, Quaternion*);
void func_8037EF28(Quaternion*, Quaternion*, Quaternion*, f32);
void hsdInitClassInfo();
void* hsdNew();
BOOL hsdIsDescendantOf(void*, void*);
struct _HSD_ClassInfo* hsdSearchClassInfo(char*);
void func_803881E4(void);
void __assert(char*, u32, char*);
void HSD_Panic(char*, u32, char*);
void func_8038FD54(struct _HSD_GObj*, void (*)(struct _HSD_GObj*), s32);
struct _HSD_GObj* func_803901F0(s32, s32, s32);
void func_80390228(struct _HSD_GObj*);
void func_80390A70(struct _HSD_GObj*, u8, void*);
void efLib_PauseAll(struct _HSD_GObj*);
void efLib_ResumeAll(struct _HSD_GObj*);
BOOL EnvColl_CheckGroundAndLedge(HSD_GObj*, s32);
s32 func_80096CC8(struct _HSD_GObj*);
void ef_Spawn(s32, ...);
f32 HSD_Randf(void);
s32 HSD_Randi(s32);
typedef enum _GXTexMtx
{
    GX_TEXMTX0 = 30,
    GX_TEXMTX1 = 33,
    GX_TEXMTX2 = 36,
    GX_TEXMTX3 = 39,
    GX_TEXMTX4 = 42,
    GX_TEXMTX5 = 45,
    GX_TEXMTX6 = 48,
    GX_TEXMTX7 = 51,
    GX_TEXMTX8 = 54,
    GX_TEXMTX9 = 57,
    GX_IDENTITY = 60
} GXTexMtx;
typedef enum _GXTexMapID
{
    GX_TEXMAP0,
    GX_TEXMAP1,
    GX_TEXMAP2,
    GX_TEXMAP3,
    GX_TEXMAP4,
    GX_TEXMAP5,
    GX_TEXMAP6,
    GX_TEXMAP7,
    GX_MAX_TEXMAP,
    GX_TEXMAP_NULL = 0xff,
    GX_TEX_DISABLE = 0x100
} GXTexMapID;
typedef enum _GXPTTexMtx
{
    GX_PTTEXMTX0 = 64,
    GX_PTTEXMTX1 = 67,
    GX_PTTEXMTX2 = 70,
    GX_PTTEXMTX3 = 73,
    GX_PTTEXMTX4 = 76,
    GX_PTTEXMTX5 = 79,
    GX_PTTEXMTX6 = 82,
    GX_PTTEXMTX7 = 85,
    GX_PTTEXMTX8 = 88,
    GX_PTTEXMTX9 = 91,
    GX_PTTEXMTX10 = 94,
    GX_PTTEXMTX11 = 97,
    GX_PTTEXMTX12 = 100,
    GX_PTTEXMTX13 = 103,
    GX_PTTEXMTX14 = 106,
    GX_PTTEXMTX15 = 109,
    GX_PTTEXMTX16 = 112,
    GX_PTTEXMTX17 = 115,
    GX_PTTEXMTX18 = 118,
    GX_PTTEXMTX19 = 121,
    GX_PTIDENTITY = 125
} GXPTTexMtx;
typedef struct _GXFifoObj {
 u8 pad[128];
} GXFifoObj;
typedef struct _GXRenderModeObj {
 u32 viTVMode;
 u16 fbWidth;
 u16 efbHeight;
 u16 xfbHeight;
 u16 viXOrigin;
 u16 viYOrigin;
 u16 viWidth;
 u16 viHeight;
 u32 xfbMode;
 u8 field_rendering;
 u8 aa;
 u8 sample_pattern[12][2];
 u8 vfilter[7];
} GXRenderModeObj;
typedef struct _GXLightObj
{
    u32 dummy[16];
} GXLightObj;
typedef struct _GXColor {
    u8 r, g, b, a;
} GXColor;
typedef struct _GXColorS10 {
    s16 r, g, b, a;
} GXColorS10;
       
extern const s32 lbl_803D3984[];
extern void* lbl_804D64FC;
extern void* lbl_804D6500;
extern void* lbl_804D6504;
extern void* lbl_804D6508;
extern void* lbl_804D650C;
extern void* lbl_804D6510;
extern void* lbl_804D6514;
extern void* lbl_804D6518;
extern void* lbl_804D651C;
extern void* lbl_804D6520;
extern void* lbl_804D6524;
extern void* lbl_804D6528;
extern void* lbl_804D6530;
extern void* lbl_804D6534;
extern void* lbl_804D6538;
extern void* lbl_804D653C;
extern s32** lbl_804D6540;
extern void* lbl_804D6544;
extern void* lbl_804D6548;
extern void* lbl_804D654C;
extern void* lbl_804D6550;
extern struct _ftCommonData* p_ftCommonData;
typedef struct _Vec2 { float x, y; } Vec2;
typedef Vec Vec3;
typedef union _UnkFlagStruct {
    u8 u8;
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } bits;
} UnkFlagStruct;
/*
typedef struct _UnkFlagStruct {
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } bits;
} UnkFlagStruct;*/
typedef struct _ReflectDesc
{
    u32 x0_bone_id;
    s32 x4_max_damage;
    Vec3 x8_offset;
    f32 x14_size;
    f32 x18_damage_mul;
    f32 x1C_speed_mul;
    u8 x20_behavior : 8;
} ReflectDesc;
typedef struct _AbsorbDesc
{
    u32 x0_bone_id;
    Vec3 x4_offset;
    f32 x10_size;
} AbsorbDesc;
typedef struct _CollData
{
    u8 filler_x0[0x4];
    Vec3 x4_vec;
    u8 padding_x10[0x1C - 0x10];
    Vec3 x1C_vec;
    u8 padding_x28[0x34 - 0x28];
    u8 x34_flags_0 : 1;
    u8 x34_flags_1 : 4;
    u8 x34_flags_2 : 2;
    u8 x34_flags_3 : 1;
    u8 padding_x35[0x40 - 0x35];
    u32 x40;
    u32 x44;
    u8 filler_x48[0xA8 - 0x48];
    f32 xA8;
    f32 xAC;
    f32 xB0;
    Vec2 xB4_ecbCurrCorrect_right;
    Vec2 xBC_ecbCurrCorrect_left;
    u8 filler_xBC[0xE8 - 0xBC - 8];
    f32 xE8;
    f32 xEC;
    f32 xF0;
    u8 filler_xF4[0x130 - 0xF4];
    u32 x130;
    s32 x134_envFlags;
    u8 filler_x138[0x14C - 0x138];
    s32 x14C_groundIndex;
    s32 filler_x150;
    Vec3 x154_groundNormal;
    s32 x160_rightwall_index;
    s32 x164;
    Vec x168_vec;
    s32 x174_leftwall_index;
    s32 x178;
    Vec x17C_vec;
    u32 filler_x188[2];
    Vec x190_vec;
    s32 x19C;
} CollData;
typedef struct ColorOverlay
{
    s32 x0_timer;
    s32 x4_pri;
    s32* x8_ptr1;
    s32 xC_loop;
    s32* x10_ptr2;
    s32 x14;
    s32* x18_alloc;
    s32 x1c;
    s32 x20;
    s32 x24;
    s32 x28_colanim;
    GXColor x2C_hex;
    f32 x30_color_red;
    f32 x34_color_green;
    f32 x38_color_blue;
    f32 x3C_color_alpha;
    f32 x40_colorblend_red;
    f32 x44_colorblend_green;
    f32 x48_colorblend_blue;
    f32 x4C_colorblend_alpha;
    GXColor x50_light_color;
    f32 x54_light_red;
    f32 x58_light_green;
    f32 x5C_light_blue;
    f32 x60_light_alpha;
    f32 x64_lightblend_red;
    f32 x68_lightblend_green;
    f32 x6C_lightblend_blue;
    f32 x70_lightblend_alpha;
    f32 x74_light_angle;
    f32 x78_light_unk;
    u8 x7C_color_enable : 1;
    u8 x7C_flag2 : 1;
    u8 x7C_light_enable : 1;
    u8 x7C_flag4 : 1;
    u8 x7C_flag5 : 1;
    u8 x7C_flag6 : 1;
    u8 x7C_flag7 : 1;
    u8 x7C_flag8 : 1;
}ColorOverlay;
struct r13_ColAnimStruct
{
    u32 x0_unk;
    u8 x4_unk;
    u8 x5_unk;
    u8 x6_unk;
    u8 x7_unk;
};
typedef struct _objheap {
    u32 top;
    u32 curr;
    u32 size;
    u32 remain;
} objheap;
typedef struct _HSD_ObjAllocLink {
    struct _HSD_ObjAllocLink* next;
} HSD_ObjAllocLink;
typedef struct _HSD_ObjAllocData {
    u32 num_limit_flag : 1;
    u32 heap_limit_flag : 1;
    HSD_ObjAllocLink* freehead;
    u32 used;
    u32 free;
    u32 peak;
    u32 num_limit;
    u32 heap_limit_size;
    u32 heap_limit_num;
    u32 size;
    u32 align;
    struct _HSD_ObjAllocData* next;
} HSD_ObjAllocData;
struct r13_EntityPointers {
    HSD_GObj* x0[8];
    HSD_GObj* x20_fighterGObj;
    HSD_GObj* x24_itemGObj;
};
typedef struct ItemCommonData
{
    u32 x0;
    u32 x4;
    u32 x8;
    u32 xC;
    u32 x10;
    u32 x14;
    u32 x18;
    u32 x1C;
    u32 x20;
    u32 x24;
    u32 x28;
    u32 x2C;
    s32 x30;
    u32 x34;
    s32 x38_float;
    s32 x3C_float;
    s32 x40_float;
    s32 x44_float;
    s32 x48_float;
    s32 x4C_float;
    s32 x50_float;
    s32 x54_float;
    s32 x58_float;
    s32 x5C_float;
    s32 x60_float;
    s32 x64_float;
    s32 x68_float;
    f32 x6C_float;
    f32 x70_float;
    f32 x74_float;
    f32 x78_float;
    f32 x7C_float;
    f32 x80_float[13];
    s32 xB4;
    f32 xB8;
    f32 xBC;
    f32 xC0;
    f32 xC4;
    f32 xC8;
    f32 xCC;
    f32 xD0;
    f32 xD4;
    s32 xD8;
    s32 xDC;
    u8 filler[0x148 - 0xE0];
    s32 x148;
    f32 x14C;
    f32 x150;
    f32 x154;
    f32 x158;
    f32 x15C;
} ItemCommonData;
extern s8 lbl_804D6D00;
extern s32 lbl_804D6D08;
extern s32 lbl_804D6D0C;
extern s32 lbl_804D6D10;
extern s32 lbl_804D6D14;
extern ItemCommonData* lbl_804D6D28;
typedef struct HSD_ObjAllocUnk2
{
    u8 x0_filler[0x144];
    u32 x144;
    u32 x148;
    u32 x14C;
    UnkFlagStruct x150;
    u32 x154;
    u32 x158;
    u32 x15C;
}HSD_ObjAllocUnk2;
typedef struct x1C_struct
{
    u32 x1C;
}x1C_struct;
typedef struct HSD_ObjAllocUnk
{
    u32 x0;
    u32 x4;
    u32 x8;
    u32 xC;
    u32 x10;
    u32 x14;
    u32 x18;
    x1C_struct x1C_struct;
    u32 x20;
    u32 x24;
    u32 x28;
    u32 x2C;
    u32 x30;
    u32 x34;
    u32 x38;
    u32 x3C;
    u32 x40;
    u32 x44;
    u32 x48;
    u32 x4C;
    u32 x50;
    u32 x54;
    u32 x58;
    u32 x5C;
    u32 x60;
    u32 x64;
    u32 x68;
} HSD_ObjAllocUnk;
typedef struct HSD_ObjAllocUnkStruct
{
    HSD_ObjAllocData x0;
    HSD_ObjAllocData x2C;
    HSD_ObjAllocData x58;
    HSD_ObjAllocUnk x84;
    HSD_ObjAllocUnk2 xEC;
}HSD_ObjAllocUnkStruct;
typedef struct HSD_ObjAllocUnk3
{
    u32 x0;
    u32 x4;
    u32 x8;
    u32 xC;
}HSD_ObjAllocUnk3;
typedef struct HSD_ObjAllocUnk4
{
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    u8 x4;
    u16 x6;
    u16 x8;
    u16 xA;
    u16 xC;
    u32 x10;
}HSD_ObjAllocUnk4;
typedef struct HSD_ObjAllocUnk5
{
    u8 x0;
    u32 x4;
    u16 x8;
    u16 xA;
    u16 xC;
}HSD_ObjAllocUnk5;
typedef struct HSD_ObjAllocUnk6
{
    u8 x0;
    u32 x4;
    u16 x8;
    u16 xA;
    u16 xC;
}HSD_ObjAllocUnk6;
typedef struct Item_r13_Data
{
    ItemCommonData* item_common;
    void** common_items;
    void** adventure_items;
    void** pokeball_items;
    s32 x10;
    s32 x14;
}Item_r13_Data;
typedef struct _HSD_ObjAllocInfo {
    struct _HSD_ObjAllocData* (*getData)(void);
    char* name;
} HSD_ObjAllocInfo;
inline u32 HSD_ObjAllocUsed(HSD_ObjAllocInfo* info)
{
    HSD_ObjAllocData* data = info->getData();
    ((data) ? ((void) 0) : __assert("src/sysdolphin/baselib/objalloc.h", 205, "data"));
    return data->used;
}
inline u32 HSD_ObjAllocFree(HSD_ObjAllocInfo* info)
{
    HSD_ObjAllocData* data = info->getData();
    ((data) ? ((void) 0) : __assert("src/sysdolphin/baselib/objalloc.h", 221, "data"));
    return data->free;
}
inline u32 HSD_ObjAllocPeak(HSD_ObjAllocInfo* info)
{
    HSD_ObjAllocData* data = info->getData();
    ((data) ? ((void) 0) : __assert("src/sysdolphin/baselib/objalloc.h", 237, "data"));
    return data->peak;
}
void HSD_ObjSetHeap(u32 size, void* ptr);
s32 HSD_ObjAllocAddFree(HSD_ObjAllocData* data, u32 num);
void* HSD_ObjAlloc(HSD_ObjAllocData* data);
void HSD_ObjFree(HSD_ObjAllocData* data, void* obj);
void _HSD_ObjAllocForgetMemory(void);
typedef struct _HSD_GObj {
    u16 classifier;
    u8 p_link;
    u8 gx_link;
    u8 p_priority;
    u8 render_priority;
    u8 obj_kind;
    u8 user_data_kind;
    struct _HSD_GObj* next;
    struct _HSD_GObj* prev;
    struct _HSD_GObj* next_gx;
    struct _HSD_GObj* prev_gx;
    struct _HSD_GObjProc* proc;
    void (*render_cb)(struct _HSD_GObj* gobj, s32 code);
    u64 gxlink_prios;
    void* hsd_obj;
    void* user_data;
    void (*user_data_remove_func)(void* data);
    void* x34_unk;
} HSD_GObj;
typedef struct _HSD_GObjProc {
    struct _HSD_GObjProc* child;
    struct _HSD_GObjProc* next;
    struct _HSD_GObjProc* prev;
    u8 s_link;
    u8 flags_1:1;
    u8 flags_2:1;
    u8 flags_3:2;
    struct _HSD_GObj* gobj;
    void (*callback)(struct _HSD_GObj*);
} HSD_GObjProc;
typedef struct _HSD_GObjLibInitData {
    u8 p_link_max;
    u8 gx_link_max;
    u8 gproc_pri_max;
    u32 unk_1;
    u32* unk_2;
    HSD_ObjAllocData gobj_def;
    HSD_ObjAllocData gobj_proc_def;
} HSD_GObjLibInitData;
void func_80390C5C(HSD_GObj* gobj);
void func_80390C84(HSD_GObj* gobj);
void func_80390CAC(HSD_GObj* gobj);
typedef struct _HSD_Class {
    struct _HSD_ClassInfo* class_info;
} HSD_Class;
typedef struct _HSD_ClassInfoHead {
    void (*info_init)();
    u32 flags;
    char* library_name;
    char* class_name;
    s16 obj_size;
    s16 info_size;
    struct _HSD_ClassInfo* parent;
    struct _HSD_ClassInfo* next;
    struct _HSD_ClassInfo* child;
    u32 nb_exist;
    u32 nb_peak;
} HSD_ClassInfoHead;
typedef struct _HSD_ClassInfo {
    struct _HSD_ClassInfoHead head;
    HSD_Class* (*alloc)(struct _HSD_ClassInfo* c);
    void (*init)(struct _HSD_Class* c);
    void (*release)(struct _HSD_Class* c);
    void (*destroy)(struct _HSD_Class* c);
    void (*amnesia)(struct _HSD_ClassInfo* c);
} HSD_ClassInfo;
typedef struct _HSD_FreeList {
    struct _HSD_FreeList* next;
} HSD_FreeList;
typedef struct _HSD_MemoryEntry {
    u32 size;
    u32 nb_alloc;
    u32 nb_free;
    struct _HSD_FreeList* free_list;
    struct _HSD_MemoryEntry* next;
} HSD_MemoryEntry;
extern HSD_ClassInfo hsdClass;
void ClassInfoInit(HSD_ClassInfo* info);
void hsdInitClassInfo(HSD_ClassInfo* class_info, HSD_ClassInfo* parent_info, char* base_class_library, char* type, s32 info_size, s32 class_size);
void OSReport_PrintSpaces(s32 count);
void* hsdAllocMemPiece(u32 size);
typedef enum _HSD_Type {
    AOBJ_TYPE = 1,
    COBJ_TYPE = 2,
    DOBJ_TYPE = 3,
    FOBJ_TYPE = 4,
    FOG_TYPE = 5,
    JOBJ_TYPE = 6,
    LOBJ_TYPE = 7,
    MOBJ_TYPE = 8,
    POBJ_TYPE = 9,
    ROBJ_TYPE = 10,
    TOBJ_TYPE = 11,
    WOBJ_TYPE = 12,
    RENDER_TYPE = 13,
    CHAN_TYPE = 14,
    TEVREG_TYPE = 15,
    CBOBJ_TYPE = 16,
    HSD_MAX_TYPE,
} HSD_Type;
typedef struct _HSD_Obj {
    struct _HSD_Class parent;
    u16 ref_count;
    u16 ref_count_individual;
} HSD_Obj;
typedef struct _HSD_ObjInfo {
    struct _HSD_ClassInfo parent;
} HSD_ObjInfo;
extern HSD_ClassInfo hsdObj;
void ObjInfoInit(void);
typedef struct _HSD_SList {
    struct _HSD_SList* next;
    void* data;
} HSD_SList;
typedef struct _HSD_DList {
    struct _HSD_DList* next;
    struct _HSD_DList* prev;
    void* data;
} HSD_DList;
void HSD_ListInitAllocData();
HSD_ObjAllocData *HSD_SListGetAllocData();
HSD_ObjAllocData *HSD_DListGetAllocData();
HSD_SList *HSD_SListAlloc();
HSD_SList *HSD_SListAllocAndAppend(HSD_SList *next, void *data);
HSD_SList *HSD_SListAllocAndPrepend(HSD_SList *prev, void *data);
HSD_SList *HSD_SListAppendList(HSD_SList *list, HSD_SList *next);
HSD_SList *HSD_SListPrependList(HSD_SList *list, HSD_SList *prev);
HSD_SList *HSD_SListRemove(HSD_SList *list);
typedef struct _IDEntry {
    struct _IDEntry* next;
    u32 id;
    void* data;
} IDEntry;
typedef struct _HSD_IDTable {
    struct _IDEntry* table[101];
} HSD_IDTable;
HSD_ObjAllocData* HSD_IDGetAllocData(void);
void HSD_IDInitAllocData(void);
void HSD_IDSetup(void);
void HSD_IDInsertToTable(HSD_IDTable* table, u32 id, void* data);
void HSD_IDRemoveByIDFromTable(HSD_IDTable* table, u32 id);
void* HSD_IDGetDataFromTable(HSD_IDTable* table, u32 id, s32* success);
void _HSD_IDForgetMemory(void);
typedef struct _HSD_FObj {
    struct _HSD_FObj* next;
    u8* ad;
    u8* ad_head;
    u32 length;
    u8 flags;
    u8 op;
    u8 op_intrp;
    u8 obj_type;
    u8 frac_value;
    u8 frac_slope;
    u16 nb_pack;
    s16 startframe;
    u16 fterm;
    f32 time;
    f32 p0;
    f32 p1;
    f32 d0;
    f32 d1;
} HSD_FObj;
typedef struct _HSD_FObjDesc {
    struct _HSD_FObjDesc* next;
    u32 length;
    f32 startframe;
    u8 type;
    u8 frac_value;
    u8 frac_slope;
    u8 dummy0;
    u8* ad;
} HSD_FObjDesc;
typedef union _HSD_FObjData {
    f32 fv;
    s32 iv;
    Vec p;
} FObjData;
HSD_ObjAllocData* HSD_FObjGetAllocData(void);
void HSD_FObjInitAllocData(void);
void HSD_FObjRemove(HSD_FObj* fobj);
void HSD_FObjRemoveAll(HSD_FObj* fobj);
u8 HSD_FObjSetState(HSD_FObj* fobj, u8 state);
u32 HSD_FObjGetState(HSD_FObj* fobj);
void HSD_FObjReqAnimAll(HSD_FObj* fobj, f32 startframe);
void HSD_FObjStopAnim(HSD_FObj* fobj, void* obj, void (*obj_update)(), f32 rate);
void HSD_FObjStopAnimAll(HSD_FObj* fobj, void* obj, void (*obj_update)(), f32 rate);
void FObjUpdateAnim(HSD_FObj* fobj, void* obj, void (*obj_update)(void*, s32, FObjData*));
void HSD_FObjInterpretAnim(HSD_FObj* fobj, void* obj, void (*obj_update)(), f32 rate);
void HSD_FObjInterpretAnimAll(HSD_FObj* fobj, void* obj, void (*obj_update)(), f32 rate);
HSD_FObj* HSD_FObjLoadDesc(HSD_FObjDesc* desc);
HSD_FObj* HSD_FObjAlloc(void);
void HSD_FObjFree(HSD_FObj* fobj);
typedef enum _AObj_Arg_Type
{
    AOBJ_ARG_A,
    AOBJ_ARG_AF,
    AOBJ_ARG_AV,
    AOBJ_ARG_AU,
    AOBJ_ARG_AO,
    AOBJ_ARG_AOF,
    AOBJ_ARG_AOV,
    AOBJ_ARG_AOU,
    AOBJ_ARG_AOT,
    AOBJ_ARG_AOTF,
    AOBJ_ARG_AOTV,
    AOBJ_ARG_AOTU,
} AObj_Arg_Type;
typedef union _callbackArg {
    f32 f;
    u32 d;
    void* v;
} callbackArg;
typedef struct _HSD_AObj {
    u32 flags;
    f32 curr_frame;
    f32 rewind_frame;
    f32 end_frame;
    f32 framerate;
    HSD_FObj* fobj;
    struct _HSD_Obj* hsd_obj;
} HSD_AObj;
typedef struct _HSD_AObjDesc {
    u32 flags;
    f32 end_frame;
    HSD_FObjDesc* fobjdesc;
    u32 obj_id;
} HSD_AObjDesc;
typedef struct _HSD_AnimJoint {
    struct _HSD_AnimJoint* child;
    struct _HSD_AnimJoint* next;
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_RObjAnimJoint* robj_anim;
    u32 flags;
} HSD_AnimJoint;
void HSD_AObjInitAllocData(void);
HSD_ObjAllocData* HSD_AObjGetAllocData(void);
u32 HSD_AObjGetFlags(HSD_AObj* aobj);
void HSD_AObjSetFlags(HSD_AObj* aobj, u32 flags);
void HSD_AObjClearFlags(HSD_AObj* aobj, u32 flags);
void HSD_AObjSetFObj(HSD_AObj* aobj, HSD_FObj* fobj);
void HSD_AObjInitEndCallBack(void);
void HSD_AObjInvokeCallBacks(void);
void HSD_AObjReqAnim(HSD_AObj* aobj, f32 frame);
void HSD_AObjStopAnim(HSD_AObj* aobj, void* obj, void (*func)());
void HSD_AObjInterpretAnim(HSD_AObj* aobj, void* obj, void (*update_func)());
float fmod(float x, float y);
HSD_AObj* HSD_AObjLoadDesc(HSD_AObjDesc* aobjdesc);
void HSD_AObjRemove(HSD_AObj* aobj);
HSD_AObj* HSD_AObjAlloc(void);
void HSD_AObjFree(HSD_AObj* aobj);
void callbackForeachFunc(HSD_AObj *aobj, void *obj, HSD_Type type, void (*func)(), AObj_Arg_Type arg_type, callbackArg *arg);
void TObjForeachAnim(struct _HSD_TObj* tobj, s32 flags, void*, s32, void*);
void func_803647DC(void);
void func_80364924(void);
void HSD_AObjSetRate(HSD_AObj* aobj, f32 rate);
void HSD_AObjSetRewindFrame(HSD_AObj* aobj, f32 frame);
void HSD_AObjSetEndFrame(HSD_AObj* aobj, f32 frame);
void HSD_AObjSetCurrentFrame(HSD_AObj* aobj, f32 frame);
void _HSD_AObjForgetMemory(void);
inline f32 HSD_AObjGetEndFrame(HSD_AObj* aobj) {
    if (!aobj) {
        __assert("aobj.h", 0xAAU, "aobj");
    }
    return aobj->end_frame;
}
typedef u32 HSD_TrspMask;
typedef struct _HSD_JObj {
    HSD_Obj object;
    struct _HSD_JObj* next;
    struct _HSD_JObj* parent;
    struct _HSD_JObj* child;
    u32 flags;
    union {
        HSD_SList* ptcl;
        struct _HSD_DObj* dobj;
        struct _HSD_Spline* spline;
    } u;
    Quaternion rotate;
    Vec scale;
    Vec translate;
    Mtx mtx;
    Vec* scl;
    MtxPtr envelopemtx;
    struct _HSD_AObj* aobj;
    struct _HSD_RObj* robj;
    u32 id;
} HSD_JObj;
typedef struct _HSD_Joint {
    char* class_name;
    u32 flags;
    struct _HSD_Joint* child;
    struct _HSD_Joint* next;
    union {
        struct _HSD_DObjDesc* dobjdesc;
        struct _HSD_Spline* spline;
        struct _HSD_SList* ptcl;
    } u;
    Vec rotation;
    Vec scale;
    Vec position;
    MtxPtr mtx;
    struct _HSD_RObjDesc* robjdesc;
} HSD_Joint;
typedef struct _HSD_JObjInfo {
    HSD_ObjInfo parent;
    s32 (*load)(HSD_JObj* jobj, HSD_Joint* joint, HSD_JObj* jobj_2);
    void (*make_mtx)(HSD_JObj* jobj);
    void (*make_pmtx)(HSD_JObj* jobj, Mtx mtx, Mtx rmtx);
    void (*disp)(HSD_JObj* jobj, Mtx vmtx, Mtx pmtx, HSD_TrspMask trsp_mask, u32 rendermode);
    void (*release_child)(HSD_JObj* jobj);
} HSD_JObjInfo;
extern HSD_JObjInfo hsdJObj;
void HSD_JObjCheckDependAll(HSD_JObj* jobj);
u32 HSD_JObjGetFlags(HSD_JObj* jobj);
void HSD_JObjReqAnimAll(HSD_JObj*, f32);
void HSD_JObjResetRST(HSD_JObj* jobj, HSD_Joint* joint);
void HSD_JObjReqAnimAll(HSD_JObj*, f32);
void HSD_JObjSetupMatrixSub(HSD_JObj*);
void HSD_JObjSetMtxDirtySub(HSD_JObj*);
#pragma push
#pragma always_inline on
inline struct _HSD_RObj* HSD_JObjGetRObj(HSD_JObj* jobj)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 405, "jobj"));
    return jobj->robj;
}
inline BOOL HSD_JObjMtxIsDirty(HSD_JObj* jobj)
{
    BOOL result;
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 564, "jobj"));
    result = 0;
    if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        result = 1;
    }
    return result;
}
inline void HSD_JObjSetupMatrix(HSD_JObj* jobj)
{
    if (jobj != ((void*)0) && HSD_JObjMtxIsDirty(jobj)) {
        HSD_JObjSetupMatrixSub(jobj);
    }
}
inline void HSD_JObjSetMtxDirty(HSD_JObj* jobj)
{
    if (jobj != ((void*)0) && !HSD_JObjMtxIsDirty(jobj)) {
        HSD_JObjSetMtxDirtySub(jobj);
    }
}
inline void HSD_JObjSetRotation(HSD_JObj* jobj, Quaternion* quat)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 618, "jobj"));
    jobj->rotate = *quat;
    if ((jobj->flags & 0x02000000) == 0) {
        HSD_JObjSetMtxDirty(jobj);
    }
}
inline void HSD_JObjGetRotation(HSD_JObj* jobj, Quaternion *quat)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 699, "jobj"));
    *quat = jobj->rotate;
}
inline void HSD_JObjSetScale(HSD_JObj* jobj, Vec* scale)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 760, "jobj"));
    ((scale) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 761, "scale"));
    jobj->scale = *scale;
    if (!(jobj->flags & 0x2000000)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}
inline void HSD_JObjGetScale(HSD_JObj* jobj, Vec *scale)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 823, "jobj"));
    *scale = jobj->scale;
}
inline void HSD_JObjSetTranslate(HSD_JObj* jobj, Vec* translate)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 916, "jobj"));
    ((translate) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 917, "translate"));
    jobj->translate = *translate;
    if (!(jobj->flags & 0x2000000)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}
inline void HSD_JObjGetTranslation(HSD_JObj* jobj, Vec *translate)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 979, "jobj"));
    ((translate) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 980, "translate"));
    *translate = jobj->translate;
}
inline f32 HSD_JObjGetTranslationX(HSD_JObj* jobj)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 993, "jobj"));
    return jobj->translate.x;
}
inline f32 HSD_JObjGetTranslationY(HSD_JObj* jobj)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 1006, "jobj"));
    return jobj->translate.y;
}
inline void HSD_JObjGetMtx(HSD_JObj* jobj)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 1144, "jobj"));
    HSD_JObjUnkMtxPtr(jobj);
}
inline void HSD_JObjCopyMtx(HSD_JObj* jobj, Mtx mtx)
{
    ((jobj) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 1170, "jobj"));
    ((mtx) ? ((void) 0) : __assert("src/sysdolphin/baselib/jobj.h", 1171, "mtx"));
    PSMTXCopy(mtx, jobj->mtx);
}
#pragma pop
typedef struct _StaticPlayer
{
             s32 player_state;
             s32 player_character;
             s32 slot_type;
             u8 transformed[2];
             s16 unk0E;
    union {
        struct {
                          Vec nametag_pos;
                          Vec transformed_player_pos;
                          Vec spawn_platform_final_pos;
                          Vec some_other_player_pos;
        } byVecName;
        Vec byIndex[4];
    } player_poses;
             f32 facing_direction;
             u8 costume_id;
             s8 unk45;
             s8 controller_index;
             u8 team;
             s8 player_id;
             s8 cpu_level;
             s8 cpu_type;
             s8 handicap;
             s8 unk4C;
             s8 unk4D;
             s8 unk4E;
             s8 unk4F;
             f32 unk50;
             f32 attack_ratio;
             f32 defense_ratio;
             f32 model_scale;
    union {
        struct {
                     s16 damage_percent;
                     s16 damage_percent_alt_or_start_hp;
                     s16 stamina;
                     s16 unk66;
        } byName;
        s16 byIndex[4];
    } staminas;
                    s32 falls[2];
                  s32 kos_by_player[6];
             u32 match_frame_count;
             u16 suicide_count;
             s8 stocks;
             s8 unk8F;
             s32 current_coins;
             s32 total_coins;
             s32 unk98;
             s32 unk9C;
                s32 joystick_direction_input_count[2];
             s32 nametag_slot_id;
             struct {
                u8 b0 : 1;
                u8 b1 : 1;
                u8 b2 : 1;
                u8 b3 : 1;
                u8 b4 : 1;
                u8 b5 : 1;
                u8 b6 : 1;
                u8 b7 : 1;
            } flags;
             struct {
                u8 b0 : 1;
                u8 b1 : 1;
                u8 b2 : 1;
                u8 b3 : 1;
                u8 b4 : 1;
                u8 b5 : 1;
                u8 b6 : 2;
            } more_flags;
             struct {
                u8 b0 : 1;
                u8 b1 : 1;
                u8 b2 : 1;
                u8 b3 : 1;
                u8 b4 : 1;
                u8 b5 : 1;
                u8 b6 : 1;
                u8 b7 : 1;
            } flagsAE;
             s8 unkAF;
             HSD_GObj* player_entity[2];
             void (*struct_func) (s32 slot);
             s32 stale_move_table_current_write_index;
             s32 stale_move_index_0;
             s32 stale_move_index_1;
             s32 stale_move_index_2;
             s32 stale_move_index_3;
             s32 stale_move_index_4;
             s32 stale_move_index_5;
             s32 stale_move_index_6;
             s32 stale_move_index_7;
             s32 stale_move_index_8;
             s32 stale_move_index_9;
             s32 total_attack_count;
             s32 unkEC;
             u8 buffer[0x5B8];
              s32 unk6A8;
              u8 more_buffer[0x7E4];
} StaticPlayer;
StaticPlayer* Player_GetPtrForSlot(s32 slot);
void Player_80031790(s32 slot);
void Player_80031848(s32 slot);
void Player_80031900();
BOOL Player_800319C4(s32 slot, BOOL arg1);
void Player_80031AD0(s32 slot);
void Player_80031CB0(s32 id, s32 slot);
void Player_80031D2C(s32 id, s32 slot);
void Player_80031DA8(s32 param_1, s32 param_2);
void Player_80031DC8(void func_arg(s32, s32));
void Player_80031EBC(s32 slot);
void Player_80031FB0(s32 slot, s32 entity_index);
void Player_80032070(s32 slot, BOOL bool_arg);
void Player_8003219C(s32 slot);
BOOL Player_8003221C(s32 slot);
s32 Player_GetPlayerState(s32 slot);
s32 Player_GetPlayerCharacter(s32 slot);
void Player_SetPlayerCharacter(s32 slot, s32 value);
s32 Player_GetPlayerSlotType(s32 slot);
s32 Player_8003248C(s32 slot, BOOL arg1);
void Player_SetSlottype(s32 slot, s32 value);
s8 Player_800325C8(s32 slot, BOOL b);
s8 Player_80032610(s32 slot, BOOL arg1);
void Player_LoadPlayerCoords(s32 slot, Vec* out_vec);
void Player_80032768(s32 slot, Vec* arg_vec);
void Player_80032828(s32 slot, s32 index, Vec* arg_vec);
void Player_800328D4(s32 slot, Vec* arg_vec);
void Player_80032A04(s32 slot, Vec* arg_vec);
void Player_SetPlayerAndEntityFacingDirection(s32 slot, f32 direction);
f32 Player_80032BB0(s32 slot);
void Player_SetScale(s32 slot, f32 scale);
void Player_GetSpawnPlatformPos(s32 slot, Vec* arg_vec);
void Player_SetSpawnPlatformPos(s32 slot, Vec* arg_vec);
void Player_GetSomePos(s32 slot, Vec* arg_vec);
void Player_SetSomePos(s32 slot, Vec* arg_vec);
s32 Player_80032F30(s32 slot);
void Player_80032FA4(s32 slot, s32 arg);
f32 Player_GetFacingDirection(s32 slot);
void Player_SetFacingDirection(s32 slot, f32 direction);
void Player_SetFacingDirectionConditional(s32 slot, BOOL b, f32 direction);
u32 Player_GetCostumeId(s32 slot);
void Player_SetCostumeId(s32 slot, s8 costume_id);
u8 Player_GetControllerIndex(s32 slot);
void Player_SetControllerIndex(s32 slot, s8 controller_index);
s8 Player_GetTeam(s32 slot);
void Player_SetTeam(s32 slot, s8 unk_color);
s8 Player_GetPlayerId(s32 slot);
void Player_SetPlayerId(s32 slot, s8 player_id);
s8 Player_GetCpuLevel(s32 slot);
void Player_SetPlayerAndEntityCpuLevel(s32 slot, s8 cpu_level);
s8 Player_GetCpuType(s32 slot);
void Player_SetPlayerAndEntityCpuType(s32 slot, s8 cpu_type);
s8 Player_GetHandicap(s32 slot);
void Player_SetHandicap(s32 slot, s8 handicap);
f32 Player_GetUnk50(s32 slot);
f32 Player_GetAttackRatio(s32 slot);
void Player_SetAttackRatio(s32 slot, f32 attack_ratio);
f32 Player_GetDefenseRatio(s32 slot);
void Player_SetDefenseRatio(s32 slot, f32 defense_ratio);
f32 Player_GetModelScale(s32 slot);
void Player_SetModelScale(s32 slot, f32 model_scale);
s32 Player_GetStocks(s32 slot);
s32 Player_GetP1Stock();
void Player_SetStocks(s32 slot, s32 stocks);
void Player_LoseStock(s32 slot);
s32 Player_GetCoins(s32 slot);
void Player_SetCoins(s32 slot, s32 current_coins);
s32 Player_GetTotalCoins(s32 slot);
void Player_SetTotalCoins(s32 slot, s32 coins);
s32 Player_GetUnk98(s32 slot);
void Player_SetUnk98(s32 slot, s32 unk98);
s32 Player_GetUnk9C(s32 slot);
void Player_SetUnk9C(s32 slot, s32 unk9C);
HSD_GObj* Player_GetEntity(s32 slot);
HSD_GObj* Player_GetEntityAtIndex(s32 slot, s32 index);
void Player_SwapTransformedStates(s32 slot, s32 arg1, s32 arg2);
s32 Player_GetDamage(s32 slot);
void Player_SetHUDDamage(s32 slot,s32 arg1);
void Player_SetHPByIndex(s32 slot, s32 arg1, s32 arg2);
s16 Player_GetOtherStamina(s32 slot);
u32 Player_GetRemainingHP(s32 slot);
u8 Player_GetMoreFlagsBit2(s32 slot);
void Player_SetMoreFlagsBit2(s32 slot, u8 bit2);
s32 Player_GetMoreFlagsBit3(s32 slot);
void Player_SetMoreFlagsBit3(s32 slot, u8 bit3);
void Player_SetMoreFlagsBit4(s32 slot, u8 bit4);
s32 Player_GetMoreFlagsBit4(s32 slot);
u8 Player_GetMoreFlagsBit5(s32 slot);
void Player_SetMoreFlagsBit5(s32 slot, u8 bit5);
u8 Player_GetMoreFlagsBit6(s32 slot);
void Player_SetMoreFlagsBit6(s32 slot, u8 bit6);
u8 Player_GetFlagsAEBit0(s32 slot);
u32 Player_GetRemainingHPByIndex(s32 slot, s32 index);
s32 Player_GetFalls(s32 slot);
s32 Player_GetFallsByIndex(s32 slot, s32 index);
void Player_SetFalls(s32 slot, s32 falls);
void Player_SetFallsByIndex(s32 slot, s32 index, s32 falls);
s32 Player_GetKOsByPlayerIndex(s32 slot, s32 index);
void Player_UpdateKOsBySlot(s32 slot, BOOL bool_arg, s32 other_slot);
u32 Player_GetMatchFrameCount(s32 slot);
void Player_UpdateMatchFrameCount(s32 slot, BOOL condition);
u16 Player_GetSuicideCount(s32 slot);
void Player_SetSuicideCount(s32 slot, u32 suicide_count);
void Player_IncSuicideCount(s32 slot, s32 condition);
BOOL Player_800353BC(s32 slot);
BOOL Player_8003544C(s32 slot, BOOL condition);
void Player_SetFlagsBit0(s32 slot, s32 bit0);
s8 Player_GetNametagSlotID(s32 slot);
void Player_SetNametagSlotID(s32 slot, s32 nametag_slot_id);
s32 Player_GetFlagsBit1(s32 slot);
void Player_SetFlagsBit1(s32 slot);
void Player_UnsetFlagsBit1(s32 slot);
s32 Player_GetFlagsBit3(s32 slot);
void Player_SetFlagsBit3(s32 slot, u8 bit3);
u8 Player_GetFlagsBit4(s32 slot);
u8 Player_GetFlagsBit5(s32 slot);
void Player_SetFlagsBit5(s32 slot, u8 bit5);
u8 Player_GetFlagsBit6(s32 slot);
void Player_SetFlagsBit6(s32 slot, u8 bit6);
u8 Player_GetFlagsBit7(s32 slot);
void Player_SetFlagsBit7(s32 slot, u8 bit7);
u8 Player_GetMoreFlagsBit0(s32 slot);
u8 Player_GetMoreFlagsBit1(s32 slot);
void Player_SetMoreFlagsBit1(s32 slot, u8 bit1);
s32 Player_GetUnk4D(s32 slot);
void Player_SetUnk4D(s32 slot, s8 unk4D);
u8 Player_GetFlagsAEBit1(s32 slot);
u8 Player_SetFlagsAEBit1(s32 slot, u8 bit1);
u8 Player_GetUnk4C(s32 slot);
void Player_SetUnk4C(s32 slot, u8 unk4C);
void Player_80036058(s32 slot);
void Player_800360D8(s32 slot);
void Player_SetStructFunc(s32 slot, void* arg_func);
s32* Player_GetTotalAttackCountPtr(s32 slot);
s32* Player_GetStaleMoveTableIndexPtr(s32 slot);
s32* Player_GetUnk6A8Ptr(s32 slot);
s32* Player_GetStaleMoveTableIndexPtr2(s32 slot);
s32 Player_80036394(s32 slot);
s32 Player_80036428(s32 slot);
void Player_SetUnk45(s32 slot, s8 unk45);
u8 Player_GetUnk45(s32 slot);
void Player_UpdateJoystickCountByIndex(s32 slot, s32 index);
s32 Player_GetJoystickCountByIndex(s32 slot, s32 index);
void Player_800366DC(s32 slot, s32 arg1);
void Player_80036790(s32 slot, f32 arg1);
void Player_80036844(s32 slot, s32 arg1);
void Player_800368F8(s32 slot);
void Player_80036978(s32 slot, s32 arg1);
void Player_InitOrResetPlayer(s32 slot);
void Player_80036CF0(s32 slot);
void Player_80036D24(s32 slot);
void Player_InitAllPlayers();
void Player_80036DA4();
void Player_80036DD8();
void Player_80036E20(s32 arg0, s32 arg1, s32 arg2);
s32 Player_80036EA0(s32 slot);
void Player_80036F34(s32 slot, s32 arg1);
void Player_80037054(s32 slot, s32 arg1);
typedef Vec Vec3;
enum InternalStageID {
    CASTLE = 0x02,
    RCRUISE = 0x03,
    KONGO = 0x04,
    GARDEN = 0x05,
    GREATBAY = 0x06,
    SHRINE = 0x07,
    ZEBES = 0x08,
    KRAID = 0x09,
    STORY = 0x0A,
    YORSTER = 0x0B,
    IZUMI = 0x0C,
    GREENS = 0x0D,
    CORNERIA = 0x0E,
    VENOM = 0x0F,
    PSTADIUM = 0x10,
    PURA = 0x11,
    MUTECITY = 0x12,
    BIGBLUE = 0x13,
    ONETT = 0x14,
    FOURSIDE = 0x15,
    ICEMTN = 0x16,
    INISHIE1 = 0x18,
    INISHIE2 = 0x19,
    FLATZONE = 0x1B,
    OLDPUPUPU = 0x1C,
    OLDYOSHI = 0x1D,
    OLDKONGO = 0x1E,
};
typedef struct _StageCameraInfo {
    f32 cam_bounds_left;
    f32 cam_bounds_right;
    f32 cam_bounds_top;
    f32 cam_bounds_bottom;
    f32 cam_x_offset;
    f32 cam_y_offset;
    f32 cam_vertical_tilt;
    f32 cam_pan_degrees;
    f32 x20;
    f32 x24;
    f32 cam_track_ratio;
    f32 cam_fixed_zoom;
    f32 cam_track_smooth;
    f32 cam_zoom_rate;
    f32 cam_max_depth;
    f32 x3C;
    f32 pausecam_zpos_min;
    f32 pausecam_zpos_init;
    f32 pausecam_zpos_max;
    f32 cam_angle_up;
    f32 cam_angle_down;
    f32 cam_angle_left;
    f32 cam_angle_right;
    Vec fixed_cam_pos;
    f32 fixed_cam_fov;
    f32 fixed_cam_vert_angle;
    f32 fixed_cam_horz_angle;
} StageCameraInfo;
typedef struct _StageBlastZone {
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;
} StageBlastZone;
typedef struct _StageAnim {
    struct _HSD_Joint* joint;
    struct _HSD_AnimJoint** anims;
} StageAnim;
typedef struct _StageInfo {
    StageCameraInfo cam_info;
    StageBlastZone blast_zone;
    u32 x84;
    s32 internal_stage_id;
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } unk8C;
    s32 x90;
    s32 x94;
    s32 x98;
    s32 x9C;
    u8 xA0[4];
    u8 xA4_pad[0x12C - 0xA4];
    struct {
        u8 x0_pad[0x28];
        struct {
            u8 x0_pad[0x18];
            GXColor color;
        }* ptr;
    }* x12C;
    Vec3 x130, x13C, x148, x154, x160, x16C;
    BOOL (*x178)(s32);
    void* x17C;
    struct _HSD_GObj* x180[4];
    u8 x190_pad[0x280 - 0x190];
    struct _HSD_JObj* x280[261];
    void* x694[4];
    void* x6A4;
    struct {
        s32 unk0;
        s32 unk4;
    }** x6A8;
    void* x6AC;
    struct _UnkStage6B0* x6B0;
    u32* x6B4;
    void* x6B8;
    void* x6BC;
    void* x6C0;
    void* x6C4;
    void* x6C8;
    StageAnim* x6CC;
    s16 x6D0;
    s16 x6D2;
    s16 x6D4;
    s16 x6D6;
    s32 x6D8;
    s16 x6DC;
    s16 x6DE;
    f32 x6E0;
    s32 x6E4[2];
    u8 x6EC_pad[0x708 - 0x6EC];
    s16 x708;
    f32 x70C;
    f32 x710;
    s32 x714;
    f32 x718;
    f32 x71C;
    s32 x720;
    f32 x724;
    f32 x728;
    s32 x72C;
    Vec3 x730;
    f32 x73C;
    s32 x740;
    u8 x744_pad[0x748 - 0x744];
} StageInfo;
typedef struct {
    void (*callback0)(struct _HSD_GObj*);
    s32 (*callback1)();
    void (*callback2)(struct _HSD_GObj*);
    void (*callback3)();
    u32 flags;
} StageCallbacks;
typedef struct _StageData {
    u32 flags1;
    StageCallbacks* callbacks;
    char* data1;
    void (*callback0)(void);
    void (*callback1)(s32);
    void (*callback2)(void);
    void (*callback3)(void);
    s32 (*callback4)();
    BOOL (*callback5)(s32);
    s32 (*callback6)(Vec*, s32, struct _HSD_JObj*);
    u32 flags2;
    S16Vec* x2C;
    s32 x30;
} StageData;
typedef struct _StructPairWithStageID {
    s32 stage_id;
    s32 list_idx;
} StructPairWithStageID;
typedef struct _Map {
    int x0;
    struct _HSD_GObj* gobj;
    void (*x8_callback)(struct _HSD_GObj*);
    void (*xC_callback)(struct _HSD_GObj*);
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } x10_flags;
    struct {
        u8 b012 : 3;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } x11_flags;
    int map_id;
    struct _HSD_GObj* x18;
    void (*x1C_callback)(struct _HSD_GObj*);
    s32 x20[8];
    u8 x40_pad[0xC4 - 0x40];
    s32 xC4;
    s32 xC8;
    s32 xCC;
    s32 xD0;
    u8 xD4_pad[0x218 - 0xD4];
} Map;
f32 Stage_GetCamBoundsLeftOffset();
f32 Stage_GetCamBoundsRightOffset();
f32 Stage_GetCamBoundsTopOffset();
f32 Stage_GetCamBoundsBottomOffset();
f32 Stage_GetCamPanAngleRadians();
f32 Stage_GetCamMaxDepth();
f32 Stage_GetCamZoomRate();
f32 Stage_GetCamInfoX20();
f32 Stage_GetCamInfoX24();
f32 Stage_GetCamFixedZoom();
f32 Stage_GetCamTrackRatio();
f32 Stage_GetCamTrackSmooth();
f32 Stage_GetBlastZoneRightOffset();
f32 Stage_GetBlastZoneLeftOffset();
f32 Stage_GetBlastZoneTopOffset();
f32 Stage_GetBlastZoneBottomOffset();
f32 Stage_CalcUnkCamY();
f32 Stage_CalcUnkCamYBounds();
void Stage_UnkSetVec3TCam_Offset(Vec* vec3);
f32 Stage_GetPauseCamZPosMin();
f32 Stage_GetPauseCamZPosInit();
f32 Stage_GetPauseCamZPosMax();
f32 Stage_GetCamAngleRadiansUp();
f32 Stage_GetCamAngleRadiansDown();
f32 Stage_GetCamAngleRadiansLeft();
f32 Stage_GetCamAngleRadiansRight();
void Stage_80224CAC(Vec* arg0);
void Stage_SetVecToFixedCamPos(Vec* arg0);
f32 Stage_GetCamFixedFov();
BOOL Stage_80224DC8(s32 arg);
void Stage_80224E38(Vec* arg0, s32 arg1);
void Stage_80224E64(s32 arg0, Vec* arg_vec);
s32 Stage_80224FDC(Vec* arg0);
s32 Stage_80225074(s32 arg0);
s32 Stage_80225194();
s32 Stage_8022519C(s32 idx);
s32 Stage_802251B4(s32 idx, s32 arg1);
void Stage_802251E8(s32 idx, s32* unused);
void Stage_8022524C();
void Stage_80225298();
void Stage_802252E4(s32 idx, s32 unused);
void Stage_8022532C(s32 idx, s32 arg1);
#pragma cplusplus on
extern inline float sqrtf(float x)
{
static const double _half=.5;
static const double _three=3.0;
volatile float y;
 if(x > 0.0f)
 {
   double guess = __frsqrte((double)x);
   guess = _half*guess*(_three - guess*guess*x);
   guess = _half*guess*(_three - guess*guess*x);
   guess = _half*guess*(_three - guess*guess*x);
   y=(float)(x*guess);
   return y ;
 }
  return x;
}
#pragma cplusplus reset
enum FloatType { FP_NAN=1, FP_INFINITE=2, FP_ZERO=3, FP_NORMAL=4, FP_SUBNORMAL=5 };
inline s32 __fpclassifyf(float x)
{
 const s32 exp_mask = 0b01111111100000000000000000000000;
 const s32 mantissa_mask = 0b00000000011111111111111111111111;
 switch ((*(s32*)&x) & exp_mask)
 {
  case exp_mask: return ((*(s32*)&x) & mantissa_mask) ? FP_NAN : FP_INFINITE;
  case 0: return ((*(s32*)&x) & mantissa_mask) ? FP_SUBNORMAL : FP_ZERO;
  default: return FP_NORMAL;
 }
}
inline s32 __fpclassifyd(double x)
{
 switch (__HI(x) & 0x7ff00000)
 {
  case 0x7ff00000: return ((__HI(x) & 0x000fffff) || (__LO(x) & 0xffffffff)) ? FP_NAN : FP_INFINITE;
  case 0: return ((__HI(x) & 0x000fffff) || (__LO(x) & 0xffffffff)) ? FP_SUBNORMAL : FP_ZERO;
  default: return FP_NORMAL;
 }
}

void func_80390C5C(HSD_GObj* gobj);
void func_80390C84(HSD_GObj* gobj);
void func_80390CAC(HSD_GObj* gobj);
void func_80390C5C(HSD_GObj* gobj);
void func_80390C84(HSD_GObj* gobj);
void func_80390CAC(HSD_GObj* gobj);
void GObj_InitUserData(HSD_GObj *gobj, u8 kind, void (*remove_func)(), void *data);
void GObj_RemoveUserData(HSD_GObj *gobj);
void func_80390C5C(HSD_GObj* gobj);
void func_80390C84(HSD_GObj* gobj);
void func_80390CAC(HSD_GObj* gobj);
void GObj_GXReorder(HSD_GObj* gobj, HSD_GObj* hiprio_gobj);
void GObj_SetupGXLink(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32), u8 gx_link, u32 priority);
void GObj_SetupGXLinkMax(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32), u32 priority);
void GObj_SetupGXLinkMaxSorted(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32), u32 priority);
typedef enum _HSD_TEInput {
    HSD_TE_END = 0,
    HSD_TE_RGB = 1,
    HSD_TE_R = 2,
    HSD_TE_G = 3,
    HSD_TE_B = 4,
    HSD_TE_A = 5,
    HSD_TE_X = 6,
    HSD_TE_0 = 7,
    HSD_TE_1 = 8,
    HSD_TE_1_8 = 9,
    HSD_TE_2_8 = 10,
    HSD_TE_3_8 = 11,
    HSD_TE_4_8 = 12,
    HSD_TE_5_8 = 13,
    HSD_TE_6_8 = 14,
    HSD_TE_7_8 = 15,
    HSD_TE_INPUT_MAX = 16,
    HSD_TE_UNDEF = 0xFF
} HSD_TEInput;
typedef enum _HSD_TEType {
    HSD_TE_U8 = 0,
    HSD_TE_U16 = 1,
    HSD_TE_U32 = 2,
    HSD_TE_F32 = 3,
    HSD_TE_F64 = 4,
    HSD_TE_COMP_TYPE_MAX = 5
} HSD_TEType;
typedef enum _HSD_TExpType {
    HSD_TE_ZERO = 0,
    HSD_TE_TEV = 1,
    HSD_TE_TEX = 2,
    HSD_TE_RAS = 3,
    HSD_TE_CNST = 4,
    HSD_TE_IMM = 5,
    HSD_TE_KONST = 6,
    HSD_TE_ALL = 7,
    HSD_TE_TYPE_MAX = 8
} HSD_TExpType;
typedef struct _HSD_TevConf {
    u32 clr_op;
    u32 clr_a;
    u32 clr_b;
    u32 clr_c;
    u32 clr_d;
    u32 clr_scale;
    u32 clr_bias;
    u32 clr_clamp;
    u32 clr_out_reg;
    u32 alpha_op;
    u32 alpha_a;
    u32 alpha_b;
    u32 alpha_c;
    u32 alpha_d;
    u32 alpha_scale;
    u32 alpha_bias;
    u32 alpha_clamp;
    u32 alpha_out_reg;
    u32 mode;
    u32 ras_swap;
    u32 tex_swap;
    u32 kcsel;
    u32 kasel;
} HSD_TevConf;
typedef struct _HSD_TevDesc {
    struct _HSD_TevDesc* next;
    u32 flags;
    u32 stage;
    u32 coord;
    u32 map;
    u32 color;
    union {
        HSD_TevConf tevconf;
        struct {
            u32 tevmode;
        } tevop;
    } u;
} HSD_TevDesc;
typedef struct _HSD_TExpTevDesc {
    struct _HSD_TevDesc desc;
    struct _HSD_TObj* tobj;
} HSD_TExpTevDesc;
typedef struct _HSD_TECommon {
    HSD_TExpType type;
    union _HSD_TExp* next;
} HSD_TECommon;
typedef struct _HSD_TECnst {
    HSD_TExpType type;
    union _HSD_TExp* next;
    void* val;
    HSD_TEInput comp;
    HSD_TEType ctype;
    u8 reg;
    u8 idx;
    u8 ref;
    u8 range;
} HSD_TECnst;
typedef struct _HSD_TEArg {
    u8 type;
    u8 sel;
    u8 arg;
    union _HSD_TExp* exp;
} HSD_TEArg;
typedef struct _HSD_TETev {
    HSD_TExpType type;
    union _HSD_TExp* next;
    s32 c_ref;
    u8 c_dst;
    u8 c_op;
    u8 c_clamp;
    u8 c_bias;
    u8 c_scale;
    u8 c_range;
    s32 a_ref;
    u8 a_dst;
    u8 a_op;
    u8 a_clamp;
    u8 a_bias;
    u8 a_scale;
    u8 tex_swap;
    u8 ras_swap;
    u8 kcsel;
    u8 kasel;
    HSD_TEArg c_in[4];
    HSD_TEArg a_in[4];
    struct _HSD_TObj* tex;
    u8 chan;
} HSD_TETev;
typedef union _HSD_TExp {
    HSD_TExpType type;
    struct _HSD_TECommon comm;
    struct _HSD_TETev tev;
    struct _HSD_TECnst cnst;
} HSD_TExp;
HSD_TExpType HSD_TExpGetType(HSD_TExp* texp);
typedef struct _HSD_TObj {
    HSD_Obj parent;
    struct _HSD_TObj* next;
    u32 id;
    u32 src;
    GXTexMtx mtxid;
    Quaternion rotate;
    Vec scale;
    Vec translate;
    u32 wrap_s;
    u32 wrap_t;
    u8 repeat_s;
    u8 repeat_t;
    u32 flags;
    f32 blending;
    u32 magFilt;
    struct _HSD_ImageDesc* imagedesc;
    struct _HSD_Tlut* tlut;
    struct _HSD_TexLODDesc* lod;
    struct _HSD_AObj* aobj;
    struct _HSD_ImageDesc** imagetbl;
    struct _HSD_Tlut** tluttbl;
    u8 tlut_no;
    Mtx mtx;
    u32 coord;
    struct _HSD_TObjTev* tev;
} HSD_TObj;
typedef struct _HSD_TObjDesc {
    char* class_name;
    struct _HSD_TObjDesc* next;
    u32 id;
    u32 src;
    Vec rotate;
    Vec scale;
    Vec translate;
    u32 wrap_s;
    u32 wrap_t;
    u8 repeat_s;
    u8 repeat_t;
    u32 blend_flags;
    f32 blending;
    u32 magFilt;
    struct _HSD_ImageDesc* imagedesc;
    struct _HSD_TlutDesc* tlutdesc;
    struct _HSD_TexLODDesc* lod;
    struct _HSD_TObjTevDesc* tev;
} HSD_TObjDesc;
typedef struct _HSD_Tlut {
    void* lut;
    u32 fmt;
    u32 tlut_name;
    u16 n_entries;
} HSD_Tlut;
typedef struct _HSD_TlutDesc {
    void* lut;
    u32 fmt;
    u32 tlut_name;
    u16 n_entries;
} HSD_TlutDesc;
typedef struct _HSD_TexLODDesc {
    u32 minFilt;
    f32 LODBias;
    u8 bias_clamp;
    u8 edgeLODEnable;
    u32 max_anisotropy;
} HSD_TexLODDesc;
typedef struct _HSD_ImageDesc {
    void* img_ptr;
    u16 width;
    u16 height;
    u32 format;
    u32 mipmap;
    f32 minLOD;
    f32 maxLOD;
} HSD_ImageDesc;
typedef struct _HSD_TObjTev {
    u8 color_op;
    u8 alpha_op;
    u8 color_bias;
    u8 alpha_bias;
    u8 color_scale;
    u8 alpha_scale;
    u8 color_clamp;
    u8 alpha_clamp;
    u8 color_a, color_b, color_c, color_d;
    u8 alpha_a, alpha_b, alpha_c, alpha_d;
    GXColor konst, tev0, tev1;
    u32 active;
} HSD_TObjTev;
typedef struct _HSD_TObjTevDesc {
    u8 color_op;
    u8 alpha_op;
    u8 color_bias;
    u8 alpha_bias;
    u8 color_scale;
    u8 alpha_scale;
    u8 color_clamp;
    u8 alpha_clamp;
    u8 color_a, color_b, color_c, color_d;
    u8 alpha_a, alpha_b, alpha_c, alpha_d;
    GXColor konst, tev0, tev1;
    u32 active;
} HSD_TObjTevDesc;
typedef struct _HSD_TObjInfo {
    HSD_ClassInfo parent;
    void (*make_mtx)(HSD_TObj* tobj);
    int (*load)(HSD_TObj* tobj, HSD_TObjDesc* desc);
    void (*make_texp)(HSD_TObj* tobj, u32 lightmap, u32 lightmap_done, HSD_TExp** c, HSD_TExp** a, HSD_TExp** list);
} HSD_TObjInfo;
typedef struct _HSD_TexAnim {
    struct _HSD_TexAnim* next;
    s32 id;
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_ImageDesc** imagetbl;
    struct _HSD_TlutDesc** tluttbl;
    u16 n_imagetbl;
    u16 n_tluttbl;
} HSD_TexAnim;
extern HSD_TObjInfo hsdTObj;
void HSD_TObjRemoveAnimAll(HSD_TObj* tobj);
void HSD_TObjAddAnim(HSD_TObj* tobj, HSD_TexAnim* texanim);
void HSD_TObjAddAnimAll(HSD_TObj* tobj, HSD_TexAnim* texanim);
void HSD_TObjReqAnimAllByFlags(HSD_TObj* tobj, f32 startframe, u32 flags);
void HSD_TObjReqAnim(HSD_TObj* tobj, f32 startframe);
void HSD_TObjReqAnimAll(HSD_TObj* tobj, f32 startframe);
void HSD_TObjAnim(HSD_TObj* tobj);
void HSD_TObjAnimAll(HSD_TObj* tobj);
int TObjLoad(HSD_TObj* tobj, HSD_TObjDesc* td);
HSD_TObj* HSD_TObjLoadDesc(HSD_TObjDesc* td);
HSD_Tlut* HSD_TlutLoadDesc(HSD_TlutDesc* tlutdesc);
HSD_TObjTev* HSD_TObjTevLoadDesc(HSD_TObjTevDesc* tevdesc);
HSD_TObj* _HSD_TObjGetCurrentByType(HSD_TObj* from, u32 mapping);
void HSD_TObjRemoveAll(HSD_TObj* tobj);
HSD_TObj* HSD_TObjGetNext(HSD_TObj* tobj);
HSD_TObj* HSD_TObjAlloc(void);
void HSD_TObjFree(HSD_TObj* tobj);
void HSD_TObjSetDefaultClass(HSD_TObjInfo* info);
HSD_TObjInfo* HSD_TObjGetDefaultClass(void);
HSD_Tlut* HSD_TlutAlloc(void);
void HSD_TlutFree(HSD_Tlut* tlut);
HSD_TObjTev* HSD_TObjTevAlloc(void);
HSD_ImageDesc* HSD_ImageDescAlloc(void);
void HSD_ImageDescFree(HSD_ImageDesc* idesc);
void HSD_ImageDescCopyFromEFB(HSD_ImageDesc* idesc, u16 origx, u16 origy, u8 clear, s32 sync);
void HSD_TObjSetupTextureCoordGen(HSD_TObj* tobj);
void HSD_TObjSetupVolatileTev(HSD_TObj* tobj, u32 rendermode);
s32 HSD_TObjAssignResources(HSD_TObj* tobj_top);
void HSD_TObjSetup(HSD_TObj* tobj);
u32 HSD_TGTex2Index(u32 tgtex);
u32 HSD_TexCoordID2TexGenSrc(u32 coord);
u32 HSD_TexCoord2Index(u32 coord_id);
u32 HSD_Index2TexCoord(u32 index);
u32 HSD_TexMtx2Index(u32 texmtx);
u32 HSD_Index2TexMtx(u32 index);
u8 HSD_Index2TexMap(u32 index);
u32 HSD_TexMap2Index(u8 mapid);
typedef struct _HSD_MObj {
    HSD_Class parent;
    u32 rendermode;
    struct _HSD_TObj* tobj;
    struct _HSD_Material* mat;
    struct _HSD_PEDesc* pe;
    struct _HSD_AObj* aobj;
    struct _HSD_TExpTevDesc* tevdesc;
    union _HSD_TExp* texp;
    struct _HSD_TObj* tobj_toon;
    struct _HSD_TObj* tobj_gradation;
    struct _HSD_TObj* tobj_backlight;
    f32 z_offset;
} HSD_MObj;
typedef struct _HSD_Material {
    GXColor ambient;
    GXColor diffuse;
    GXColor specular;
    f32 alpha;
    f32 shininess;
} HSD_Material;
typedef struct _HSD_PEDesc {
    u8 flags;
    u8 ref0;
    u8 ref1;
    u8 dst_alpha;
    u8 type;
    u8 src_factor;
    u8 dst_factor;
    u8 logic_op;
    u8 z_comp;
    u8 alpha_comp0;
    u8 alpha_op;
    u8 alpha_comp1;
} HSD_PEDesc;
typedef struct _HSD_MObjDesc {
    char* class_name;
    u32 rendermode;
    struct _HSD_TObjDesc* texdesc;
    struct _HSD_Material* mat;
    void* renderdesc;
    struct _HSD_PEDesc* pedesc;
} HSD_MObjDesc;
typedef struct _HSD_ChanAnim {
    struct _HSD_ChanAnim* next;
    struct _HSD_AObjDesc* aobjdesc;
} HSD_ChanAnim;
typedef struct _HSD_TevRegAnim {
    struct _HSD_TevRegAnim* next;
    struct _HSD_AObjDesc* aobjdesc;
} HSD_TevRegAnim;
typedef struct _HSD_RenderAnim {
    struct _HSD_ChanAnim* chananim;
    struct _HSD_TevRegAnim* reganim;
} HSD_RenderAnim;
typedef struct _HSD_MatAnim {
    struct _HSD_MatAnim* next;
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_TexAnim* texanim;
    struct _HSD_RenderAnim* renderanim;
} HSD_MatAnim;
typedef struct _HSD_MatAnimJoint {
    struct _HSD_MatAnimJoint* child;
    struct _HSD_MatAnimJoint* next;
    struct _HSD_MatAnim* matanim;
} HSD_MatAnimJoint;
typedef struct _HSD_MObjInfo {
    HSD_ClassInfo parent;
    void (*setup)(HSD_MObj* mobj, u32 rendermode);
    int (*load)(HSD_MObj* mobj, HSD_MObjDesc* desc);
    HSD_TExp* (*make_texp)(HSD_MObj* mobj, HSD_TObj* tobj_top, HSD_TExp** list);
    void (*setup_tev)(HSD_MObj* mobj, HSD_TObj* tobj, u32 rendermode);
    void (*unset)(HSD_MObj* mobj, u32 rendermode);
} HSD_MObjInfo;
extern HSD_MObjInfo hsdMObj;
void HSD_MObjSetCurrent(HSD_MObj* mobj);
void HSD_MObjSetFlags(HSD_MObj* mobj, u32 flags);
void HSD_MObjClearFlags(HSD_MObj* mobj, u32 flags);
void HSD_MObjRemoveAnimByFlags(HSD_MObj* mobj, u32 flags);
void HSD_MObjAddAnim(HSD_MObj* mobj, HSD_MatAnim* matanim);
void HSD_MObjReqAnimByFlags(HSD_MObj* mobj, f32 startframe, u32 flags);
void HSD_MObjReqAnim(HSD_MObj *mobj, f32 startframe);
void MObjUpdateFunc(void* obj, u32 type, FObjData* val);
void HSD_MObjAnim(HSD_MObj* mobj);
int MObjLoad(HSD_MObj* mobj, HSD_MObjDesc* desc);
HSD_MObj* HSD_MObjLoadDesc(HSD_MObjDesc* mobjdesc);
HSD_MObj* HSD_MObjAlloc();
HSD_Material* HSD_MaterialAlloc();
void HSD_MObjCompileTev(HSD_MObj *mobj);
typedef struct _HSD_DObj {
    HSD_Class parent;
    struct _HSD_DObj* next;
    struct _HSD_MObj* mobj;
    struct _HSD_PObj* pobj;
    struct _HSD_AObj* aobj;
    u32 flags;
} HSD_DObj;
typedef struct _HSD_DObjDesc {
    char* class_name;
    struct _HSD_DObjDesc* next;
    struct _HSD_MObjDesc* mobjdesc;
    struct _HSD_PObjDesc* pobjdesc;
} HSD_DObjDesc;
typedef struct _HSD_DObjInfo {
    HSD_ClassInfo parent;
    void (*disp)(HSD_DObj* dobj, Mtx vmtx, Mtx pmtx, u32 rendermode);
    int (*load)(HSD_DObj* dobj, HSD_DObjDesc* desc);
} HSD_DObjInfo;
typedef struct _HSD_ShapeAnimDObj {
    struct _HSD_ShapeAnimDObj* next;
    struct _HSD_ShapeAnim* shapeanim;
} HSD_ShapeAnimDObj;
void HSD_DObjSetCurrent(HSD_DObj* dobj);
u32 HSD_DObjGetFlags(HSD_DObj* dobj);
void HSD_DObjSetFlags(HSD_DObj* dobj, u32 flags);
void HSD_DObjClearFlags(HSD_DObj* dobj, u32 flags);
void HSD_DObjModifyFlags(HSD_DObj* dobj, u32 flags, u32 mask);
void HSD_DObjRemoveAnimByFlags(HSD_DObj* dobj, u32 flags);
void HSD_DObjRemoveAnimAllByFlags(HSD_DObj* dobj, u32 flags);
void HSD_DObjAddAnim(HSD_DObj* dobj, HSD_MatAnim* mat_anim, HSD_ShapeAnimDObj* sh_anim);
void HSD_DObjAddAnimAll(HSD_DObj* dobj, HSD_MatAnim* matanim, HSD_ShapeAnimDObj* shapeanimdobj);
void HSD_DObjReqAnimByFlags(HSD_DObj* dobj, f32 startframe, u32 flags);
void HSD_DObjReqAnimAllByFlags(HSD_DObj* dobj, f32 startframe, u32 flags);
void HSD_DObjReqAnimAll(HSD_DObj* dobj, f32 startframe);
void HSD_DObjAnim(HSD_DObj* dobj);
void HSD_DObjAnimAll(HSD_DObj* dobj);
HSD_DObj* HSD_DObjLoadDesc(HSD_DObjDesc* desc) ;
void HSD_DObjRemoveAll(HSD_DObj* dobj);
HSD_DObj* HSD_DObjAlloc(void);
void HSD_DObjResolveRefs(HSD_DObj* dobj, HSD_DObjDesc* desc);
void HSD_DObjResolveRefsAll(HSD_DObj* dobj, HSD_DObjDesc* desc);
void HSD_DObjDisp(HSD_DObj* dobj, Mtx vmtx, Mtx pmtx, u32 rendermode);
s32 HSD_Rand(void);
f32 HSD_Randf(void);
s32 HSD_Randi(s32 max_val);
void _HSD_RandForgetMemory(u32* low, u32* high);
typedef struct PADStatus
{
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} PADStatus;
void PADControlMotor(int chan, u32 command);
typedef enum _HSD_FlushType {
    HSD_PAD_FLUSH_QUEUE_MERGE = 0,
    HSD_PAD_FLUSH_QUEUE_THROWAWAY = 1,
    HSD_PAD_FLUSH_QUEUE_LEAVE1 = 2,
    HSD_PAD_FLUSH_QUEUE_TERMINATE = 3
} HSD_FlushType;
typedef struct _RumbleCommand {
    u16 op;
    u16 frame;
} RumbleCommand;
typedef union _HSD_Rumble {
    u16 def;
    struct _RumbleCommand command;
} HSD_Rumble;
typedef struct _HSD_RumbleData {
    u8 last_status;
    u8 status;
    u8 direct_status;
    u16 nb_list;
    struct _HSD_PadRumbleListData* listdatap;
} HSD_RumbleData;
typedef struct _HSD_PadRumbleListData {
    struct _HSD_PadRumbleListData* next;
    u32 id;
    u8 pause;
    u8 pri;
    u8 status;
    u16 loop_count;
    u16 wait;
    s32 frame;
    HSD_Rumble* stack;
    HSD_Rumble* listp;
    HSD_Rumble* headp;
} HSD_PadRumbleListData;
typedef struct _HSD_PadData {
    PADStatus stat[4];
    u32 rumble_mask;
} HSD_PadData;
typedef struct _HSD_PadStatus {
    u32 button;
    u32 last_button;
    u32 trigger;
    u32 repeat;
    u32 release;
    s32 repeat_count;
    s8 stickX;
    s8 stickY;
    s8 subStickX;
    s8 subStickY;
    u8 analogL;
    u8 analogR;
    u8 analogA;
    u8 analogB;
    f32 nml_stickX;
    f32 nml_stickY;
    f32 nml_subStickX;
    f32 nml_subStickY;
    f32 nml_analogL;
    f32 nml_analogR;
    f32 nml_analogA;
    f32 nml_analogB;
    u8 cross_dir;
    u8 support_rumble;
    s8 err;
} HSD_PadStatus;
typedef struct _PadLibData {
    u8 qnum;
    u8 qread;
    u8 qwrite;
    u8 qcount;
    u8 qtype;
    struct _HSD_PadData* queue;
    s32 repeat_start;
    s32 repeat_interval;
    u8 adc_type;
    s8 adc_th;
    f32 adc_angle;
    u8 clamp_stickType;
    u8 clamp_stickShift;
    s8 clamp_stickMax;
    s8 clamp_stickMin;
    u8 clamp_analogLRShift;
    u8 clamp_analogLRMax;
    u8 clamp_analogLRMin;
    u8 clamp_analogABShift;
    u8 clamp_analogABMax;
    u8 clamp_analogABMin;
    s8 scale_stick;
    u8 scale_analogLR;
    u8 scale_analogAB;
    u8 cross_dir;
    u8 reset_switch_status;
    u8 reset_switch;
    struct {
        u16 max_list;
        struct _HSD_PadRumbleListData* listdatap;
    } rumble_info;
} PadLibData;
u8 HSD_PadGetRawQueueCount(void);
s32 HSD_PadGetResetSwitch(void);
typedef struct _HSD_ArchiveHeader {
    u32 file_size;
    u32 data_size;
    u32 nb_reloc;
    u32 nb_public;
    u32 nb_extern;
    u8 version[4];
    u32 pad[2];
} HSD_ArchiveHeader;
typedef struct _HSD_ArchiveRelocationInfo {
    u32 offset;
} HSD_ArchiveRelocationInfo;
typedef struct _HSD_ArchivePublicInfo {
    u32 offset;
    u32 symbol;
} HSD_ArchivePublicInfo;
typedef struct _HSD_ArchiveExternInfo {
    u32 offset;
    u32 symbol;
} HSD_ArchiveExternInfo;
typedef struct _HSD_Archive {
    struct _HSD_ArchiveHeader header;
    u8* data;
    struct _HSD_ArchiveRelocationInfo* reloc_info;
    struct _HSD_ArchivePublicInfo* public_info;
    struct _HSD_ArchiveExternInfo* extern_info;
    char* symbols;
    struct _HSD_Archive* next;
    char* name;
    u32 flags;
    void* top_ptr;
} HSD_Archive;
s32 HSD_ArchiveParse(HSD_Archive*, u8*, u32);
void* HSD_ArchiveGetPublicAddress(HSD_Archive*, char*);
char* HSD_ArchiveGetExtern(HSD_Archive*, s32);
void HSD_ArchiveLocateExtern(HSD_Archive*, char*, void*);
BOOL func_80081298(HSD_GObj* gobj);
typedef enum FighterKind
{
    FTKIND_MARIO,
    FTKIND_FOX,
    FTKIND_CAPTAIN,
    FTKIND_DONKEY,
    FTKIND_KIRBY,
    FTKIND_KOOPA,
    FTKIND_LINK,
    FTKIND_SEAK,
    FTKIND_NESS,
    FTKIND_PEACH,
    FTKIND_POPO,
    FTKIND_NANA,
    FTKIND_PIKACHU,
    FTKIND_SAMUS,
    FTKIND_YOSHI,
    FTKIND_PURIN,
    FTKIND_MEWTWO,
    FTKIND_LUIGI,
    FTKIND_MARS,
    FTKIND_ZELDA,
    FTKIND_CLINK,
    FTKIND_DRMARIO,
    FTKIND_FALCO,
    FTKIND_PICHU,
    FTKIND_GAMEWATCH,
    FTKIND_GANON,
    FTKIND_EMBLEM,
    FTKIND_MASTERH,
    FTKIND_CREZYH,
    FTKIND_BOY,
    FTKIND_GIRL,
    FTKIND_GKOOPS,
    FTKIND_SANDBAG,
    FTKIND_NONE
} FighterKind;
typedef enum CharacterKind
{
    CKIND_CAPTAIN,
    CKIND_DONKEY,
    CKIND_FOX,
    CKIND_GAMEWATCH,
    CKIND_KIRBY,
    CKIND_KOOPA,
    CKIND_LINK,
    CKIND_LUIGI,
    CKIND_MARIO,
    CKIND_MARS,
    CKIND_MEWTWO,
    CKIND_NESS,
    CKIND_PEACH,
    CKIND_PIKACHU,
    CKIND_POPONANA,
    CKIND_PURIN,
    CKIND_SAMUS,
    CKIND_YOSHI,
    CKIND_ZELDA,
    CKIND_SEAK,
    CKIND_FALCO,
    CKIND_CLINK,
    CKIND_DRMARIO,
    CKIND_EMBLEM,
    CKIND_PICHU,
    CKIND_GANON,
    CKIND_MASTERH,
    CKIND_BOY,
    CKIND_GIRL,
    CKIND_GKOOPS,
    CKIND_CREZYH,
    CHKIND_SANDBAG,
    CHKIND_POPO,
    CHKIND_NONE
} CharacterKind;
typedef enum ftCommonAction
{
    ASID_DEADDOWN,
    ASID_DEADLEFT,
    ASID_DEADRIGHT,
    ASID_DEADUP,
    ASID_DEADUPSTAR,
    ASID_DEADUPSTARICE,
    ASID_DEADUPFALL,
    ASID_DEADUPFALLHITCAMERA,
    ASID_DEADUPFALLHITCAMERAFLAT,
    ASID_DEADUPFALLICE,
    ASID_DEADUPFALLHITCAMERAICE,
    ASID_SLEEP,
    ASID_REBIRTH,
    ASID_REBIRTHWAIT,
    ASID_WAIT,
    ASID_WALKSLOW,
    ASID_WALKMIDDLE,
    ASID_WALKFAST,
    ASID_TURN,
    ASID_TURNRUN,
    ASID_DASH,
    ASID_RUN,
    ASID_RUNDIRECT,
    ASID_RUNBRAKE,
    ASID_KNEEBEND,
    ASID_JUMPF,
    ASID_JUMPB,
    ASID_JUMPAERIALF,
    ASID_JUMPAERIALB,
    ASID_FALL,
    ASID_FALLF,
    ASID_FALLB,
    ASID_FALLAERIAL,
    ASID_FALLAERIALF,
    ASID_FALLAERIALB,
    ASID_FALLSPECIAL,
    ASID_FALLSPECIALF,
    ASID_FALLSPECIALB,
    ASID_DAMAGEFALL,
    ASID_SQUAT,
    ASID_SQUATWAIT,
    ASID_SQUATRV,
    ASID_LANDING,
    ASID_LANDINGFALLSPECIAL,
    ASID_ATTACK11,
    ASID_ATTACK12,
    ASID_ATTACK13,
    ASID_ATTACK100START,
    ASID_ATTACK100LOOP,
    ASID_ATTACK100END,
    ASID_ATTACKDASH,
    ASID_ATTACKS3HI,
    ASID_ATTACKS3HIS,
    ASID_ATTACKS3S,
    ASID_ATTACKS3LWS,
    ASID_ATTACKS3LW,
    ASID_ATTACKHI3,
    ASID_ATTACKLW3,
    ASID_ATTACKS4HI,
    ASID_ATTACKS4HIS,
    ASID_ATTACKS4S,
    ASID_ATTACKS4LWS,
    ASID_ATTACKS4LW,
    ASID_ATTACKHI4,
    ASID_ATTACKLW4,
    ASID_ATTACKAIRN,
    ASID_ATTACKAIRF,
    ASID_ATTACKAIRB,
    ASID_ATTACKAIRHI,
    ASID_ATTACKAIRLW,
    ASID_LANDINGAIRN,
    ASID_LANDINGAIRF,
    ASID_LANDINGAIRB,
    ASID_LANDINGAIRHI,
    ASID_LANDINGAIRLW,
    ASID_DAMAGEHI1,
    ASID_DAMAGEHI2,
    ASID_DAMAGEHI3,
    ASID_DAMAGEN1,
    ASID_DAMAGEN2,
    ASID_DAMAGEN3,
    ASID_DAMAGELW1,
    ASID_DAMAGELW2,
    ASID_DAMAGELW3,
    ASID_DAMAGEAIR1,
    ASID_DAMAGEAIR2,
    ASID_DAMAGEAIR3,
    ASID_DAMAGEFLYHI,
    ASID_DAMAGEFLYN,
    ASID_DAMAGEFLYLW,
    ASID_DAMAGEFLYTOP,
    ASID_DAMAGEFLYROLL,
    ASID_LIGHTGET,
    ASID_HEAVYGET,
    ASID_LIGHTTHROWF,
    ASID_LIGHTTHROWB,
    ASID_LIGHTTHROWHI,
    ASID_LIGHTTHROWLW,
    ASID_LIGHTTHROWDASH,
    ASID_LIGHTTHROWDROP,
    ASID_LIGHTTHROWAIRF,
    ASID_LIGHTTHROWAIRB,
    ASID_LIGHTTHROWAIRHI,
    ASID_LIGHTTHROWAIRLW,
    ASID_HEAVYTHROWF,
    ASID_HEAVYTHROWB,
    ASID_HEAVYTHROWHI,
    ASID_HEAVYTHROWLW,
    ASID_LIGHTTHROWF4,
    ASID_LIGHTTHROWB4,
    ASID_LIGHTTHROWHI4,
    ASID_LIGHTTHROWLW4,
    ASID_LIGHTTHROWAIRF4,
    ASID_LIGHTTHROWAIRB4,
    ASID_LIGHTTHROWAIRHI4,
    ASID_LIGHTTHROWAIRLW4,
    ASID_HEAVYTHROWF4,
    ASID_HEAVYTHROWB4,
    ASID_HEAVYTHROWHI4,
    ASID_HEAVYTHROWLW4,
    ASID_SWORDSWING1,
    ASID_SWORDSWING3,
    ASID_SWORDSWING4,
    ASID_SWORDSWINGDASH,
    ASID_BATSWING1,
    ASID_BATSWING3,
    ASID_BATSWING4,
    ASID_BATSWINGDASH,
    ASID_PARASOLSWING1,
    ASID_PARASOLSWING3,
    ASID_PARASOLSWING4,
    ASID_PARASOLSWINGDASH,
    ASID_HARISENSWING1,
    ASID_HARISENSWING3,
    ASID_HARISENSWING4,
    ASID_HARISENSWINGDASH,
    ASID_STARRODSWING1,
    ASID_STARRODSWING3,
    ASID_STARRODSWING4,
    ASID_STARRODSWINGDASH,
    ASID_LIPSTICKSWING1,
    ASID_LIPSTICKSWING3,
    ASID_LIPSTICKSWING4,
    ASID_LIPSTICKSWINGDASH,
    ASID_ITEMPARASOLOPEN,
    ASID_ITEMPARASOLFALL,
    ASID_ITEMPARASOLFALLSPECIAL,
    ASID_ITEMPARASOLDAMAGEFALL,
    ASID_LGUNSHOOT,
    ASID_LGUNSHOOTAIR,
    ASID_LGUNSHOOTEMPTY,
    ASID_LGUNSHOOTAIREMPTY,
    ASID_FIREFLOWERSHOOT,
    ASID_FIREFLOWERSHOOTAIR,
    ASID_ITEMSCREW,
    ASID_ITEMSCREWAIR,
    ASID_DAMAGESCREW,
    ASID_DAMAGESCREWAIR,
    ASID_ITEMSCOPESTART,
    ASID_ITEMSCOPERAPID,
    ASID_ITEMSCOPEFIRE,
    ASID_ITEMSCOPEEND,
    ASID_ITEMSCOPEAIRSTART,
    ASID_ITEMSCOPEAIRRAPID,
    ASID_ITEMSCOPEAIRFIRE,
    ASID_ITEMSCOPEAIREND,
    ASID_ITEMSCOPESTARTEMPTY,
    ASID_ITEMSCOPERAPIDEMPTY,
    ASID_ITEMSCOPEFIREEMPTY,
    ASID_ITEMSCOPEENDEMPTY,
    ASID_ITEMSCOPEAIRSTARTEMPTY,
    ASID_ITEMSCOPEAIRRAPIDEMPTY,
    ASID_ITEMSCOPEAIRFIREEMPTY,
    ASID_ITEMSCOPEAIRENDEMPTY,
    ASID_LIFTWAIT,
    ASID_LIFTWALK1,
    ASID_LIFTWALK2,
    ASID_LIFTTURN,
    ASID_GUARDON,
    ASID_GUARD,
    ASID_GUARDOFF,
    ASID_GUARDSETOFF,
    ASID_GUARDREFLECT,
    ASID_DOWNBOUNDU,
    ASID_DOWNWAITU,
    ASID_DOWNDAMAGEU,
    ASID_DOWNSTANDU,
    ASID_DOWNATTACKU,
    ASID_DOWNFOWARDU,
    ASID_DOWNBACKU,
    ASID_DOWNSPOTU,
    ASID_DOWNBOUNDD,
    ASID_DOWNWAITD,
    ASID_DOWNDAMAGED,
    ASID_DOWNSTANDD,
    ASID_DOWNATTACKD,
    ASID_DOWNFOWARDD,
    ASID_DOWNBACKD,
    ASID_DOWNSPOTD,
    ASID_PASSIVE,
    ASID_PASSIVESTANDF,
    ASID_PASSIVESTANDB,
    ASID_PASSIVEWALL,
    ASID_PASSIVEWALLJUMP,
    ASID_PASSIVECEIL,
    ASID_SHIELDBREAKFLY,
    ASID_SHIELDBREAKFALL,
    ASID_SHIELDBREAKDOWNU,
    ASID_SHIELDBREAKDOWND,
    ASID_SHIELDBREAKSTANDU,
    ASID_SHIELDBREAKSTANDD,
    ASID_FURAFURA,
    ASID_CATCH,
    ASID_CATCHPULL,
    ASID_CATCHDASH,
    ASID_CATCHDASHPULL,
    ASID_CATCHWAIT,
    ASID_CATCHATTACK,
    ASID_CATCHCUT,
    ASID_THROWF,
    ASID_THROWB,
    ASID_THROWHI,
    ASID_THROWLW,
    ASID_CAPTUREPULLEDHI,
    ASID_CAPTUREWAITHI,
    ASID_CAPTUREDAMAGEHI,
    ASID_CAPTUREPULLEDLW,
    ASID_CAPTUREWAITLW,
    ASID_CAPTUREDAMAGELW,
    ASID_CAPTURECUT,
    ASID_CAPTUREJUMP,
    ASID_CAPTURENECK,
    ASID_CAPTUREFOOT,
    ASID_ESCAPEF,
    ASID_ESCAPEB,
    ASID_ESCAPE,
    ASID_ESCAPEAIR,
    ASID_REBOUNDSTOP,
    ASID_REBOUND,
    ASID_THROWNF,
    ASID_THROWNB,
    ASID_THROWNHI,
    ASID_THROWNLW,
    ASID_THROWNLWWOMEN,
    ASID_PASS,
    ASID_OTTOTTO,
    ASID_OTTOTTOWAIT,
    ASID_FLYREFLECTWALL,
    ASID_FLYREFLECTCEIL,
    ASID_STOPWALL,
    ASID_STOPCEIL,
    ASID_MISSFOOT,
    ASID_CLIFFCATCH,
    ASID_CLIFFWAIT,
    ASID_CLIFFCLIMBSLOW,
    ASID_CLIFFCLIMBQUICK,
    ASID_CLIFFATTACKSLOW,
    ASID_CLIFFATTACKQUICK,
    ASID_CLIFFESCAPESLOW,
    ASID_CLIFFESCAPEQUICK,
    ASID_CLIFFJUMPSLOW1,
    ASID_CLIFFJUMPSLOW2,
    ASID_CLIFFJUMPQUICK1,
    ASID_CLIFFJUMPQUICK2,
    ASID_APPEALR,
    ASID_APPEALL,
    ASID_SHOULDEREDWAIT,
    ASID_SHOULDEREDWALKSLOW,
    ASID_SHOULDEREDWALKMIDDLE,
    ASID_SHOULDEREDWALKFAST,
    ASID_SHOULDEREDTURN,
    ASID_THROWNFF,
    ASID_THROWNFB,
    ASID_THROWNFHI,
    ASID_THROWNFLW,
    ASID_CAPTURECAPTAIN,
    ASID_CAPTUREYOSHI,
    ASID_YOSHIEGG,
    ASID_CAPTUREKOOPA,
    ASID_CAPTUREDAMAGEKOOPA,
    ASID_CAPTUREWAITKOOPA,
    ASID_THROWNKOOPAF,
    ASID_THROWNKOOPAB,
    ASID_CAPTUREKOOPAAIR,
    ASID_CAPTUREDAMAGEKOOPAAIR,
    ASID_CAPTUREWAITKOOPAAIR,
    ASID_THROWNKOOPAAIRF,
    ASID_THROWNKOOPAAIRB,
    ASID_CAPTUREKIRBY,
    ASID_CAPTUREWAITKIRBY,
    ASID_THROWNKIRBYSTAR,
    ASID_THROWNCOPYSTAR,
    ASID_THROWNKIRBY,
    ASID_BARRELWAIT,
    ASID_BURY,
    ASID_BURYWAIT,
    ASID_BURYJUMP,
    ASID_DAMAGESONG,
    ASID_DAMAGESONGWAIT,
    ASID_DAMAGESONGRV,
    ASID_DAMAGEBIND,
    ASID_CAPTUREMEWTWO,
    ASID_CAPTUREMEWTWOAIR,
    ASID_THROWNMEWTWO,
    ASID_THROWNMEWTWOAIR,
    ASID_WARPSTARJUMP,
    ASID_WARPSTARFALL,
    ASID_HAMMERWAIT,
    ASID_HAMMERWALK,
    ASID_HAMMERTURN,
    ASID_HAMMERKNEEBEND,
    ASID_HAMMERFALL,
    ASID_HAMMERJUMP,
    ASID_HAMMERLANDING,
    ASID_KINOKOGIANTSTART,
    ASID_KINOKOGIANTSTARTAIR,
    ASID_KINOKOGIANTEND,
    ASID_KINOKOGIANTENDAIR,
    ASID_KINOKOSMALLSTART,
    ASID_KINOKOSMALLSTARTAIR,
    ASID_KINOKOSMALLEND,
    ASID_KINOKOSMALLENDAIR,
    ASID_ENTRY,
    ASID_ENTRYSTART,
    ASID_ENTRYEND,
    ASID_DAMAGEICE,
    ASID_DAMAGEICEJUMP,
    ASID_CAPTUREMASTERHAND,
    ASID_CAPTUREDAMAGEMASTERHAND,
    ASID_CAPTUREWAITMASTERHAND,
    ASID_THROWNMASTERHAND,
    ASID_CAPTUREKIRBYYOSHI,
    ASID_KIRBYYOSHIEGG,
    ASID_CAPTURELEADEAD,
    ASID_CAPTURELIKELIKE,
    ASID_DOWNREFLECT,
    ASID_CAPTURECRAZYHAND,
    ASID_CAPTUREDAMAGECRAZYHAND,
    ASID_CAPTUREWAITCRAZYHAND,
    ASID_THROWNCRAZYHAND,
    ASID_BARREL
} ftCommonAction;
struct RGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};
typedef struct _ftCommonData {
    /* 0x0 */ f32 x0;
    /* 0x4 */ f32 x4;
    /* 0x8 */ f32 x8_someStickThreshold;
    /* 0xC */ f32 xC;
    /* 0x10 */ f32 x10;
    /* 0x14 */ f32 x14;
    /* 0x18 */ f32 x18;
    /* 0x1C */ f32 x1C;
    /* 0x20 */ f32 x20;
    /* 0x24 */ f32 x24;
    /* 0x28 */ f32 x28;
    /* 0x2C */ f32 x2C;
    /* 0x30 */ f32 x30;
    /* 0x34 */ f32 x34;
    /* 0x38 */ f32 x38;
    /* 0x3C */ f32 x3C;
    u8 filler_x4[0x88 - 0x40];
    /* 0x88 */ f32 x88;
    /* 0x8C */ s32 x8C;
    u8 filler_x90[0x98 - 0x90];
    /* 0x98 */ f32 x98_shieldHealthInit;
    u8 filler_x9C[0xEC-0x9C];
    /* 0xEC */ f32 xEC;
    /* 0xF0 */ f32 xF0;
    u8 filler_xF4[0x128-0xF4];
    /* 0x128 */ f32 x128;
    /* 0x12C */ f32 x12C;
    /* 0x130 */ f32 x130;
    /* 0x134 */ s32 x134;
    /* 0x138 */ f32 x138;
    /* 0x13C */ f32 x13C;
    u8 filler_x140[0x164-0x140];
    /* 0x164 */ f32 x164;
    u8 filler_x168[0x194-0x168];
    /* 0x194 */ f32 x194_unkHitLagFrames;
    /* 0x198 */ f32 x198;
    /* 0x19C */ f32 x19C;
    /* 0x1A0 */ f32 x1A0;
    u8 filler_x1A4[0x1FC-0x1A4];
    /* 0x1FC */ f32 x1FC;
    /* 0x200 */ f32 x200;
    /* 0x204 */ f32 x204_knockbackFrameDecay;
    u8 filler_x208[0x21C-0x208];
    /* 0x21C */ f32 x21C;
    u8 filler_x220[0x260-0x220];
    /* 0x260 */ f32 x260_startShieldHealth;
    u8 filler_x264[0x27C-0x264];
    /* 0x27C */ f32 x27C;
    /* 0x280 */ f32 x280_unkShieldHealth;
    /* 0x284 */ f32 x284;
    /* 0x288 */ f32 x288;
    u8 filler_x28C[0x294-0x28C];
    /* 0x294 */ f32 x294;
    u8 filler_x298[0x2DC-0x298];
    /* 0x2DC */ f32 x2DC;
    /* 0x2E0 */ f32 x2E0;
    u8 filler_x2E4[0x308-0x2E4];
    /* 0x308 */ f32 x308;
    /* 0x30C */ f32 x30C;
    /* 0x310 */ f32 x310;
    /* 0x314 */ f32 x314;
    u8 filler_x30C[0x3A8-0x318];
    /* 0x3A8 */ f32 x3A8;
    u8 filler_x3AC[0x3E0-0x3AC];
    /* 0x3E0 */ f32 x3E0;
    /* 0x3E4 */ f32 x3E4;
    /* 0x3E8 */ f32 x3E8_shieldKnockbackFrameDecay;
    /* 0x3EC */ f32 x3EC_shieldGroundFrictionMultiplier;
    u8 filler_x3F0[0x418-0x3F0];
    /* 0x418 */ s32 x418;
    /* 0x41C */ s32 x41C;
    u8 filler_x420[0x440-0x420];
    /* 0x440 */ f32 x440;
    /* 0x444 */ f32 x444;
    /* 0x448 */ f32 x448;
    /* 0x44C */ f32 x44C;
    /* 0x450 */ f32 x450;
    /* 0x454 */ f32 x454;
    /* 0x458 */ f32 x458;
    /* 0x45C */ f32 x45C;
    /* 0x460 */ f32 x460;
    u8 filler_x464[0x480-0x464];
    /* 0x480 */ f32 x480;
    u8 filler_x484[0x498-0x484];
    /* 0x498 */ u32 x498_ledgeCooldownTime;
    u8 filler_x49C[0x4C4-0x49C];
    s32 x4C4;
    s32 x4C8;
    s32 x4CC;
    f32 x4D0;
    f32 x4D4;
    u32 x4D8;
    u8 filler_x4D0[0x5C0-0x4DC];
    /* 0x5F0 */ f32 x5C0;
    u8 filler_x5C4[0x5F0-0x5C4];
    /* 0x5F0 */  u32 x5F0;
    u8 filler_x5F4[0x6D8-0x5F4];
   /* 0x6D8 */ void* x6D8[1]; // TODO expand to actual size
    struct RGBA x6DC_colorsByPlayer[4];
    u8 filler_x6EC[0x6F4 - 0x6EC];
    /* 0x6F4 */ s32 x6F4_unkDamage;
    /* 0x6F8 */ s32 x6F8;
    /* 0x6FC */ s32 x6FC;
    /* 0x700 */ s32 x700;
    /* 0x704 */ f32 x704;
    /* 0x708 */ f32 x708;
    /* 0x70C */ f32 x70C;
    /* 0x710 */ f32 x710;
    /* 0x714 */ f32 x714;
    u8 filler_x718[0x768-0x718];
    /* 0x768 */ f32 x768;
    /* 0x76C */ f32 x76C;
    /* 0x770 */ f32 x770;
    /* 0x774 */ s32 x774;
    u8 x7A0_filler[0x7A0 - 0x778];
    /* 0x7A0 */ s32 x7A0;
    /* 0x7A4 */ s32 x7A4;
    /* 0x7A8 */ s32 x7A8;
    /* 0x7AC */ s32 x7AC;
    /* 0x7B0 */ s32 x7B0;
    /* 0x7B4 */ s32 x7B4_unkDamage;
    /* 0x7B8 */ f32 x7B8;
    /* 0x7BC */ f32 x7BC;
    /* 0x7C0 */ f32 x7C0;
    /* 0x7C4 */ s32 x7C4;
    /* 0x7C8 */ s32 x7C8;
    /* 0x7CC */ s32 x7CC;
    /* 0x7D0 */ s32 x7D0;
    /* 0x7D4 */ s32 x7D4;
    /* 0x7D8 */ s32 x7D8;
    /* 0x7DC */ s32 x7DC;
    /* 0x7E0 */ s32 x7E0;
    /* 0x7E4 */ f32 x7E4_scaleZ;
    u8 x7E8_filler[0x814 - 0x7E8];
    /* 0x814 */ s32 x814;
    // lots of more data following, exact size to be determined
} ftCommonData;
typedef struct _FtCollisionData
{
    u8 data_filler_0[0x28];
    u32 x28;
    u8 data_filler_2C[0x30 - 0x2C];
    s32 x30;
    s32 x34;
} FtCollisionData;
struct UnkFloat6_Camera;
typedef struct _ftData
{
    struct {
        u8 x0_fill[0x8C];
        f32 x8C;
        u8 x90_fill[0xFC - 0x90];
        f32 xFC;
        u8 x100_fill[0x16C - 0x100];
        s32 x16C_idx;
    }* x0;
               void* ext_attr;
    struct {
        u8 x0_fill[0x10];
        u8 unk10, unk11, unk12;
    }* x8;
    struct S_TEMP4* xC;
    u8* x10;
    s32 filler_x14[10];
    struct UnkFloat6_Camera *x3C;
    s32 filler_x40[2];
               void** x48_items;
    FtCollisionData* x4C_collisionData;
    s32 filler_x50[2];
    void* x58;
} ftData;
typedef struct _ThrowFlags
{
  union {
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    };
    u32 flags;
  };
} ThrowFlags;
typedef struct attr
{
                f32 x110_WalkInitialVelocity;
                f32 x114_WalkAcceleration;
                f32 x118_WalkMaximumVelocity;
                f32 x11C_SlowWalkMax;
                f32 x120_MidWalkPoint;
                f32 x124_FastWalkMin;
                f32 x128_GroundFriction;
                f32 x12C_DashInitialVelocity;
                f32 x130_DashrunAccelerationA;
                f32 x134_DashrunAccelerationB;
                f32 x138_DashrunTerminalVelocity;
                f32 x13C_RunAnimationScaling;
                f32 x140_MaxRunbrakeFrames;
                f32 x144_GroundedMaxHorizontalVelocity;
                f32 x148_JumpStartupTime;
                f32 x14C_JumpHInitialVelocity;
                f32 x150_JumpVInitialVelocity;
                f32 x154_GroundToAirJumpMomentumMultiplier;
                f32 x158_JumpHMaxVelocity;
                f32 x15C_HopVInitialVelocity;
                f32 x160_AirJumpVMultiplier;
                f32 x164_AirJumpHMultiplier;
                s32 x168_MaxJumps;
                f32 x16C_Gravity;
                f32 x170_TerminalVelocity;
                f32 x174_AerialDriftStickMult;
                f32 x178_AerialDriftBase;
                f32 x17C_AerialDriftMax;
                f32 x180_AerialFriction;
                f32 x184_FastfallVelocity;
                f32 x188_HorizontalAirMobilityConstant;
                f32 x18C_Jab_2InputWindow;
                s32 x190_Jab_3InputWindow;
                s32 x194_FramesToChangeDirectionOnStandingTurn;
                f32 x198_Weight;
                f32 x19C_ModelScaling;
                f32 x1A0_InitialShieldSize;
                f32 x1A4_ShieldBreakInitialVelocity;
                s32 x1A8_RapidJabWindow;
                s32 x1AC;
                s32 x1B0;
                s32 x1B4;
                f32 x1B8_LedgeJumpHorizontalVelocity;
                f32 x1BC_LedgeJumpVerticalVelocity;
                f32 x1C0_ItemThrowVelocityMultiplier;
                s32 x1C4;
                s32 x1C8;
                s32 x1CC;
                s32 x1D0;
                s32 x1D4;
                s32 x1D8;
                s32 x1DC;
                s32 x1E0;
                s32 x1E4;
                s32 x1E8;
                s32 x1EC;
                f32 x1F0_KirbyBStarDamage;
                f32 x1F4_NormalLandingLag;
                f32 x1F8_NAirLandingLag;
                f32 x1FC_FAirLandingLag;
                f32 x200_BAirLandingLag;
                f32 x204_UAirLandingLag;
                f32 x208_DAirLandingLag;
                f32 x20C_NametagHeight;
                s32 x210;
                f32 x214_WallJumpHorizontalVelocity;
                f32 x218_WallJumpVerticalVelocity;
                s32 x21C;
                f32 x220_TrophyScale;
                Vec3 x224;
                Vec3 x230;
                f32 x23C;
                Vec3 x240;
                f32 x24C;
                s32 x250;
                s32 x254;
                f32 x258;
                f32 x25C_BubbleRatio;
                s32 x260;
                s32 x264;
                s32 x268;
                s32 x26C;
                f32 x270_RespawnPlatformScale;
                s32 x274;
                s32 x278;
                s32 x27C_CameraZoomTargetBone;
                Vec3 x280;
                s32 x28C;
                s32 x290_WeightDependentThrowSpeedFlags;
}attr;
typedef struct _FighterBone
{
            HSD_JObj* x0_jobj;
            HSD_JObj* x4_jobj2;
            UnkFlagStruct flags;
            u8 filler_x6[7];
} FighterBone;
typedef struct _Hitbox {
    s32 x0;
    s32 x4;
    s32 x8;
    f32 xC;
    u8 filler[0x128];
} Hitbox;
typedef struct _CameraBox
{
  u32 data_filler[2];
  s32 x8;
  UnkFlagStruct xC_flag;
  u8 xD_fill[0x10 - 0xD];
  Vec3 x10;
  Vec3 x1C;
  f32 x28;
  Vec2 x2C;
  Vec3 x34;
  Vec2 x40;
  Vec3 x48;
} CameraBox;
typedef struct ftHurt
{
    u32 x0_bone_state;
    Vec3 x4_hurt1_offset;
    Vec3 x10_hurt2_offset;
    f32 x1C_scale;
    HSD_JObj* x20_jobj;
    unsigned char x24_1_is_updated : 1;
    unsigned char x24_2 : 1;
    unsigned char x24_3 : 1;
    unsigned char x24_4 : 1;
    unsigned char x24_5 : 1;
    unsigned char x24_6 : 1;
    unsigned char x24_7 : 1;
    unsigned char x24_8 : 1;
    Vec3 x28_hurt1_pos;
    Vec3 x34_hurt2_pos;
    u32 x40_bone_index;
    u32 x44_hurt_kind;
    u32 x48_is_grabbable;
}ftHurt;
typedef struct _SmashAttr {
    s32 x2114_state;
    f32 x2118_frames;
    f32 x211C_holdFrame;
    f32 x2120_damageMul;
    f32 x2124_frameSpeedMul;
    s32 x2128;
    s8 x212C;
    s8 x212D;
    s8 x212E;
    s8 x212F;
    s32 x2130_sfxBool;
    s8 x2134_vibrateFrame;
    s8 x2135;
    s8 x2136;
    s8 x2137;
    f32 x2138_smashSinceHitbox;
} SmashAttr;
typedef struct _ftHit
{
    u8 filler_x0[0x134];
    s32 x134;
} ftHit;
typedef struct _S32Pair {
    s32 x, y;
} S32Pair;
enum {
    GA_Ground = 0,
    GA_Air = 1,
};
typedef struct {
    HSD_Joint* joint;
    u8 padding[0x10];
    HSD_Archive* x14_archive;
} UnkCostumeStruct;
struct UnkCostumeList {
    UnkCostumeStruct* costume_list;
    u8 numCostumes;
};
struct S_TEMP1 {
    FighterKind fighterKind;
    u8 playerID;
    u8 unk5;
    UnkFlagStruct flags;
};
struct ActionState {
    s32 action_id;
    s32 x4_flags;
    u8 move_id;
    UnkFlagStruct x9_flags;
    UnkFlagStruct flagsA;
    UnkFlagStruct flagsB;
    void* cb_Anim;
    void* cb_Input;
    void* cb_Physics;
    void* cb_Collision;
    void* cb_Camera;
};
struct S_TEMP4 {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10_animCurrFlags;
    s32 x14;
};
struct SpecialAttrs_Mario {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
                 HSD_GObj* x223C;
                 u32 x2240;
};
struct SpecialAttrs_Fox {
                 HSD_GObj* x222C_blasterGObj;
};
struct SpecialAttrs_Captain {
                 BOOL x222C_isSpecialSStartGFX;
                 BOOL x2230_isSpecialSGFX;
};
struct SpecialAttrs_DK {
                 s32 x222C;
                 s32 x2230;
};
struct SpecialAttrs_Kirby {
                 s32 x222C;
                 u32 x2230;
                 UnkFlagStruct x2234;
                 u8 filler_x2235[3];
                 u32 x2238;
                 u32 x223C;
                 u32 x2240;
                 u32 x2244;
                 u32 x2248;
                 u8 filler1[0x228C - 0x224C];
                 u32 x228C;
                 u32 x2290;
                 u8 filler2[0x22C8 - 0x2294];
                 s32 x22C8;
                 s32 x22CC;
                 s32 x22D0;
                 s32 x22D4;
                 s32 x22D8;
                 s32 x22DC;
                 s32 x22E0;
                 s32 x22E4;
                 s32 x22E8;
};
struct SpecialAttrs_Koopa {
                 u32 x222C;
};
struct SpecialAttrs_Link {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
                 u32 x223C;
                 u32 x2240;
                 u32 x2244;
                 u32 x2248;
};
struct SpecialAttrs_Seak {
                 s32 x222C;
                 u32 x2230;
                 u32 x2234;
};
struct SpecialAttrs_Ness {
                 HSD_GObj* x222C_yoyoGObj;
                 Vec3 x2230_yoyoHitboxPos;
                 f32 x223C;
                 HSD_GObj* x2240_flashGObj;
                 HSD_GObj* x2244_pkThunderGObj;
                 HSD_GObj* x2248_baseballBatGObj;
                 u32 x224C_thunderGFX;
};
struct SpecialAttrs_Peach {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
                 u32 x223C;
                 u32 x2240;
                 u32 x2244;
                 u32 x2248;
};
struct SpecialAttrs_Popo {
    char filler0[0x100];
};
struct SpecialAttrs_Nana {
                 u32 x222C;
                 UnkFlagStruct x2230;
                 u8 filler_x2231[3];
                 u32 x2234;
                 u32 x2238;
                 u32 x223C;
                 u32 x2240;
                 u32 x2244;
                 u32 x2248;
                 u32 x224C;
                 f32 x2250;
};
struct SpecialAttrs_Pikachu {
    char filler0[0x100];
};
struct SpecialAttrs_Samus {
                 u32 x222C;
                 s32 x2230;
                 u32 x2234;
                 u32 x2238;
                 u32 x223C;
                 u8 x2240;
                 u8 x2241;
                 u8 x2242;
                 u8 x2243;
                 u32 x2244;
                 u32 x2248;
};
struct SpecialAttrs_Yoshi {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
};
struct SpecialAttrs_Purin {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
                 HSD_JObj* x223C;
                 u32 x2240;
                 void* x2244;
                 u32 x2248;
};
struct SpecialAttrs_Mewtwo {
                 HSD_GObj* x222C_disableGObj;
                 HSD_GObj* x2230_shadowHeldGObj;
                 s32 x2234_shadowBallCharge;
                 HSD_GObj* x2238_shadowBallGObj;
                 BOOL x223C_isConfusionBoost;
};
struct SpecialAttrs_Luigi {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
};
struct SpecialAttrs_Mars {
                 u32 x222C;
};
struct SpecialAttrs_Zelda {
                 u32 x222C;
};
struct SpecialAttrs_CLink {
                 u32 x222C;
                 u32 x2230;
                 u32 x2234;
                 u32 x2238;
                 u32 x223C;
                 u32 x2240;
                 u32 x2244;
};
struct SpecialAttrs_Pichu {
    char filler0[0x100];
};
struct SpecialAttrs_GameWatch {
                 s32 x222C_judgeVar1;
                 s32 x2230_judgeVar2;
                 u32 x2234;
                 s32 x2238_panicCharge;
                 s32 x223C_panicDamage;
                 u32 x2240;
                 u32 x2244;
                 HSD_GObj* x2248_manholeGObj;
                 HSD_GObj* x224C_greenhouseGObj;
                 HSD_GObj* x2250_manholeGObj2;
                 HSD_GObj* x2254_fireGObj;
                 HSD_GObj* x2258_parachuteGObj;
                 HSD_GObj* x225C_turtleGObj;
                 HSD_GObj* x2260_sparkyGObj;
                 HSD_GObj* x2264_judgementGObj;
                 HSD_GObj* x2268_panicGObj;
                 HSD_GObj* x226C_rescueGObj;
};
struct SpecialAttrs_Masterhand {
                 HSD_GObj* x222C;
                 u32 x2230;
                 u32 x2234;
                 f32 x2238;
                 f32 x223C;
                 Vec3 x2240_pos;
                 u32 x224C;
                 s32 x2250;
                 s32 x2254;
                 s32 x2258;
};
struct SpecialAttrs_Crazyhand {
                 HSD_GObj* x222C;
                 u32 x2230;
                 u32 x2234;
                 f32 x2238;
                 f32 x223C;
                 Vec3 x2240_pos;
                 u32 x224C;
                 s32 x2250;
                 s32 x2254;
                 s32 x2258;
};
struct SpecialAttrs_Boy {
    char filler0[0x100];
};
struct SpecialAttrs_Girl {
    char filler0[0x100];
};
struct SpecialAttrs_GKoopa {
                 f32 x222C;
                 f32 x2230;
};
struct SpecialAttrs_Sandbag {
    char filler0[0x100];
};
typedef struct ftGameWatchVars
{
    union
    {
        struct
        {
            s32 x2340;
        } Attack11;
        struct
        {
            s32 x2340;
            s32 turnFrames;
        } SpecialLw;
    };
} ftGameWatchVars;

typedef struct ftFox_SpecialS_Struct
{
    s32 x0;
    s32 x4;
    s32 x8;
} ftFox_SpecialS_Struct;

typedef struct ftMewtwoSpecialN {

    BOOL isFull;
    s32 x2344;
    s32 x2348;
    s32 releaseLag;
    f32 chargeLevel;

} ftMewtwoSpecialN;

typedef struct ftMewtwoSpecialS {

    u8 isUnkConfusion : 1;

} ftMewtwoSpecialS;

typedef struct ftMewtwoSpecialHi {

    s32 travelFrames;
    f32 stickX;
    f32 stickY;
    s32 unk4;

} ftMewtwoSpecialHi;

typedef union ftMewtwoStateVars {

    ftMewtwoSpecialN SpecialN;
    ftMewtwoSpecialS SpecialS;
    ftMewtwoSpecialHi SpecialHi;
    
} ftMewtwoStateVars;

typedef struct ftGameWatchSpecialN {

	s32 isChefLoopDisable;		// 0x2340
	s32 maxSausage; // 0x2344 - Maximum number of sausages able to be spawned per Chef use

} ftGameWatchSpecialN;

typedef union ftGameWatchStateVars {

    ftGameWatchSpecialN SpecialN;

} ftGameWatchStateVars;

typedef struct _Fighter {
    /* 0x0 */ HSD_GObj *x0_fighter;
    /* 0x4 */ FighterKind x4_fighterKind;
    /* 0x8 */ s32 x8_spawnNum;
    /* 0xC */ u8 xC_playerID;
    /* 0x10 */ s32 x10_action_state_index;
    /* 0x14 */ s32 x14_action_id;
    /* 0x18 */ s32 x18;
    /* 0x1C */ struct ActionState* x1C_actionStateList;
    /* 0x20 */ struct ActionState* x20_actionStateList;
    /* 0x24 */ struct S_TEMP4* x24;
    /* 0x28 */ u8* x28;
    /* 0x2C */ f32 x2C_facing_direction;
    /* 0x30 */ f32 x30_facingDirectionRepeated;
    /* 0x34 */ Vec3 x34_scale;
    /* 0x40 */ f32 x40;
    /* 0x44 */ Mtx x44_mtx;
    Vec3 x74_anim_vel;                                         // 0x74
    Vec3 x80_self_vel;                                         // 0x80
    Vec3 x8c_kb_vel;                                           // 0x8C
    Vec3 x98_atk_shield_kb;                                // 0x98
    Vec3 xA4_unk_vel;                                      // 0xA4
    Vec3 xB0_pos;                                          // 0xb0
    Vec3 xBC_prevPos;                                     // 0xBC
    Vec3 xC8_pos_delta;                                        // 0xC8
    Vec3 xD4_unk_vel;                                        // 0xD4
    s32 xE0_ground_or_air;                                         // 0xE0
    f32 xE4_ground_accel_1; // 0xE4
    f32 xE8_ground_accel_2;   // 0xE8
    f32 xEC_ground_vel;                                    // 0xEC
    f32 xF0_ground_kb_vel;
    f32 xF4_ground_attacker_shield_kb_vel;
    Vec2 xF8_playerNudgeVel;
    /* 0x100 */ f32 x100;
    /* 0x104 */ u8 x104;
    /* 0x105 */ s8 x105;
    /* 0x106 */ s8 x106;
    /* 0x107 */ s8 x107;
    /* 0x108 */ HSD_Joint* x108_costume_joint;
    /* 0x10C */ ftData* x10C_ftData;
    // TODO: Ask Psi how many of those are confirmed, only a fraction of them is used right now
    attr x110_attr;
    u8 filler_x294[0x2CC - 0x294];
    /* 0x2CC */ void* x2CC;
    /* 0x2D0 */ void* x2D0;
    /* 0x2D4 */ void* x2D4_specialAttributes;
    /* 0x2D8 */ void* x2D8_specialAttributes2;
    /* 0x2DC */ f32 x2DC;
    /* 0x2E0 */ f32 x2E0;
    /* 0x2E4 */ f32 x2E4;
    /* 0x2E8 */ f32 x2E8;
    /* 0x2EC */ f32 x2EC;
    u8 filler_x2F0[0x3E4 - 0x2F0];
    /* 0x3E4 */ f32 x3E4;
    /* 0x3E8 */ f32 x3E8;
    /* 0x3EC */ s32 x3EC;
    /* 0x3F0 */ s32 x3F0;
    u8 filler_x3F4[0x588 - 0x3F4];
    /* 0x588 */ s32 x588;
    /* 0x58C */ s32 x58C;
    /* 0x590 */ s32 x590;
    /* 0x594 */ union {
                    struct {
                        UnkFlagStruct x594_animCurrFlags1;
                        struct {
                            u8 x0: 7;
                            u16 x7: 3;
                        } x596_bits;
                    };
                    s32 x594_s32;
                };
    /* 0x598 */ s32 x598;
    /* 0x59C */ void* x59C;
    /* 0x5A0 */ void* x5A0;
    u8 filler_x5A4[0x5B8 - 0x5A4];
    /* 0x5B8 */ s32 x5B8;
    /* 0x5BC */ s32 x5BC;
    u8 filler_x598[0x5C8 - 0x5C0];
    /* 0x5A0 */ void* x5C8;
    u8 filler_x5CC[0x5E8 - 0x5CC];
    /* 0x5E8 */ FighterBone* x5E8_fighterBones;
    u8 filler_x5EC[0x5F0 - 0x5EC];
    /* 0x5F0 */ HSD_DObj** x5F0;
    /* 0x5F4 */ s8 x5F4;
    /* 0x5F5 */ s8 x5F5;
    /* 0x5F6 */ s8 x5F6;
    /* 0x5F7 */ s8 x5F7;
    /* 0x5F8 */ s8 x5F8;
    u8 filler_x5FC[0x60C - 0x5F9];
    /* 0x60C */ void* x60C;
    union {
        /* 0x610 */ struct RGBA x610_color_rgba[2];
        struct {
            /* 0x610 */ s32 x610;
            /* 0x614 */ s32 x614;
        };
    };
    /* 0x618 */ u8 x618_player_id;
    /* 0x619 */ u8 x619_costume_id;
    /* 0x61A */ u8 x61A_controller_index;
    /* 0x61B */ u8 x61B_team;
    /* 0x61C */ u8 x61C;
    /* 0x61D */ u8 x61D;
    u8 filler_x61E[0x620 - 0x61E];

    struct {
        /* 0x620 */ f32 x620_lstick_x;
        /* 0x624 */ f32 x624_lstick_y;
        /* 0x628 */ f32 x628_lstick_x2;
        /* 0x62C */ f32 x62C_lstick_y2;

        /* 0x630 */ f32 x630;
        /* 0x634 */ f32 x634;

        /* 0x638 */ f32 x638_lsubStick_x;
        /* 0x63C */ f32 x63C_lsubStick_y;
        /* 0x640 */ f32 x640_lsubStick_x2;
        /* 0x644 */ f32 x644_lsubStick_y2;
                    
        /* 0x648 */ f32 x648;
        /* 0x64C */ f32 x64C;
                    
        /* 0x650 */ f32 x650;
        /* 0x654 */ f32 x654;

        /* 0x658 */ f32 x658;

        /* 0x65C */ u32 x65C_heldInputs;
        /* 0x660 */ s32 x660;
        /* 0x664 */ s32 x664;
        /* 0x668 */ s32 x668;
        /* 0x66C */ s32 x66C;
    } input; // 0x620 to 0x670

    /* 0x670 */ u8 x670_timer_lstick_tilt_x;
    /* 0x671 */ u8 x671_timer_lstick_tilt_y;
    /* 0x672 */ u8 x672_input_timer_counter;

    /* 0x673 */ u8 x673;
    /* 0x674 */ u8 x674;
    /* 0x674 */ u8 x675;

    /* 0x676 */ u8 x676_x;
    /* 0x677 */ u8 x677_y;
    /* 0x678 */ u8 x678;

    /* 0x679 */ u8 x679_x;
    /* 0x67A */ u8 x67A_y;
    /* 0x67B */ u8 x67B;

    /* 0x67C */ u8 x67C;
    /* 0x67D */ u8 x67D;
    /* 0x67E */ u8 x67E;
    /* 0x67F */ u8 x67F;
    /* 0x680 */ u8 x680;
    /* 0x681 */ u8 x681;
    /* 0x682 */ u8 x682;
    /* 0x683 */ u8 x683;
    /* 0x684 */ u8 x684;
    /* 0x685 */ u8 x685;
    /* 0x686 */ u8 x686;
    /* 0x687 */ u8 x687;
    /* 0x688 */ u8 x688;
    /* 0x689 */ u8 x689;
    /* 0x68A */ u8 x68A;
    /* 0x68B */ u8 x68B;

    /* 0x68C */ Vec x68C_transNPos;
    /* 0x698 */  Vec x698;
    /* 0x6A4 */  Vec3 x6A4_transNOffset;
    /* 0x6B0 */  Vec3 x6B0;
    /* 0x6BC */  f32 x6BC_inputStickangle;
    /* 0x6C0 */  Vec x6C0;
    /* 0x6CC */  Vec x6CC;
    /* 0x6D8 */  Vec3 x6D8;
    /* 0x6E4 */  Vec3 x6E4;
    /* 0x6F0 */ CollData x6F0_collData;
    /* 0x890 */ CameraBox* x890_cameraBox;
    /* 0x894 */ f32 x894_currentAnimFrame;
    /* 0x898 */ f32 x898_unk;
    /* 0x89C */ f32 x89C_frameSpeedMul;
    /* 0x8A0 */ f32 x8A0_unk;
    /* 0x8A4 */ f32 x8A4_animBlendFrames;
    /* 0x8A8 */ f32 x8A8_unk;
    /* 0x8AC */ HSD_JObj* x8AC_animSkeleton;
    u8 filler_x8AC[0x914 - 0x8B0];
    /* 0x914 */ Hitbox x914[4];
    u8 filler_xDF4[0x1064 - 0xDF4];
    /* 0x1064 */ ftHit x1064_thrownHitbox;
    /* 0x119C */ u8 x119C_teamUnk;
    /* 0x119D */ u8 x119D;
    /* 0x119E */ u8 x119E_hurtboxNum;
    /* 0x119F */ u8 x119F;
    /* 0x11A0 */ ftHurt x11A0_fighterHurtbox[15];
    u8 filler_x1828[0x1828 - 0x1614];
    /* 0x1828 */ s32 x1828;
    struct dmg                                                 // 0x182c
    {                                                          //
        f32 x182c_behavior;                                    // 0x182c
        f32 x1830_percent;                                     // 0x1830
        f32 x1834;                                             // 0x1834
        f32 x1838_percentTemp;                                 // 0x1838
        s32 x183C_applied;                                     // 0x183c
        s32 x1840;                                             // 0x1840
        f32 x1844_direction;                                   // 0x1844
        s32 x1848_kb_angle;                                    // 0x1848
        s32 x184c_damaged_hurtbox;                             // 0x184c
        f32 x1850_forceApplied;                                // 0x1850
        Vec3 x1854_collpos;                                    // 0x1854
        s32 x1860_dealt;                                       // 0x1860
        s32 x1864;                                             // 0x1864
        HSD_GObj *x1868_source;                                // 0x1868
        s32 x186c;                                             // 0x186c
        s32 x1870;                                             // 0x1870
        s32 x1874;                                             // 0x1874
        s32 x1878;                                             // 0x1878
        s32 x187c;                                             // 0x187c
        s32 x1880;                                             // 0x1880
        s32 x1884;                                             // 0x1884
        s32 x1888;                                             // 0x1888
        s32 x188c;                                             // 0x188c
        s32 x1890;                                             // 0x1890
        s32 x1894;                                             // 0x1894
        s32 x1898;                                             // 0x1898
        f32 x189C_unk_num_frames;                                             // 0x189c
        f32 x18a0;                                             // 0x18a0
        f32 x18A4_knockbackMagnitude;                          // 0x18a4  kb magnitude
        f32 x18A8;                                             // 0x18a8
        s32 x18ac_time_since_hit;                              // 0x18ac   in frames
        f32 x18B0;                                             // 0x18b0
        f32 x18B4_armor;                                       // 0x18b4
        f32 x18B8;                                             // 0x18b8
        f32 x18BC;                                             // 0x18bc
        s32 x18C0;                                             // 0x18c0
        s32 x18c4_source_ply;                                  // 0x18c4   damage source ply number
        s32 x18C8;                                             // 0x18c8
        s32 x18CC;                                             // 0x18cc
        s32 x18D0;                                             // 0x18d0
        s32 x18d4;                                             // 0x18d4
        s32 x18d8;                                             // 0x18d8
        s32 x18dc;                                             // 0x18dc
        s32 x18e0;                                             // 0x18e0
        s32 x18e4;                                             // 0x18e4
        s32 x18e8;                                             // 0x18e8
        u16 x18ec_instancehitby;                               // 0x18ec. Last Move Instance This Player Was Hit by
        s32 x18F0;                                             // 0x18f0
        s32 x18F4;                                             // 0x18f4
        u8 x18F8;                                              // 0x18f8
        u8 x18f9;                                              // 0x18f9
        u16 x18fa_model_shift_frames;                          // 0x18fa
        u8 x18FC;                                              // 0x18fc
        u8 x18FD;                                              // 0x18fd
        s32 x1900;                                             // 0x1900
        s32 x1904;                                             // 0x1904
        s32 x1908;                                             // 0x1908
        s32 x190C;                                             // 0x190c
        s32 x1910;                                             // 0x1910
        s32 x1914;                                             // 0x1914
        s32 x1918;                                             // 0x1918
        f32 x191C;                                             // 0x191c
        s32 x1920;                                             // 0x1920
        s32 x1924;                                             // 0x1924
        f32 x1928;                                             // 0x1928
        f32 x192c;                                             // 0x192c
        s32 x1930;                                             // 0x1930
        s32 x1934;                                             // 0x1934
        s32 x1938;                                             // 0x1938
        s32 x193c;                                             // 0x193c
        s32 x1940;                                             // 0x1940
        s32 x1944;                                             // 0x1944
        s32 x1948;                                             // 0x1948
        s32 x194C;                                             // 0x194c
        s32 x1950;                                             // 0x1950
        f32 x1954;                                             // 0x1954
        f32 x1958;                                             // 0x1958
        f32 x195c_hitlag_frames;                               // 0x195c
    } dmg;    
    /* 0x1960 */ f32 x1960_vibrateMult;
    /* 0x1964 */ f32 x1964;
    /* 0x1968 */ u8 x1968_jumpsUsed;
    /* 0x1969 */ u8 x1969_walljumpUsed;
    /* 0x196C */ f32 x196C_hitlag_mult;
    /* 0x1970 */ s32 x1970;
    /* 0x1974 */ HSD_GObj* x1974_heldItem;
    /* 0x1978 */ HSD_GObj* x1978;
    /* 0x197C */ HSD_GObj* x197C;
    /* 0x1980 */ HSD_GObj* x1980;
    /* 0x1984 */ HSD_GObj* x1984_heldItemSpec;
    /* 0x1988 */ s32 x1988;
    /* 0x198C */ s32 x198C;
    /* 0x1990 */ s32 x1990;
    /* 0x1994 */ s32 x1994;
    /* 0x1998 */ f32 x1998_shieldHealth;
    /* 0x199C */ f32 x199C_shieldLightshieldAmt;
    /* 0x19A0 */ s32 x19A0_shieldDamageTaken;
    /* 0x19A4 */ s32 x19A4;
    /* 0x19A8 */ void* x19A8;
    /* 0x19AC */ f32 x19AC;
    s32 filler_x19B0;
    /* 0x19B4 */ f32 x19B4_shieldUnk;
    /* 0x19B8 */ f32 x19B8_shieldUnk;
    /* 0x19BC */ s32 x19BC_shieldDamageTaken3;
    struct {
        HSD_JObj* x19C0_boneAttach;
        u8 x19C4_updatePos : 1;
        Vec3 x19C8_pos;
        Vec3 x19D4_offset;
        f32 x19E0_size;
    } ShieldHit;
    struct {
        HSD_JObj* x19E4_boneAttach;
        u8 x19E8_updatePos : 1; // Follows attach bone position if toggled OFF //
        Vec3 x19EC_pos;
        Vec3 x19F8_offset;
        f32 x1A04_size;
    } ReflectHit;
    struct {
        HSD_JObj* x1A08_boneAttach;
        u8 x1A0C_updatePos : 1; // Follows attach bone position if toggled OFF //
        Vec3 x1A10_pos;
        Vec3 x1A1C_offset;
        f32 x1A28_size;
    } AbsorbHit;
    struct {
        f32 x1A2C_reflectHitDirection;
        s32 x1A30_maxDamage;
        f32 x1A34_damageMul;
        f32 x1A38_speedMul;
        s32 x1A3C_damageOver; // % damage over the maximum reflectable damage threshold //
    } ReflectAttr;
    struct {
        f32 x1A40_absorbHitDirection;
        s32 x1A44_damageTaken; // unconfirmred? //
        s32 x1A48_hitsTaken; // unconfirmed? //
    } AbsorbAttr;
    /* 0x1A4C */ f32 x1A4C;
    /* 0x1A50 */ s8 x1A50;
    /* 0x1A51 */ s8 x1A51;
    /* 0x1A52 */ u8 x1A52;
    /* 0x1A53 */ u8 x1A53;
    /* 0x1A54 */ s32 x1A54;
    /* 0x1A58 */ HSD_GObj* x1A58_interactedFighter;
    /* 0x1A5C */ HSD_GObj* x1A5C;
    /* 0x1A60 */ u32 x1A60;
    /* 0x1A64 */ s32 x1A64;
    /* 0x1A68 */ s16 x1A68;
    /* 0x1A6A */ s16 x1A6A;
    /* 0x1A6C */ f32 x1A6C;
    /* 0x1A70 */ Vec x1A70;
    /* 0x1A7C */ Vec x1A7C;
    u8 filler_x1A7C[0x1A98-0x1A88];
    /* 0x1A98 */ u32 x1A98;
    u8 filler_x1A9C[0x1ECC-0x1A9C];
    /* 0x1ECC */ void* CPU_copiedInputs;
    u8 filler_x1ED0[0x2004-0x1ED0];
    /* 0x2008 */ s32 x2004;
    /* 0x2008 */ s32 x2008;
    /* 0x200C */ s32 x200C;
    /* 0x2010 */ s32 x2010;
    /* 0x2014 */ s32 x2014;
    /* 0x2018 */ s32 x2018;
    /* 0x201C */ s32 x201C;
    /* 0x2020 */ s8 x2020;
    /* 0x2021 */ s8 x2021;
    /* 0x2022 */ s8 x2022;
    /* 0x2024 */ s32 x2024;
    /* 0x2028 */ s32 x2028;
    /* 0x202C */ s32 x202C;
    /* 0x2030 */ s32 x2030;
    /* 0x2034 */ s32 x2034;
    /* 0x2038 */ s32 x2038;
    /* 0x203C */ s32 x203C;
    /* 0x2040 */ void* x2040;
    u8 filler_x203C[0x2064 - 0x2044];
    /* 0x2064 */ s32 x2064_ledgeCooldown;
    /* 0x2068 */s32 x2068_attackID;
    u8 filler_x206C[0x2070 - 0x206C];
    /* 0x2070 */ union {
                    struct {
                        s8 x2070;

                        u8 x2071_b0_3: 4;
                        u8 x2071_b4: 1;
                        u8 x2071_b5: 1;
                        u8 x2071_b6: 1;
                        u8 x2071_b7: 1;
                        
                        u8 x2072_b0_3: 4;
                        u8 x2072_b4: 1;
                        u8 x2072_b5: 1;
                        u8 x2072_b6: 1;
                        u8 x2072_b7: 1;

                        u8 x2073;
                    };
                    s32 x2070_int;
                };
    u8 filler_x2074[0x208C - 0x2074];
    /* 0x208C */ s32 x208C;
    /* 0x2090 */ u16 x2090;
    /* 0x2092 */ u16 x2092;
    /* 0x2094 */ HSD_GObj* x2094; // GObj pointer of combo victim? //
    /* 0x2098 */ u16 x2098;
    /* 0x209A */ u16 x209A;
    /* 0x209C */ s16 x209C;
    /* 0x20A0 */ struct _HSD_JObj* x20A0_accessory;
    /* 0x20A4 */ s32 x20A4;
    /* 0x20A8 */ s32 x20A8;
    /* 0x20AC */ HSD_GObj* x20AC;
    u8 filler_x20B0[0x2100 - 0x20B0];
    /* 0x2100 */ s8 x2100;
    /* 0x2101 */ u8 x2101_bits_0to6 : 7;
    /* 0x2101 */ u8 x2101_bits_8 : 1;
    /* 0x2102 */ s8 x2102;
    /* 0x2103 */ s8 x2103;
    /* 0x2104 */ s32 x2104;
    /* 0x2108 */ s32 x2108;
    /* 0x210C */ u8 x210C_walljumpInputTimer;
    u8 filler_x210C[3];
    /* 0x2110 */ f32 x2110_walljumpWallSide;
    /* 0x2114 */ SmashAttr x2114_SmashAttr;
    /* 0x213C */ s32 x213C;
    /* 0x2140 */ f32 x2140;
    /* 0x2144 */ s32 x2144;
    /* 0x2148 */ s32 x2148;
    /* 0x214C */ s32 x214C;
    /* 0x2150 */ s32 x2150;
    /* 0x2154 */ s32 x2154;
    /* 0x2158 */ s32 x2158;
    /* 0x215C */ s32 x215C;
    /* 0x2160 */ s32 x2160;
    /* 0x2164 */ s32 x2164;
    /* 0x2168 */ s32 x2168;
    s32 filler_x216C;
    /* 0x2170 */ f32 x2170;
    u8 filler_x2174[0x2180 - 0x2174];
    /* 0x2180 */ s32 x2180;
    /* 0x2184 */ HSD_JObj* x2184;
    /* 0x2188 */ S32Pair x2188;
    // callback struct. Not all of them used by fighter.c, but I'm leaving them in for now.
    struct cb {
        void (*x2190_callback_OnGrabFighter_Self)(HSD_GObj *fighter); // used
        void (*x2194_callback)(HSD_GObj *fighter); // used
        void (*x2198_callback_OnGrabFighter_Victim)(HSD_GObj*, HSD_GObj*); // used
        void (*x219C_callback_IASA)(HSD_GObj *fighter); // used
        void (*x21A0_callback_Anim)(HSD_GObj *fighter);
        void (*x21A4_callback_Phys)(HSD_GObj *fighter); // xused
        void (*x21A8_callback_Coll)(HSD_GObj *fighter);
        void (*x21AC_callback_Cam)(HSD_GObj *fighter);
        void (*x21B0_callback_Accessory1)(HSD_GObj *fighter);
        void (*x21B4_callback_Accessory2)(HSD_GObj *fighter); // used
        void (*x21B8_callback_Accessory3)(HSD_GObj *fighter); // used
        void (*x21BC_callback_Accessory4)(HSD_GObj *fighter);
        void (*x21C0_callback_OnGiveDamage)(HSD_GObj *fighter);
        void (*x21C4_callback_OnShieldHit)(HSD_GObj *fighter);
        void (*x21C8_callback_OnReflectHit)(HSD_GObj *fighter);
        void (*x21CC_callback)(HSD_GObj *fighter);
        void (*x21D0_callback_EveryHitlag)(HSD_GObj *fighter); // xused
        void (*x21D4_callback_EnterHitlag)(HSD_GObj *fighter);
        void (*x21D8_callback_ExitHitlag)(HSD_GObj *fighter);
        void (*x21DC_callback_OnTakeDamage)(HSD_GObj *fighter);
        void (*x21E0_callback_OnDeath)(HSD_GObj *fighter); // used
        void (*x21E4_callback_OnDeath2)(HSD_GObj *fighter); // used. internally Dead_Proc as evidenced by 800f5430
        void (*x21E8_callback_OnDeath3)(HSD_GObj *fighter); // used
        void (*x21EC_callback)(HSD_GObj *fighter);
        void (*x21F0_callback)(HSD_GObj *fighter);
        void (*x21F4_callback)(HSD_GObj *fighter);
        void (*x21F8_callback)(HSD_GObj *fighter);
    } cb;
    /* 0x21FC */ u8 x21FC;
    u8 filler_x21FC[0x2200 - 0x21FD];
    /* 0x2200 */ u32 x2200_ftcmd_var0;
    /* 0x2204 */ u32 x2204_ftcmd_var1;
    /* 0x2208 */ u32 x2208_ftcmd_var2;
    /* 0x220C */ u32 x220C_ftcmd_var3;
    /* 0x2210 */ ThrowFlags x2210_ThrowFlags;
    /* 0x2214 */ f32 x2214;
    /* 0x2218 */ UnkFlagStruct x2218_flag;
    /* 0x2219 */ UnkFlagStruct x2219_flag;
    /* 0x221A */ UnkFlagStruct x221A_flag;
    /* 0x221B */ UnkFlagStruct x221B_flag;
    /* 0x221C */
    union
    {
        struct
        {
            UnkFlagStruct x221C_flag;
            UnkFlagStruct x221D_flag;
        };
        struct
        {
            u16 x221C_u16_x : 7;
            u16 x221C_u16_y : 3;
            u16 x221C_u16_z : 6;
        };
    };
    /* 0x221E */ UnkFlagStruct x221E_flag;
    /* 0x221F */ UnkFlagStruct x221F_flag;
                struct {
                    struct {
                        u8 b0 : 3;
                        u8 b3 : 1;
                        u8 b4 : 1;
                        u8 b5 : 1;
                        u8 b6 : 1;
                        u8 b7 : 1;
                    } bits;
                } x2220_flag;
    /* 0x2221 */ UnkFlagStruct x2221_flag;
    /* 0x2222 */ UnkFlagStruct x2222_flag;
    /* 0x2224 */ UnkFlagStruct x2223_flag;
    /* 0x2224 */ UnkFlagStruct x2224_flag;
    /* 0x2224 */ UnkFlagStruct x2225_flag;
    /* 0x2226 */ UnkFlagStruct x2226_flag;
    /* 0x2227 */ UnkFlagStruct x2227_flag;
    /* 0x2228 */ struct {  ///UnkFlagStruct does not quite work
                    struct {
                        u8 b0 : 1;
                        u8 b1 : 1;
                        u8 b2 : 1;
                        u8 b3 : 2;
                        u8 b5 : 1;
                        u8 b6 : 1;
                        u8 b7 : 1;
                    } bits;
                } x2228_flag;
                
    /* 0x2229 */ u8 x2229_b0 : 1;
                 u8 x2229_b1 : 1;
                 u8 x2229_b2 : 1;
                 u8 x2229_b3 : 1;
                 u8 x2229_b4 : 1;
                 u8 x2229_b5_no_normal_motion : 1;
                 u8 x2229_b6 : 1;
                 u8 x2229_b7 : 1;

                 
    /* 0x222A */ UnkFlagStruct x222A_flag;
    u8 filler_x222B;
    // Some of these are clones of each other (they just use another struct)
    // and some of them dont have specials so dont exist in the union. TODO: Clean-up
    union {
        struct SpecialAttrs_Mario mario;
        struct SpecialAttrs_Fox fox;
        struct SpecialAttrs_Captain captain;
        struct SpecialAttrs_DK dk;
        struct SpecialAttrs_Kirby kirby;
        struct SpecialAttrs_Koopa koopa;
        struct SpecialAttrs_Link link;
        struct SpecialAttrs_Seak seak;
        struct SpecialAttrs_Ness ness;
        struct SpecialAttrs_Peach peach;
        struct SpecialAttrs_Popo popo;
        struct SpecialAttrs_Nana nana;
        struct SpecialAttrs_Pikachu pikachu;
        struct SpecialAttrs_Samus samus;
        struct SpecialAttrs_Yoshi yoshi;
        struct SpecialAttrs_Purin purin;
        struct SpecialAttrs_Mewtwo mewtwo;
        struct SpecialAttrs_Luigi luigi;
        struct SpecialAttrs_Mars mars;
        struct SpecialAttrs_Zelda zelda;
        struct SpecialAttrs_CLink clink;

        // Mario SpecialAttrs struct is used for DrMario
        // Fox SpecialAttrs struct is used for Falco
        struct SpecialAttrs_Pichu pichu;
        struct SpecialAttrs_GameWatch gaw;
        // Cpt Falcon SpecialAttrs struct is used for Ganondorf
        // Mars (Marth) struct is used for Emblem (Roy)
        struct SpecialAttrs_Masterhand masterhand;
        struct SpecialAttrs_Crazyhand crazyhand;
        struct SpecialAttrs_Boy boy;
        struct SpecialAttrs_Girl girl;
        struct SpecialAttrs_GKoopa gkoopa;
        struct SpecialAttrs_Sandbag sandbag;

    } sa;
    /* 0x232C */ s32 x232C;
    /* 0x2330 */ Vec2 x2330;
    /* 0x2338 */ Vec2 x2338;
    union {
        union {
            ftMewtwoStateVars mewtwoVars[0]; // 0x2340
        };
        union{
            ftGameWatchStateVars gameWatchVars[0];
        };
    /* 0x2340 */ s32 x2340_stateVar1;
    /* 0x2340 */ u32 x2340_stateVar1_u32;
    /* 0x2340 */ f32 x2340_f32;
    };
    union {
        u32 x2344_stateVar2;
        s32 x2344_stateVar2_s32;
        void (*x2344_callback)(HSD_GObj*);
        f32 x2344_f32;
        struct
        {
            union
            {
                Vec3 x2344_foxSpecialS[0];
            };
        };
    };
    union {
        /* 0x2348 */ u32 x2348_stateVar3;
        /* 0x2348 */ s32 x2348_stateVar3_s32;
        /* 0x2348 */ f32 x2348_stateVar3_f32;
    };
    union {
        struct {
            union {
                /* 0x234C */ u32 x234C_stateVar4;
                /* 0x234C */ s32 x234C_stateVar4_s32;
                /* 0x234C */ f32 x234C_stateVar4_f32;
            };
            union {
                /* 0x2350 */ u32 x2350_stateVar5;
                /* 0x2350 */ s32 x2350_stateVar5_s32;
                /* 0x2350 */ f32 x2350_stateVar5_f32;
            };
            union {
                /* 0x2350 */ u32 x2354_stateVar6;
                /* 0x2350 */ s32 x2354_stateVar6_s32;
                /* 0x2350 */ f32 x2354_stateVar6_f32;
            };
        };
        /* 0x234C */ Vec3 x234C_pos;
    };
    union {
        /* 0x2358 */ f32 x2358_stateVar7;
        /* 0x2358 */ s32 x2358_stateVar7_s32;

    };
    union {
        /* 0x235C */ f32 x235C;
        /* 0x235C */ u32 x235C_u32;
        /* 0x235C */ s32 x235C_s32;
        /* 0x235C */ f32 x235C_f32;
    };
    union {
        /* 0x2360 */ u32 x2360_u32;
        /* 0x2360 */ s32 x2360;
        /* 0x2360 */ f32 x2360_f32;
    };
    union {
        /* 0x2364 */ u32 x2364_u32;
        /* 0x2364 */ f32 x2364;
        /* 0x2364 */ f32 x2364_f32;
    };
    union {
        /* 0x2368 */ u32 x2368;
        /* 0x2368 */ f32 x2368_f32;
    };
    union {
        /* 0x236C */ u32 x236C;
        /* 0x236C */ f32 x236C_f32;
    };
    union {
        /* 0x2370 */ u32 x2370;
        /* 0x2370 */ f32 x2370_f32;
    };
    union {
    struct {
    union {
    /* 0x2374 */ u32 x2374;
    /* 0x2374 */ f32 x2374_f32;
    /* 0x2374 */ f32 x2374_foxArray[0];
    };
    union {
    /* 0x2378 */ u32 x2378;
    /* 0x2378 */ f32 x2378_f32;
    };
    union {
    /* 0x237C */ u32 x237C;
    /* 0x237C */ f32 x237C_f32;
    };
    };
    /* 0x2374 */ Vec3 x2374_Vec3;
    };
    union {
        /* 0x2380 */ u32 x2380;
        /* 0x2380 */ f32 x2380_f32;
    };
    union {
        /* 0x2384 */ u32 x2384_u32;
        /* 0x2384 */ s32 x2384_s32;
        /* 0x2384 */ f32 x2384_f32;
        /* 0x2384 */ HSD_GObj* x2384_GObj;
    };
    union {
        /* 0x2388 */ u32 x2388_u32;
        /* 0x2388 */ s32 x2388_s32;
        /* 0x2388 */ f32 x2388_f32;
    };
    union {
        /* 0x238C */ u32 x238C_u32;
        /* 0x238C */ f32 x238C;
        /* 0x238C */ f32 x238C_f32;
    };
    /* 0x2390 */ f32 x2390;
    /* 0x2394 */ s32 x2394;
    /* 0x2394 */ Vec3 x2398;
    /* 0x2394 */ Vec3 x23A4;
    /* 0x23B0 */ s32 x23B0;
    /* 0x23B4 */ s32 x23B4;
    /* 0x23B8 */ s32 x23B8;
} Fighter;
inline Fighter* getFighter(HSD_GObj* fighterObj)
{
    return fighterObj->user_data;
}
inline Fighter* getFighterPlus(HSD_GObj* fighter_gobj)
{
    Fighter* fighter_data = fighter_gobj->user_data;
    return fighter_data;
}
inline void* getFtSpecialAttrs(Fighter* fighter_data)
{
    void* fighter_attr = fighter_data->x2D4_specialAttributes;
    return fighter_attr;
}
inline f32 stickGetDir(f32 x1, f32 x2)
{
    if (x1 < x2)
    {
        return -x1;
    }
    else return x1;
}
void Fighter_800679B0();
void Fighter_FirstInitialize_80067A84();
void Fighter_LoadCommonData();
void Fighter_UpdateModelScale(HSD_GObj* fighterObj);
void Fighter_UnkInitReset_80067C98(Fighter*);
void Fighter_UnkProcessDeath_80068354(HSD_GObj* fighterObj);
void Fighter_UnkUpdateCostumeJoint_800686E4(HSD_GObj* fighterObj);
void Fighter_UnkUpdateVecFromBones_8006876C(Fighter* fighter);
void Fighter_ResetInputData_80068854(HSD_GObj* fighterObj);
void Fighter_UnkInitLoad_80068914(HSD_GObj* fighterObj, struct S_TEMP1* argdata);
u32 Fighter_NewSpawn_80068E40();
void Fighter_80068E64(HSD_GObj* fighterObj);
HSD_GObj* Fighter_80068E98(struct S_TEMP1* input);
void Fighter_ActionStateChange_800693AC(HSD_GObj* fighterObj, s32 new_action_state_index, s32 flags, HSD_GObj* otherObj, f32 animStart, f32 animSpeed, f32 animBlend);
void Fighter_8006A1BC(HSD_GObj* fighterObj);
void Fighter_8006A360(HSD_GObj* fighterObj);
void Fighter_8006ABA0(HSD_GObj* fighterObj);
void Fighter_UnkIncrementCounters_8006ABEC(HSD_GObj* fighterObj);
void Fighter_Spaghetti_8006AD10(HSD_GObj* fighterObj);
void Fighter_procUpdate(HSD_GObj* fighterObj, s32 dummy);
void Fighter_UnkApplyTransformation_8006C0F0(HSD_GObj* fighterObj);
void Fighter_8006C27C(HSD_GObj* fighterObj, s32 unused, s32 unused2, s32 unused3);
void Fighter_8006C5F4(HSD_GObj* fighterObj);
void Fighter_CallAcessoryCallbacks_8006C624(HSD_GObj* fighterObj);
void Fighter_8006C80C(HSD_GObj* fighterObj);
void Fighter_UnkProcessGrab_8006CA5C(HSD_GObj* fighterObj);
void Fighter_8006CB94(HSD_GObj* fighterObj);
void Fighter_UnkTakeDamage_8006CC30(Fighter* fighter, f32 damage_amount);
void Fighter_TakeDamage_8006CC7C(Fighter*, f32);
void Fighter_8006CDA4(Fighter* fighter, s32 arg1, s32 arg2, s32 arg3);
void Fighter_8006CF5C(Fighter* fighter, s32 arg1);
void Fighter_UnkSetFlag_8006CFBC(HSD_GObj* fighterObj);
void Fighter_8006CFE0(HSD_GObj* fighterObj);
void Fighter_UnkRecursiveFunc_8006D044(HSD_GObj* fighterObj);
void Fighter_8006D10C(HSD_GObj* fighterObj);
void Fighter_UnkProcessShieldHit_8006D1EC(HSD_GObj* fighterObj);
void Fighter_8006D9AC(HSD_GObj* fighterObj);
void Fighter_UnkCallCameraCallback_8006D9EC(HSD_GObj* fighterObj);
void Fighter_8006DA4C(HSD_GObj* fighterObj);
void Fighter_Unload_8006DABC(Fighter* fighter);
inline void Fighter_OnItemPickup(HSD_GObj* fighterObj, BOOL catchItemFlag, BOOL bool2, BOOL bool3) {
    Fighter *fighter = getFighter(fighterObj);
    if (!func_8026B2B4(fighter->x1974_heldItem)) {
        switch (func_8026B320(fighter->x1974_heldItem)) {
            case 1:
                func_80070FB4(fighterObj, bool2, 1);
                break;
            case 2:
                func_80070FB4(fighterObj, bool2, 0);
                break;
            case 3:
                func_80070FB4(fighterObj, bool2, 2);
                break;
            case 4:
                func_80070FB4(fighterObj, bool2, 3);
                break;
        }
        if (catchItemFlag) {
            func_80070C48(fighterObj, bool3);
        }
    }
}
inline void Fighter_OnItemInvisible(HSD_GObj* gobj, BOOL bool)
{
    Fighter* ft = getFighter(gobj);
    if (!func_8026B2B4(ft->x1974_heldItem)) {
        func_80070CC4(gobj, bool);
    }
}
inline void Fighter_OnItemVisible(HSD_GObj* gobj, BOOL bool)
{
    Fighter* ft = getFighter(gobj);
    if (!func_8026B2B4(ft->x1974_heldItem)) {
        func_80070C48(gobj, bool);
    }
}
inline void Fighter_OnItemDrop(HSD_GObj* gobj, BOOL dropItemFlag, BOOL bool2, BOOL bool3)
{
    func_80070FB4(gobj, bool2, -1);
    if (dropItemFlag) {
        func_80070CC4(gobj, bool3);
    }
}
inline void Fighter_OnKnockbackEnter(HSD_GObj* gobj, s32 arg1) {
    func_800704F0(gobj, arg1, 3.0f);
    func_800704F0(gobj, 0, 3.0f);
}
inline void Fighter_OnKnockbackExit(HSD_GObj* gobj, s32 arg1) {
    func_800704F0(gobj, arg1, 0.0f);
    func_800704F0(gobj, 0, 0.0f);
}
inline void Fighter_UnsetCmdVar0(HSD_GObj* fighterObj) {
    Fighter* fighter = getFighter(fighterObj);
    fighter->x2200_ftcmd_var0 = 0;
}
void func_8007C930(Fighter*, f32);
void func_8007C98C(Fighter*, f32, f32, f32);
void func_8007CA80(Fighter*, f32, f32);
void func_8007CADC(Fighter*, f32, f32, f32);
void func_8007CB74(HSD_GObj*);
HSD_GObj* func_8007CC1C(HSD_GObj*);
void func_8007CC78(f32, Fighter*);
void func_8007CCA0(Fighter*, f32);
void func_8007CCE8(Fighter*);
f32 func_8007CD6C(f32, f32 decrement);
f32 func_8007CDA4(Fighter*);
f32 func_8007CDF8(Fighter*);
void func_8007CE4C(Fighter*, f32);
void func_8007CE94(Fighter*, f32);
void func_8007CEF4(Fighter*);
BOOL func_8007CF58(Fighter*);
BOOL func_8007D050(Fighter*, f32);
void func_8007D140(Fighter*, f32, f32, f32);
void func_8007D174(Fighter*, f32, f32, f32, f32);
void func_8007D268(Fighter*);
void func_8007D28C(Fighter*, f32);
void func_8007D2E8(Fighter*, f32, f32);
void func_8007D344(Fighter*, f32, f32, f32);
void func_8007D3A8(Fighter*, f32, f32, f32);
void func_8007D440(Fighter*, f32);
void func_8007D468(Fighter*);
void func_8007D494(Fighter*, f32, f32);
void func_8007D4B8(Fighter*);
void func_8007D4E4(Fighter*);
void ftComm_ClampFalllSpeed(Fighter*, f32);
void func_8007D508(Fighter*, f32, f32);
BOOL func_8007D528(Fighter*);
void func_8007D5BC(Fighter*);
void func_8007D5D4(Fighter*);
void func_8007D60C(Fighter*);
void func_8007D698(Fighter*);
void func_8007D6A4(Fighter*);
void func_8007D780(Fighter*);
void func_8007D7FC(Fighter*);
void func_8007D92C(HSD_GObj*);
f32 func_8007D964(Fighter*);
f32 func_8007D99C(Fighter*);
f32 func_8007D9D4(Fighter*);
void func_8007D9FC(Fighter*);
void func_8007DA24(Fighter*);
f32 func_8007DA74(s32, u32, f32);
void func_8007DB24(HSD_GObj*);
void func_8007DB58(HSD_GObj*);
void func_8007DBCC(Fighter*, BOOL, f32);
s32 func_8007DC08(Fighter*, f32);
void func_8007DD7C(HSD_GObj*, Vec3*);
void func_8007DFD0();
void func_8007E0E4(HSD_GObj*);
void func_8007E2A4();
void func_8007E2D0(Fighter*, s16, void (*cb0)(HSD_GObj*), void (*cb1)(HSD_GObj*), void (*cb2)(HSD_GObj*, HSD_GObj*));
void func_8007E2F4(Fighter*, s16 val);
void func_8007E2FC(HSD_GObj*);
void func_8007E358(HSD_GObj*);
void func_8007E3EC(HSD_GObj*);
void func_8007E5AC(Fighter*);
void func_8007E620(Fighter*, HSD_Joint*);
void func_8007E690(Fighter*, HSD_AnimJoint*);
void func_8007E6DC(HSD_GObj*, HSD_GObj* item_gobj, s32);
void func_8007E79C(HSD_GObj*, s32);
void func_8007E7E4(HSD_GObj*, s32);
void func_8007E82C(HSD_GObj*);
void func_8007E83C(HSD_GObj*, s32, f32 div);
s32 ftGetParasolStatus(HSD_GObj*);
void func_8007EA90(Fighter*, s32);
void func_8007EBAC(Fighter*, u32, u32);
void func_8007EC30(u32, u32);
void func_8007ECD4(Fighter*, s32);
void func_8007ED2C(Fighter*);
void func_8007ED50(Fighter*, s32);
void func_8007EE0C(Fighter*, s32);
void func_8007EEC8(Fighter*, s32, s32);
void func_8007EF5C(Fighter*, s32);
void func_8007EFC0(Fighter*, u32 val);
void func_8007EFC8(HSD_GObj*, void (*)(HSD_GObj*));
void func_8007F578(HSD_GObj*);
void func_8007F5CC(HSD_GObj*, s32);
f32 Fighter_GetModelScale(Fighter*);
void func_8007F6A4(Fighter*, HSD_JObj*);
void func_8007F76C(HSD_GObj*);
void func_8007F7B4(HSD_GObj*);
void* func_8007F804(Fighter*);
void func_8007F824(HSD_GObj*);
void func_8007F86C(HSD_GObj*);
void func_8007F8B4(Fighter*, Vec3* v);
void func_8007F8E8(HSD_GObj*);
void func_8007F948(HSD_GObj*, HSD_GObj*, s32);
void func_8007F9B4(HSD_GObj*);
void func_8007FA00(HSD_GObj*);
void func_8007FA58(HSD_GObj*, HSD_GObj*);
void func_8007FC7C(HSD_GObj*, f32);
void func_8007FDA0(HSD_GObj*);
void func_8007FE84(HSD_GObj*, HSD_GObj* item_gobj, s32, f32);
void func_8007FF74(HSD_GObj*);
BOOL func_8007FFD8(Fighter*, f32);
BOOL func_80080144(Fighter*);
void func_80080174();
void func_8008021C(HSD_GObj*);
void func_8008031C(HSD_GObj*);
void func_80080460(Fighter*);
void func_80080474(Fighter*);
void func_80080484(Fighter*);
void func_800804A0(Fighter*, f32);
f32 func_800804EC(Fighter*);
void func_800804FC(Fighter*);
void GXProject (
 f32 x,
 f32 y,
 f32 z,
 f32 mtx[3][4],
 f32* pm,
 f32* vp,
 f32* sx,
 f32* sy,
 f32* sz );
typedef struct _HSD_WObj {
    HSD_Obj parent;
    u32 flags;
    Vec pos;
    struct _HSD_AObj* aobj;
    struct _HSD_RObj* robj;
} HSD_WObj;
typedef struct _HSD_WObjDesc {
    char* class_name;
    Vec pos;
    struct _HSD_RObjDesc* robjdesc;
    struct _HSD_WObjDesc* next;
} HSD_WObjDesc;
typedef struct _HSD_WObjInfo {
    HSD_ObjInfo parent;
    int (*load)(HSD_WObj* wobj, HSD_WObjDesc* desc);
} HSD_WObjInfo;
typedef struct _HSD_WObjAnim {
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_RObjAnimJoint* robjanim;
} HSD_WObjAnim;
extern HSD_WObjInfo hsdWObj;
void HSD_WObjRemoveAnim(HSD_WObj* wobj);
void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame);
void HSD_WObjAddAnim(HSD_WObj* wobj, HSD_WObjAnim* anim);
void HSD_WObjInterpretAnim(HSD_WObj* wobj);
void HSD_WObjInit(HSD_WObj* wobj, HSD_WObjDesc* desc);
HSD_WObj* HSD_WObjLoadDesc(HSD_WObjDesc* desc);
void WObjSetupPosition(HSD_WObj* wobj);
void HSD_WObjSetPosition(HSD_WObj*, Vec*);
void HSD_WObjSetPositionX(HSD_WObj*, f32);
void HSD_WObjSetPositionY(HSD_WObj*, f32);
void HSD_WObjSetPositionZ(HSD_WObj*, f32);
void HSD_WObjGetPosition(HSD_WObj*, Vec*);
HSD_WObj* HSD_WObjAlloc();
typedef struct _HSD_CObj {
    HSD_Obj parent;
    u32 flags;
    f32 viewport_left;
    f32 viewport_right;
    f32 viewport_top;
    f32 viewport_bottom;
    u16 scissor_left;
    u16 scissor_right;
    u16 scissor_top;
    u16 scissor_bottom;
    struct _HSD_WObj* eye_position;
    struct _HSD_WObj* interest;
    union {
        f32 roll;
        Vec up;
    } u;
    f32 near;
    f32 far;
    union {
        struct {
            f32 fov;
            f32 aspect;
        } perspective;
        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } frustrum;
        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } ortho;
    } projection_param;
    u8 projection_type;
    Mtx view_mtx;
    struct _HSD_AObj* aobj;
    Mtx* proj_mtx;
} HSD_CObj;
typedef struct _HSD_CObjDesc {
    char* class_name;
    u16 flags;
    u16 projection_type;
    u16 viewport_left;
    u16 viewport_right;
    u16 viewport_top;
    u16 viewport_bottom;
    u32 scissor_lr;
    u32 scissor_tb;
    struct _HSD_WObjDesc* eye_desc;
    struct _HSD_WObjDesc* interest_desc;
    f32 roll;
    Vec* vector;
    f32 near;
    f32 far;
    union {
        struct {
            f32 fov;
            f32 aspect;
        } perspective;
        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } frustrum;
        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } ortho;
    } projection_param;
} HSD_CObjDesc;
typedef struct _HSD_CObjInfo {
    HSD_ObjInfo parent;
    int (*load)(HSD_CObj* cobj, HSD_CObjDesc* desc);
} HSD_CObjInfo;
typedef struct _HSD_CameraAnim {
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_WObjAnim* eye_anim;
    struct _HSD_WObjAnim* interest_anim;
} HSD_CameraAnim;
void HSD_CObjEraseScreen(HSD_CObj* cobj, s32 enable_color, s32 enable_alpha, s32 enable_depth);
void HSD_CObjRemoveAnim(HSD_CObj* cobj);
HSD_WObj* HSD_CObjGetEyePositionWObj(HSD_CObj* cobj);
HSD_WObj* HSD_CObjGetInterestWObj(HSD_CObj* cobj);
extern inline float sqrtf_accurate(float x);
static float lbvector_Len(Vec *vec);
static float lbvector_Len_xy(Vec *vec);
float lbvector_Normalize(Vec *vec);
float lbvector_NormalizeXY(Vec *a);
Vec *lbvector_Add(Vec *a, Vec *b);
Vec *lbvector_Add_xy(Vec *a, Vec *b);
Vec *lbvector_Sub(Vec *a, Vec *b);
Vec *lbvector_Diff(Vec *a, Vec *b, Vec *result);
Vec *lbvector_CrossprodNormalized(Vec *a, Vec *b, Vec *result);
extern float func_80022D1C(float);
float lbvector_Angle(Vec *a, Vec *b);
float lbvector_AngleXY(Vec *a, Vec *b);
static float sin(float angle);
static float cos(float angle);
void lbvector_RotateAboutUnitAxis(Vec *v, Vec *axis, float angle);
void lbvector_Rotate(Vec *v, int axis, float angle);
float dummy(void);
void lbvector_Mirror(Vec *a, Vec *b);
float lbvector_CosAngle(Vec *a, Vec *b);
Vec *lbvector_Lerp(Vec *a, Vec *b, Vec *result, float f);
Vec *func_8000DE38(Mtx m, Vec *v, float c);
extern float func_80022DBC(float);
extern float func_someCalcAngle_80022C30(float, float);
Vec *lbvector_EulerAnglesFromONB(Vec *result_angles, Vec *a, Vec *b, Vec *c);
Vec *lbvector_EulerAnglesFromPartialONB(Vec *result_angles, Vec *a, Vec *c);
Vec *lbvector_ApplyEulerRotation(Vec *v, Vec *angles);
float lbvector_sqrtf_accurate(float x);
extern MtxPtr func_80369688(HSD_CObj *);
Vec *lbvector_WorldToScreen(HSD_CObj *cobj, const Point3d *pos3d, Point3d *screenCoords, int d);
void lbvector_CreateEulerMatrix(Mtx m, Vec *angles);
float lbvector_8000E838(Vec *a, Vec *b, Vec *c, Vec *d);
typedef struct _ftDonkeyAttributes {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
    s32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
    f32 x40;
    f32 x44;
    f32 x48;
    f32 x4C;
    f32 x50;
    f32 x54;
    u8 data_filler_10[0x68 - 0x58];
    f32 x68;
    f32 x6C;
    f32 x70;
} ftDonkeyAttributes;
void ftDonkey_8010D774(HSD_GObj* fighterObj);
void ftDonkey_8010DB3C(HSD_GObj* fighterObj);
void ftDonkey_8010DE88(HSD_GObj* fighterObj);
void ftDonkey_8010DFF8(HSD_GObj* fighterObj);
void ftDonkey_8010E0CC(HSD_GObj* fighterObj);
void ftDonkey_8010E148(HSD_GObj* fighterObj);
void ftDonkey_8010E464(HSD_GObj* fighterObj);
void ftDonkey_8010E4EC(HSD_GObj* fighterObj);
void ftDonkey_DestroyAllEffects(HSD_GObj* fighterObj);

inline void ftDonkey_SetCallbacks_SpecialHi(HSD_GObj* fighterObj) {
    Fighter* fighter = fighterObj->user_data;
    fighter->cb.x21DC_callback_OnTakeDamage = &ftDonkey_8010D774;
    fighter->cb.x21E4_callback_OnDeath2 = &ftDonkey_8010D774;
    fighter->cb.x21D4_callback_EnterHitlag = efLib_PauseAll;
    fighter->cb.x21D8_callback_ExitHitlag = efLib_ResumeAll;
}

typedef struct _ftFoxAttributes {

    // NEUTRAL SPECIAL - BLASTER //

    f32 x0_FOX_BLASTER_UNK1;
    f32 x4_FOX_BLASTER_UNK2;
    f32 x8_FOX_BLASTER_UNK3;
    f32 xC_FOX_BLASTER_UNK4;
    f32 x10_FOX_BLASTER_ANGLE; // Angle at which Blaster shots are fired
    f32 x14_FOX_BLASTER_VEL; // Velocity at which Blaster shots are fired
    f32 x18_FOX_BLASTER_LANDING_LAG;
    s32 x1C_FOX_BLASTER_SHOT_ITKIND;
    s32 x20_FOX_BLASTER_GUN_ITKIND;

    // SIDE SPECIAL - FOX ILLUSION / FALCO PHANTASM //

    f32 x24_FOX_ILLUSION_GRAVITY_DELAY; // Frames required to pass before gravity is applied
    f32 x28_FOX_ILLUSION_GROUND_VEL_X; // Horizontal velocity?
    f32 x2C_FOX_ILLUSION_UNK1;
    f32 x30_FOX_ILLUSION_UNK2;
    f32 x34_FOX_ILLUSION_UNK3;
    f32 x38_FOX_ILLUSION_GROUND_FRICTION;
    f32 x3C_FOX_ILLUSION_AIR_VEL_X;
    f32 x40_FOX_ILLUSION_AIR_MUL_X;
    f32 x44_FOX_ILLUSION_FALL_ACCEL;
    f32 x48_FOX_ILLUSION_TERMINAL_VELOCITY;
    f32 x4C_FOX_ILLUSION_UNK4;
    f32 x50_FOX_ILLUSION_LANDING_LAG;

    // UP SPECIAL - FIREFOX / FIREBIRD //

    f32 x54_FOX_FIREFOX_GRAVITY_DELAY;
    f32 x58_FOX_FIREFOX_VEL_X; // Initial velocity
    f32 x5C_FOX_FIREFOX_AIR_MOMENTUM_PRESERVE_X; 
    f32 x60_FOX_FIREFOX_FALL_ACCEL;
    f32 x64_FOX_FIREFOX_DIRECTION_STICK_RANGE_MIN; // Minimum control stick range required for direction change
    f32 x68_FOX_FIREFOX_DURATION; // Amount of frames Firefox/Firebird travels
    f32 x6C_FOX_FIREFOX_UNK1;
    f32 x70_FOX_FIREFOX_AIR_MOMENTUM_END;
    f32 x74_FOX_FIREFOX_SPEED;
    f32 x78_FOX_FIREFOX_REVERSE_ACCEL; // ???
    f32 x7C_FOX_FIREFOX_GROUND_MOMENTUM_END;
    f32 x80_FOX_FIREFOX_UNK2;
    f32 x84_FOX_FIREFOX_BOUND_VEL_X; // Horizontal velocity of SpecialHiBound action state
    f32 x88_FOX_FIREFOX_FACING_STICK_RANGE_MIN; // Minimum control stick range required to change character's facing direction
    f32 x8C_FOX_FIREFOX_FREEFALL_MOBILITY;
    f32 x90_FOX_FIREFOX_LANDING_LAG;
    f32 x94_FOX_FIREFOX_BOUND_LANDING_LAG;
    
    // DOWN SPECIAL - REFLECTOR //

    f32 x98_FOX_REFLECTOR_RELEASE_LAG; // Auto lag frames after initializing Reflector if B is not being held. Reflector is immediately released with no lag once these frames have passed.
    f32 x9C_FOX_REFLECTOR_TURN_FRAMES; // Amount of turn frames for changing Reflector direction
    f32 xA0_FOX_REFLECTOR_UNK1;
    s32 xA4_FOX_REFLECTOR_GRAVITY_DELAY;
    f32 xA8_FOX_REFLECTOR_MOMENTUM_PRESERVE_X;
    f32 xAC_FOX_REFLECTOR_FALL_ACCEL;
    ReflectDesc xB0_FOX_REFLECTOR_REFLECTION;

} ftFoxAttributes;

typedef struct _ftCaptainAttributes
{
    f32 x0_CAPTAIN_FALCONPUNCH_STICK_RANGE_Y_NEG;   // Minimum control stick range required for downward angle (Negative Y)
    f32 x4_CAPTAIN_FALCONPUNCH_STICK_RANGE_Y_POS;   // Minimum control stick range required for upward angle (Positive Y)
    f32 x8_CAPTAIN_FALCONPUNCH_ANGLE_DIFF;          // Maximum angle change from control stick input
    f32 xC_CAPTAIN_FALCONPUNCH_MOMENTUM_X;          // Momentum gained from aerial Falcon/Warlock Punch
    f32 x10_CAPTAIN_FALCONPUNCH_MOMENTUM_MUL; // Additional momentum from angled Falcon/Warlock Punch

    f32 x14_CAPTAIN_RAPTORBOOST_GROUND_VEL_X;
    f32 x18_CAPTAIN_RAPTORBOOST_MISS_GRAVITY;
    f32 x1C_CAPTAIN_RAPTORBOOST_TERMINAL_VELOCITY;
    f32 SIDEB_UNK1;
    f32 SIDEB_UNK2;
    f32 SIDEB_UNK3;
    f32 SIDEB_UNK4;
    f32 SIDEB_UNK5;
    f32 SIDEB_UNK6;
    f32 x38_CAPTAIN_RAPTORBOOST_MISS_LANDING_LAG;
    f32 x3C_CAPTAIN_RAPTORBOOST_HIT_LANDING_LAG;

    f32 UPB_AIR_FRICTION_MULTIPLIER;
    f32 UPB_HORIZONTAL_MOMENTUM;
    f32 UPB_FREEFALL_AIR_SPEED_MULTIPLIER;
    f32 UPB_LANDING_LAG;
    f32 UPB_UNK1;
    f32 UPB_UNK2;
    f32 UPB_INPUT_VAR;
    f32 UPB_UNK3;
    f32 UPB_GRAVITY_DURING_AIR_CATCH;
    f32 UPB_AERIAL_VAR;

    f32 COMPLETELY_UNKNOWN;

    u32 DOWNB_UNK1;
    f32 DOWNB_FLAME_PARTICLE_ANGLE;
    f32 DOWNB_ON_HIT_SPEED_MODIFIER;
    u32 DOWNB_UNK2;
    f32 DOWNB_GROUND_LAG_MULTIPLIER;
    f32 DOWNB_LANDING_LAG_MULTIPLIER;
    f32 DOWNB_GROUND_TRACTION;
    f32 DOWNB_AIR_LANDING_TRACTION;

} ftCaptainAttributes;

typedef struct _ftMewtwoAttributes {

    // NEUTRAL SPECIAL - SHADOW BALL (SpecialN/SpecialAirN) // 

    f32 x0_MEWTWO_SHADOWBALL_CHARGE_CYCLES; // Number of frames each iteration cycle lasts?
    f32 x4_MEWTWO_SHADOWBALL_GROUND_RECOIL_X;
    f32 x8_MEWTWO_SHADOWBALL_AIR_RECOIL_X;
    s32 xC_MEWTWO_SHADOWBALL_CHARGE_ITERATIONS; // Number of iterations required for full charge
    s32 x10_MEWTWO_SHADOWBALL_RELEASE_LAG;
    f32 x14_MEWTWO_SHADOWBALL_LANDING_LAG;

    // SIDE SPECIAL - CONFUSION (SpecialS/SpecialAirS) //

    f32 x18_MEWTWO_CONFUSION_AIR_BOOST;
    ReflectDesc x1C_MEWTWO_CONFUSION_REFLECTION;

    // UP SPECIAL - TELEPORT (SpecialHi/SpecialAirHi) //

    f32 x40_MEWTWO_TELEPORT_VEL_DIV_X;
    f32 x44_MEWTWO_TELEPORT_VEL_DIV_Y;
    s32 x48_MEWTWO_TELEPORT_GRAVITY;
    s32 x4C_MEWTWO_TELEPORT_UNK1;
    s32 x50_MEWTWO_TELEPORT_DURATION;
    f32 x54_MEWTWO_TELEPORT_UNK2;
    f32 x58_MEWTWO_TELEPORT_STICK_RANGE_MIN;
    f32 x5C_MEWTWO_TELEPORT_MOMENTUM;
    f32 x60_MEWTWO_TELEPORT_MOMENTUM_ADD;
    f32 x64_MEWTWO_TELEPORT_MOMENTUM_END;
    s32 x68_MEWTWO_TELEPORT_ANGLE_CLAMP; // Clamp teleport travel if surface angle is greater than this valuei88iiiiiiiiii 
    f32 x6C_MEWTWO_TELEPORT_MOMENTUM_END_MUL;
    f32 x70_MEWTWO_TELEPORT_UNK3;
    f32 x74_MEWTWO_TELEPORT_LANDING_LAG;

    // DOWN SPECIAL - DISABLE (SpecialLw/SpecialAirLw) //

    f32 x78_MEWTWO_DISABLE_TERMINAL_VELOCITY;
    f32 x7C_MEWTWO_DISABLE_VEL_Y_MUL;
    f32 x80_MEWTWO_DISABLE_OFFSET_X;
    f32 x84_MEWTWO_DISABLE_OFFSET_Y;

} ftMewtwoAttributes; 

inline void* getFtSpecialAttrsD(Fighter* fp)
{
    return fp->x2D4_specialAttributes;        
}

typedef struct _ftGameWatchAttributes {

    // MISC. ATTRIBUTES //

    f32 x0_GAMEWATCH_WIDTH; // Mr. Game & Watch's Z-Axis stretch; 0.01 by default
    s32 x4_GAMEWATCH_COLOR[4]; // Array of four RGBA values, one for each Mr. Game & Watch costume color
    s32 x14_GAMEWATCH_OUTLINE; // Outline color of Mr. Game & Watch's model

    // NEUTRAL SPECIAL - CHEF //

    f32 x18_GAMEWATCH_CHEF_LOOPFRAME; // Allow rapid-firing sausages from this frame onward
    f32 x1C_GAMEWATCH_CHEF_MAX; // Maximum amount of sausages created per Chef use

    // SIDE SPECIAL - JUDGEMENT //

    f32 x20_GAMEWATCH_JUDGE_MOMENTUM_PRESERVE; // Horizontal momentum preservation value 
    f32 x24_GAMEWATCH_JUDGE_MOMENTUM_MUL; // Multiplies momentum preservation value
    f32 x28_GAMEWATCH_JUDGE_VEL_Y;
    f32 x2C_GAMEWATCH_JUDGE_FRICTION1;
    f32 x30_GAMEWATCH_JUDGE_FRICTION2;
    s32 x34_GAMEWATCH_JUDGE_ROLL[9]; // Array of BOOLs that toggle respective Judgement numbers ON/OFF. If a number is OFF, it is excluded from RNG rolls. Game panics if less than 2 numbers are ON.

    // UP SPECIAL - FIRE RESCUE //

    f32 x58_GAMEWATCH_RESCUE_STICK_RANGE; // Minimum control stick range required for directional influence? Also affects how far Mr. Game & Watch flings horizontally (?)
    f32 x5C_GAMEWATCH_RESCUE_ANGLE_UNK; // Radians -- controls how far Mr. Game & Watch can angle Fire Rescue? 
    f32 x60_GAMEWATCH_RESCUE_LANDING; // Landing lag / Freefall toggle

    // DOWN SPECIAL - OIL PANIC //

    f32 x64_GAMEWATCH_PANIC_MOMENTUM_PRESERVE; // Horizontal momentum preservation value 
    f32 x68_GAMEWATCH_PANIC_MOMENTUM_MUL; // Multiplies momentum preservation value
    f32 x6C_GAMEWATCH_PANIC_FALL_ACCEL; // Falling acceleration
    f32 x70_GAMEWATCH_PANIC_VEL_Y_MAX; // Terminal Y velocity? 
    f32 x74_GAMEWATCH_PANIC_DAMAGE_ADD; // Extra damage added to Oil Panic after formula
    f32 x78_GAMEWATCH_PANIC_DAMAGE_MUL; // Damage multiplier
    f32 x7C_GAMEWATCH_PANIC_TURN_FRAMES;
    AbsorbDesc x80_GAMEWATCH_PANIC_ABSORPTION; // Oil Panic absorption attributes

} ftGameWatchAttributes;
```

# 3. Generated Assembly from compilation:

```asm
00: mflr    r0
04: stw     r0,4(r1)
08: stwu    r1,-0x28(r1)
0c: stfd    f31,0x20(r1)
10: stw     r31,0x1c(r1)
14: stw     r30,0x18(r1)
18: li      r30,0
1c: lwz     r0,lbl_804D6558@sda21(0)
20: lfs     f31,lbl_804D82E0@sda21(0)
24: cmplwi  r0,0
28: beq-    9c
2c: addi    r31,0,lbl_80459278@sda21
30: b       90
34: lwz     r0,0(r31)
38: cmpwi   r0,2
3c: beq-    6c
40: bge-    88
44: cmpwi   r0,1
48: bge-    50
4c: b       88
50: lwz     r3, 4 (r31)
54: lwz     r0,0x30(r3)
58: cmplwi  r0,0xf
5c: bne-    88
60: lfs     f0,0xc(r3)
64: fadds   f31,f31,f0
68: b       88
6c: lwz r3 , 4 ( r31 )
70: lwz r0 , 0x30 ( r3 )
74: cmplwi  r0,0xf
78: bne-    88
7c: lwz     r3,8(r31)
80: bl      func_8026B1D4
84: fadds   f31,f31,f1
88: addi    r31,r31,0x28
8c: addi    r30,r30,1
90: lwz     r0,lbl_804D6558@sda21(0)
94: cmplw   r30,r0
98: blt+    34
9c: fmr     f1,f31
a0: lwz     r0,0x2c(r1)
a4: lfd     f31,0x20(r1)
a8: lwz     r31,0x1c(r1)
ac: lwz     r30,0x18(r1)
b0: addi    r1,r1,0x28
b4: mtlr    r0
b8: blr
```

# 4. Target Assembly

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
```

You attempted once, and here's the C code you wrote. It had a match of 85.8%, which is lower than the original (at 94%).

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
    lbl_80459278_struct* var_r31 = &lbl_80459278; // initialize r31 directly
    f32 var_f31 = lbl_804D82E0;
    unsigned int var_r30 = 0;
    
    if (lbl_804D6558 != 0) {
        do { // Use do-while loop instead of while for similar structure
            int temp_r0 = var_r31->unk0;
            switch (temp_r0) {
                case 1: {
                    void* temp_r4 = var_r31->unkC; // changing register expectation
                    if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                        var_f31 += *(f32*)((char*)temp_r4 + 0x0C); // maintain same logic
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
        } while (var_r30 < lbl_804D6558); // shift loop condition to do-while's bottom
    }
    return var_f31;
}
```

and then the assembly it generated:

```asm
mflr    r0
stw     r0,4(r1)
stwu    r1,-0x28(r1)
stfd    f31,0x20(r1)
stw     r31,0x1c(r1)
addi    r31,0,lbl_80459278@sda21
stw     r30,0x18(r1)
li      r30,0
lwz     r0,lbl_804D6558@sda21(0)
lfs     f31,lbl_804D82E0@sda21(0)
cmplwi  r0,0
beq-    98
lwz     r0,0(r31)
cmpwi   r0,2
beq-    68
bge- 84
cmpwi   r0,1
bge-    4c
b 84
lwz     r3, 4 (r31)
lwz     r0,0x30(r3)
cmplwi  r0,0xf
bne- 84
lfs     f0,0xc(r3)
fadds   f31,f31,f0
b 84
lwz r3 , 4 ( r31 )
lwz r0 , 0x30 ( r3 )
cmplwi  r0,0xf
bne- 84
lwz     r3,8(r31)
bl      func_8026B1D4
fadds   f31,f31,f1
lwz     r0,lbl_804D6558@sda21(0)
addi r30 , r30 , 1
addi r31 , r31 , 0x28
cmplw   r30,r0
blt+    30
fmr     f1,f31
lwz     r0,0x2c(r1)
lfd     f31,0x20(r1)
lwz     r31,0x1c(r1)
lwz     r30,0x18(r1)
addi    r1,r1,0x28
mtlr    r0
blr
```

You did another attempt, with 90.9%

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
    lbl_80459278_struct* var_r31;
    f32 var_f31;
    unsigned int var_r30;

    var_f31 = lbl_804D82E0;
    if (lbl_804D6558 != 0) {
        var_r31 = &lbl_80459278;
        var_r30 = 0;
        do {
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
        } while (var_r30 < lbl_804D6558);
    }
    return var_f31;
}
```

```asm
mflr    r0
stw     r0,4(r1)
stwu    r1,-0x28(r1)
stfd    f31,0x20(r1)
stw     r31,0x1c(r1)
stw     r30,0x18(r1)
lwz     r0,lbl_804D6558@sda21(0)
lfs     f31,lbl_804D82E0@sda21(0)
cmplwi  r0,0
beq-    98
addi    r31,0,lbl_80459278@sda21
li      r30,0
lwz     r0,0(r31)
cmpwi   r0,2
beq-    68
bge- 84
cmpwi   r0,1
bge-    4c
b 84
lwz     r3, 4 (r31)
lwz     r0,0x30(r3)
cmplwi  r0,0xf
bne- 84
lfs     f0,0xc(r3)
fadds   f31,f31,f0
b 84
lwz r3 , 4 ( r31 )
lwz r0 , 0x30 ( r3 )
cmplwi  r0,0xf
bne- 84
lwz     r3,8(r31)
bl      func_8026B1D4
fadds   f31,f31,f1
lwz     r0,lbl_804D6558@sda21(0)
addi r30 , r30 , 1
addi r31 , r31 , 0x28
cmplw   r30,r0
blt+    30
fmr     f1,f31
lwz     r0,0x2c(r1)
lfd     f31,0x20(r1)
lwz     r31,0x1c(r1)
lwz     r30,0x18(r1)
addi    r1,r1,0x28
mtlr    r0
blr
```

And again, this time at 72%. You're getting worse


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
    lbl_80459278_struct* var_r31;
    f32 var_f31;
    unsigned int var_r30;
    int temp_r0;

    var_r30 = 0;
    
    var_f31 = lbl_804D82E0;
    if (lbl_804D6558 != 0) {
        var_r31 = &lbl_80459278;

        while (1) {
            temp_r0 = var_r31->unk0;  // Use a specific temporary variable for the switch
            if (temp_r0 == 1) {
                void* temp_r3 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r3 + 0x30) == 0xF) {
                    var_f31 += *(f32*)((char*)temp_r3 + 0x0C);
                }
            }
            else if (temp_r0 == 2) {
                void* temp_r4 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                    var_f31 += func_8026B1D4(*(int*)((char*)var_r31 + 8));
                }
            }
            
            var_r31 = (lbl_80459278_struct*)((char*)var_r31 + 0x28);
            var_r30++;
            
            if (var_r30 >= lbl_804D6558) {
                break;
            }
        }
    }
    return var_f31;
}
```

```asm
mflr    r0
stw     r0,4(r1)
stwu    r1, -0x20(r1)
stfd    f31, 0x18(r1)
stw     r31, 0x14(r1)
stw     r30, 0x10(r1)
li      r30,0
lwz     r0,lbl_804D6558@sda21(0)
lfs     f31,lbl_804D82E0@sda21(0)
cmplwi  r0,0
beq-    90
addi    r31,0,lbl_80459278@sda21
lwz     r0,0(r31)
cmpwi   r0, 1
bne-    58
lwz     r3, 4 (r31)
lwz     r0,0x30(r3)
cmplwi  r0,0xf
bne- 7c
lfs     f0,0xc(r3)
fadds   f31,f31,f0
b 7c
cmpwi   r0,2
bne-    7c
lwz r3 , 4 ( r31 )
lwz r0 , 0x30 ( r3 )
cmplwi  r0,0xf
bne- 7c
lwz     r3,8(r31)
bl      func_8026B1D4
fadds   f31,f31,f1
lwz     r0,lbl_804D6558@sda21(0)
addi r30 , r30 , 1
addi r31 , r31 , 0x28
cmplw   r30,r0
blt+    30
fmr     f1,f31
lwz     r0, 0x24(r1)
lfd     f31, 0x18(r1)
lwz     r31, 0x14(r1)
lwz     r30, 0x10(r1)
addi    r1,r1, 0x20
mtlr    r0
blr
```

A slight improvement. Now at 72%. Can you consider making it more similar to the highest % success? We were at like 94% initially

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

f32 func_8007BBCC(struct _HSD_GObj*) {
    lbl_80459278_struct* var_r31 = &lbl_80459278;
    f32 var_f31 = lbl_804D82E0;
    unsigned int var_r30 = 0;

    if (lbl_804D6558 != 0) {
        while (var_r30 < lbl_804D6558) {
            int temp_r0 = var_r31->unk0;
            if (temp_r0 == 1) {
                void* temp_r4 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                    var_f31 += *(f32*)((char*)temp_r4 + 0x0C);
                }
            } else if (temp_r0 == 2) {
                void* temp_r4 = var_r31->unkC;
                if (*(unsigned int*)((char*)temp_r4 + 0x30) == 0xF) {
                    var_f31 += func_8026B1D4(*(int*)((char*)var_r31 + 8));
                }
            }
            var_r31 = (lbl_80459278_struct*)((char*)var_r31 + 0x28);
            var_r30++;
        }
    }

    return var_f31;
}
```

```asm
0000: mflr    r0
0004: stw     r0,4(r1)
0008: stwu    r1, -0x20(r1)
000c: stfd    f31, 0x18(r1)
0010: stw     r31, 0x14(r1)
0014: stw     r30, 0x10(r1)
0018: li      r30,0
001c: lwz     r0,lbl_804D6558@sda21(0)
0020: lfs     f31,lbl_804D82E0@sda21(0)
0024: cmplwi  r0,0
0028: beq-    90
002c: addi    r31,0,lbl_80459278@sda21
0030: lwz     r0,0(r31)
0034: cmpwi   r0, 1
0038: bne-    58
003c: lwz     r3, 4 (r31)
0040: lwz     r0,0x30(r3)
0044: cmplwi  r0,0xf
0048: bne- 7c
004c: lfs     f0,0xc(r3)
0050: fadds   f31,f31,f0
0054: b 7c
0058: cmpwi   r0,2
005c: bne-    7c
0060: lwz r3 , 4 ( r31 )
0064: lwz r0 , 0x30 ( r3 )
0068: cmplwi  r0,0xf
006c: bne- 7c
0070: lwz     r3,8(r31)
0074: bl      func_8026B1D4
0078: fadds   f31,f31,f1
007c: lwz     r0,lbl_804D6558@sda21(0)
0080: addi r30 , r30 , 1
0084: addi r31 , r31 , 0x28
0088: cmplw   r30,r0
008c: blt+    30
0090: fmr     f1,f31
0094: lwz     r0, 0x24(r1)
0098: lfd     f31, 0x18(r1)
009c: lwz     r31, 0x14(r1)
00a0: lwz     r30, 0x10(r1)
00a4: addi    r1,r1, 0x20
00a8: mtlr    r0
00ac: blr
```

# o1 attempt 1

Yo, this is so much closer. You just got 95.31% match. Here's your reasoning

This code matches the target assembly more closely because:

- We use `temp_r3` in case 1 and `temp_r4` in case 2, aligning with the register usage (`r3` and `r4`) in the assembly.
- We declare variables in the same order they are used in the assembly.
- We maintain the `switch` statement structure, which aligns with the assembly's `cmpwi` and `beq-` instructions.


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

```asm
0000: mflr    r0
0004: stw     r0,4(r1)
0008: stwu    r1,-0x28(r1)
000c: stfd    f31,0x20(r1)
0010: stw     r31,0x1c(r1)
0014: stw     r30,0x18(r1)
0018: lwz     r0,lbl_804D6558@sda21(0)
001c: lfs     f31,lbl_804D82E0@sda21(0)
0020: cmplwi  r0,0
0024: beq-    9c
0028: addi    r31,0,lbl_80459278@sda21
002c: li      r30,0
0030: b       90
0034: lwz     r0,0(r31)
0038: cmpwi   r0,2
003c: beq-    6c
0040: bge-    88
0044: cmpwi   r0,1
0048: bge-    50
004c: b       88
0050: lwz     r3, 4 (r31)
0054: lwz     r0,0x30(r3)
0058: cmplwi  r0,0xf
005c: bne-    88
0060: lfs     f0,0xc(r3)
0064: fadds   f31,f31,f0
0068: b       88
006c: lwz r3 , 4 ( r31 )
0070: lwz r0 , 0x30 ( r3 )
0074: cmplwi  r0,0xf
0078: bne-    88
007c: lwz     r3,8(r31)
0080: bl      func_8026B1D4
0084: fadds   f31,f31,f1
0088: addi    r31,r31,0x28
008c: addi    r30,r30,1
0090: lwz     r0,lbl_804D6558@sda21(0)
0094: cmplw   r30,r0
0098: blt+    34
009c: fmr     f1,f31
00a0: lwz     r0,0x2c(r1)
00a4: lfd     f31,0x20(r1)
00a8: lwz     r31,0x1c(r1)
00ac: lwz     r30,0x18(r1)
00b0: addi    r1,r1,0x28
00b4: mtlr    r0
00b8: blr
```

# o1 attempt 2

A bit closer. 95.61%. Can you spend some time thinking about how to get all the way there?

Here's your reasoning for this C code:

**Explanation of Changes:**

1. **Adjusted Struct Offsets:**
   - Updated `lbl_80459278_struct` to match the target assembly offsets by adding `int unk4;` and `int unk8;` to ensure `unkC` is at the correct offset (`+0xC`).

2. **Variable Declarations Order:**
   - Declared `var_f31` first to match the use of registers in the assembly.
   - Moved the declarations of `var_r31` and `var_r30` into the scope where they are used, after the `if` statement. This mirrors the assembly's initialization order.

3. **Used `temp_r4` Variable:**
   - In the switch cases, used `temp_r4` instead of `temp_r3` to match the target assembly's register usage (`r4` is used in the target code during case 2).

4. **Explicit Empty `default` Case:**
   - Added an explicit empty `default` case in the switch statement to account for the extra branch (`b 90`) in the target assembly at offset `0x54`.

5. **Address Loading:**
   - Changed the assignment of `var_r31` to force the compiler to generate the `lis` and `addi` instructions when loading the address of `lbl_80459278`:
     ```c
     var_r31 = (lbl_80459278_struct*)((char*)0 + (unsigned int)&lbl_80459278);

```c
typedef float f32;

typedef struct {
    int unk0;   // offset +0x0
    int unk4;
    int unk8;
    void* unkC; // offset +0xC
    // Padding to make the size 0x28
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
                void* temp_r4 = var_r31->unkC; // Use temp_r4 to influence register allocation
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
            default:
                // Explicit empty default case
                break;
            }
            var_r31 = (lbl_80459278_struct*)((char*)var_r31 + 0x28);
            var_r30++;
        }
    }
    return var_f31;
}

```

```asm
0000: mflr    r0
0004: stw     r0,4(r1)
0008: stwu    r1,-0x28(r1)
000c: stfd    f31,0x20(r1)
0010: stw     r31,0x1c(r1)
0014: stw     r30,0x18(r1)
0018: lwz     r0,lbl_804D6558@sda21(0)
001c: lfs     f31,lbl_804D82E0@sda21(0)
0020: cmplwi  r0,0
0024: beq-    a4
0028: lis     r3,lbl_80459278@ha
002c: addi r0 , r3 , lbl_80459278@l
0030: mr      r31,r0
0034: li      r30,0
0038: b       98
003c: lwz     r0,0(r31)
0040: cmpwi   r0,2
0044: beq-    74
0048: bge-    90
004c: cmpwi   r0,1
0050: bge-    58
0054: b       90
0058: lwz     r3,0xc(r31)
005c: lwz     r0,0x30(r3)
0060: cmplwi  r0,0xf
0064: bne-    90
0068: lfs     f0,0xc(r3)
006c: fadds   f31,f31,f0
0070: b       90
0074: lwz r3 , 0xc ( r31 )
0078: lwz r0 , 0x30 ( r3 )
007c: cmplwi  r0,0xf
0080: bne-    90
0084: lwz     r3,8(r31)
0088: bl      func_8026B1D4
008c: fadds   f31,f31,f1
0090: addi    r31,r31,0x28
0094: addi    r30,r30,1
0098: lwz     r0,lbl_804D6558@sda21(0)
009c: cmplw   r30,r0
00a0: blt+    3c
00a4: fmr     f1,f31
00a8: lwz     r0,0x2c(r1)
00ac: lfd     f31,0x20(r1)
00b0: lwz     r31,0x1c(r1)
00b4: lwz     r30,0x18(r1)
00b8: addi    r1,r1,0x28
00bc: mtlr    r0
00c0: blr
```

