# IMFHttpDownloadSession::Close

## Description

Invoked by Microsoft Media Foundation to specify that no more HTTP requests will be created, and allows [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession) to free any internal resources.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully closed the session. |

## See also

[IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession)