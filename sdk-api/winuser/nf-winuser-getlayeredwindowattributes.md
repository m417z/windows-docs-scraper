# GetLayeredWindowAttributes function

## Description

Retrieves the opacity and transparency color key of a layered window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the layered window. A layered window is created by specifying **WS_EX_LAYERED** when creating the window with the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function or by setting **WS_EX_LAYERED** using [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) after the window has been created.

### `pcrKey` [out, optional]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

A pointer to a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that receives the transparency color key to be used when composing the layered window. All pixels painted by the window in this color will be transparent. This can be **NULL** if the argument is not needed.

### `pbAlpha` [out, optional]

Type: **BYTE***

The Alpha value used to describe the opacity of the layered window. Similar to the **SourceConstantAlpha** member of the [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction) structure. When the variable referred to by *pbAlpha* is 0, the window is completely transparent. When the variable referred to by *pbAlpha* is 255, the window is opaque. This can be **NULL** if the argument is not needed.

### `pdwFlags` [out, optional]

Type: **DWORD***

A layering flag. This parameter can be **NULL** if the value is not needed. The layering flag can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LWA_ALPHA**<br><br>0x00000002 | Use *pbAlpha* to determine the opacity of the layered window. |
| **LWA_COLORKEY**<br><br>0x00000001 | Use *pcrKey* as the transparency color. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetLayeredWindowAttributes** can be called only if the application has previously called [SetLayeredWindowAttributes](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlayeredwindowattributes) on the window. The function will fail if the layered window was setup with [UpdateLayeredWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatelayeredwindow).

For more information, see [Using Layered Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

**Reference**

[SetLayeredWindowAttributes](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlayeredwindowattributes)

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[Using Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)