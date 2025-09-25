# EVT_UDECX_USB_ENDPOINT_RESET callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to reset an endpoint of the virtual USB device.

## Parameters

### `UdecxUsbEndpoint` [in]

A handle to a UDE endpoint object that represents the endpoint to reset. The client driver retrieved this pointer in the previous call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate).

### `Request` [in]

A handle to a framework request object that represents the request to reset the endpoint.

## Remarks

The client driver registered this callback function in a previous call to [UdecxUsbEndpointInitSetCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointinitsetcallbacks) by supplying a function pointer to its implementation.

The reset request clears the error condition in the endpoint that causes failed I/O transfers. At that time, UdeCx can invoke the *EVT_UDECX_USB_ENDPOINT_RESET* callback function. That call is asynchronous. The client driver completes the request and signals completion with status by calling [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation) method . (this is the only way the UDECX client uses the request parameter).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[How to recover from USB pipe errors](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)