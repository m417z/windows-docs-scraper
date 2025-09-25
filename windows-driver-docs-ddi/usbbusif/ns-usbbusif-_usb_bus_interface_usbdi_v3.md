# _USB_BUS_INTERFACE_USBDI_V3 structure

## Description

The **USB_BUS_INTERFACE_USBDI_V3** structure is provided by the USB hub driver to allow USB clients to make direct calls to the hub driver without allocating IRPs.

## Members

### `Size`

Specifies the size in bytes of the buffer that holds the interface pointers.

### `Version`

Indicates, on input, the version of the interface. The values that this member can take are as follows.

| Value | Meaning |
| --- | --- |
| USB_BUSIF_USBDI_VERSION_0 | Version 0 of the interface. |
| USB_BUSIF_USBDI_VERSION_1 | Version 1 of the interface. |
| USB_BUSIF_USBDI_VERSION_2 | Version 2 of the interface. |
| USB_BUSIF_USBDI_VERSION_3 | Version 3 of the interface. |

### `BusContext`

Contains information that describes the USB bus and the USB bus driver that exposes this interface. This is an opaque entity that the caller must pass to the interface routines.

### `InterfaceReference`

Pointer to a routine that increments the number of references to this interface. For more information about this routine, see [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference).

### `InterfaceDereference`

Pointer to a routine that decrements the number of references to this interface. For more information about this routine, see [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `GetUSBDIVersion`

Pointer to a routine that returns the USB interface version number, the version number of USB specification that defines the interface, along with host controller capabilities information. This routine returns the highest USBDI interface version supported by the port driver. For more information about this routine, see [GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_getusbdi_version).

### `QueryBusTime`

Pointer to a routine that returns the current 32-bit USB frame number. This routine replaces the [USBD_QueryBusTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_querybustime) function provided by usbd.sys. For more information about this routine, see [QueryBusTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_bus_time).

### `SubmitIsoOutUrb`

Reserved. Do not use.

### `QueryBusInformation`

Pointer to a routine that retrieves information about the bus. The information that is returned depends on the value of the **Level** member. If **Level** is 0, this routine returns bus bandwidth information. If **Level** is 1, it returns bus bandwidth information and the host controller's symbolic name. This routine replaces the **USBD_QueryBusInformation** function provided by usbd.sys. For more information about this routine, see [QueryBusInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_bus_information).

### `IsDeviceHighSpeed`

Pointer to a routine that determines if the USB device is operating at high speed. This routine returns **TRUE** if the USB device is operating at high speed USB 2.0 compliant device. Returns **FALSE** otherwise. For more information about this routine, see [IsDeviceHighSpeed](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_is_device_high_speed).

### `EnumLogEntry`

Reserved. Do not use.

### `QueryBusTimeEx`

This routine is not implemented.

### `QueryControllerType`

Pointer to a routine that returns information about the USB host controller the USB device is attached to. For more information about this routine, see [QueryControllerType](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_controller_type).

## Remarks

The **IsDeviceHighSpeed** routine does not indicate whether a device is capable of high-speed operation, but whether it is in fact operating at high speed.

The routines in this structure must be callable at IRQL >= DISPATCH_LEVEL.

## See also

[Bus Driver Interface Routines for USB Client Drivers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540046(v=vs.85))

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)