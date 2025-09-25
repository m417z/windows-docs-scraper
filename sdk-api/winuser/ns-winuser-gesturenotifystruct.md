# GESTURENOTIFYSTRUCT structure

## Description

When transmitted with [WM_GESTURENOTIFY](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesturenotify) messages,
passes information about a gesture.

## Members

### `cbSize`

The size of the structure.

### `dwFlags`

Reserved for future use.

### `hwndTarget`

The target window for the gesture notification.

### `ptsLocation`

The location of the gesture in physical screen coordinates.

### `dwInstanceID`

A specific gesture instance with gesture messages starting with **GID_START** and ending with **GID_END**.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wintouch/mtstructures)

[WM_GESTURENOTIFY](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesturenotify)