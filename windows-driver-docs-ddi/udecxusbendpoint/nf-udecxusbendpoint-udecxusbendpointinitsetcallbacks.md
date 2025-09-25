# UdecxUsbEndpointInitSetCallbacks function

## Description

Sets pointers to UDE client driver-implemented callback functions in the initialization parameters of the simple endpoint to create.

## Parameters

### `UdecxUsbEndpointInit`

A pointer to an **UDECXUSBENDPOINT_INIT** structure that the client driver retrieved in the previous call to [**UdecxUsbSimpleEndpointInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate).

### `EndpointCallbacks` [in]

A pointer to [UDECX_USB_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/ns-udecxusbendpoint-_udecx_usb_endpoint_callbacks) that contains function pointers to event callback functions implemented by the UDE client driver.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)