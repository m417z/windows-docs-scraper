# GetPointerDevices function

## Description

Gets information about the pointer devices attached to the system.

## Parameters

### `deviceCount` [in, out]

If *pointerDevices* is NULL, *deviceCount* returns the total number of attached pointer devices. Otherwise, *deviceCount* specifies the number of [POINTER_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_info) structures pointed to by *pointerDevices*.

### `pointerDevices` [out, optional]

Array of [POINTER_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_info) structures for the pointer devices attached to the system. If NULL, the total number of attached pointer devices is returned in *deviceCount*.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Windows 8 supports the following:

* 256 contacts per pointer device.
* 2560 total contacts per system session, regardless of the number of attached devices. For example, 10 pointer devices with 256 contacts each, 20 pointer devices with 128 contacts each, and so on.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)