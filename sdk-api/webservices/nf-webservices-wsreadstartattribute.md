# WsReadStartAttribute function

## Description

Moves the Reader to the specified attribute so that the content may be read using [WsReadValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadvalue), [WsReadChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadchars), or [WsReadBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbytes).
If the reader is not positioned on a start element then it returns a **WS_E_INVALID_FORMAT** exception.

(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

**Note** Attributes read do not appear in any particular order. [WsFindAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfindattribute) can be used to locate the index of a particular attribute.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** object used to read the Start attribute.

### `attributeIndex` [in]

The index of the attribute to read.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

The [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode) function returns EOF when advanced within an attribute. The [WsReadEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadendattribute) function can be used
to return the reader to the containing element.