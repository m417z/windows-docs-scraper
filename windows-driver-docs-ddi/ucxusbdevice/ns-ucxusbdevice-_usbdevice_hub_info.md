# _USBDEVICE_HUB_INFO structure

## Description

Contains parameters for a request to get information about the specified hub. This structure is passed by UCX in request parameters (**Parameters.Others.Arg1**) of a framework request object of the [EVT_UCX_USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_hub_info) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `NumberOfPorts`

The count of ports available for the USB hub, filled by the client driver.

### `NumberOfTTs`

The count of TT hubs, filled by the client driver.

### `TTThinkTime`

The ThinkTime property of the TT hub, filled by the client driver.

## See also

[EVT_UCX_USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_hub_info)