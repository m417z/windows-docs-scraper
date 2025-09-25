# IXMLHTTPRequest2Callback::OnDataAvailable

## Description

Occurs when a client receives part of the HTTP response data from the server.

## Parameters

### `pXHR` [in, optional]

The initial HTTP request.

### `pResponseStream` [in, optional]

The response stream being received. The client can call [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) to begin processing the data, or it can wait until it has received the complete response. This response stream is wrapped in a stream synchronization object that prevents concurrent read and write operations, so the application does not need to implement custom synchronization.

## Return value

Returns **S_OK** on success.

**Note** This callback function must not throw exceptions.

## Remarks

When this callback function returns the application can begin processing data from the HTTP response, even if it has not yet received the entire response. However, receiving is suspended for the request until this callback function returns. Additionally, this callback can be invoked multiple times during a single request.

This callback function must not block and should not be made to perform resource intensive operations such as UI updates.

Custom streams receive a call to [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) before **OnDataAvailable** is fired. The client can process data directly from the Write call instead of calling [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) on the custom stream, and it can rely on the Write call to indicate that new data is available.

## See also

[ISequentialStream Interface](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)