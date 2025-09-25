# UsbPm_RetrieveHubProperties function

## Description

Retrieves the properties of a hub. The properties are static, which do not change during the lifecycle of a hub.

## Parameters

### `ClientHandle` [In]

The handle that the client driver received in a previous call to [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

### `HubHandle` [In]

The hub handle provided by Policy Manager when it calls the driver's implementation of [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback). The handle is set in the **EventData.HubArrivalRemoval.HubHandle** member of the _Params_ value.

### `HubProperties` [Out]

A pointer to a driver-provided [**USBPM_HUB_PROPERTIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_hub_properties) structure that receives the hub properties. Initialize the structure by calling [**USBPM_HUB_PROPERTIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_hub_properties_init).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

## See also

[**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)

[**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback)