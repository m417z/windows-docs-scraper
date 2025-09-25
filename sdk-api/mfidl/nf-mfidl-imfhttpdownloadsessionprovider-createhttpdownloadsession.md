# IMFHttpDownloadSessionProvider::CreateHttpDownloadSession

## Description

Called by the Microsoft Media Foundation to open HTTP or HTTPS URLs instead of using the default implementation.

## Parameters

### `wszScheme` [in]

The name of the protocol to for which an [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) is being requested. Microsoft Media Foundation specifies the protocol scheme of the URL that the application provided the Media Foundation Source Resolver. Valid values include “http” for HTTP, and “https” for HTTPS. URL scheme names are generally not case-sensitive.

### `ppDownloadSession` [out]

On successful execution, the parameter is set to a pointer to an [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) interface. The returned interface is used by Microsoft Media Foundation to open a single HTTP or HTTPS URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully created the [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) object. |
| **E_INVALIDARG** | The value specified for the *wszScheme* parameter is incorrect. |
| **E_POINTER** | The *ppDownloadSession* parameter is an invalid pointer. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## Remarks

Specifying “https” as the value of *wszScheme* does not imply that HTTPS will be used for a particular request, as that is specified on a per-request basis in [IMFhttpDownloadSession::CreateRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadsession-createrequest).

## See also

[IMFHttpDownloadSessionProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsessionprovider)