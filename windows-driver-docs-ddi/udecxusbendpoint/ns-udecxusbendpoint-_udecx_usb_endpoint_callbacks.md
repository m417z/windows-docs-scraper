# _UDECX_USB_ENDPOINT_CALLBACKS structure

## Description

Contains function pointers to endpoint callback functions implemented by the UDE client driver. Initialize this structure by calling [UDECX_USB_ENDPOINT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecx_usb_endpoint_callbacks_init).

## Members

### `Size`

The size of this structure.

### `EvtUsbEndpointReset`

Required. A pointer to an [EVT_UDECX_USB_ENDPOINT_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_reset) callback function implemented by a UDE client driver.

### `EvtUsbEndpointStart`

Optional. A pointer to an [EVT_UDECX_USB_ENDPOINT_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_start) callback function implemented by a UDE client driver.

### `EvtUsbEndpointPurge`

Optional. A pointer to an [EVT_UDECX_USB_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nc-udecxusbendpoint-evt_udecx_usb_endpoint_purge) callback function implemented by a UDE client driver.

## See also

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[UdecxUsbEndpointInitSetCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointinitsetcallbacks)