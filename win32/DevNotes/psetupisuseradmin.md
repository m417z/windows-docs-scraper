# pSetupIsUserAdmin function

\[This function is not available in Windows Vista or Windows Server 2008.\]

Indicates whether the current user is an administrator.

## Parameters

This function has no parameters.

## Return value

**TRUE** if the current user is an administrator, otherwise **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

