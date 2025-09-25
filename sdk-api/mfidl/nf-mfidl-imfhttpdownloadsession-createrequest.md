# IMFHttpDownloadSession::CreateRequest

## Description

Invoked by Microsoft Media Foundation to create an object that implements the [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest) interface, which is used to send a single HTTP, or HTTPS request. Since multiple requests may be needed to fully download a resource, Media Foundation may invoke **CreateRequest** multiple times on the same [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) instance. Media Foundation will use each **IMFHttpDownloadRequest** instance for only a single request.

## Parameters

### `szObjectName` [in]

Pointer to a string that contains the name of the target resource of the specified HTTP verb. This is generally a file name, an executable module, or a search specifier. The target resource always begins with a forward slash character and includes any query string that was included on the URL.

### `fBypassProxyCache` [in]

If set to TRUE, indicates that the request should be forwarded to the originating server rather than sending a cached version of a resource from a proxy server. When this flag is set to TRUE, a "Pragma: no-cache" header should be added to the request. When creating an HTTP/1.1 request, a "Cache-Control: no-cache" should also be added.

### `fSecure` [in]

If set to TRUE, causes the secure variant of the protocol to be used, if applicable. For example, if the [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) is for HTTP/HTTPS, setting *fSecure* to TRUE will cause the request to use HTTPS. Otherwise, the unsecure variant of the protocol (in this example, HTTP) is used.

### `szVerb` [in, optional]

Pointer to a string that contains the HTTP verb to use in the request. If this parameter is NULL, the function uses GET as the HTTP verb.

**Note** This string should be all uppercase. Many servers treat HTTP verbs as case-sensitive, and the Internet Engineering Task Force (IETF) Requests for Comments (RFCs) spell these verbs using uppercase characters only.

### `szReferrer` [in, optional]

Pointer to a string that specifies the URL of the document from which the URL in the request *szObjectName* was obtained. If this parameter is set to NULL, no referring document is specified.

### `ppRequest`

Upon successful return of the method, this parameter is set to an [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully stored the supplied information. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **MF_E_INVALIDREQUEST** | The method was invoked after [Close](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadsession-close) or before [SetServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadsession-setserver) was invoked. |

## See also

[IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession)