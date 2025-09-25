# WsWriteBytes function

## Description

Writes bytes to the writer in a format optimized for the encoding. When writing
in a text encoding, it will emit the bytes encoded in base64. When writing to
a binary format, it will emit the bytes directly.

## Parameters

### `writer` [in]

The writer to which the bytes will be written.

### `bytes`

The bytes to write to the document.

### `byteCount` [in]

The number bytes to write to the document.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

**WsWriteBytes** may be called more than once between [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) and [WsWriteEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendattribute). It may
not be combined with [WsWriteChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritechars), [WsWriteCharsUtf8](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritecharsutf8), [WsWriteValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritevalue) or [WsWriteText](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritetext) when writing an attribute.

For the [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding), if the byteCount exceeds the maxInlineByteCount specified
during [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) then the bytes will be buffered and placed in their own MIME part. Otherwise
the bytes are encoded in base64 and placed directly in the document.

For the [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding), if the element containing the bytes has an attribute with
the name 'contentType' and the namespace 'http://www.w3.org/2004/11/xmlmime', then the value of the attribute
will be reflected in the content type header for the MIME part as described in
XML-binary Optimized Packaging.