# RtlAbsoluteToSelfRelativeSD function

## Description

The **RtlAbsoluteToSelfRelativeSD** routine creates a new security descriptor in self-relative format by using a security descriptor in absolute format as a template.

## Parameters

### `AbsoluteSecurityDescriptor` [in]

Pointer to a caller-allocated buffer that contains a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure in absolute format. **RtlAbsoluteToSelfRelativeSD** creates a version of this security descriptor in self-relative format without modifying the original.

### `SelfRelativeSecurityDescriptor` [out]

Pointer to a caller-allocated buffer that receives a security descriptor in self-relative format.

### `BufferLength` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *SelfRelativeSecurityDescriptor* parameter. If the buffer is not large enough to hold the security descriptor, **RtlAbsoluteToSelfRelativeSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

## Return value

**RtlAbsoluteToSelfRelativeSD** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BAD_DESCRIPTOR_FORMAT** | The buffer pointed to by the *AbsoluteSecurityDescriptor* parameter did not contain a SECURITY_DESCRIPTOR structure in absolute format. STATUS_BAD_DESCRIPTOR_FORMAT is an error code. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer pointed to by the *SelfRelativeSecurityDescriptor* parameter was too small to contain the security descriptor in self-relative format. STATUS_BUFFER_TOO_SMALL is an error code. |

## Remarks

A security descriptor in absolute format contains pointers to the information it contains, rather than containing the information itself. A security descriptor in self-relative format contains the information in a contiguous block of memory. In a self-relative security descriptor, a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure always starts the information, but the security descriptor's other components can follow the SECURITY_DESCRIPTOR structure in any order. Instead of using memory addresses, the components of the security descriptor are identified by offsets from the beginning of the security descriptor. This format is useful when a security descriptor must be stored on a disk or transmitted by means of a communications protocol.

To create a new security descriptor in absolute format by using a security descriptor in self-relative format as a template, use [RtlSelfRelativeToAbsoluteSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlselfrelativetoabsolutesd).

For more information about security and access control, see the Microsoft Windows SDK documentation.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSelfRelativeToAbsoluteSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlselfrelativetoabsolutesd)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)