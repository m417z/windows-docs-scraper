# LsaSetInformationPolicy function

## Description

The **LsaSetInformationPolicy** function modifies information in a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The required access rights for this handle depend on the value of the *InformationClass* parameter. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `InformationClass` [in]

Specifies one of the following values from the
[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class) enumeration type. The value indicates the type of information to set.

| Value | Meaning |
| --- | --- |
| **PolicyAuditEventsInformation** | Sets the system's auditing rules. The handle passed in the *PolicyHandle* parameter must have the POLICY_SET_AUDIT_REQUIREMENTS access right. The *Buffer* parameter must be a pointer to a [POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info) structure. |
| **PolicyPrimaryDomainInformation** | Sets the name and SID of the system's primary domain. The handle passed in the *PolicyHandle* parameter must have the POLICY_TRUST_ADMIN access right. The *Buffer* parameter must be a pointer to a [POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info) structure. |
| **PolicyAccountDomainInformation** | Sets the name and SID of the system's account domain. The handle passed in the *PolicyHandle* parameter must have the POLICY_TRUST_ADMIN access right. The *Buffer* parameter must be a pointer to a [POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info) structure. |
| **PolicyDnsDomainInformation** | Sets Domain Name System (DNS) information about the primary domain associated with the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle passed in the *PolicyHandle* parameter must have the POLICY_TRUST_ADMIN access right. The *Buffer* parameter must be a pointer to a [POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info) structure. |
| **PolicyLsaServerRoleInformation** | Sets the role of an LSA server. The handle passed in the *PolicyHandle* parameter must have the POLICY_SERVER_ADMIN access right. The *Buffer* parameter must be a pointer to a [POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info) structure.<br><br>Changing a server's role from primary to backup has no effect (although the function returns STATUS_SUCCESS). Changing a server's role from backup to primary requires extensive network operations and may be slow. |

### `Buffer` [in]

Pointer to a structure containing the information to set. The type of structure depends on the value of the *InformationClass* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info)

[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info)

[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info)

[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info)

[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info)