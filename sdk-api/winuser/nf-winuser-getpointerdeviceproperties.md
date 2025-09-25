# GetPointerDeviceProperties function

## Description

Gets device properties that aren't included in the [POINTER_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_info) structure.

## Parameters

### `device` [in]

The pointer device to query properties from.

A call to the [GetPointerDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerdevices) function returns this handle in the [POINTER_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_info) structure.

### `propertyCount` [in, out]

The number of properties.

Returns the count that's written or needed if *pointerProperties* is NULL.

If this value is less than the number of properties that the pointer device supports and *pointerProperties* is not NULL, the function returns the actual number of properties in this variable and fails.

### `pointerProperties` [out, optional]

The array of properties.

## Return value

TRUE if the function succeeds; otherwise, FALSE. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)