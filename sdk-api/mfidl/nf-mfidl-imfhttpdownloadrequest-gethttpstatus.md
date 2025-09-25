# IMFHttpDownloadRequest::GetHttpStatus

## Description

Invoked by Microsoft Media Foundation to retrieve the HTTP status code that the server specified in its response. Media Foundation invokes this method after a successful call to [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse).

## Parameters

### `pdwHttpStatus` [out]

The HTTP status code of the response. For example, the value is 200 for a typical successful response.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully returned the HTTP status code. |
| **E_FAIL** | The HTTP response has not yet been received. |
| **E_POINTER** | The *pdwHttpStatus* parameter is an invalid pointer. |

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)