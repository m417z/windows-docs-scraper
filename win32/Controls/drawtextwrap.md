# DrawTextWrap function

\[**DrawTextWrap** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions. It is recommended to use [**DrawText**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) directly instead.\]

Draws formatted text in the specified rectangle. It formats the text according to the specified method (expanding tabs, justifying characters, breaking lines, and so on). This function wraps a call to [**DrawText**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext).

## Parameters

*hdc* \[in\]

Type: **[**HDC**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the device context.

*lpString* \[in, out\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that contains the text to draw. If the *nCount* parameter is -1, the string must be null-terminated.

If *uFormat* includes DT\_MODIFYSTRING, the function might add up to four additional characters to this string. The buffer that contains the string should be large enough to accommodate these extra characters.

*nCount* \[in\]

Type: **int**

The length of the string pointed to by *lpString*. If *nCount* is -1, then the *lpString* parameter is assumed to be a pointer to a null-terminated string and [**DrawText**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) computes the character count automatically.

*lpRect* \[in, out\]

Type: **LPRECT**

A pointer to a [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that contains the rectangle, in logical coordinates, in which the text is to be formatted.

*uFormat* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The formatting options. See the documentation for [**DrawText**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) for a complete list of options.

*lpDTParams* \[in\]

Type: **LPDRAWTEXTPARAMS**

A pointer to a [**DRAWTEXTPARAMS**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-drawtextparams) structure that specifies additional formatting options. This parameter can be **NULL**.

## Return value

Type: **int**

If the function succeeds, the return value is the text height in logical units. If **DT\_VCENTER** or **DT\_BOTTOM** is specified, the return value is the offset from the **top** member of *lprc* to the bottom of the drawn text If the function fails, the return value is zero.

If the function fails, the return value is zero.

To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**DrawTextWrap** is not exported by name or declared in a public header. To use it, you must use [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 415 from ComCtl32.dll to obtain a function pointer.

For additional remarks, please see [**DrawText**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 6.0 or later) |

