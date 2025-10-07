# EndIMEShare function

Terminates IME Share.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

This function should be called after the last IME Share function is called.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**FInitIMEShare**](https://learn.microsoft.com/windows/win32/devnotes/finitimeshare)

