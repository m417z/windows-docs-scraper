# RtlGetGroupSecurityDescriptor function

## Description

The **RtlGetGroupSecurityDescriptor** routine returns the primary group information for a given security descriptor.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the security descriptor whose primary group information is to be returned.

### `Group` [out]

Pointer to a variable that receives a pointer to the security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) for the primary group. If the security descriptor does not contain a primary group, **Group* receives **NULL**.

### `GroupDefaulted` [out]

Pointer to a Boolean variable that receives the value of the SE_GROUP_DEFAULTED flag in the security descriptor's SECURITY_DESCRIPTOR_CONTROL structure. This value is valid only if **Group* receives a non-**NULL** value.

## Return value

**RtlGetGroupSecurityDescriptor** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_UNKNOWN_REVISION** | The security descriptor's revision level is not known or is not supported. This is an error code. |

## Remarks

If the security descriptor pointed to by *SecurityDescriptor* contains a primary group, **RtlGetGroupSecurityDescriptor** sets the pointer pointed to by *Group* to the address of the security descriptor's group SID and sets the variable pointed to by *GroupDefaulted* to a valid value.

If the security descriptor pointed to by *SecurityDescriptor* does not contain a primary group, **RtlGetGroupSecurityDescriptor** sets the pointer pointed to by *Group* to **NULL** and ignores the remaining output parameter, *GroupDefaulted*.

To set the primary group information for a security descriptor, use [RtlSetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetgroupsecuritydescriptor).

To retrieve the owner information for a security descriptor, use [RtlGetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetownersecuritydescriptor).

For more information about security and access control, see the Microsoft Windows SDK documentation.

## See also

[RtlGetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetownersecuritydescriptor)

[RtlSetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetgroupsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)