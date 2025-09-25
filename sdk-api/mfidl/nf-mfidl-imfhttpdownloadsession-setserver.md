# IMFHttpDownloadSession::SetServer

## Description

Called by Microsoft Media Foundation to specify parameters common to all requests created by this instance of [IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession).

## Parameters

### `szServerName` [in]

The host name, fully qualified DNS name, or IP address of the HTTP server that the requests shall be sent to.

### `nPort` [in]

The TCP port number of the server.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully stored the supplied data. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## See also

[IMFHttpDownloadSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadsession)