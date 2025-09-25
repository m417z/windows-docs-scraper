# WsReadEndAttribute function

## Description

Moves the reader back to the element node containing the attribute that was read.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** that reads the **End attribute**.
The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

[WsReadStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartattribute) must have been called in order to use this API.