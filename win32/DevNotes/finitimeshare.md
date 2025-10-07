# FInitIMEShare function

Initializes IME Share.

## Parameters

This function has no parameters.

## Return value

The function returns **TRUE** on success or **FALSE** otherwise.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

This function should be called before any other IME Share functions are called.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**EndIMEShare**](https://learn.microsoft.com/windows/win32/devnotes/endimeshare)

