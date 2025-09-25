# IXMLHTTPRequest2::SetCustomResponseStream

## Description

Provides a custom stream to replace the standard stream for receiving an HTTP response.

## Parameters

### `pSequentialStream`

Custom stream that will receive the HTTP response. [ISequentialStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

## Return value

Returns **S_OK** on success.

## Remarks

After this method is called, [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) will call the [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) method when it receives response data from the server. You can begin processing the data at that time, but avoid heavy processing because the call is made inline to receiving further data from the server. Because this **IXMLHTTPRequest2** never calls [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) on the custom stream, it is safe to return **E_NOTIMPL** if the application does not need to use **ISequentialStream::Read**.

## See also

[ISequentialStream Interface](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)