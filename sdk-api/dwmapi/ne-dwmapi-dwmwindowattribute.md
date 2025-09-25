## Description

Options used by the [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute) and [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) functions.

## Constants

### `DWMWA_NCRENDERING_ENABLED`

**IMPORTANT**. The value of **DWMWA_NCRENDERING_ENABLED** is 1.

```
typedef enum DWMWINDOWATTRIBUTE {
  DWMWA_NCRENDERING_ENABLED = 1,
  DWMWA_NCRENDERING_POLICY,
  ...
```

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute). Discovers whether non-client rendering is enabled. The retrieved value is of type **BOOL**. **TRUE** if non-client rendering is enabled; otherwise, **FALSE**.

### `DWMWA_NCRENDERING_POLICY`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Sets the non-client rendering policy. The *pvAttribute* parameter points to a value from the [DWMNCRENDERINGPOLICY](https://learn.microsoft.com/windows/win32/api/dwmapi/ne-dwmapi-dwmncrenderingpolicy) enumeration.

### `DWMWA_TRANSITIONS_FORCEDISABLED`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Enables or forcibly disables DWM transitions. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to disable transitions, or **FALSE** to enable transitions.

### `DWMWA_ALLOW_NCPAINT`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Enables content rendered in the non-client area to be visible on the frame drawn by DWM. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to enable content rendered in the non-client area to be visible on the frame; otherwise, **FALSE**.

### `DWMWA_CAPTION_BUTTON_BOUNDS`

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute). Retrieves the bounds of the caption button area in the window-relative space. The retrieved value is of type [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect). If the window is minimized or otherwise not visible to the user, then the value of the **RECT** retrieved is undefined. You should check whether the retrieved **RECT** contains a boundary that you can work with, and if it doesn't then you can conclude that the window is minimized or otherwise not visible.

### `DWMWA_NONCLIENT_RTL_LAYOUT`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Specifies whether non-client content is right-to-left (RTL) mirrored. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** if the non-client content is right-to-left (RTL) mirrored; otherwise, **FALSE**.

### `DWMWA_FORCE_ICONIC_REPRESENTATION`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Forces the window to display an iconic thumbnail or peek representation (a static bitmap), even if a live or snapshot representation of the window is available. This value is normally set during a window's creation, and not changed throughout the window's lifetime. Some scenarios, however, might require the value to change over time. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to require a iconic thumbnail or peek representation; otherwise, **FALSE**.

### `DWMWA_FLIP3D_POLICY`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Sets how Flip3D treats the window. The *pvAttribute* parameter points to a value from the [DWMFLIP3DWINDOWPOLICY](https://learn.microsoft.com/windows/win32/api/dwmapi/ne-dwmapi-dwmflip3dwindowpolicy) enumeration.

### `DWMWA_EXTENDED_FRAME_BOUNDS`

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute). Retrieves the extended frame bounds rectangle in screen space. The retrieved value is of type [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect).

### `DWMWA_HAS_ICONIC_BITMAP`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). The window will provide a bitmap for use by DWM as an iconic thumbnail or peek representation (a static bitmap) for the window. **DWMWA_HAS_ICONIC_BITMAP** can be specified with **DWMWA_FORCE_ICONIC_REPRESENTATION**. **DWMWA_HAS_ICONIC_BITMAP** normally is set during a window's creation and not changed throughout the window's lifetime. Some scenarios, however, might require the value to change over time. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to inform DWM that the window will provide an iconic thumbnail or peek representation; otherwise, **FALSE**.

**Windows Vista and earlier:** This value is not supported.

### `DWMWA_DISALLOW_PEEK`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Do not show peek preview for the window. The peek view shows a full-sized preview of the window when the mouse hovers over the window's thumbnail in the taskbar. If this attribute is set, hovering the mouse pointer over the window's thumbnail dismisses peek (in case another window in the group has a peek preview showing). The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to prevent peek functionality, or **FALSE** to allow it.

**Windows Vista and earlier:** This value is not supported.

### `DWMWA_EXCLUDED_FROM_PEEK`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Prevents a window from fading to a glass sheet when peek is invoked. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to prevent the window from fading during another window's peek, or **FALSE** for normal behavior.

**Windows Vista and earlier:** This value is not supported.

### `DWMWA_CLOAK`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Cloaks the window such that it is not visible to the user. The window is still composed by DWM.

**Using with DirectComposition:** Use the DWMWA_CLOAK flag to cloak the layered child window when animating a representation of the window's content via a DirectComposition visual that has been associated with the layered child window. For more details on this usage case, see [How to animate the bitmap of a layered child window](https://learn.microsoft.com/windows/desktop/directcomp/how-to--animate-the-bitmap-of-a-layered-child-window).

**Windows 7 and earlier:** This value is not supported.

### `DWMWA_CLOAKED`

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute). If the window is cloaked, provides one of the following values explaining why.

**DWM_CLOAKED_APP** (value 0x00000001). The window was cloaked by its owner application.

**DWM_CLOAKED_SHELL** (value 0x00000002). The window was cloaked by the Shell.

**DWM_CLOAKED_INHERITED** (value 0x00000004). The cloak value was inherited from its owner window.

**Windows 7 and earlier:** This value is not supported.

### `DWMWA_FREEZE_REPRESENTATION`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Freeze the window's thumbnail image with its current visuals. Do no further live updates on the thumbnail image to match the window's contents.

**Windows 7 and earlier:** This value is not supported.

### `DWMWA_USE_HOSTBACKDROPBRUSH`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Enables a non-UWP window to use host backdrop brushes. If this flag is set, then a Win32 app that calls [Windows::UI::Composition](https://learn.microsoft.com/uwp/api/windows.ui.composition) APIs can build transparency effects using the host backdrop brush (see [Compositor.CreateHostBackdropBrush](https://learn.microsoft.com/uwp/api/windows.ui.composition.compositor.createhostbackdropbrush)). The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to enable host backdrop brushes for the window, or **FALSE** to disable it.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_USE_IMMERSIVE_DARK_MODE` : 20

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Allows the window frame for this window to be drawn in dark mode colors when the dark mode system setting is enabled. For compatibility reasons, all windows default to light mode regardless of the system setting. The *pvAttribute* parameter points to a value of type **BOOL**. **TRUE** to honor dark mode for the window, **FALSE** to always use light mode.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_WINDOW_CORNER_PREFERENCE` : 33

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Specifies the rounded corner preference for a window. The *pvAttribute* parameter points to a value of type [DWM_WINDOW_CORNER_PREFERENCE](https://learn.microsoft.com/windows/win32/api/dwmapi/ne-dwmapi-dwm_window_corner_preference).

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_BORDER_COLOR`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Specifies the color of the window border. The *pvAttribute* parameter points to a value of type [COLORREF](https://learn.microsoft.com/windows/win32/gdi/colorref). The app is responsible for changing the border color according to state changes, such as a change in window activation.

Specifying **DWMWA_COLOR_NONE** (value 0xFFFFFFFE) for the color will suppress the drawing of the window border. This makes it possible to have a rounded window with no border.

Specifying **DWMWA_COLOR_DEFAULT** (value 0xFFFFFFFF) for the color will reset the window back to using the system's default behavior for the border color.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_CAPTION_COLOR`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Specifies the color of the caption. The *pvAttribute* parameter points to a value of type [COLORREF](https://learn.microsoft.com/windows/win32/gdi/colorref).

Specifying **DWMWA_COLOR_DEFAULT** (value 0xFFFFFFFF) for the color will reset the window back to using the system's default behavior for the caption color.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_TEXT_COLOR`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Specifies the color of the caption text. The *pvAttribute* parameter points to a value of type [COLORREF](https://learn.microsoft.com/windows/win32/gdi/colorref).

Specifying **DWMWA_COLOR_DEFAULT** (value 0xFFFFFFFF) for the color will reset the window back to using the system's default behavior for the caption text color.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_VISIBLE_FRAME_BORDER_THICKNESS`

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute). Retrieves the width of the outer border that the DWM would draw around this window. The value can vary depending on the DPI of the window. The *pvAttribute* parameter points to a value of type **UINT**.

This value is supported starting with Windows 11 Build 22000.

### `DWMWA_SYSTEMBACKDROP_TYPE`

Use with [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute) or [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute). Retrieves or specifies the system-drawn backdrop material of a window, including behind the non-client area. The *pvAttribute* parameter points to a value of type [DWM_SYSTEMBACKDROP_TYPE](https://learn.microsoft.com/windows/win32/api/dwmapi/ne-dwmapi-dwm_systembackdrop_type).

This value is supported starting with Windows 11 Build 22621.

### `DWMWA_REDIRECTIONBITMAP_ALPHA`

Use with
[DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute)
. Enables or disables the use of the alpha channel in the window's redirection
bitmap. If this attribute is set to true, the window must contain premultiplied
alpha values in each pixel. If it is false, the alpha is ignored and the
redirection bitmap is treated as fully opaque. This attribute defaults to false.

This value is supported starting with Windows 11 Build 26100.

### `DWMWA_BORDER_MARGINS`

Use with [DwmSetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute)
. Specifies the override location of the window border, as a distance from each
edge. The *pvAttribute* parameter points to a value of type FRAME_MARGIN.

A value of all zeros disables the override set by this attribute, resulting in
default window borders. Otherwise, all values must be greater than or equal to 1.

Each value in the FRAME_MARGIN (left, right, top, bottom) indicates a distance
inwards from each edge of the window. Non-zero border margins forces the window
to have a border and sets the location of the border. Window contents covered
by or outside the border are clipped.

This value will be supported in an upcoming update to Windows 11 build 26100.

### `DWMWA_LAST`

The maximum recognized **DWMWINDOWATTRIBUTE** value, used for validation purposes.

## See also

* [DwmGetWindowAttribute function](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute)
* [DwmSetWindowAttribute function](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmsetwindowattribute)
* [Enable and control DWM composition](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw)