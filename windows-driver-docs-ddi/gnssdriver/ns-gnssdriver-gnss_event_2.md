## Description

The **GNSS_EVENT_2** structure defines the information required for a GNSS event.

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

Unused.

### `FixData`

This structure is filled if EventType is GNSS_Fix_Available.

### `FixData2`

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

## See also