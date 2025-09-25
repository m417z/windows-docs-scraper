# IXMLHTTPRequest2Callback::OnResponseReceived

## Description

Occurs when a client has received a complete response from the server.

## Parameters

### `pXHR` [in, optional]

The initial HTTP request object

### `pResponseStream` [in, optional]

The response stream being received. The client can call [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) to begin processing the data, or it can store a reference to *pResponseStream* for later processing. This response stream is wrapped in a stream synchronization object that prevents concurrent read and write operations, so the application does not need to implement custom synchronization.

## Return value

Returns **S_OK** on success.

**Note** This callback function must not throw exceptions.

## Remarks

When this event fires the application can begin processing data from the HTTP response. Processing may begin before this event fires if an earlier [OnDataAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-ondataavailable) event has occurred.

Unless [OnError](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror) is called, the call to **OnResponseReceived** is the final callback. The client should perform any required cleanup including releasing references to the [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) object.

Custom streams receive a call to [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) specifying 0 bytes written before **OnResponseReceived** is fired. The client can process data directly from the Write call instead of calling [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) on the custom stream, and it can rely on the zero-byte Write call to indicate that the response has been received.

## See also

[ISequentialStream Interface](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)