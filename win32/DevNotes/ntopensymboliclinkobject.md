# NtOpenSymbolicLinkObject function

\[This function may be altered or unavailable in the future.\]

Opens an existing symbolic link.

## Parameters

*LinkHandle* \[out\]

A handle to the newly opened symbolic link object.

*DesiredAccess* \[in\]

An [**ACCESS\_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask) that specifies the requested access to the directory object. It is typical to use GENERIC\_READ so the handle can be passed to the [**NtQueryDirectoryObject**](https://learn.microsoft.com/windows/win32/devnotes/ntquerydirectoryobject) function.

*ObjectAttributes* \[in\]

The attributes for the directory object. To initialize the **OBJECT\_ATTRIBUTES** structure, use the **InitializeObjectAttributes** macro. If the caller is not running in a system thread context, it must specify the **OBJ\_KERNEL\_HANDLE** flag when initializing the structure. For more information, see the documentation for these items in the documentation for the WDK.

## Return value

The function returns **STATUS\_SUCCESS** or an error status.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[**NtQueryDirectoryObject**](https://learn.microsoft.com/windows/win32/devnotes/ntquerydirectoryobject)

