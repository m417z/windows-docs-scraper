# LsaSetForestTrustInformation function

## Description

The **LsaSetForestTrustInformation** function sets the forest trust information for a specified [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object for the system.

### `TrustedDomainName` [in]

Pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object to which to set the forest trust information specified by the *ForestTrustInfo* parameter.

### `ForestTrustInfo` [in]

Pointer to an [LSA_FOREST_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_information) structure that contains the forest trust information to set to the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object specified by the *TrustedDomainName* parameter.

### `CheckOnly` [in]

Boolean value that specifies whether changes to the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object are persisted. If this value is **TRUE**, this function will check for collisions with the specified parameters but will not set the forest trust information specified by the *ForestTrustInfo* parameter to the **TrustedDomain** object specified by the *TrustedDomainName* parameter. If this value is **FALSE**, the forest trust information will be set to the **TrustedDomain** object.

### `CollisionInfo` [out]

Pointer to a pointer to an [LSA_FOREST_TRUST_COLLISION_INFORMATION](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_collision_information) structure that returns information about any collisions that occurred.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the [LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code/value | Description |
| --- | --- |
| **STATUS_INVALID_DOMAIN_STATE** | The operation is legal only on domain controllers in the root domain. |
| **STATUS_INVALID_DOMAIN_ROLE** | The operation is legal only on the primary domain controller. |