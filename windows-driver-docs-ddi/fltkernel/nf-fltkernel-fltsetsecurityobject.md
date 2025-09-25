# FltSetSecurityObject function

## Description

**FltSetSecurityObject** sets an object's security state.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the object whose security state is to be set. The caller must have the access specified in the Meaning column of the table shown in the description of the **SecurityInformation** parameter. This parameter is required and cannot be **NULL**.

### `SecurityInformation` [in]

[**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) value specifying the information to be set as a combination of one or more of the following.

| Value | Meaning |
| ----- | ------- |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is to be set. Requires WRITE_OWNER access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is to be set. Requires WRITE_OWNER access. |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is to be set. Requires WRITE_DAC access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is to be set. Requires ACCESS_SYSTEM_SECURITY access. |

### `SecurityDescriptor` [in]

Pointer to the security descriptor to be set for the object.

## Return value

**FltSetSecurityObject** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | The caller did not have the required access. This is an error code. |
| STATUS_ACCESS_VIOLATION| *SecurityDescriptor* was a **NULL** pointer. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | The object's security descriptor could not be captured. This is an error code. |
| STATUS_INVALID_ACL | The object's security descriptor contained an invalid ACL. This is an error code. |
| STATUS_INVALID_SECURITY_DESCR | *SecurityDescriptor* did not point to a valid security descriptor. This is an error code. |
| STATUS_INVALID_SID | The object's security descriptor contained an invalid SID. This is an error code. |
| STATUS_UNKNOWN_REVISION | The revision level of the object's security descriptor was unknown or not supported. This is an error code. |
| STATUS_NOT_IMPLEMENTED | The **FltSetSecurityObject** routine is present but not supported in the operating system environment in which it was called. |

## Remarks

The **FltSetSecurityObject** routine is present and supported starting with Windows Vista. In Windows 2000, Windows XP, and Server 2003 SP1, the routine is present but not supported, and will return STATUS_NOT_IMPLEMENTED if called in any of these environments.

A security descriptor can be in absolute or self-relative form. In self-relative form, all members of the structure are located contiguously in memory. In absolute form, the structure only contains pointers to the members. For more information, see [Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/win32/secauthz/absolute-and-self-relative-security-descriptors).

For more information about security and access control, see the documentation on these topics in the Windows SDK.

## See also

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[ZwQuerySecurityObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerysecurityobject)

[ZwSetSecurityObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetsecurityobject)

[FltQuerySecurityObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerysecurityobject)