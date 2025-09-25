# WsWriteStartAttribute function

## Description

This operation starts writing an attribute to the current element.
[WsWriteStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartelement) must be called before an attribute can be written.
After the attribute has been started, the attribute value can be written
using [WsWriteChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritechars), [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes), or [WsWriteValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritevalue). The attribute must
be completed using [WsWriteEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendattribute).

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the attribute is written. The pointer must reference a valid **XML Writer** object.

### `prefix` [in, optional]

A WS_XML_STRING pointer to the prefix to use for the attribute. If the value referenced by this parameter is **NULL** the Writer will choose a attribute.

### `localName` [in]

A WS_XML_STRING pointer to the local name used by the attribute. It must be at least one character long.

### `ns` [in]

A WS_XML_STRING pointer to the namespace to be used for the attribute.
If no prefix is specified the Writer may use a prefix in scope that is bound to the specified namespace or it may generate a prefix and include an XMLNS attribute.

If a prefix is specified the Writer will use that prefix and may include an XMLNS attribute if needed to override an existing prefix in scope.

### `singleQuote` [in]

Determines whether to use a single or a double quote for the attribute value.

**Note** With [WS_XML_WRITER_BINARY_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_binary_encoding) the quote character is not preserved and this parameter has no effect.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

If a **NULL** prefix is specified the writer will choose a prefix for the namespace.

To write an "xml:lang" or "xml:space" attribute, specify "xml" for the prefix, "lang" or "space" for the localName,
and "http://www.w3.org/XML/1998/namespace" for the namespace.

If writing the attribute causes [WS_XML_WRITER_PROPERTY_MAX_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id) to be exceeded
then **WS_E_QUOTA_EXCEEDED** is returned.

If a non-empty prefix is specified with an empty namespace **WS_E_INVALID_FORMAT** is returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)