## Description

The **GNSS_EVENT** structure defines the information required for a GNSS event.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `EventType`

Event type.

Depending on the event type, a specific data element of the union will be filled.

### `EventDataSize`

The size of the event data union contained in this event.

The GNSS driver must fill in appropriate size to avoid excessive data-copy between the layers. The GNSS adapter will access only the initial bytes of the event data, as specified by this element.

### `Unused`

Padding buffer reserved fore future use.

### `FixData`

This structure is filled if EventType is GNSS_Fix_Available.

### `AgnssRequest`

This structure is filled if EventType is GNSS_Require_Agnss.

### `NiRequest`

This structure is filled if EventType is GNSS_Event_Ni.

### `ErrorInformation`

This structure is filled if EventType is GNSS_Error.

### `NmeaData`

This structure is filled if EventType is GNSS_Event_NmeaData.

### `GeofenceAlertData`

This structure is filled if EventType is GNSS_Event_GeofenceAlertData.

### `BreadcrumbAlertData`

This structure contains alert information for when the breadcrumb buffer has reached a level where OS read operations should be performed.

### `GeofencesTrackingStatus`

This structure is filled if EventType is GNSS_Event_GeofencesTrackingStatus.

### `DriverRequestData`

This structure is filled if EventType is GNSS_Event_DriverRequest.

### `CustomData`

Custom data field.

## Remarks

The GNSS driver sends solicited and unsolicited notifications to the GNSS adapter. This is done through a common event protocol between the driver and the GNSS adapter. The adapter registers for one or more types of events and this ensures that one or more I/O requests are always pending for the driver to send the notification up to the adapter. The driver completes the I/O request on the pending IRP and this causes the notification to flow up to the adapter. The adapter creates one or more I/O requests to listen for further notifications.

 It is recommended (but not required) that the driver uses separate queues for managing different types of event. Separation of queues allows the driver to process certain types of events in parallel.

The notification model allows for adding custom or vendor-specific events in the future that can optionally be processed by a custom GNSS helper component. The GNSS adapter can act as a broker between the driver and the helper component and ensures that the commands and data are marshaled between these two components back and forth.

Each event type has associate event-specific data that the GNSS adapter uses to determine how to process the specific event. For example, for assistance requirements (AGNSS), the adapter injects the needed assistance data. For data-retrieval type event, the adapter processes and sends the data to an upper layer. Subsequently the adapter re-registers for same event with the driver through well-defined IOCTLs. All events follow the same overall data-structure.

Events can be of various types. Certain events occur as a result of a previous request initiated by the driver (for example, a start fix request). Certain events are raised for informational purpose. Assistance events are raised when the driver requires the adapter to inject specific assistance data.