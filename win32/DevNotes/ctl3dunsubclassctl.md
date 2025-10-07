# Ctl3dUnsubclassCtl function

Turns off subclassing for the specified control.

## Parameters

*hwnd*

A handle to the control window.

## Return value

Returns **TRUE** if the control is successfully subclassed; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

## See also

[**Ctl3dSubclassCtl**](https://learn.microsoft.com/windows/win32/devnotes/ctl3dsubclassctl)

