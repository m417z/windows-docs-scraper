# _ACCESS_DENIED_ACE structure

## Description

The ACCESS_DENIED_ACE structure defines an access-control entry ([ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)) for the discretionary access-control list (DACL) controlling access to an object. An access-denied ACE denies access to an object for a specific subject identified by a security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)).

## Members

### `Header`

Specifies an ACE_HEADER structure.

### `Mask`

ACCESS_MASK structure specifying the access rights explicitly denied by this ACE.

### `SidStart`

Specifies a SID. The access rights specified by the **Mask** member are denied to any subject possessing an enabled SID matching this member.

## Remarks

This structure must be aligned on a 32-bit boundary.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_ace_header)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_alarm_ace)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_audit_ace)