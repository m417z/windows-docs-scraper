# UdecxUsbEndpointSetWdfIoQueue function

## Description

Sets a framework queue object with a UDE endpoint.

## Parameters

### `UdecxUsbEndpoint` [in]

A handle to a UDE endpoint object. The client driver retrieved this pointer in the previous call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate).

### `WdfQueue` [in]

A handle to a framework queue object that will handle requests sent to the endpoint. The client driver retrieved this pointer in the previous call to [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)