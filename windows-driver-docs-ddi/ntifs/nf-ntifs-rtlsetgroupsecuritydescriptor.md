# RtlSetGroupSecurityDescriptor function

## Description

The **RtlSetGroupSecurityDescriptor** routine sets the primary group information of an absolute-format security descriptor. It replaces any primary group information that is already present in the security descriptor.

## Parameters

### `SecurityDescriptor` [in, out]

Pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure whose primary group is to be set. **RtlSetGroupSecurityDescriptor** replaces any existing primary group with the new primary group.

### `Group` [in, optional]

Pointer to a security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) structure for the security descriptor's new primary owner. This pointer, not the SID structure itself, is copied into the security descriptor. If *Group* is **NULL**, **RtlSetGroupSecurityDescriptor** clears the security descriptor's primary group information. This marks the security descriptor as having no primary group.

### `GroupDefaulted` [in, optional]

Set this Boolean variable to **TRUE** if the primary group information is derived from a default mechanism. If this parameter is **TRUE**, **RtlSetGroupSecurityDescriptor** sets the SE_GROUP_DEFAULTED flag in the security descriptor's SECURITY_DESCRIPTOR_CONTROL field. If this parameter is **FALSE**, **RtlSetGroupSecurityDescriptor** clears the SE_GROUP_DEFAULTED flag.

## Return value

**RtlSetGroupSecurityDescriptor** returns STATUS_SUCCESS if the primary group was successfully set or reset. Otherwise, it returns an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_SECURITY_DESCR** | The given security descriptor is not a valid absolute security descriptor. STATUS_INVALID_SECURITY_DESCR is an error code. |
| **STATUS_UNKNOWN_REVISION** | The given security descriptor's revision is not recognized by this routine. STATUS_UNKNOWN_REVISION is an error code. |

## Remarks

To retrieve the primary group information for a security descriptor, use [RtlGetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetgroupsecuritydescriptor).

To set the owner information for a security descriptor, use [RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor).

For more information about security and access control, see the Microsoft Windows SDK documentation.

## See also

[RtlGetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetgroupsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)