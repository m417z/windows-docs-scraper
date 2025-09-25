# UPDATELAYEREDWINDOWINFO structure

## Description

Used by [UpdateLayeredWindowIndirect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633557(v=vs.85)) to provide position, size, shape, content, and translucency information for a layered window.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of this structure.

### `hdcDst`

Type: **HDC**

A handle to a DC for the screen. This handle is obtained by specifying **NULL** in this member when calling [UpdateLayeredWindowIndirect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633557(v=vs.85)). The handle is used for palette color matching when the window contents are updated. If **hdcDst** is **NULL**, the default palette is used.

If **hdcSrc** is **NULL**, **hdcDst** must be **NULL**.

### `pptDst`

Type: **const [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

The new screen position of the layered window. If the new position is unchanged from the current position, **pptDst** can be **NULL**.

### `psize`

Type: **const [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

The new size of the layered window. If the size of the window will not change, this parameter can be **NULL**. If **hdcSrc** is **NULL**, **psize** must be **NULL**.

### `hdcSrc`

Type: **HDC**

A handle to the DC for the surface that defines the layered window. This handle can be obtained by calling the [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) function. If the shape and visual context of the window will not change, **hdcSrc** can be **NULL**.

### `pptSrc`

Type: **const [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

The location of the layer in the device context. If **hdcSrc** is **NULL**, **pptSrc** should be **NULL**.

### `crKey`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

The color key to be used when composing the layered window. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `pblend`

Type: **const [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction)***

The transparency value to be used when composing the layered window.

### `dwFlags`

Type: **DWORD**

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ULW_ALPHA**<br><br>0x00000002 | Use *pblend* as the blend function. If the display mode is 256 colors or less, the effect of this value is the same as the effect of ULW_OPAQUE. |
| **ULW_COLORKEY**<br><br>0x00000001 | Use *crKey* as the transparency color. |
| **ULW_OPAQUE**<br><br>0x00000004 | Draw an opaque layered window. |
| **ULW_EX_NORESIZE**<br><br>0x00000008 | Force the [UpdateLayeredWindowIndirect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633557(v=vs.85)) function to fail if the current window size does not match the size specified in the *psize*. |

If **hdcSrc** is **NULL**, **dwFlags** should be zero.

### `prcDirty`

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The area to be updated. This parameter can be **NULL**. If it is non-NULL, only the area in this rectangle is updated from the source DC.

## See also

**Conceptual**

**Reference**

[UpdateLayeredWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatelayeredwindow)

[Window Features](https://learn.microsoft.com/windows/desktop/winmsg/window-features)