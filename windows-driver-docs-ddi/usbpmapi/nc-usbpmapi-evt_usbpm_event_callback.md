# EVT_USBPM_EVENT_CALLBACK callback function

## Description

Sends notifications about hub arrival/removal and connector state changes.

## Parameters

### `Params` [In]

A pointer to the caller-supplied [**USBPM_EVENT_CALLBACK_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_event_callback_params) structure that the client driver fills with event-specific data.

## Prototype

```cpp
//Declaration

EVT_USBPM_EVENT_CALLBACK EvtUsbpmEventCallback;

// Definition

VOID EvtUsbpmEventCallback
(
	PUSBPM_EVENT_CALLBACK_PARAMS Params
)
{...}

```

## Remarks

The client driver registers its implementation of this callback function by setting the appropriate member of [**USBPM_CLIENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config) and then calling [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register). Policy Manager can invoke the client driver's implementation before [**UsbPm_Register**] returns.

To stop Policy Manager from invoking the callback function, the client driver must call [**UsbPm_Deregister**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_deregister).

Callback function calls are serialized. Only one call is active at a time.

## See also

[**USBPM_EVENT_CALLBACK_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_event_callback_params)