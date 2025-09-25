# LSA_FOREST_TRUST_INFORMATION structure

## Description

The **LSA_FOREST_TRUST_INFORMATION** structure contains [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust information.

## Members

### `RecordCount.range`

### `RecordCount.range.0`

### `RecordCount.range.MAX_RECORDS_IN_FOREST_TRUST_INFO`

### `Entries.size_is`

### `Entries.size_is.RecordCount`

### `RecordCount`

Number of [LSA_FOREST_TRUST_RECORD](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_record) structures in the array pointed to by the **Entries** member.

### `Entries`

Pointer to a pointer to an array of [LSA_FOREST_TRUST_RECORD](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_record) structures, each of which contains one piece of forest trust information.