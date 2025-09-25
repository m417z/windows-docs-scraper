# EVT_UDECX_USB_ENDPOINT_PURGE callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to stop queuing I/O requests to the endpoint's queue and cancel unprocessed requests.

## Parameters

### `UdecxUsbEndpoint` [in]

A handle to a UDE endpoint object that represents the endpoint for which I/O requests must be canceled. The client driver retrieved this pointer in the previous call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate).

## Remarks

The client driver registered this callback function in a previous call to [UdecxUsbEndpointInitSetCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointinitsetcallbacks) by supplying a function pointer to its implementation.

In the implementation, the client driver is required to ensure all I/O forwarded from the endpoint’s queue has been completed, and that newly forwarded I/O request fail, until UdeCx invokes [EVT_UDECX_USB_ENDPOINT_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_start). Typically, those tasks are achieved by calling [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge). This call is asynchronous and the client river must call [UdecxUsbEndpointPurgeComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointpurgecomplete).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)