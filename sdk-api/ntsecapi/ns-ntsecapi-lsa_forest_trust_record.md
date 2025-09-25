# LSA_FOREST_TRUST_RECORD structure

## Description

The **LSA_FOREST_TRUST_RECORD** structure represents a [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust record.

## Members

### `Flags`

Flags that control the behavior of the operation.

### `ForestTrustType`

[LSA_FOREST_TRUST_RECORD_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-lsa_forest_trust_record_type) enumeration that indicates the type of the record. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **ForestTrustTopLevelName** | Record contains an included top-level name. |
| **ForestTrustTopLevelNameEx** | Record contains an excluded top-level name. |
| **ForestTrustDomainInfo** | Record contains an [LSA_FOREST_TRUST_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_domain_info) structure. |
| **ForestTrustRecordTypeLast** | Marks the end of an enumeration. |

### `Time`

Time stamp of the record.

### `ForestTrustData.TopLevelName.case`

### `ForestTrustData.TopLevelName.case.ForestTrustTopLevelName`

### `ForestTrustData.TopLevelName.case.ForestTrustTopLevelNameEx`

### `ForestTrustData.DomainInfo.case`

### `ForestTrustData.DomainInfo.case.ForestTrustDomainInfo`

### `ForestTrustData.Data.default`

### `ForestTrustData`

### `ForestTrustData.TopLevelName`

Top-level name. This member is used only if the **ForestTrustType** member is **ForestTrustTopLevelName** or **ForestTrustTopLevelNameEx**.

### `ForestTrustData.DomainInfo`

Domain information. This member is used only if the **ForestTrustType** member is **ForestTrustDomainInfo**.

### `ForestTrustData.Data`

Binary data. This member is used for unrecognized entries after ForestTrustRecordTypeLast.