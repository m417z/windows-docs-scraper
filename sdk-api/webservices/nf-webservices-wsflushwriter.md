# WsFlushWriter function

## Description

Instructs the writer to invoke the [callback](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_stream_output) specified in [WS_XML_WRITER_STREAM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_stream_output) if sufficient data has been buffered.

## Parameters

### `writer` [in]

The writer to flush.

### `minSize` [in]

Specifies the minimum number of bytes that must be buffered in order for the
[callback](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback) to be invoked. If fewer than this number of bytes
are buffered, then the **callback** will not be invoked. This can be
used to minimize the number of i/o's that occur when writing small amounts of data.

Zero should be specified to guarantee that the [callback](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback) is invoked.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |

## Remarks

The writer buffers all data until **WsFlushWriter** is called.

If necessary, the **WsFlushWriter** should be called before [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter) to guarantee all data is emitted.

By specifying a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) the buffered data will be written asynchronously.

This function is a no-op if the writer is using [WS_XML_WRITER_BUFFER_OUTPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_buffer_output).

If [WsWriteStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartelement) has been called, but the element has not been committed (see **WsWriteStartElement**)
then this element will not be flushed.

If this function is called when using [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding) and there are
no open elements on the writer, then the supporting MIME parts will be generated and emitted. Once this
occurs, any API that attempts to write further to the XML document will return **WS_E_INVALID_OPERATION**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)