## Description

The **GNSS_SUPL_NI_INFO** structure contains the requested SUPL NI information.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `RequestorId`

Requestor ID.

This will be displayed on the notification dialog to the user. The GNSS driver must provide a UNICODE string that is decoded per the encoding scheme required by the mobile operator.

### `ClientName`

Name of the client that requests the location of the device.

This will be displayed on the notification dialog to the user. The GNSS driver must provide a UNICODE string that is decoded per the encoding scheme required by the mobile operator.

### `SuplNiUrl`

NI URL information.