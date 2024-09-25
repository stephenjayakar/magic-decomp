.fn Fighter_LoadCommonData, global
mflr r0
lis r3, "@235"@ha
stw r0, 0x4(r1)
lis r4, "@236"@ha
crclr cr1eq
addi r3, r3, "@235"@l
stwu r1, -0x10(r1)
addi r5, r4, "@236"@l
addi r4, r1, 0x8
li r6, 0x0
bl lbArchive_80016C64
lwz r3, 0x8(r1)
lwz r0, 0x0(r3)
stw r0, p_ftCommonData@sda21(r0)
lwz r0, 0x4(r3)
stw r0, Fighter_804D6550@sda21(r0)
lwz r0, 0x8(r3)
stw r0, Fighter_804D654C@sda21(r0)
lwz r0, 0xc(r3)
stw r0, Fighter_804D6548@sda21(r0)
lwz r0, 0x10(r3)
stw r0, ftPartsTable@sda21(r0)
lwz r0, 0x14(r3)
stw r0, Fighter_804D6540@sda21(r0)
lwz r0, 0x18(r3)
stw r0, Fighter_804D653C@sda21(r0)
lwz r0, 0x1c(r3)
stw r0, Fighter_804D6538@sda21(r0)
lwz r0, 0x20(r3)
stw r0, Fighter_804D6534@sda21(r0)
lwz r0, 0x24(r3)
stw r0, Fighter_804D6530@sda21(r0)
lwz r0, 0x28(r3)
stw r0, Fighter_804D652C@sda21(r0)
lwz r0, 0x2c(r3)
stw r0, Fighter_804D6528@sda21(r0)
lwz r0, 0x30(r3)
stw r0, Fighter_804D6524@sda21(r0)
lwz r0, 0x34(r3)
stw r0, Fighter_804D6520@sda21(r0)
lwz r0, 0x38(r3)
stw r0, Fighter_804D651C@sda21(r0)
lwz r0, 0x3c(r3)
stw r0, Fighter_804D6518@sda21(r0)
lwz r0, 0x40(r3)
stw r0, Fighter_804D6514@sda21(r0)
lwz r0, 0x44(r3)
stw r0, Fighter_804D6510@sda21(r0)
lwz r0, 0x48(r3)
stw r0, Fighter_804D650C@sda21(r0)
lwz r0, 0x4c(r3)
stw r0, Fighter_804D6508@sda21(r0)
lwz r0, 0x50(r3)
stw r0, Fighter_804D6504@sda21(r0)
lwz r0, 0x54(r3)
stw r0, Fighter_804D6500@sda21(r0)
lwz r0, 0x58(r3)
stw r0, Fighter_804D64FC@sda21(r0)
lwz r0, 0x14(r1)
addi r1, r1, 0x10
mtlr r0
blr
.endfn Fighter_LoadCommonData
