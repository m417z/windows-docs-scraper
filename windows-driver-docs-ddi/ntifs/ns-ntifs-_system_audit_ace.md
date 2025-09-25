# _SYSTEM_AUDIT_ACE structure

## Description

The SYSTEM_AUDIT_ACE structure defines an access-control entry (ACE) for the system access-control list (ACL) specifying what types of access cause system-level notifications. A system-audit ACE causes an audit message to be logged when a specified user or group attempts to gain access to an object. The user or group is identified by a security identifier (SID).

## Members

### `Header`

Specifies an ACE_HEADER structure.

### `Mask`

Specifies an ACCESS_MASK structure that gives the access rights causing audit messages to be generated. The SUCCESSFUL_ACCESS_ACE_FLAG and FAILED_ACCESS_ACE_FLAG flags in the **AceFlags** member of the ACE_HEADER structure indicate whether messages are generated for successful access attempts, unsuccessful access attempts, or both.

### `SidStart`

Specifies a SID. An access attempt of a kind specified by the **Mask** member by any user or group whose SID matches the **SidStart** member causes the system to generate an audit message. If an application does not specify a SID for this member, audit messages are generated for the specified access rights for all users and groups.

## Remarks

Audit messages are stored in an event log that can be manipulated by using the Microsoft Win32 event-logging functions or by using the Event Viewer (EVENTVWR.EXE).

This structure must be aligned on a 32-bit boundary.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_denied_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_ace_header)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_alarm_ace)