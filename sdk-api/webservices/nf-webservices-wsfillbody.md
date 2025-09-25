# WsFillBody function

## Description

Ensures that there are a sufficient number of bytes available in a message for reading. It is up to the application to specify the number of bytes sufficient to contain the next XML construct to read.

**Note** This function is called before using [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody) or the XML Readerof the message to read the message body.

This function is a shortcut for calling [WsFillReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillreader) for the XML Reader being used to write the message. Calling **WsFillReader** directly is equivalent to calling this function.

## Parameters

### `message` [in]

A pointer to the [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure intended for "filling".

### `minSize` [in]

The minimum number of bytes that the message should have buffered. If the current byte count buffered is equal to or greater than the value of *minSize* the function does nothing.

**Note** The value of *minSize* represents the size of the encoded form of the XML that is expected. This can vary by encoding and also how the actual XML is structured. Typical use of this function is to select an expected upper bound byte count for encoding or XML structure to ensure that the expected data is read.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) data structure with information about invoking the function asynchronously. A **NULL** value indicates a request for synchronous operation.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Start of message was received successfully. |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This function is typically used when writing the message body with streamed mode set to [WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode), or when using an XML Reader in streamed mode.

This function is a "no-op" when writing the message body and [WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) is not set, or with an XML Reader's mode set to [WS_XML_READER_BUFFER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_buffer_input).