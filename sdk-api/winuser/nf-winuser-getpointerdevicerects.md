# GetPointerDeviceRects function

## Description

Gets the x and y range for the pointer device (in himetric) and the x and y range (current resolution) for the display that the pointer device is mapped to.

## Parameters

### `device` [in]

The handle to the pointer device.

### `pointerDeviceRect` [out]

The structure for retrieving the device's physical range data.

### `displayRect` [out]

The structure for retrieving the display resolution.

## Return value

TRUE if the function succeeds; otherwise, FALSE. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)