# USBPM_CLIENT_CONFIG_INIT function

## Description

Initializes a [**USBPM_CLIENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config) structure. The client driver must call this function before calling [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

## Parameters

### `ClientConfig` [Out]

A pointer to a [**USBPM_CLIENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config) to initialize.

### `AccessDesired` [In]

A bitwise-OR of the flags defined by the [**USBPM_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ne-usbpmapi-_usbpm_access_type) enumeration that indicates the type of access the client driver requires.

### `EventCallback` [In]

A pointer to the [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback) callback function implemented by the client driver.

### `ExtraInfo` [In]

A pointer to a [**USBPM_CLIENT_CONFIG_EXTRA_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config_extra_info) structure that contains optional information such as the WDM device object.

## Remarks

## See also