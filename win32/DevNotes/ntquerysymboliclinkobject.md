# NtQuerySymbolicLinkObject function

\[This function may be altered or unavailable in the future.\]

Retrieves the target of a symbolic link.

## Parameters

*LinkHandle* \[in\]

A handle to the symbolic link object.

*LinkTarget* \[in, out\]

A pointer to an initialized Unicode string that receives the target of the symbolic link. The **MaximumLength** and **Buffer** members must be set if the call fails.

*ReturnedLength* \[out, optional\]

A pointer to a variable that receives the length of the Unicode string returned in the *LinkTarget* parameter. If the function returns **STATUS\_BUFFER\_TOO\_SMALL**, this variable receives the required buffer size.

## Return value

The function returns **STATUS\_SUCCESS** or an error status.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

## See also

[**NtOpenSymbolicLinkObject**](https://learn.microsoft.com/windows/win32/devnotes/ntopensymboliclinkobject)

