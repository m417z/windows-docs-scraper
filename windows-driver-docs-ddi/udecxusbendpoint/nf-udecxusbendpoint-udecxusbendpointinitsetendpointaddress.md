# UdecxUsbEndpointInitSetEndpointAddress function

## Description

Sets the address of the endpoint in the initialization parameters of the simple endpoint to create.

## Parameters

### `Init` [in, out]

A pointer to an **UDECXUSBENDPOINT_INIT** structure that the client driver retrieved in the previous call to [UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate).

### `EndpointAddress` [in]

Specifies the USB-defined endpoint address. The four low-order bits specify the endpoint number. The high-order bit specifies the direction of data flow on this endpoint: 1 for in, 0 for out.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)