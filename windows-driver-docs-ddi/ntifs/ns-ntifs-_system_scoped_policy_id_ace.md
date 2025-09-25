# _SYSTEM_SCOPED_POLICY_ID_ACE structure

## Description

The SYSTEM_SCOPED_POLICY_ID_ACE structure defines an access-control entry (ACE) for the system access-control list (ACL) specifying rights for a scoped policy identifier. This ACE causes an audit message to be logged when an attempt to gain access to an object based on a configured policy scope.

## Members

### `Header`

Specifies an ACE_HEADER structure.

### `Mask`

Specifies an ACCESS_MASK structure that specifies access rights for the scoped policy identifier.

### `SidStart`

Specifies a SID. The SID represents a scoped policy configured to control access to an object or group of objects.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_ace_header)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)