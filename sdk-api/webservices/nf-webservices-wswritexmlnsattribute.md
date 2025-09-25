# WsWriteXmlnsAttribute function

## Description

Writes an Xmlns attribute to the current element.
[WsWriteStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartelement) must be called before an attribute can be written and if the number of attributes exceeds the maximum number of attributes permitted for the writer the function returns **WS_E_QUOTA_EXCEEDED**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the Xmlns attribute is written. The pointer must reference a valid **XML Writer** object.

### `prefix` [in, optional]

A WS_XML_STRING pointer to the prefix to use for the start element. If the value referenced by this parameter is **NULL** the Writer will choose a attribute.

Specifies the prefix to use for the xmlns attribute.

### `ns` [in]

A WS_XML_STRING pointer to the namespace to bind to the prefix.

### `singleQuote` [in]

Determines whether to use a single or a double quote for the attribute value.

**Note** If [WS_XML_WRITER_BINARY_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_binary_encoding) is set the quotation character is not preserved and this
parameter has have no effect.

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

The following conditions apply:

* If an empty prefix is specified then the default namespace is assigned.
* If a **NULL** prefix is specified then the Writer chooses the appropriate prefix for the namespace.
* If the Xmlns attribute is redundant it cannot be written.
* If a non-empty prefix is specified with an empty namespace **WS_E_INVALID_FORMAT** is returned.