# EVT_UCX_ROOTHUB_INTERRUPT_TX callback function

## Description

The client driver's implementation that UCX calls when it receives a request for information about changed ports.

## Parameters

### `UcxRootHub` [in]

A handle to a UCX object that represents the root hub.

### `Request` [in]

Contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the root hub interrupt transfer request.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
method.

 The *Request* parameter contains a buffer in which each bit corresponds to a root
hub port, with the first bit corresponding to the first port. The
client driver sets the corresponding bit if any port has changed, and then completes the request.

The client driver returns completion status in *Request*.

#### Examples

This snippet shows how the callback extracts the root hub interrupt transfer request.

```
        WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
        WdfRequestGetParameters(WdfRequest, &wdfRequestParams);

        urb = (PURB)wdfRequestParams.Parameters.Others.Arg1;
        transferBuffer = urb->UrbBulkOrInterruptTransfer.TransferBuffer;
        transferBufferLength = urb->UrbBulkOrInterruptTransfer.TransferBufferLength;

```