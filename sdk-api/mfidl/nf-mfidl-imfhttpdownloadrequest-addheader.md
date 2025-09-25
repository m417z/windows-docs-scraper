# IMFHttpDownloadRequest::AddHeader

## Description

Invoked by Microsoft Media Foundation to add a single HTTP header to a HTTP request. Microsoft Media Foundation will invoke this method once for each header that shall be included in the HTTP request, before it invokes the [BeginSendRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginsendrequest) method.

## Parameters

### `szHeader` [in]

Contains a single HTTP request header, for example, “Accept: */*”. The string does not include the carriage return or line feed characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully added the header to the list of headers to be sent with the request. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)