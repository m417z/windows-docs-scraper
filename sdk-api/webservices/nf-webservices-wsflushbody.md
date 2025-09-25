# WsFlushBody function

## Description

Flushes all accumulated message body data that has been written.

When message uses [WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody) or XML Writer, the data is accumulated in a buffer. WsFlushBody subsequently performs the actual
I/O.

WsFlushBody is typically used when channel I/O is set to
[WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode), or when using an
XML Writer set to use [WS_XML_WRITER_STREAM_OUTPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_stream_output).

## Parameters

### `message` [in]

A pointer to the [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure containing the accumulated message body data.

### `minSize` [in]

Specifies the minimum number of bytes that must be present in the
message for the function to perform the data flush.

**Note** If the message contains less
than *minSize* WSFlushBody terminates without doing the I/O flush. A larger value will ensure that no I/O will be done until
the larger value has been accumulated. This is useful for ensuring
that larger chunks are used when doing I/O.
And presuming that
there is at least one byte of accumulated data a value of 0 in *minSize* guarantees that it will be flushed.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) data structure with information about invoking the function asynchronously. A **NULL**
value indicates a request for synchronous operation.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This function is a "no-op" when [WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) is not set, or when using an
XML Writer with [WS_XML_WRITER_BUFFER_OUTPUT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_buffer_output) set.

This function is shortcut for calling [WsFlushWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushwriter) for
the XML Writer being used to write the message. Calling
**WsFlushWriter** directly is equivalent to calling this function.