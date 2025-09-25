# _UCXUSBDEVICE_INFO structure

## Description

Contains information about the USB device. This structure is passed by UCX in the [EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add) event callback function.

## Members

### `Size`

The size in bytes of this structure.

### `DeviceSpeed`

Defines the device speed of the USB device or hub.

### `TtHub`

A handle to the USB device object that represents the TT hub.

### `PortPath`

The port path for the USB device or hub.

## See also

[EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add)