# _DEFAULT_ENDPOINT_UPDATE structure

## Description

Contains the handle to the default endpoint to update in a framework request that is passed by UCX when it invokes [EVT_UCX_DEFAULT_ENDPOINT_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_default_endpoint_update) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains header information related to the USB device or hub endpoint.

### `DefaultEndpoint`

A handle to the default endpoint to update.

### `MaxPacketSize`

The maximum packet size of the default endpoint.

## See also

[EVT_UCX_DEFAULT_ENDPOINT_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_default_endpoint_update)