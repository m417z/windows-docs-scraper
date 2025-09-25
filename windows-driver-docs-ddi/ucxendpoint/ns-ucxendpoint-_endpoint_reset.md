# _ENDPOINT_RESET structure

## Description

Describes information required to reset an endpoint. This structure is passed by UCX in the [EVT_UCX_ENDPOINT_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_reset) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that stores handles to the USB hub or device whose endpoints.

### `Endpoint`

A handle to the device endpoint to reset.

### `Flags`

A [ENDPOINT_RESET_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ne-ucxendpoint-_endpoint_reset_flags) value that indicates reset parameters.

## See also

[ENDPOINT_RESET_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ne-ucxendpoint-_endpoint_reset_flags)