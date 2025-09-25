# NtOpenFile function

## Description

Opens an existing file, device, directory, or volume, and returns a handle for the file
object.

This function is equivalent to the **ZwOpenFile** function documented in the
Windows Driver Kit (WDK).

## Parameters

### `FileHandle` [out]

A pointer to a handle for the opened file. The driver must close the handle with
**ZwClose** once the handle is no longer in use.

### `DesiredAccess` [in]

The **ACCESS_MASK** value that expresses the types of file access desired by the
caller. For information about the types of access that can be specified, see
**ZwCreateFile** in the WDK.

### `ObjectAttributes` [in]

A pointer to a structure that a caller initializes with
**InitializeObjectAttributes**. If the caller is not running in the system process
context, it must set the **OBJ_KERNEL_HANDLE** attribute for
*ObjectAttributes*. For more information about specifying object attributes, see
the *CreateOptions* parameter of **ZwCreateFile** in the WDK.

### `IoStatusBlock` [out]

A pointer to a structure that contains information about the requested operation and the final completion
status.

### `ShareAccess` [in]

The type of share access for the file. For more information, see
**ZwCreateFile** in the WDK.

### `OpenOptions` [in]

The options to be applied when opening the file. For more information, see
**ZwCreateFile** in the WDK.

## Return value

**NtOpenFile** either returns
**STATUS_SUCCESS** or an appropriate error status. If it returns an error status, the
caller can find additional information about the cause of the failure by checking the
*IoStatusBlock*.

## Remarks

Driver routines that run in a process context other than that of the system process must set the
**OBJ_KERNEL_HANDLE** attribute for the *ObjectAttributes*
parameter of **ZwOpenFile**. This restricts the use of the handle returned by
**ZwOpenFile** to processes running only in kernel mode. Otherwise, the handle can
be accessed by the process in whose context the driver is running. Drivers can call
**InitializeObjectAttributes** to set the
**OBJ_KERNEL_HANDLE** attribute as follows.

`InitializeObjectAttributes(&ObjectAddributes, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);`

Callers of **ZwCreateFile** must be running at IRQL = PASSIVE_LEVEL.

Note that the WDK header file Ntdef.h is necessary for many constant definitions.
You can also use the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to
Ntdll.dll.