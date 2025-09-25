# POINTER_DEVICE_INFO structure

## Description

Contains information about a pointer device. An array of these structures is returned from the [GetPointerDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerdevices) function. A single structure is returned from a call to the [GetPointerDevice](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerdevice) function.

## Members

### `displayOrientation`

 One of the values from [DISPLAYCONFIG_ROTATION](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_rotation), which identifies the orientation of the input digitizer.

**Note** This value is 0 when the source of input is [Touch Injection](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/touch-injection-portal).

### `device`

The handle to the pointer device.

### `pointerDeviceType`

The device type.

### `monitor`

The HMONITOR for the display that the device is mapped to. This is not necessarily the monitor that the pointer device is physically connected to.

### `startingCursorId`

The lowest ID that's assigned to the device.

### `maxActiveContacts`

The number of supported simultaneous contacts.

### `productString`

The string that identifies the product.

## See also

[Structures](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/structures)