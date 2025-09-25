# LSA_FOREST_TRUST_COLLISION_RECORD_TYPE enumeration

## Description

The **LSA_FOREST_TRUST_COLLISION_RECORD_TYPE** enumeration defines the types of collision that can occur between [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust records.

## Constants

### `CollisionTdo`

Collision between [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) objects. This indicates a collision with a namespace element of another forest.

### `CollisionXref`

Collision between cross-references. This indicates a collision with a domain in the same forest.

### `CollisionOther`

Collision that is not a collision between [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) objects or cross-references.

## Remarks

This enumeration is used by the [LSA_FOREST_TRUST_COLLISION_RECORD](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_collision_record) structure.