# IMFHttpDownloadRequest::Close

## Description

Invoked by Microsoft Media Foundation to allow [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest) to free any internal resources. It will also cancel the current request if it is still in progress.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully closed the request object. |

## Remarks

Microsoft Media Foundation will not invoke any other methods on the [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest) interface after having invoked **Close**.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)