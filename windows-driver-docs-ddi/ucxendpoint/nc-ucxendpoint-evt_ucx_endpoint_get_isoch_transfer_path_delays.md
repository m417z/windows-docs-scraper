# EVT_UCX_ENDPOINT_GET_ISOCH_TRANSFER_PATH_DELAYS callback function

## Description

UCX invokes this callback function to get information about transfer path delays for an isochronous endpoint.

## Parameters

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the isochronous endpoint for which the client driver receives the transfer path delays.

### `UcxEndpointTransferPathDelays` [in, out]

A pointer to a [UCX_ENDPOINT_ISOCH_TRANSFER_PATH_DELAYS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_endpoint_isoch_transfer_path_delays) structure that contains transfer path delay values.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

## See also

- [USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)
- [_URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_isoch_pipe_transfer_path_delays)