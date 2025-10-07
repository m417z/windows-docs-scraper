# GetTextExtentPoint32Wrap function

\[**GetTextExtentPoint32Wrap** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions. It is recommended to use [**GetTextExtentPoint**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa) directly instead.\]

Computes the width and height of the specified string of text. This function wraps a call to [**GetTextExtentPoint**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa).

## Parameters

*hdc* \[in\]

Type: **[**HDC**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the device context.

*lpString* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that contains the text to be drawn. The string does not need to be zero-terminated, since *cbCount* specifies the length of the string.

*cbCount* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length, in bytes, of the string pointed to by *lpString*.

*lpSize* \[out\]

Type: **LPSIZE**

When this method returns, contains a pointer to a [**SIZE**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure containing the dimensions of the string, in logical units.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns a nonzero value if successful; otherwise, 0.

To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetTextExtentPoint32Wrap** is not exported by name or declared in a public header file. To use it, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 420 from ComCtl32.dll to obtain a function pointer.

For additional remarks, please see [**GetTextExtentPoint**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.81 or later) |

