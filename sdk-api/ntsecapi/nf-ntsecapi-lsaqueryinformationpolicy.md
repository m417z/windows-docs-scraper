# LsaQueryInformationPolicy function

## Description

The **LsaQueryInformationPolicy** function retrieves information about a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The required access rights for this handle depend on the value of the *InformationClass* parameter. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `InformationClass` [in]

Specifies one of the following values from the
[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class) enumeration type. The value indicates the type of information to retrieve.

| Value | Meaning |
| --- | --- |
| **PolicyAuditEventsInformation** | Retrieves the system's auditing rules. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_AUDIT_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info) structure. |
| **PolicyPrimaryDomainInformation** | Retrieves the name and SID of the system's primary domain. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_LOCAL_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info) structure. |
| **PolicyAccountDomainInformation** | Retrieves the name and SID of the system's account domain. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_LOCAL_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info) structure. |
| **PolicyLsaServerRoleInformation** | Retrieves the role of an LSA server. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_LOCAL_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info) structure. |
| **PolicyModificationInformation** | Retrieves information about the creation time and last modification of the LSA database. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_LOCAL_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_MODIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_modification_info) structure. |
| **PolicyDnsDomainInformation** | Retrieves the Domain Name System (DNS) information about the primary domain associated with the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle passed in the *PolicyHandle* parameter must have the POLICY_VIEW_LOCAL_INFORMATION access right. The *Buffer* parameter receives a pointer to a [POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info) structure. |

### `Buffer` [out]

Pointer to a variable that receives a pointer to a structure containing the requested information. The type of structure depends on the value of the *InformationClass* parameter.

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

## Return value

If the **LsaQueryInformationPolicy** function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

For an example that demonstrates calling this function see
[Managing Policy Information](https://learn.microsoft.com/windows/desktop/SecMgmt/managing-policy-information).

## See also

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info)

[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info)

[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)

[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info)

[POLICY_MODIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_modification_info)

[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info)