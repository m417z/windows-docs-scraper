## Description

The **PS_CREATE_NOTIFY_INFO** structure provides information about a newly created process.

## Members

### `Size`

The size, in bytes, of this structure. The operating system uses this size to indicate the type of structure that it passes to [CreateProcessNotifyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine). Currently, this member is always **sizeof**(**PS_CREATE_NOTIFY_INFO**).

### `Flags`

Reserved. Use the **FileOpenNameAvailable** member instead.

### `FileOpenNameAvailable`

A Boolean value that specifies whether the **ImageFileName** member contains the exact file name that is used to open the process executable file.

### `IsSubsystemProcess`

A Boolean value that indicates the type of process subsystem is a subsystem other than Win32.

**IsSubsystemProcess** is only populated for subsystem processes other than Win32 when a driver has registered through [PsSetCreateProcessNotifyRoutineEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex2) with a type that allows for notifications from subsystem processes. When **IsSubsystemProcess** is set, the **FileObject**, **ImageFileName**, and **CommandLine** may be NULL. Drivers should use **ProcessSubsystemInformation** to query the subsystem type if needed.

For more information, see [NtQueryInformationProcess](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess).

### `Reserved`

Reserved for system use.

### `ParentProcessId`

The process ID of the parent process for the new process. Note that the parent process is not necessarily the same process as the process that created the new process. The new process can inherit certain properties of the parent process, such as handles or shared memory. (The process ID of the process creator is given by **CreatingThreadId**->**UniqueProcess**.)

### `CreatingThreadId`

The process ID and thread ID of the process and thread that created the new process. **CreatingThreadId**->**UniqueProcess** contains the process ID, and **CreatingThreadId**->**UniqueThread** contains the thread ID.

### `FileObject`

A pointer to the file object for the process executable file.

If **IsSubsystemProcess** is TRUE, this value may be **NULL**.

### `ImageFileName`

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) string that holds the file name of the executable. If the **FileOpenNameAvailable** member is **TRUE**, the string specifies the exact file name that is used to open the executable file. If **FileOpenNameAvailable** is **FALSE**, the operating system might provide only a partial name.

If **IsSubsystemProcess** is TRUE, this value maybe NULL.

### `CommandLine`

A pointer to a **UNICODE_STRING** string that holds the command that is used to execute the process. If the command is not available, **CommandLine** is **NULL**.

If **IsSubsystemProcess** is TRUE, this value maybe NULL.

### `CreationStatus`

The NTSTATUS value to return for the process-creation operation. Drivers can change this value to an error code to prevent the process from being created.

## See also

[CreateProcessNotifyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetCreateProcessNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)