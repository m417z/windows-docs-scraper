# EVT_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS callback function

## Description

The client driver's implementation that UCX calls to notify the controller driver that it can complete cancelled transfers on the endpoint.

## Parameters

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

Before completing the URB associated with the transfer, the client driver calls [UcxEndpointNeedToCancelTransfers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointneedtocanceltransfers) and then waits for UCX to call this function. Then the client driver can complete the URB with **STATUS_CANCELLED**.

> [!NOTE]
> If GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL capability is supported, the hub driver may send a control transfer to clear the TT (Transaction Translator) buffer before UCX calls this function.