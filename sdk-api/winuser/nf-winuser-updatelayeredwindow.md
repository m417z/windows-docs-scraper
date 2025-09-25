# UpdateLayeredWindow function

## Description

Updates the position, size, shape, content, and translucency of a layered window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to a layered window. A layered window is created by specifying **WS_EX_LAYERED** when creating the window with the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function.

**Windows 8:** The **WS_EX_LAYERED** style is supported for top-level windows and child windows. Previous Windows versions support **WS_EX_LAYERED** only for top-level windows.

### `hdcDst` [in, optional]

Type: **HDC**

A handle to a DC for the screen. This handle is obtained by specifying **NULL** when calling the [GetDC](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getdc) function. It is used for palette color matching when the window contents are updated. If *hdcDst* is **NULL**, the default palette will be used.

If *hdcSrc* is **NULL**, *hdcDst* must be **NULL**.

### `pptDst` [in, optional]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a structure that specifies the new screen position of the layered window. If the current position is not changing, *pptDst* can be **NULL**.

### `psize` [in, optional]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

A pointer to a structure that specifies the new size of the layered window. If the size of the window is not changing, *psize* can be **NULL**. If *hdcSrc* is **NULL**, *psize* must be **NULL**.

### `hdcSrc` [in, optional]

Type: **HDC**

A handle to a DC for the surface that defines the layered window. This handle can be obtained by calling the [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) function. If the shape and visual context of the window are not changing, *hdcSrc* can be **NULL**.

### `pptSrc` [in, optional]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a structure that specifies the location of the layer in the device context. If *hdcSrc* is **NULL**, *pptSrc* should be **NULL**.

### `crKey` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A structure that specifies the color key to be used when composing the layered window. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `pblend` [in, optional]

Type: **[BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction)***

A pointer to a structure that specifies the transparency value to be used when composing the layered window.

### `dwFlags` [in]

Type: **DWORD**

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ULW_ALPHA**<br><br>0x00000002 | Use *pblend* as the blend function. If the display mode is 256 colors or less, the effect of this value is the same as the effect of **ULW_OPAQUE**. |
| **ULW_COLORKEY**<br><br>0x00000001 | Use *crKey* as the transparency color. |
| **ULW_OPAQUE**<br><br>0x00000004 | Draw an opaque layered window. |
| **ULW_EX_NORESIZE**<br><br>0x00000008 | Force the [UpdateLayeredWindowIndirect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633557(v=vs.85)) function to fail if the current window size does not match the size specified in the *psize*. |

If *hdcSrc* is **NULL**, *dwFlags* should be zero.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The source DC should contain the surface that defines the visible contents of the layered window. For example, you can select a bitmap into a device context obtained by calling the [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) function.

An application should call [SetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setlayout) on the *hdcSrc* device context to properly set the mirroring mode. **SetLayout** will properly mirror all drawing into an **HDC** while properly preserving text glyph and (optionally) bitmap direction order. It cannot modify drawing directly into the bits of a device-independent bitmap (DIB). For more information, see [Window Layout and Mirroring](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

The **UpdateLayeredWindow** function maintains the window's appearance on the screen. The windows underneath a layered window do not need to be repainted when they are uncovered due to a call to **UpdateLayeredWindow**, because the system will automatically repaint them. This permits seamless animation of the layered window.

**UpdateLayeredWindow** always updates the entire window. To update part of a window, use the traditional [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) and set the blend value using [SetLayeredWindowAttributes](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlayeredwindowattributes).

For best drawing performance by the layered window and any underlying windows, the layered window should be as small as possible. An application should also process the message and re-create its layered windows when the display's color depth changes.

For more information, see [Layered Windows](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

## See also

[AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend)

**Conceptual**

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

**Other Resources**

**Reference**

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[TransparentBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-transparentblt)

[UpdateLayeredWindowIndirect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633557(v=vs.85))

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)