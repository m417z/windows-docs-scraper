# RtlSelfRelativeToAbsoluteSD function

## Description

The **RtlSelfRelativeToAbsoluteSD** routine creates a new security descriptor in absolute format by using a security descriptor in self-relative format as a template.

## Parameters

### `SelfRelativeSecurityDescriptor` [in]

Pointer to a caller-allocated buffer that contains a SECURITY_DESCRIPTOR structure in self-relative format. **RtlSelfRelativeToAbsoluteSD** creates a version of this security descriptor in absolute format without modifying the original.

### `AbsoluteSecurityDescriptor` [out]

Pointer to a caller-allocated buffer that receives the main body of an absolute-format security descriptor. This information is formatted as a SECURITY_DESCRIPTOR structure.

### `AbsoluteSecurityDescriptorSize` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *AbsoluteSecurityDescriptor* parameter. If the buffer is not large enough to hold the security descriptor, **RtlSelfRelativeToAbsoluteSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

### `Dacl` [out]

Pointer to a caller-allocated buffer that receives the DACL of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `DaclSize` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *Dacl* parameter. If the buffer is not large enough to hold the DACL, **RtlSelfRelativeToAbsoluteSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

### `Sacl` [out]

Pointer to a caller-allocated buffer that receives the SACL of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `SaclSize` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *Sacl* parameter. If the buffer is not large enough to hold the SACL, **RtlSelfRelativeToAbsoluteSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

### `Owner` [out]

Pointer to a caller-allocated buffer that receives the SID of the owner of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `OwnerSize` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *Owner* parameter. If the buffer is not large enough to hold the SID, **RtlSelfRelativeToAbsoluteSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

### `PrimaryGroup` [out]

Pointer to a caller-allocated buffer that receives the SID of the primary group of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `PrimaryGroupSize` [in, out]

Pointer to a caller-allocated variable that specifies the size, in bytes, of the buffer pointed to by the *PrimaryGroup* parameter. If the buffer is not large enough to hold the SID, **RtlSelfRelativeToAbsoluteSD** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the minimum required size.

## Return value

**RtlSelfRelativeToAbsoluteSD** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BAD_DESCRIPTOR_FORMAT** | The buffer pointed to by the *AbsoluteSecurityDescriptor* parameter did not contain a SECURITY_DESCRIPTOR structure in absolute format. STATUS_BAD_DESCRIPTOR_FORMAT is an error code. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer pointed to by the *AbsoluteSecurityDescriptor* , *Dacl*, *Sacl*, *Owner*, or *PrimaryGroup* parameter was too small. STATUS_BUFFER_TOO_SMALL is an error code. |

## Remarks

A security descriptor in absolute format contains pointers to the information, rather than containing the information itself. A security descriptor in self-relative format contains the information in a contiguous block of memory. In a self-relative security descriptor, a SECURITY_DESCRIPTOR structure always starts the information, but the security descriptor's other components can follow the SECURITY_DESCRIPTOR structure in any order. Instead of using memory addresses, the components of the security descriptor are identified by offsets from the beginning of the security descriptor. This format is useful when a security descriptor must be stored on a floppy disk or transmitted by means of a communications protocol.

Note that the *AbsoluteSecurityDescriptor* parameter receives only the main body of the absolute security descriptor. The entire absolute security descriptor consists of this main body, plus all of the security descriptor components returned in the *Dacl*, *Sacl*, *Owner*, and *PrimaryGroup* buffers. Thus, the caller cannot free these buffers after calling **RtlSelfRelativeToAbsoluteSD**, because doing so would invalidate the absolute security descriptor.

To create a new security descriptor in self-relative format by using a security descriptor in absolute format as a template, use [RtlAbsoluteToSelfRelativeSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlabsolutetoselfrelativesd).

For more information about security and access control, see the Microsoft Windows SDK documentation.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlAbsoluteToSelfRelativeSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlabsolutetoselfrelativesd)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)