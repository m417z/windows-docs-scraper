# GNSS_EVENT_TYPE enumeration

## Description

This enumeration indicates the type of an event and is used by the [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

The GNSS driver utilizes events to send solicited and unsolicited information to the GNSS adapter. Events can occur for various reasons, such as a driver request to the GNSS adapter for the injection of assistance data or for informational purposes.

## Constants

### `GNSS_Event_FixAvailable`

This event is raised as a result of a prior [IOCTL_GNSS_GET_FIXDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_get_fixdata) call from the adapter. The GNSS driver raises this event when a fix is available for the adapter to collect. The fix data is included in the event data in form of [GNSS_FIXDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_fixdata) structure.

### `GNSS_Event_RequireAgnss`

This event is raised as a result of a prior [IOCTL_GNSS_LISTEN_AGNSS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_listen_agnss) call from the adapter. The driver raises this event whenever it needs injection of certain AGNSS assistance data. The specifics of the injection are available in the event data in form of [GNSS_AGNSS_REQUEST_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_agnss_request_param) structure.

### `GNSS_Event_Error`

This event is raised as a result of a prior [IOCTL_GNSS_LISTEN_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_listen_error) call from the adapter. The driver raises this event when an out-of-band error occurs that the adapter needs to be aware of. The error details are available in the event data in form of [GNSS_ERRORINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_errorinfo) structure. The information can be used by Microsoft to capture telemetry data about what type of errors are seen in the field by different devices, and the data could be shared with OEMs/IHVs to help understand common issues and increase the quality of GNSS engine implementations.

### `GNSS_Event_NiRequest`

This event is raised when the driver wants to notify an NI request. The HLOS will process the request (for example, display a dialog if requested) then inject a response back to the driver.

### `GNSS_Event_NmeaData`

This event is raised as a result of a prior [IOCTL_GNSS_LISTEN_NMEA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_listen_nmea) call, if NMEA logging is enabled in the device. The GNSS driver raises this event when NMEA data is ready to be read by the calling client. The calling client will typically be a test tool. The NMEA sentences data is included in the event data in form of [GNSS_NMEA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_nmea_data) structure.

### `GNSS_Event_GeofenceAlertData`

A previously created geofence has been breached. At the creation time of the geofence, the HLOS had specifically asked for an alert when such a breach happens. For example, an alert for entry should not be raised if the HLOS has requested only exit alerts.

### `GNSS_Event_GeofencesTrackingStatus`

The GNSS engine is unable to track one or more geofences due to bad signal conditions or other positioning issues. A status is also raised when the GNSS engine has recovered from a previous failure condition and is now able to track all the geofences.

### `GNSS_Event_DriverRequest`

Reserved for future extension.

The GNSS driver is requesting some out-of-band information from the HLOS.

### `GNSS_Event_BreadcrumbAlertEvent`

Reserved for future extension: 0x0012-0x7FFF.

For each new event type, there will be a well-defined IOCTL describing the initiation process of this event by the adapter, and a well-defined event data structure describing the data/command associated with this event.

### `GNSS_Event_FixAvailable_2`

The fix data included in the event data in the [GNSS_FIXDATA_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_fixdata_2) structure.

### `GNSS_Event_Custom`

Reserved for vendor-specific custom actions: 0x8000-0xFFFF.

The GNSS driver raises this event as needed. The command and data are packaged in an opaque blob as part of the event data. The package is sent up to the adapter for marshaling to the GNSS helper component.

## Remarks

Events can be of various types. Certain events occur as a result of a previous request initiated by the driver, for example, start fix request. Certain events are raised for informational purpose. Assistance events are raised when the driver requires the adapter to inject specific assistance data.