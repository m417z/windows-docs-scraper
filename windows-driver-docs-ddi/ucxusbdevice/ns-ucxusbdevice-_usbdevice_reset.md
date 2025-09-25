# _USBDEVICE_RESET structure

## Description

Contains parameters for a request to reset the specified device. This structure is passed by UCX in request parameters (**Parameters.Others.Arg1**) of a framework request object of the [EVT_UCX_USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_reset) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `DefaultEndpoint`

The default endpoint for the USB hub or device.

### `EndpointsToDisableCount`

The number of endpoints to disable.

### `EndpointsToDisable`

A pointer to an array of handles to endpoints to disable.

## See also

[EVT_UCX_USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_reset)