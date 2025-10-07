# CSCFindClose function

\[This function is not supported and should not be used.\]

Closes a search handle.

## Parameters

*hFind* \[in\]

A search handle returned by the [**CSCFindFirstFileW**](https://learn.microsoft.com/windows/win32/devnotes/cscfindfirstfilew) function.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Cscmig.dll |

## See also

[**CSCFindFirstFileW**](https://learn.microsoft.com/windows/win32/devnotes/cscfindfirstfilew)

