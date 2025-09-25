# LSA_FOREST_TRUST_COLLISION_RECORD structure

## Description

The **LSA_FOREST_TRUST_COLLISION_RECORD** structure contains information about a [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust collision.

## Members

### `Index`

Index of this collision record in the array of **LSA_FOREST_TRUST_COLLISION_RECORD** structures pointed to by the **Entries** member of the [LSA_FOREST_TRUST_COLLISION_INFORMATION](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_collision_information) structure.

### `Type`

Type of the collision. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **CollisionTdo** | Collision between [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) objects. |
| **CollisionXref** | Collision between cross-references. |
| **CollisionOther** | Collision that is not a collision between [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) objects or cross-references. |

### `Flags`

Flags that provide more information about the collision. The following table lists the possible values for this member when the **Type** member is CollisionTdo.

#### LSA_TLN_DISABLED_NEW (0x00000001)

#### LSA_TLN_DISABLED_ADMIN (0x00000002)

#### LSA_TLN_DISABLED_CONFLICT (0x00000004)

The following table lists the possible values for this member when the **Type** member is CollisionXref.

#### LSA_SID_DISABLED_ADMIN (0x00000001)

#### LSA_SID_DISABLED_CONFLICT (0x00000002)

#### LSA_NB_DISABLED_ADMIN (0x00000004)

#### LSA_NB_DISABLED_CONFLICT (0x00000008)

### `Name`

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the collision record.