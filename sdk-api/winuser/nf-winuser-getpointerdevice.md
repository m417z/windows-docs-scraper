# GetPointerDevice function

## Description

Gets information about the pointer device.

## Parameters

### `device` [in]

The handle to the device.

### `pointerDevice` [out]

A [POINTER_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_info) structure that contains information about the pointer device.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)