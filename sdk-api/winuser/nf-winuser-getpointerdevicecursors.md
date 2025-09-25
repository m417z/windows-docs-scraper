# GetPointerDeviceCursors function

## Description

Gets the cursor IDs that are mapped to the cursors associated with a pointer device.

## Parameters

### `device` [in]

The device handle.

### `cursorCount` [in, out]

The number of cursors associated with the pointer device.

### `deviceCursors` [out, optional]

An array of [POINTER_DEVICE_CURSOR_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_cursor_info) structures that contain info about the cursors. If NULL, *cursorCount* returns the number of cursors associated with the pointer device.

## Return value

TRUE if the function succeeds; otherwise, FALSE. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)