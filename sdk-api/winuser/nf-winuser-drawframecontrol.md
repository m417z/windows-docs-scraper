## Description

The **DrawFrameControl** function draws a frame control of the specified type and style.

## Parameters

### `hdc` [in]

A handle to the device context of the window in which to draw the control.

### `lprc` [in]

 A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the bounding rectangle for frame control.

### `uType` [in]

The type of frame control to draw. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DFC_BUTTON** | Standard button |
| **DFC_CAPTION** | Title bar |
| **DFC_MENU** | Menu bar |
| **DFC_POPUPMENU** | Popup menu item. |
| **DFC_SCROLL** | Scroll bar |

### `uState` [in]

The initial state of the frame control. If *uType* is DFC_BUTTON, *uState* can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DFCS_BUTTON3STATE** | Three-state button |
| **DFCS_BUTTONCHECK** | Check box |
| **DFCS_BUTTONPUSH** | Push button |
| **DFCS_BUTTONRADIO** | Radio button |
| **DFCS_BUTTONRADIOIMAGE** | Image for radio button (nonsquare needs image) |
| **DFCS_BUTTONRADIOMASK** | Mask for radio button (nonsquare needs mask) |

If *uType* is DFC_CAPTION, *uState* can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DFCS_CAPTIONCLOSE** | **Close** button |
| **DFCS_CAPTIONHELP** | **Help** button |
| **DFCS_CAPTIONMAX** | **Maximize** button |
| **DFCS_CAPTIONMIN** | **Minimize** button |
| **DFCS_CAPTIONRESTORE** | **Restore** button |

If *uType* is DFC_MENU, *uState* can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DFCS_MENUARROW** | Submenu arrow |
| **DFCS_MENUARROWRIGHT** | Submenu arrow pointing left. This is used for the right-to-left cascading menus used with right-to-left languages such as Arabic or Hebrew. |
| **DFCS_MENUBULLET** | Bullet |
| **DFCS_MENUCHECK** | Check mark |

If *uType* is DFC_SCROLL, *uState* can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DFCS_SCROLLCOMBOBOX** | Combo box scroll bar |
| **DFCS_SCROLLDOWN** | Down arrow of scroll bar |
| **DFCS_SCROLLLEFT** | Left arrow of scroll bar |
| **DFCS_SCROLLRIGHT** | Right arrow of scroll bar |
| **DFCS_SCROLLSIZEGRIP** | Size grip in lower-right corner of window |
| **DFCS_SCROLLSIZEGRIPRIGHT** | Size grip in lower-left corner of window. This is used with right-to-left languages such as Arabic or Hebrew. |
| **DFCS_SCROLLUP** | Up arrow of scroll bar |

The following style can be used to adjust the bounding rectangle of the push button.

| Value | Meaning |
| --- | --- |
| **DFCS_ADJUSTRECT** | Bounding rectangle is adjusted to exclude the surrounding edge of the push button. |

One or more of the following values can be used to set the state of the control to be drawn.

| Value | Meaning |
| --- | --- |
| **DFCS_CHECKED** | Button is checked. |
| **DFCS_FLAT** | Button has a flat border. |
| **DFCS_HOT** | Button is hot-tracked. |
| **DFCS_INACTIVE** | Button is inactive (grayed). |
| **DFCS_MONO** | Button has a monochrome border. |
| **DFCS_PUSHED** | Button is pushed. |
| **DFCS_TRANSPARENT** | The background remains untouched. This flag can only be combined with DFCS_MENUARROWUP or DFCS_MENUARROWDOWN. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If *uType* is either DFC_MENU or DFC_BUTTON and *uState* is not DFCS_BUTTONPUSH, the frame control is a black-on-white mask (that is, a black frame control on a white background). In such cases, the application must pass a handle to a bitmap memory device control. The application can then use the associated bitmap as the *hbmMask* parameter to the [MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt) function, or it can use the device context as a parameter to the [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) function using ROPs such as SRCAND and SRCINVERT.

### DPI Virtualization

This API does not participate in DPI virtualization. The input given is always in terms of physical pixels, and is not related to the calling context.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)