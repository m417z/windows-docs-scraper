# IXMLHTTPRequest2::Send

## Description

Sends an HTTP request to the server asynchronously. On success, methods on the [IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback) interface implemented by the app are called to process the response.

## Parameters

### `pBody` [in, optional]

The body of the message being sent with the request. This stream is read in order to upload data for non-**GET** requests. For requests that do not require uploading, set this parameter to NULL.

### `cbBody` [in]

The length, in bytes, of the message being sent with the request. For requests that do not require uploading, set this parameter to 0.

## Return value

Returns **S_OK** on success.

## Remarks

The [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-open) method must be called before **Send** can be called successfully.

Because this method is asynchronous, it returns immediately before the request has started processing. The application will be notified through the [IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback) interface as progress is made in the request processing.

Alternatives to using [ISequentialStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream) for a POST request include [SHCreateMemStream](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatememstream)/[SHCreateStreamOnFile](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatestreamonfilea) for desktop apps, and [CreateStreamOverRandomAccessStream](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createstreamoverrandomaccessstream) for Windows Store apps.

## See also

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)