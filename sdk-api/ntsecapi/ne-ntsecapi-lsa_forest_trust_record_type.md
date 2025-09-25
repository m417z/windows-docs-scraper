# LSA_FOREST_TRUST_RECORD_TYPE enumeration

## Description

The **LSA_FOREST_TRUST_RECORD_TYPE** enumeration defines the type of a [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust record.

## Constants

### `ForestTrustTopLevelName`

Record contains an included top-level name.

### `ForestTrustTopLevelNameEx`

Record contains an excluded top-level name.

### `ForestTrustDomainInfo`

Record contains an [LSA_FOREST_TRUST_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_domain_info) structure.

### `ForestTrustRecordTypeLast`

Marks the end of an enumeration.

## Remarks

This enumeration is used by the [LSA_FOREST_TRUST_RECORD](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_record) structure.