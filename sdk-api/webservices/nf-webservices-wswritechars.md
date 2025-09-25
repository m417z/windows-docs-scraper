# WsWriteChars function

## Description

Writes a series of characters to an element or attribute.
To write characters to an attribute value, call [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) first. Only whitespace characters may be written at the root of an xml document unless the **WS_XML_WRITER_PROPERTY_ALLOW_FRAGMENT** has been set to **TRUE**.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the characters are written. The pointer must reference a valid **XML Writer** object.

### `chars`

A pointer to the characters to write.

### `charCount` [in]

The number of characters to write.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

**WsWriteChars** can be called more than once between [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) and [WsWriteEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendattribute). It cannot be combined with [WsWriteCharsUtf8](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritecharsutf8), [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes), [WsWriteValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritevalue) or [WsWriteText](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritetext) when writing an attribute.