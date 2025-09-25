# POLICY_AUDIT_EVENT_TYPE enumeration

## Description

The **POLICY_AUDIT_EVENT_TYPE** enumeration defines values that indicate the types of events the system can audit. The
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) and
[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) functions use this enumeration when their *InformationClass* parameters are set to PolicyAuditEventsInformation.

## Constants

### `AuditCategorySystem:0`

Determines whether the operating system must audit any of the following attempts:

* Attempted system time change.
* Attempted security system startup, restart, or shutdown.
* Attempt to load extensible authentication features.
* Loss of audited events due to auditing system failure.
* Security log size that exceeds a configurable warning threshold level.

### `AuditCategoryLogon`

Determines whether the operating system must audit each time this computer validates the credentials of an account. Account logon events are generated whenever a computer validates the credentials of one of its local accounts. The credential validation can be in support of a local logon or, in the case of an Active Directory domain account on a domain controller, can be in support of a logon to another computer. Audited events for local accounts must be logged on the local security log of the computer. Account logoff does not generate an event that can be audited.

### `AuditCategoryObjectAccess`

Determines whether the operating system must audit each instance of user attempts to access a non-Active Directory object, such as a file, that has its own system access control list (SACL) specified. The type of access request, such as Write, Read, or Modify, and the account that is making the request must match the settings in the SACL.

### `AuditCategoryPrivilegeUse`

Determines whether the operating system must audit each instance of user attempts to use [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `AuditCategoryDetailedTracking`

Determines whether the operating system must audit specific events, such as program activation, some forms of handle duplication, indirect access to an object, and process exit.

### `AuditCategoryPolicyChange`

Determines whether the operating system must audit attempts to change [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/the-policy-object-type) object rules, such as user rights assignment policy, audit policy, account policy, or trust policy.

### `AuditCategoryAccountManagement`

Determines whether the operating system must audit attempts to create, delete, or change user or group accounts. Also, audit password changes.

### `AuditCategoryDirectoryServiceAccess`

Determines whether the operating system must audit attempts to access the directory service. The Active Directory object has its own SACL specified. The type of access request, such as Write, Read, or Modify, and the account that is making the request must match the settings in the SACL.

### `AuditCategoryAccountLogon`

Determines whether the operating system must audit each instance of a user attempt to log on or log off this computer. Also audits logon attempts by privileged accounts that log on to the domain controller. These audit events are generated when the Kerberos [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KDC) logs on to the domain controller. Logoff attempts are generated whenever the logon session of a logged-on user account is terminated.

## Remarks

The **POLICY_AUDIT_EVENT_TYPE** enumeration may expand in future versions of Windows. Because of this, you should not compute the number of values in this enumeration directly. Instead, you should obtain the count of values by calling
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) with the *InformationClass* parameter set to PolicyAuditEventsInformation and extract the count from the **MaximumAuditEventCount** member of the returned
[POLICY_AUDIT_EVENTS_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_events_info) structure.

## See also

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)