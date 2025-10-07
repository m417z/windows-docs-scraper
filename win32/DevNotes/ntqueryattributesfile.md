# NtQueryAttributesFile function

\[This function may be changed or removed from Windows without further notice.\]

Retrieves basic attributes for the specified file object.

## Parameters

*ObjectAttributes* \[in\]

A pointer to an [OBJECT\_ATTRIBUTES](https://msdn.microsoft.com/library/aa491657.aspx) structure that supplies the attributes to be used for the file object.

*FileInformation* \[out\]

A pointer to a [FILE\_BASIC\_INFORMATION](https://msdn.microsoft.com/library/aa491634.aspx) structure to receive the returned file attribute information.

## Return value

Returns an NTSTATUS or error code.

The forms and significance of NTSTATUS error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. The associated import library, Ntdll.lib, is available in the WDK. You can also use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/devnotes/-loadlibrary) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/devnotes/-getprocaddress-) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

