#define NULL ((void*) 0)

// These should probably be in all files
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
#define UNK_T void*
typedef struct _Vec2 { float x, y; } Vec2;
typedef struct
{
 f32 x, y, z;
} Vec, *VecPtr, Point3d, *Point3dPtr;
typedef Vec Vec3;
struct RGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};
typedef struct
{
 f32 x, y, z, w;
} Quaternion, *QuaternionPtr, Qtrn, *QtrnPtr;
// End ALL files

typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];

typedef struct _S32Pair {
    s32 x, y;
} S32Pair;

typedef struct _HSD_SList {
    struct _HSD_SList* next;
    void* data;
} HSD_SList;
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
typedef struct _HSD_Obj {
    struct _HSD_Class parent;
    u16 ref_count;
    u16 ref_count_individual;
} HSD_Obj;
typedef struct _HSD_ImageDesc {
    void* img_ptr;
    u16 width;
    u16 height;
    u32 format;
    u32 mipmap;
    f32 minLOD;
    f32 maxLOD;
} HSD_ImageDesc;
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
typedef struct _GXColor {
    u8 r, g, b, a;
} GXColor;
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

typedef struct _HSD_AObj {
    u32 flags;
    f32 curr_frame;
    f32 rewind_frame;
    f32 end_frame;
    f32 framerate;
    HSD_FObj* fobj;
    struct _HSD_Obj* hsd_obj;
} HSD_AObj;

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
typedef struct _FtCollisionData
{
    u8 data_filler_0[0x28];
    u32 x28;
    u8 data_filler_2C[0x30 - 0x2C];
    s32 x30;
    s32 x34;
} FtCollisionData;
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
typedef struct _attr {
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
} attr;
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
typedef struct _FighterBone
{
            HSD_JObj* x0_jobj;
            HSD_JObj* x4_jobj2;
            UnkFlagStruct flags;
            u8 filler_x6[7];
} FighterBone;
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
typedef struct _Hitbox {
    s32 x0;
    s32 x4;
    s32 x8;
    f32 xC;
    u8 filler[0x128];
} Hitbox;
typedef struct _ftHit
{
    u8 filler_x0[0x134];
    s32 x134;
} ftHit;

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

typedef enum FighterKind {
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
    FTKIND_NONE,
    FTKIND_MAX = FTKIND_NONE
} FighterKind;

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

HSD_ObjAllocData fighter_alloc_data;

HSD_ObjAllocData Fighter_80458FFC;

void ft_800852B0(void);

void* lbArchive_80016C64(char*, void**, ...);

typedef struct ftCommonData ftCommonData;

ftCommonData* p_ftCommonData;

int** Fighter_804D6550 = NULL;
int** Fighter_804D6540 = NULL;
UNK_T Fighter_804D654C = NULL;
UNK_T Fighter_804D6548 = NULL;
typedef struct _FighterPartsTable {
    u8* joint_to_part;
    u8* part_to_joint;
    u32 parts_num;
} FighterPartsTable;
FighterPartsTable** ftPartsTable = NULL;
struct Fighter_804D653C_t {
    u32 unk;
    u8 unk4;
    u8 unk5;
};
struct Fighter_804D653C_t* Fighter_804D653C = NULL;
struct Fighter_804D653C_t* Fighter_804D6538 = NULL;
UNK_T Fighter_804D6534 = NULL;
Vec2** Fighter_804D6530 = NULL;
UNK_T Fighter_804D652C = NULL;
UNK_T Fighter_804D6528 = NULL;
float* Fighter_804D6524 = NULL;
UNK_T Fighter_804D6520 = NULL;
UNK_T Fighter_804D651C = NULL;
UNK_T Fighter_804D6518 = NULL;
UNK_T Fighter_804D6514 = NULL;
UNK_T Fighter_804D6510 = NULL;
int* Fighter_804D650C = NULL;
UNK_T Fighter_804D6508 = NULL;
HSD_Joint* Fighter_804D6504 = NULL;
UNK_T Fighter_804D6500 = NULL;
UNK_T Fighter_804D64FC = NULL;

void ft_8008549C(void);

#define UNK_RET void
#define UNK_PARAMS void
UNK_RET ftCo_8009F4A4(UNK_PARAMS);
void ftCo_800C8064(void);
void ftCo_800C8F6C(void);

HSD_ObjAllocData fighter_bones_alloc_data;
HSD_ObjAllocData Fighter_80459054;
HSD_ObjAllocData Fighter_80459080;
u32 Fighter_804D64F8 = 0;
#define g_spawnNumCounter Fighter_804D64F8

typedef void (*Event)(void);
extern Event ftData_Table_Unk1[FTKIND_MAX];

