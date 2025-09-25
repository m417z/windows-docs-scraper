# SetLayeredWindowAttributes function

## Description

Sets the opacity and transparency color key of a layered window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the layered window. A layered window is created by specifying **WS_EX_LAYERED** when creating the window with the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function or by setting **WS_EX_LAYERED** via [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) after the window has been created.

**Windows 8:** The **WS_EX_LAYERED** style is supported for top-level windows and child windows. Previous Windows versions support **WS_EX_LAYERED** only for top-level windows.

### `crKey` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that specifies the transparency color key to be used when composing the layered window. All pixels painted by the window in this color will be transparent. To generate a **COLORREF**, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `bAlpha` [in]

Type: **BYTE**

Alpha value used to describe the opacity of the layered window. Similar to the **SourceConstantAlpha** member of the [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction) structure. When *bAlpha* is 0, the window is completely transparent. When *bAlpha* is 255, the window is opaque.

### `dwFlags` [in]

Type: **DWORD**

An action to be taken. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LWA_ALPHA**<br><br>0x00000002 | Use *bAlpha* to determine the opacity of the layered window. |
| **LWA_COLORKEY**<br><br>0x00000001 | Use *crKey* as the transparency color. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Note that once **SetLayeredWindowAttributes** has been called for a layered window, subsequent [UpdateLayeredWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatelayeredwindow) calls will fail until the layering style bit is cleared and set again.

For more information, see [Using Layered Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

[AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

**Other Resources**

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

**Reference**

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[TransparentBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-transparentblt)

[UpdateLayeredWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatelayeredwindow)

[Using Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)