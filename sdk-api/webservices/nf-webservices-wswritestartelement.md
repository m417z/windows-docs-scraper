# WsWriteStartElement function

## Description

Writes a start element to the writer.

After calling this function [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) or [WsWriteXmlnsAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritexmlnsattribute) can be called to write additional attributes to the element. The element is not committed to the writer until [WsWriteEndElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendelement) or some other function that writes content is called.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the start element is written. The pointer must reference a valid **XML Writer** object.

### `prefix` [in, optional]

A WS_XML_STRING pointer to the prefix to use for the start element. If the value referenced by this parameter is **NULL** the Writer will choose a attribute.

### `localName` [in]

A WS_XML_STRING pointer to the local name used by the start element. It must be at least one character long.

### `ns` [in]

A WS_XML_STRING pointer to the namespace to be used for the start element.
If no prefix is specified the Writer may use a prefix in scope that is bound to the specified namespace or it may generate a prefix and include an XMLNS attribute. If a prefix is specified the Writer will use that prefix and may include an XMLNS attribute if needed to override an existing prefix in scope.

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

If the underlying encoding supports empty elements and the element has no content an empty element is written.

If a non-empty prefix is specified with an empty namespace **WS_E_INVALID_FORMAT** is returned.

If writing the start element causes **WS_XML_WRITER_PROPERTY_MAX_DEPTH** to be exceeded
**WS_E_QUOTA_EXCEEDED** is returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

When using [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding) it is an error to attempt to write an element with the
localName "Include" from the namespace"http://www.w3.org/2004/08/xop/include".

[WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) can also be used to add an attribute to an element when the writer is
positioned on an element using [WsMoveWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovewriter) or [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition).