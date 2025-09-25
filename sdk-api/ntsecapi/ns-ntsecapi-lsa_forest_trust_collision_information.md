# LSA_FOREST_TRUST_COLLISION_INFORMATION structure

## Description

The **LSA_FOREST_TRUST_COLLISION_INFORMATION** structure contains information about [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust collisions.

## Members

### `RecordCount`

Number of [LSA_FOREST_TRUST_COLLISION_RECORD](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_collision_record) structures in the array pointed to by the **Entries** member.

### `Entries`

Pointer to a pointer to an array of [LSA_FOREST_TRUST_COLLISION_RECORD](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_collision_record) structures, each of which contains information about a single collision.

### `Entries.size_is`

### `Entries.size_is.RecordCount`