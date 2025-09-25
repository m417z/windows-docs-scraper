# LsaQueryDomainInformationPolicy function

## Description

The **LsaQueryDomainInformationPolicy** function retrieves domain information from the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object for the system.

### `InformationClass` [in]

[POLICY_DOMAIN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_domain_information_class) enumeration that specifies the information to be returned from the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **PolicyDomainEfsInformation** | The information is for [Encrypting File System](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). |
| **PolicyDomainKerberosTicketInformation** | The information is for a Kerberos ticket. |

### `Buffer` [out]

Pointer to a buffer that receives the requested information.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be the following value or one of the [LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code/value | Description |
| --- | --- |
| **STATUS_INTERNAL_DB_CORRUPTION** | The policy database is corrupt. The returned policy information is not valid for the given class. |

## Remarks

The POLICY_VIEW_LOCAL_INFORMATION access type is required to retrieve domain information from the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. For more information, see [Policy Object Access Rights](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object-access-rights).