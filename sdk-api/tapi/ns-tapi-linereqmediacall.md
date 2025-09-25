# LINEREQMEDIACALL structure

## Description

The
**LINEREQMEDIACALL** structure describes a request initiated by a call to the
[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest) function. This data structure is obsolete and should not be used.

## Members

### `hWnd`

A handle to the window of the application that made the request.

### `wRequestID`

The identifier of the request. Used to match an asynchronous response.

### `szDeviceClass`

The device class required to fill the request.

### `ucDeviceID`

The device identifier.

### `dwSize`

Size, in bytes, of this structure.

### `dwSecure`

Not used.

### `szDestAddress`

The destination address.

### `szAppName`

The name of application that made the request.

### `szCalledParty`

The called party name.

### `szComment`

The comment buffer.

## See also

[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest)