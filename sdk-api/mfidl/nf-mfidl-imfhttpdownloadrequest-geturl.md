# IMFHttpDownloadRequest::GetURL

## Description

Returns the URL that is used for sending the request.

## Parameters

### `ppszURL` [out]

The URL that is used for sending the request to the server. Note that this URL may be different if the server has issued a HTTP protocol “redirect”. The memory for *pszURL* must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and will be freed by Media Foundation with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully returned the URL. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **E_POINTER** | The *ppszURL* parameter is an invalid pointer. |

## Remarks

By default, **GetURL** returns an URL which is synthesized from the parameters provided by Media Foundation in the [IMFHttpDownloadSession::SetServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadsession-setserver) and [IMFHttpDownloadSession::CreateRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadsession-createrequest) methods. However, if the HTTP server has redirected the [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest) to a different server (i.e., through a “302 See Other” HTTP response) then the **GetURL** method returns the URL that the HTTP server specified.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)