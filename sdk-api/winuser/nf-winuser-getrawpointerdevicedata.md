# GetRawPointerDeviceData function

## Description

Gets the raw input data from the pointer device.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve information.

### `historyCount` [in]

The pointer history.

### `propertiesCount` [in]

Number of properties to retrieve.

### `pProperties` [in]

Array of [POINTER_DEVICE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_device_property) structures that contain raw data reported by the device.

### `pValues` [out]

The values for *pProperties*.

## Return value

TRUE if the function succeeds; otherwise, FALSE. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/functions)