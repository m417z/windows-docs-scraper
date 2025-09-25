## Description

The **GNSS_CP_NI_INFO** structure contains CP NI information.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `RequestorId`

Requestor ID.

This will be displayed on the notification dialog to the user. The GNSS driver must provide a UNICODE string that is decoded per the encoding scheme required by the mobile operator.

### `NotificationText`

Name of the client that requests the location of the device.

This will be displayed on the notification dialog to the user. The GNSS Driver must provide a UNICODE string that is decoded per the encoding scheme required by the mobile operator.