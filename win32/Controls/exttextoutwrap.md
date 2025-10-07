# ExtTextOutWrap function

\[**ExtTextOutWrap** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions. It is recommended to use [**ExtTextOut**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) directly instead.\]

Draws text using the currently selected font, background color, and text color. You can optionally provide dimensions to be used for clipping, opacity, or both. This function wraps a call to [**ExtTextOut**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta).

## Parameters

*hdc* \[in\]

Type: **[**HDC**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the device context.

*X* \[in\]

Type: **int**

The x-coordinate, in logical coordinates, of the reference point used to position the string.

*Y* \[in\]

Type: **int**

The y-coordinate, in logical coordinates, of the reference point used to position the string.

*uOptions* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Values that specify how to use the application-defined rectangle. See [**ExtTextOut**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) for a complete list of options.

*lprc* \[in\]

Type: **const [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)\***

A pointer to an optional [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the dimensions, in logical coordinates, of a rectangle that is used for clipping, opacity, or both.

*lpString* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that contains the text to be drawn. The string does not need to be zero-terminated, since *cbCount* specifies the length of the string.

*cbCount* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of the string, in bytes, pointed to by *lpString*.

*lpDx* \[in\]

Type: **const [**INT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

A pointer to an optional array of values that indicate the distance between origins of adjacent character cells. For example, *lpDx*\[x\] logical units separate the origins of character cell x and character cell (x + 1).

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns a nonzero value if the string is drawn successfully. However, if the ANSI version of [**ExtTextOut**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) is called with ETO\_GLYPH\_INDEX, the function returns **TRUE** even though the function does nothing.

If the function fails, the return value is zero.

To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**ExtTextOutWrap** is not exported by name or declared in a public header file. To use it, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 417 from ComCtl32.dll to obtain a function pointer.

For additional remarks, please see [**ExtTextOut**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 6.0 or later) |

