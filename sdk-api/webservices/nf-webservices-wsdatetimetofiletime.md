# WsDateTimeToFileTime function

## Description

Converts a [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) object into a FILETIME object.
A reference to the FILETIME object is returned by output parameter.

## Parameters

### `dateTime` [in]

A pointer to the [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) structure to convert.

### `fileTime` [out]

A pointer to the new FILETIME object that contains the converted time.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

A FILETIME cannot represent dates between January 1, 0001 and January 1, 1601. A [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) within this range causes the function to return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)