# _USBPM_EVENT_TYPE enumeration

## Description

Defines values for types of events. This enumeration is used in the [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback) callback function.

## Constants

### `UsbPmEventPolicyManagerArrival`

The Policy Manager has arrived. This is the first callback event after client registration.

### `UsbPmEventPolicyManagerRemoval`

 The Policy Manager has left.

### `UsbPmEventHubArrival`

A new connector hub has arrived.

### `UsbPmEventHubRemoval`

A connector hub has been removed.

### `UsbPmEventConnectorStateChange`

 The connector state has changed.

## Remarks

## See also

[**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback)

[**USBPM_EVENT_CALLBACK_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_event_callback_params)