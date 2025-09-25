# ZwSetSecurityObject function

## Description

The **ZwSetSecurityObject** routine sets an object's security state.

## Parameters

### `Handle` [in]

Handle for the object whose security state is to be set. This handle must have the access specified in the Meaning column of the table shown in the description of the **SecurityInformation** parameter.

### `SecurityInformation` [in]

A [**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)value specifying the information to be set. Can be a combination of one or more of the following values.

| Value | Meaning |
| ----- | ------- |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is to be set. Requires WRITE_DAC access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is to be set. Requires WRITE_OWNER access. |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is to be set. Requires WRITE_OWNER access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is to be set. Requires ACCESS_SYSTEM_SECURITY access. |

### `SecurityDescriptor` [in]

Pointer to the security descriptor to be set for the object.

## Return value

**ZwSetSecurityObject** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | **Handle** does not have the required access rights. |
| STATUS_ACCESS_VIOLATION | **SecurityDescriptor** is a **NULL** pointer. |
| STATUS_INSUFFICIENT_RESOURCES | The object's security descriptor could not be captured. |
| STATUS_INVALID_ACL | The object's security descriptor contains an invalid ACL. |
| STATUS_INVALID_HANDLE | **Handle** is not a valid handle. |
| STATUS_INVALID_SECURITY_DESCR | **SecurityDescriptor** does not point to a valid security descriptor. |
| STATUS_INVALID_SID | The object's security descriptor contains an invalid **SID**. |
| STATUS_OBJECT_TYPE_MISMATCH | **Handle** is not a handle of the expected type. |
| STATUS_UNKNOWN_REVISION | The revision level of the object's security descriptor is unknown or is not supported. |

## Remarks

A security descriptor can be in absolute or self-relative form. In self-relative form, all members of the structure are located contiguously in memory. In absolute form, the structure only contains pointers to the members. For more information, see "Absolute and Self-Relative Security Descriptors" in the Security section of the Windows SDK documentation.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

Minifilters should use [**FltSetSecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetsecurityobject) instead of **ZwSetSecurityObject**.

Callers of **ZwSetSecurityObject** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
> If the call to the **ZwSetSecurityObject** function occurs in user mode, you should use the name "[**NtSetSecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetsecurityobject)" instead of "**ZwSetSecurityObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FltSetSecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetsecurityobject)

[**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**ZwQuerySecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerysecurityobject)