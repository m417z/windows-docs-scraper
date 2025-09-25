# THUMBBUTTON structure

## Description

Used by methods of the [ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3) interface to define buttons used in a toolbar embedded in a window's thumbnail representation.

## Members

### `dwMask`

Type: **[THUMBBUTTONMASK](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-thumbbuttonmask)**

A combination of [THUMBBUTTONMASK](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-thumbbuttonmask) values that specify which members of this structure contain valid data; other members are ignored, with the exception of **iId**, which is always required.

### `iId`

Type: **UINT**

The application-defined identifier of the button, unique within the toolbar.

### `iBitmap`

Type: **UINT**

The zero-based index of the button image within the image list set through [ITaskbarList3::ThumbBarSetImageList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarsetimagelist).

### `hIcon`

Type: **HICON**

The handle of an icon to use as the button image.

### `szTip`

Type: **WCHAR[260]**

A wide character array that contains the text of the button's tooltip, displayed when the mouse pointer hovers over the button.

### `dwFlags`

Type: **[THUMBBUTTONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-thumbbuttonflags)**

A combination of [THUMBBUTTONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-thumbbuttonflags) values that control specific states and behaviors of the button.

## Remarks

When a button is clicked, a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message that contains the button ID is sent to the associated application window. The application handles whatever action it has assigned to the button.

### Button Images

When using an icon, specified through the **hIcon** member, the taskbar makes its own copy of the icon. It is the caller's responsibility to free the handle it passed in **hIcon** when it is no longer needed.

If both an icon and an image list are specified for a button's image, the icon is used if possible. If for some reason the attempt to retrieve the icon fails, the image from the image list is used.

Applications must provide these button images:

* The button in its default active state.
* Images suitable for use with high-dpi (dots per inch) displays.

Images must be 32-bit and of dimensions [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_CXICON) x [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_CYICON). The toolbar itself provides visuals for a button's clicked, disabled, and hover states.

## See also

[ITaskbarList3::ThumbBarAddButtons](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbaraddbuttons)

[ITaskbarList3::ThumbBarUpdateButtons](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbarupdatebuttons)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)

[Taskbar Thumbnail Toolbar Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee663597(v=vs.85))