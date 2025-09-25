# EVT_UDECX_USB_ENDPOINT_START callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to start processing I/O requests on the specified endpoint of the virtual USB device.

## Parameters

### `UdecxUsbEndpoint` [in]

A handle to a UDE endpoint object that represents the endpoint which can start receiving I/O requests. The client driver retrieved this pointer in the previous call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate).

## Remarks

The client driver registered this callback function in a previous call to [UdecxUsbEndpointInitSetCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointinitsetcallbacks) by supplying a function pointer to its implementation.

After the client driver creates an endpoint, it does not automatically start receiving I/O requests. When UdeCx is ready to forward those request for processing, it invokes the client driver's *EVT_UDECX_USB_ENDPOINT_START* function and the client driver can begin processing I/O on the endpoint’s queue, and on any queues that receive forwarded I/O for the endpoint. This callback returns the endpoint to a state of processing I/O after an [EVT_UDECX_USB_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_purge) callback has and completed.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_purge)

[Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)