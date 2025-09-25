# SeQuerySecurityDescriptorInfo function

## Description

The **SeQuerySecurityDescriptorInfo** routine retrieves a copy of an object's security descriptor.

## Parameters

### `SecurityInformation` [in]

Pointer to a [SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) value specifying which security information is being queried.

| Value | Meaning |
| --- | --- |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is being queried. Requires READ_CONTROL access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is being queried. Requires READ_CONTROL access. |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is being queried. Requires READ_CONTROL access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is being queried. Requires ACCESS_SYSTEM_SECURITY access. |

### `SecurityDescriptor` [out]

Caller-allocated user buffer that **SeQuerySecurityDescriptorInfo** fills with a copy of the specified security descriptor in self-relative format.

### `Length` [in, out]

Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by *SecurityDescriptor*. Upon return, **SeQuerySecurityDescriptorInfo** sets this variable to the number of bytes required to store the requested information.

### `ObjectsSecurityDescriptor` [in, out]

Pointer to a pointer to an object's security descriptor. The security descriptor must be in self-relative format.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call to **SeQuerySecurityDescriptorInfo** succeeded. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small for the security descriptor. None of the security information was copied to the buffer. |

## Remarks

A security descriptor can be in absolute or self-relative format. A security descriptor in absolute format contains pointers to the information it contains, rather than containing the information itself. A security descriptor in self-relative format contains the information in a contiguous block of memory. In a self-relative security descriptor, a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure always starts the information, but the security descriptor's other components can follow the SECURITY_DESCRIPTOR structure in any order. Instead of using memory addresses, the components of the security descriptor are identified by offsets from the beginning of the security descriptor. This format is useful when a security descriptor must be stored on a disk or transmitted by means of a communications protocol.

Because the security descriptor is returned in self-relative format, the caller of **SeQuerySecurityDescriptorInfo** should cast the value returned in the *SecurityDescriptor* parameter to type PISECURITY_DESCRIPTOR_RELATIVE.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlAbsoluteToSelfRelativeSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlabsolutetoselfrelativesd)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlCreateSecurityDescriptorRelative](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[RtlGetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetownersecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)