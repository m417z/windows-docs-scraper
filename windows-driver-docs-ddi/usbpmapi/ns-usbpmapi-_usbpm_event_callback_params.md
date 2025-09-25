# _USBPM_EVENT_CALLBACK_PARAMS structure

## Description

Contains the details of the events related to changes in policy manager arrival/removal, hub arrival/removal or connector state change. This structure is used in the [**EVT_USBPM_EVENT_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nc-usbpmapi-evt_usbpm_event_callback) callback function.

## Members

### `EventType`

A [**USBPM_EVENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ne-usbpmapi-_usbpm_event_type)-type value that indicates the type of event.

### `EventData`

A union that contains the event-specific data. The client driver should set the event data in the inner structure related to the event.

### `EventData.PolicyManagerArrival`

Data about the Policy Manager arrival event.

### `EventData.PolicyManagerArrival.AccessGranted`

### `EventData.HubArrivalRemoval`

Data about the hub arrival or removal event.

### `EventData.HubArrivalRemoval.HubHandle`

The handle to the connector hub.

### `EventData.ConnectorStateChange`

Data about the connector state change event.

### `EventData.ConnectorStateChange.ConnectorHandle`

The handle to the connector.

### `Context`

The context which is provided by the client driver in a previous call to [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

## Remarks

## See also