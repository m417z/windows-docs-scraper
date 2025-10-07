# pSetupGetFileTitle function

\[This function is not available in Windows Vista or Windows Server 2008.\]

Retrieves the file title for the specified file path.

## Parameters

*FilePath* \[in\]

The file path.

## Return value

A pointer to string that receives the file title.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

