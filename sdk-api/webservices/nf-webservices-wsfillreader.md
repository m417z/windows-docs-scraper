# WsFillReader function

## Description

Ensures that the reader has buffered the minimum byte count of XML data for use by subsequent reader functions. It will invoke the callback specified by [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_stream_input) as many times as necessary to obtain the number of bytes specified by the value of the *minSize* parameter. On completion the buffered data is available to other reader functions. If a subsequent reader function requires more data than what has been obtained the function
will return a **WS_E_QUOTA_EXCEEDED** exception.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

## Parameters

### `reader` [in]

A pointer to a [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) structure used for obtaining the data.

### `minSize` [in]

Specifies the minimum number of bytes that the reader should have obtained. If the current byte count buffered is equal to or greater than the value of *minSize* the function will do nothing and will return immediately.

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

## Remarks

The number of bytes required to read a particular segment of XML data depends upon the encoding
and its formatting.

This function is a "no-op" when used with a reader using [WS_XML_READER_BUFFER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_buffer_input).

By specifying a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) the data is read asynchronously.