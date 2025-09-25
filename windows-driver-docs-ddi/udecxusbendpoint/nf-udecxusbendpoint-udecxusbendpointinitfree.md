# UdecxUsbEndpointInitFree function

## Description

Release the resources that were allocated by the [UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate) call.

## Parameters

### `Init` [in]

A pointer to an **UDECXUSBENDPOINT_INIT** structure that the client driver retrieved in the previous call to [UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)