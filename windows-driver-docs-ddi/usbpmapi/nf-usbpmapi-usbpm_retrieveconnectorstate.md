# UsbPm_RetrieveConnectorState function

## Description

Retrieves the current state of a connector. Unlike connector properties, state information is dynamic, which can change at runtime.

## Parameters

### `ClientHandle` [In]

The handle that the client driver received in a previous call to [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

### `ConnectorHandle` [In]

The connector handle provided by Policy Manager when it calls the driver's implementation of [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback). The handle is set in the **EventData.ConnectorStateChange.ConnectorHandle** member of the _Params_ value.

### `ConnectorState` [Out]

A pointer to a driver-provided [**USBPM_CONNECTOR_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_connector_state) structure that receives the connector state. Initialize the structure by calling [**USBPM_CONNECTOR_STATE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_connector_state_init).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

## See also

[**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)

[**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback)