# WsWriteValue function

## Description

This operation derives the best representation for a primitive value from the underlying encoding and passes the derived value to a Writer object.

**Note** It is generally more efficient to use this function to write out primitive values rather than converting
the value to text and subsequently using [WsWriteChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritechars).

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the value is written. The pointer must reference a valid **XML Writer** object.

### `valueType` [in]

Indicates the Type of primitive value referenced by the *value* parameter.

I

### `value`

A void pointer to the primitive value.

### `valueSize` [in]

The size in bytes of the value being written.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

**WsWriteValue** may be called only once between [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) and [WsWriteEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendattribute).
It may not be combined with [WsWriteChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritechars), [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes), [WsWriteCharsUtf8](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritecharsutf8) or [WsWriteText](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritetext) when writing an attribute.