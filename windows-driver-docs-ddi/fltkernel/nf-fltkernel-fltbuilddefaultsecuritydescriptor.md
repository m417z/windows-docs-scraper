# FltBuildDefaultSecurityDescriptor function

## Description

**FltBuildDefaultSecurityDescriptor** builds a default security descriptor for use with [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport).

## Parameters

### `SecurityDescriptor` [out]

Pointer to a caller-allocated variable that receives an opaque pointer to the newly created [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor).

### `DesiredAccess` [in]

Bitmask of flags that specify the type of access that the caller requires to the port object. The set of system-defined *DesiredAccess* flags determines the following specific access rights for minifilter driver communication port objects.

| DesiredAccess Flags | Meaning |
| --- | --- |
| FLT_PORT_CONNECT | The caller can connect to the port. |
| FLT_PORT_ALL_ACCESS | FLT_PORT_CONNECT \| STANDARD_RIGHTS_ALL |

## Return value

**FltBuildDefaultSecurityDescriptor** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltBuildDefaultSecurityDescriptor** encountered a pool allocation failure. This is an error code. |

## Remarks

When creating a minifilter driver communication port, a minifilter driver can call **FltBuildDefaultSecurityDescriptor** to create a default security descriptor for the port. The minifilter driver then creates the port by calling [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) and [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport). The security descriptor is passed as a parameter to **InitializeObjectAttributes**.

**FltBuildDefaultSecurityDescriptor** causes the system to allocate a default security descriptor from paged pool. When this security descriptor is applied to an object, only users with system or administrator privileges have access to the object.

Minifilter drivers usually call **FltBuildDefaultSecurityDescriptor** immediately before calling [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport) and [FltFreeSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreesecuritydescriptor) immediately after calling **FltCreateCommunicationPort**.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltFreeSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreesecuritydescriptor)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlCreateSecurityDescriptorRelative](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)