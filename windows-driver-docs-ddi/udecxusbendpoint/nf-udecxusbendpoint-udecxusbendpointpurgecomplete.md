# UdecxUsbEndpointPurgeComplete function

## Description

Completes an asynchronous request for canceling all I/O requests queued to the specified endpoint.

## Parameters

### `UdecxUsbEndpoint` [in]

A handle to a UDE endpoint object. The client driver retrieved this pointer in the previous call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_purge)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)