# _UCX_ENDPOINT_ISOCH_TRANSFER_PATH_DELAYS structure

## Description

Stores the isochronous transfer path delay values.

## Members

### `MaximumSendPathDelayInMilliSeconds`

The maximum delay in milliseconds from the time the client driver's isochronous transfer is received by the USB driver stack to the time the transfer is programmed in the host controller. The host controller could either be a local host (as in case of wired USB) or it could be a remote controller as in case of Media-Agnostic USB (MA-USB). In case of MA-USB, it includes the maximum delay associated with the network medium.

### `MaximumCompletionPathDelayInMilliSeconds`

The maximum delay in milliseconds from the time an isochronous transfer is completed by the (local or remote) host controller to the time the corresponding client driver's request is completed by the USB driver stack. For MA-USB, it includes the maximum delay associated with the network medium.

## See also

[EVT_UCX_ENDPOINT_GET_ISOCH_TRANSFER_PATH_DELAYS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_get_isoch_transfer_path_delays)