# WS_XML_READER_PROPERTY_ID enumeration

## Description

Identifies each XML reader property is and its associated
value. This enumeration is used within the [WS_XML_READER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_property) structure, which is used as a parameter to [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader), [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput), [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer), and [WsReadXmlBufferFromBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadxmlbufferfrombytes). It is also used directly as a parameter to [WsGetReaderProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderproperty).

## Constants

### `WS_XML_READER_PROPERTY_MAX_DEPTH:0`

A **ULONG** that specifies the maximum depth of the document that the reader will permit.

Depth is measured at any point by the number of nested start elements.

A depth of 0 prevents any start elements from being read.

This property defaults to 32.

See [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader) for security considerations.

### `WS_XML_READER_PROPERTY_ALLOW_FRAGMENT:1`

A **BOOL** that
specifies whether the reader will permit multiple elements and non-white space at the top level of the document. This property
may not be set to **TRUE** with [WS_XML_READER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding).

This property defaults to **FALSE**.

### `WS_XML_READER_PROPERTY_MAX_ATTRIBUTES:2`

A **ULONG** that specifies the maximum number of attributes the reader will permit on an element.

This property defaults to 128.

See [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader) for security considerations.

### `WS_XML_READER_PROPERTY_READ_DECLARATION:3`

A **BOOL** that specifies if the reader should permit an xml declaration at the start of the document.

This property defaults to **TRUE**.

### `WS_XML_READER_PROPERTY_CHARSET:4`

A [WS_CHARSET](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_charset) value that returns the character set of the xml document. This value is only available for
text documents.

If the reader was initialized with a [WS_CHARSET_AUTO](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_charset) then it will automatically determine this
value. The reader input source is streamed, then the reader must have enough data buffered to be able to
inspect initial byte order marks and the xml declaration. See [WsFillReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillreader).

If the reader was initialized with any other value, then this property simply returns that value.

### `WS_XML_READER_PROPERTY_ROW:5`

A **ULONGLONG** that returns the 0 based row number of the node the reader is positioned on for text xml documents.

### `WS_XML_READER_PROPERTY_COLUMN:6`

A **ULONGLONG** that returns the 0 based column number of the node the reader is positioned on for text xml documents.

### `WS_XML_READER_PROPERTY_UTF8_TRIM_SIZE:7`

A **ULONG** that specifies the trim size of the internal buffer used by the
[WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) for performing UTF-16 to UTF-8 conversions. Increasing this value
uses more memory, but can reduce allocations when processing UTF-16 encoded documents.

This property defaults to 4096.

### `WS_XML_READER_PROPERTY_STREAM_BUFFER_SIZE:8`

A **ULONG** that specifies the size of the buffer the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) will use when configured to use
[WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_stream_input). Increasing this value uses more memory, but
can reduce the number of times the [WS_READ_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_callback) is invoked.

This property defaults to 4096.

### `WS_XML_READER_PROPERTY_IN_ATTRIBUTE:9`

Indicates that [WsReadStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartattribute) has been called and the reader is
positioned on attribute content.

### `WS_XML_READER_PROPERTY_STREAM_MAX_ROOT_MIME_PART_SIZE:10`

A **ULONG** used with [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding) in conjunction with [WS_XML_READER_MTOM_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding).
This value specifies the maximum size of the root MIME part, which is the part that contains
the xml portion of the document. It has no effect when used with other encodings, or when used with
[WS_XML_READER_BUFFER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_buffer_input).

This property defaults to 65536.

### `WS_XML_READER_PROPERTY_STREAM_MAX_MIME_HEADERS_SIZE:11`

A **ULONG** used with [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding) in conjunction with [WS_XML_READER_MTOM_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding).
This value specifies the maximum size of any group of MIME headers that may appear in the document.
It has no effect when used with other encodings, or when used with [WS_XML_READER_BUFFER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_buffer_input).

This property defaults to 256.

### `WS_XML_READER_PROPERTY_MAX_MIME_PARTS:12`

A **ULONG** used with [WS_XML_READER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding). This value specifies the maximum number of MIME parts
that may appear in the document. It has no effect when used with other encodings.

This property defaults to 4096.

### `WS_XML_READER_PROPERTY_ALLOW_INVALID_CHARACTER_REFERENCES:13`

A **BOOL** used with [WS_XML_READER_TEXT_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_text_encoding). Setting this to **TRUE** permits character references
of characters considered invalid by XML 1.0 to be accepted.

Setting this property to **TRUE** may affect interoperability.

This property defaults to **FALSE**.

### `WS_XML_READER_PROPERTY_MAX_NAMESPACES:14`

A **ULONG** that specifies the maximum number of xmlns unique declarations that may appear in scope at any point
while reading the document.

This property defaults to 32.

See [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader) for security considerations.