# _USBDEVICE_ADDRESS structure

## Description

Contains parameters for a request to transition the specified device to the Addressed state. This structure is passed by UCX in request parameters (**Parameters.Others.Arg1**) of a framework request object of the [EVT_UCX_USBDEVICE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_address) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `Reserved`

Do not use.

### `Address`

The address of the specified the USB hub or device.

## See also

[EVT_UCX_USBDEVICE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_address)