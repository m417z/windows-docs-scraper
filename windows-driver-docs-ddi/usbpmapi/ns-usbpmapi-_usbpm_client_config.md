# _USBPM_CLIENT_CONFIG structure

## Description

The configuration structure used in the registering the client driver with the Policy Manager. This structure is used in the [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register) call.

## Members

### `Version`

Version of this structure.

### `AccessDesired`

A bitwise-OR of the [**USBPM_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ne-usbpmapi-_usbpm_access_type) values.

### `EventCallback`

A pointer to the client driver's implementation of the [**USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback) callback function.

### `Context`

A driver-defined context structure.

### `ExtraInfo`

A pointer to a USBPM_CLIENT_CONFIG_EXTRA_INFO structure that contains additional information, such as the WDM device object associated with the client driver.

## Remarks

## See also

[**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)