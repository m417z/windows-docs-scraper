# _SYSTEM_RESOURCE_ATTRIBUTE_ACE structure

## Description

The SYSTEM_RESOURCE_ATTRIBUTE_ACE structure defines an access-control entry (ACE) for the system access-control list (ACL) specifying what rights a particular claim has to a resource. A resource attribute ACE causes an audit message to be logged when an attempt to gain access to resource based on a supported claim occurs.

## Members

### `Header`

Specifies an ACE_HEADER structure.

### `Mask`

Specifies an ACCESS_MASK structure that specifies access rights for a claim to a resource.

### `SidStart`

Specifies a SID. This is set to the Everyone, or S-1-1-0, SID.

## Remarks

Following the **SidStart** member begins a **CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1** structure which describes a supported claim.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_ace_header)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)