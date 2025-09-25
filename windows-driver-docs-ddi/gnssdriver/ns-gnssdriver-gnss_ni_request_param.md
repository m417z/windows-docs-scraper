# GNSS_NI_REQUEST_PARAM structure

## Description

This structure contains the NI request parameters.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `RequestId`

The ID that uniquely identifies the NI request. It is used later by the NI response to identify the request to respond to.

### `RequestType`

A [GNSS_NI_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_ni_request_type) enumeration value that specifies the request type.

### `NotificationType`

A [GNSS_NI_NOTIFICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_ni_notification_type) enumeration value that specifies the notification type.

### `RequestPlaneType`

A [GNSS_NI_PLANE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_ni_plane_type) enumeration value that specifies the plane type.

### `SuplNiInfo`

The [GNSS_SUPL_NI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_supl_ni_info) structure that contains the SUPL NI information.

### `CpNiInfo`

The [GNSS_CP_NI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_cp_ni_info) structure that contains CP NI information.

### `V2UplNiInfo`

V2Upl NI request information.

### `ResponseTimeInSec`

The required response time, in seconds.

### `EmergencyLocation`

Indicates an emergency request, so an existing NI dialog will be dismissed and the new request will be processed immediately.