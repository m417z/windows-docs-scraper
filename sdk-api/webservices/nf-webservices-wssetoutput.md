# WsSetOutput function

## Description

Sets the encoding and output callbacks for the writer. The callbacks are used to
provides buffers to the writer and to perform asynchronous i/o.

## Parameters

### `writer` [in]

The writer for which the output will be set.

### `encoding` [in, optional]

The encoding describes the format of the input bytes. This should be one of [WS_XML_WRITER_TEXT_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_text_encoding),
[WS_XML_WRITER_BINARY_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_binary_encoding) or [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding).

### `output` [in, optional]

Specifies where the writer should place its data.

### `properties`

An array of optional properties of the writer. See [WS_XML_WRITER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_property).

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

When **WsSetOutput** is used on the writer, the writer will function in a forward only manner and
the functions [WsGetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterposition), [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition) and [WsMoveWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovewriter) cannot be used.

If [encoding](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_encoding) is **NULL**, then [WS_XML_WRITER_OUTPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_output) is ignored and the writer is set up so that any attempt to write to it will fail.

If [encoding](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_encoding) is not **NULL**, then [WS_XML_WRITER_OUTPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_output) must be non-**NULL** as well.

If [WS_XML_WRITER_OUTPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_buffer_output) is [WS_XML_WRITER_BUFFER_OUTPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_buffer_output) then the writer will buffer the generated
bytes of the document. Use [WsGetWriterProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterproperty) with [WS_XML_WRITER_PROPERTY_BUFFERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id) or
**WS_XML_WRITER_PROPERTY_BYTES** to obtain these bytes. In this mode [WsFlushWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushwriter) has no effect.

If [WS_XML_WRITER_OUTPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_stream_output) is [WS_XML_WRITER_STREAM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_stream_output) then the writer will pass the generated
bytes of the document to the specified [WS_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback) during calls to [WsFlushWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushwriter).

The writer will be initialized to use the properties specified in [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter). Any properties
specified to **WsSetOutput** will override those properties.

See [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter) for the default values of the properties of the writer.