# POLICY_NOTIFICATION_INFORMATION_CLASS enumeration

## Description

The **POLICY_NOTIFICATION_INFORMATION_CLASS** enumeration defines the types of policy information and policy domain information for which your application can request notification of changes.

## Constants

### `PolicyNotifyAuditEventsInformation:1`

Notify when any of the audited categories are changed.

### `PolicyNotifyAccountDomainInformation`

Notify when the account domain information changes.

### `PolicyNotifyServerRoleInformation`

Notify when the LSA server changes its role from primary to backup, or vice versa.

### `PolicyNotifyDnsDomainInformation`

Notify when the DNS domain information changes or if the primary domain information changes.

### `PolicyNotifyDomainEfsInformation`

Notify when the Encrypting File System (EFS) domain information changes.

### `PolicyNotifyDomainKerberosTicketInformation`

Notify when the Kerberos ticket for the domain changes.

### `PolicyNotifyMachineAccountPasswordInformation`

Notify when the machine account password changes.

### `PolicyNotifyGlobalSaclInformation`

### `PolicyNotifyMax`

## See also

[LsaRegisterPolicyChangeNotification](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterpolicychangenotification)

[LsaUnregisterPolicyChangeNotification](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaunregisterpolicychangenotification)