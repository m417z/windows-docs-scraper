# UsbPm_AssignConnectorPowerLevel function

## Description

Attempts a PD contract renegotiation with the specified voltage/current/power value.

## Parameters

### `ClientHandle` [In]

The handle that the client driver received in a previous call to [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

### `ConnectorHandle` [In]

The connector handle provided by Policy Manager when it calls the driver's implementation of [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback). The handle is set in the **EventData.ConnectorStateChange.ConnectorHandle** member of the _Params_ value.

### `Params` [In]

A pointer to a driver-provided [**USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_assign_connector_power_level_params) structure that contains the voltage/current/power value to negotiate. Initialize the structure by calling [**USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_assign_connector_power_level_params_init).

Specifying 0 as the voltage/current/power value for a connector in power sink role causes the connector to stop charging.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

The negotiated settings are persistent only as long as the port partner is attached, and is discarded when the port partner is detached. The client driver is required to call this function based on the current connector state, without assuming the previous setting.

If this call succeeds, the request has been accepted but PD contract renegotiation might not be complete. The result of PD contract renegotiation can be either success or failure.

As a result of successful PD contract renegotiation, **EVT_USBPM_EVENT_CALLBACK** is invoked with a connector state change event. If PD contract renegotiation request fails, the callback function is not invoked. For example, the request gets rejected by the partner, or is no longer valid because the connector state has changed.
In Windows 10, version 1809, the driver can only call this function with the power role of UsbCPowerRoleSink and when a partner is attached to the connector.

## See also

[**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)

[**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback)