# FWinIMEColorStyle function

Specifies whether the specified color is a Windows color.

## Parameters

*pcolorstyle* \[in\]

An **IMECOLORSTY** structure returned from a [**PColorStyleBackFromIMEStyle**](https://learn.microsoft.com/windows/win32/devnotes/pcolorstylebackfromimestyle) or [**PColorStyleTextFromIMEStyle**](https://learn.microsoft.com/windows/win32/devnotes/pcolorstyletextfromimestyle) function.

## Return value

Returns **TRUE** when the color is a Windows color.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**PColorStyleBackFromIMEStyle**](https://learn.microsoft.com/windows/win32/devnotes/pcolorstylebackfromimestyle)

[**PColorStyleTextFromIMEStyle**](https://learn.microsoft.com/windows/win32/devnotes/pcolorstyletextfromimestyle)

