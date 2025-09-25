# POLICY_INFORMATION_CLASS enumeration

## Description

The **POLICY_INFORMATION_CLASS** enumeration defines values that indicate the type of information to set or query in a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

## Constants

### `PolicyAuditLogInformation:1`

This value is obsolete.

### `PolicyAuditEventsInformation`

Query or set the auditing rules of the system. You can enable or disable auditing and specify the types of events that are audited. Use the
[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info) structure.

### `PolicyPrimaryDomainInformation`

This value is obsolete. Use the **PolicyDnsDomainInformation** value instead.

### `PolicyPdAccountInformation`

This value is obsolete.

### `PolicyAccountDomainInformation`

Query or set the name and SID of the account domain of the system. Use the
[POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info) structure.

### `PolicyLsaServerRoleInformation`

Query or set the role of an LSA server. Use the
[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info) structure.

### `PolicyReplicaSourceInformation`

This value is obsolete.

### `PolicyDefaultQuotaInformation`

This value is obsolete.

### `PolicyModificationInformation`

Query or set information about the creation time and last modification of the LSA database. Use the
[POLICY_MODIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_modification_info) structure.

### `PolicyAuditFullSetInformation`

This value is obsolete.

### `PolicyAuditFullQueryInformation`

This value is obsolete.

### `PolicyDnsDomainInformation`

Query or set Domain Name System (DNS) information about the account domain associated with a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. Use the
[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info) structure.

### `PolicyDnsDomainInformationInt`

### `PolicyLocalAccountDomainInformation`

### `PolicyMachineAccountInformation`

### `PolicyLastEntry`

## See also

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_ACCOUNT_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_account_domain_info)

[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info)

[POLICY_DNS_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-policy_dns_domain_info)

[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info)

[POLICY_MODIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_modification_info)

[POLICY_PRIMARY_DOMAIN_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_primary_domain_info)