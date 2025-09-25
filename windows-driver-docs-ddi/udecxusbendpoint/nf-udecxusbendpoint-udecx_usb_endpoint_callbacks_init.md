# UDECX_USB_ENDPOINT_CALLBACKS_INIT function

## Description

Initializes a [UDECX_USB_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/ns-udecxusbendpoint-_udecx_usb_endpoint_callbacks) structure before a [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate) call.

## Parameters

### `Callbacks` [out]

A pointer to a [UDECX_USB_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/ns-udecxusbendpoint-_udecx_usb_endpoint_callbacks) to initialize.

### `EvtUsbEndpointReset`

Pointer to an [EVT_UDECX_USB_ENDPOINT_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_reset) callback function.

## See also

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)