# IMFHttpDownloadRequest::BeginReceiveResponse

## Description

Invoked by Microsoft Media Foundation to receive the response, provided by the server, in response to a previously sent HTTP or HTTPS request. Media Foundation invokes this method only after having successfully invoked the [EndSendRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endsendrequest) method.

## Parameters

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object that is implemented by Microsoft Media Foundation.

### `punkState`

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a state object, defined by Microsoft Media Foundation. This parameter can be NULL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully started the asynchronous operation. |

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)