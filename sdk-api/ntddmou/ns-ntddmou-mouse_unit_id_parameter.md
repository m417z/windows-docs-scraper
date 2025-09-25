# MOUSE_UNIT_ID_PARAMETER structure

## Description

MOUSE_UNIT_ID_PARAMETER specifies a unit ID that Mouclass assigns to a mouse.

## Members

### `UnitId`

Specifies the unit number of the mouse device. A mouse [device name](https://learn.microsoft.com/windows-hardware/drivers/kernel/nt-device-names) has the format \Device\PointerPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\PointerPort0, has a unit number of zero, and a device, whose name is \Device\PointerPort1, has a unit number of one.

## Remarks

Although this structure is used with an [IOCTL_MOUSE_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ni-ntddmou-ioctl_mouse_query_attributes) request, Mouclass does not use the **UnitId** value.

## See also

[IOCTL_MOUSE_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ni-ntddmou-ioctl_mouse_query_attributes)