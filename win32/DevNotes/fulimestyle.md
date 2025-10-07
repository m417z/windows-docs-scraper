# FUlIMEStyle function

Specifies whether a non-color style has an underline style.

## Parameters

*pimestyle* \[in\]

An **IMESTYLE** structure returned from [**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr) function.

## Return value

TRUE if the style has an underline style.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr)

