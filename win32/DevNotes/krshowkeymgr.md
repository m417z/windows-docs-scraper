# KRShowKeyMgr function

\[This function is included only in Windows XP. It is not currently included in any other version of Windows, nor is it expected to be included in any future versions of Windows.\]

Brings up the key manager dialog into the user interface.

## Parameters

*hwParent*

A handle to the parent window of the dialog. This parameter can be **NULL**.

*hInstance*

This parameter is not used and should be set to **NULL**.

*pszCmdLine*

This parameter is not used and should be set to **NULL**.

*CmdShow*

This parameter is not used and should be set to **NULL**.

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Keymgr.dll |

