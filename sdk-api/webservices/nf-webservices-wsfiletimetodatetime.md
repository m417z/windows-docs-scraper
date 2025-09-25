# WsFileTimeToDateTime function

## Description

Takes a reference to a FILETIME object and converts it into a [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) object.
A reference to the WS_DATETIME object is returned by output parameter.

## Parameters

### `fileTime` [in]

A pointer to the FILETIME structure to convert.

### `dateTime` [out]

A pointer to the new WS_DATETIME object that has the newly converted time.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

A [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) cannot represent dates from the year 10000 and beyond. A FILETIME representing a date
later than this will cause the function return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

The format field of the [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime) will be set to [WS_DATETIME_FORMAT_UTC](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_datetime_format).