void Fighter_LoadCommonData(void)
{
    void** pData;
    lbArchive_80016C64("PlCo.dat", (void**) &pData, "ftLoadCommonData", 0);

    // copy 23 4-byte chunks from pData to p_ftCommonData in reverse order,
    // equivalent to this: for(i=0; i<23; i++)
    //   (&Fighter_804D64FC)[23-1-i] = pData[i];
    // loop unrolling doesn't work (only up to 8 elements)
    p_ftCommonData = pData[0]; // p_ftCommonData
    Fighter_804D6550 = pData[1];
    Fighter_804D654C = pData[2];
    Fighter_804D6548 = pData[3];
    ftPartsTable = pData[4];
    Fighter_804D6540 = pData[5];
    Fighter_804D653C = pData[6];
    Fighter_804D6538 = pData[7];
    Fighter_804D6534 = pData[8];
    Fighter_804D6530 = pData[9];
    Fighter_804D652C = pData[10];
    Fighter_804D6528 = pData[11];
    Fighter_804D6524 = pData[12];
    Fighter_804D6520 = pData[13];
    Fighter_804D651C = pData[14];
    Fighter_804D6518 = pData[15];
    Fighter_804D6514 = pData[16];
    Fighter_804D6510 = pData[17];
    Fighter_804D650C = pData[18];
    Fighter_804D6508 = pData[19];
    Fighter_804D6504 = pData[20];
    Fighter_804D6500 = pData[21];
    Fighter_804D64FC = pData[22];
}


#ifndef ATTRIBUTE_NORETURN
#if defined(__clang__) || defined(__GNUC__)
#define ATTRIBUTE_NORETURN __attribute__((noreturn))
#else
#define ATTRIBUTE_NORETURN
#endif
#endif
ATTRIBUTE_NORETURN void __assert(char*, u32, char*);

#ifndef BUGFIX
#define HSD_ASSERT(line, cond)                                                \
    ((cond) ? ((void) 0) : __assert(__FILE__, line, #cond))
#else
#define HSD_ASSERT(line, cond)                                                \
    ((cond) ? ((void) 0) : __assert(__FILE__, __LINE__, #cond))
#endif

#ifndef SECTION_INIT
#if defined(__MWERKS__) && !defined(M2CTX)
#define SECTION_INIT __declspec(section ".init")
#else
#define SECTION_INIT
#endif
#endif

SECTION_INIT void* memset(void* dst, int val, unsigned long n);

static HSD_ObjAllocData* alloc_datas;

void HSD_ObjAllocInit(struct _HSD_ObjAllocData *data, u32 size, u32 align);
void Fighter_800679B0(void)
{
    s32 i;

    /// @warning don't hardcode the allocation sizes
    HSD_ObjAllocInit(&fighter_alloc_data, sizeof(Fighter), /*align*/ 4);
    HSD_ObjAllocInit(&Fighter_80458FFC, /*size*/ 0x424, /*align*/ 4);
    ft_800852B0();
    Fighter_LoadCommonData();
    ft_8008549C();
    ftCo_8009F4A4();
    ftCo_800C8064();
    ftCo_800C8F6C();
    // @TODO: &fighter_alloc_data+2, +3, +4 are not defined in the fighter.s
    // data section, how does this work?
    HSD_ObjAllocInit(&fighter_bones_alloc_data, /*size*/ 0x8c0, /*align*/ 4);
    HSD_ObjAllocInit(&Fighter_80459054, /*size*/ 0x1f0, /*align*/ 4);
    HSD_ObjAllocInit(&Fighter_80459080, /*size*/ 0x80, /*align*/ 4);

    g_spawnNumCounter = 1;

    for (i = 0; i < FTKIND_MAX; i++) {
        if (ftData_Table_Unk1[i]) {
            ftData_Table_Unk1[i]();
        }
    }
}

inline void removeAll(HSD_ObjAllocData* data)
{
    HSD_ObjAllocData** cur = &alloc_datas;
    while (*cur != NULL) {
        if (*cur == data) {
            *cur = (*cur)->next;
        } else {
            cur = &(*cur)->next;
        }
    }
}

void HSD_ObjAllocInit(HSD_ObjAllocData* data, size_t size, u32 align)
{
    HSD_ASSERT(0x185, data);
    if (data != NULL) {
        removeAll(data);
    } else {
        alloc_datas = NULL;
    }
    memset(data, 0, sizeof(HSD_ObjAllocData));
    data->num_limit = -1;
    data->heap_limit_size = 0;
    data->heap_limit_num = -1;
    data->align = align - 1;
    data->size = (size + data->align) & ~data->align;
    data->next = alloc_datas;
    alloc_datas = data;
}
