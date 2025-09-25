# THUMBBUTTONFLAGS enumeration

## Description

Used by [THUMBBUTTON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-thumbbutton) to control specific states and behaviors of the button.

## Constants

### `THBF_ENABLED:0`

The button is active and available to the user.

### `THBF_DISABLED:0x1`

The button is disabled. It is present, but has a visual state that indicates that it will not respond to user action.

### `THBF_DISMISSONCLICK:0x2`

When the button is clicked, the taskbar button's flyout closes immediately.

### `THBF_NOBACKGROUND:0x4`

Do not draw a button border, use only the image.

### `THBF_HIDDEN:0x8`

The button is not shown to the user.

### `THBF_NONINTERACTIVE:0x10`

The button is enabled but not interactive; no pressed button state is drawn. This value is intended for instances where the button is used in a notification.

## See also

[THUMBBUTTON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-thumbbutton)

[THUMBBUTTONMASK](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-thumbbuttonmask)