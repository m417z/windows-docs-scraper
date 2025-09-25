# ZwDuplicateObject function

## Description

The **ZwDuplicateObject** routine creates a handle that is a duplicate of the specified source handle.

## Parameters

### `SourceProcessHandle` [in]

A handle to the source process for the handle being duplicated.

### `SourceHandle` [in]

The handle to duplicate.

### `TargetProcessHandle` [in, optional]

A handle to the target process that is to receive the new handle. This parameter is optional and can be specified as NULL if the **DUPLICATE_CLOSE_SOURCE** flag is set in *Options*.

### `TargetHandle` [out, optional]

A pointer to a HANDLE variable into which the routine writes the new duplicated handle. The duplicated handle is valid in the specified target process. This parameter is optional and can be specified as NULL if no duplicate handle is to be created.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the desired access for the new handle.

### `HandleAttributes` [in]

A ULONG that specifies the desired attributes for the new handle. For more information about attributes, see the description of the **Attributes** member in [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes).

### `Options` [in]

A set of flags to control the behavior of the duplication operation. Set this parameter to zero or to the bitwise OR of one or more of the following flags.

| Flag name | Description |
| --- | --- |
| **DUPLICATE_SAME_ATTRIBUTES** | Instead of using the *HandleAttributes* parameter, copy the attributes from the source handle to the target handle. |
| **DUPLICATE_SAME_ACCESS** | Instead of using the *DesiredAccess* parameter, copy the access rights from the source handle to the target handle. |
| **DUPLICATE_CLOSE_SOURCE** | Close the source handle. |

## Return value

**ZwDuplicateObject** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The source handle is evaluated in the context of the specified source process. The calling process must have **PROCESS_DUP_HANDLE** access to the source process. The duplicate handle is created in the handle table of the specified target process. The calling process must have **PROCESS_DUP_HANDLE** access to the target process.

By default, the duplicate handle is created with the attributes specified by the *HandleAttributes* parameter, and with the access rights specified by the *DesiredAccess* parameter. If necessary, the caller can override one or both defaults by setting the **DUPLICATE_SAME_ATTRIBUTES** and **DUPLICATE_SAME_ACCESS** flags in the *Options* parameter.

If the call to this function occurs in user mode, you should use the name "**NtDuplicateObject**" instead of "**ZwDuplicateObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)