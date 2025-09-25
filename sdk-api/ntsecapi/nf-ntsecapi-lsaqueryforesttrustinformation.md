# LsaQueryForestTrustInformation function

## Description

The **LsaQueryForestTrustInformation** function retrieves forest trust information
for the specified [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object for the system.

### `TrustedDomainName` [in]

Pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object for which to retrieve forest trust information.

### `ForestTrustInfo` [out]

Pointer to an [LSA_FOREST_TRUST_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_forest_trust_information) structure that returns the forest trust information for the [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object specified by the *TrustedDomainName* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the [LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code/value | Description |
| --- | --- |
| **STATUS_INVALID_DOMAIN_ROLE** | The operation is legal only on the primary domain controller. |
| **STATUS_INVALID_DOMAIN_STATE** | The operation is legal only on domain controllers in the root domain. |
| **STATUS_NO_SUCH_DOMAIN** | The specified [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object does not exist. |
| **STATUS_NOT_FOUND** | The specified [TrustedDomain](https://learn.microsoft.com/windows/desktop/SecMgmt/trusteddomain-object) object does not contain forest trust information. |

## Remarks

Access to this function is protected by a securable object.