# NtQuerySecurityObject function

## Description

The **NtQuerySecurityObject** routine retrieves a copy of an object's security descriptor.

## Parameters

### `Handle` [in]

Handle for the object whose security descriptor is to be queried. This handle must have the access specified in the Meaning column of the table shown in the description of the **SecurityInformation** parameter.

### `SecurityInformation` [in]

A [**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) value specifying the information to be queried as a combination of one or more of the following.

| Value | Meaning |
| ----- | ------- |
| OWNER_SECURITY_INFORMATION | The object's owner identifier is being queried. Requires READ_CONTROL access. |
| GROUP_SECURITY_INFORMATION | The object's primary group identifier is being queried. Requires READ_CONTROL access. |
| SACL_SECURITY_INFORMATION | The object's system ACL (SACL) is being queried. Requires ACCESS_SYSTEM_SECURITY access. |
| DACL_SECURITY_INFORMATION | The object's discretionary access control list (DACL) is being queried. Requires READ_CONTROL access. |

### `SecurityDescriptor` [out]

Caller-allocated buffer that **NtQuerySecurityObject** fills with a copy of the specified security descriptor. The [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure is returned in self-relative format.

### `Length` [in]

Size, in bytes, of the buffer pointed to by **SecurityDescriptor**.

### `LengthNeeded` [out]

Pointer to a caller-allocated variable that receives the number of bytes required to store the copied security descriptor.

## Return value

**NtQuerySecurityObject** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | **Handle** did not have the required access. |
| STATUS_BUFFER_TOO_SMALL | The buffer is too small for the security descriptor. None of the security information was copied to the buffer. |
| STATUS_INVALID_HANDLE | **Handle** was not a valid handle. |
| STATUS_OBJECT_TYPE_MISMATCH | **Handle** was not a handle of the expected type. |

## Remarks

Minifilters should call [**FltQuerySecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerysecurityobject).

A security descriptor can be in absolute or self-relative form. In self-relative form, all members of the structure are located contiguously in memory. In absolute form, the structure only contains pointers to the members. For more information, see [Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/win32/secauthz/absolute-and-self-relative-security-descriptors).

The NTFS file system imposes a 64K limit on the size of the security descriptor that is written to disk for a file. (The FAT file system does not support security descriptors for files.) Thus a 64K **SecurityDescriptor** buffer is guaranteed to be large enough to hold the returned **SECURITY_DESCRIPTOR** structure.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

> [!NOTE]
> If the call to the **NtQuerySecurityObject** function occurs in user mode, you should use the name "**NtQuerySecurityObject**" instead of "**ZwQuerySecurityObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FltQuerySecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerysecurityobject)

[**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[**NtSetSecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetsecurityobject)