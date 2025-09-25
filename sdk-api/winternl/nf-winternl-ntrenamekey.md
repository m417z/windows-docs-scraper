# NtRenameKey function

## Description

[This function may be changed or removed from Windows without further notice. ]

Changes the name of the specified registry key.

## Parameters

### `KeyHandle` [in]

A handle to the key to be renamed. The handle must be opened with the KEY_WRITE access right.

### `NewName` [in]

A pointer to a UNICODE string that is the new name for the key.

## Return value

Returns an **NTSTATUS** or error code. An error code of **STATUS_ACCESS_DENIED** indicates that the caller does not have the necessary access rights to the specified registry key or subkeys.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. You can also use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/DevNotes/-loadlibrary) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/DevNotes/-getprocaddress-) functions to dynamically link to Ntdll.dll.

The **NtRenameKey** function can be used to rename an entire registry subtree. The caller must have **KEY_CREATE_SUB_KEY** access to the parent of the specified key and DELETE access to the entire subtree being renamed.

## See also

[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights)