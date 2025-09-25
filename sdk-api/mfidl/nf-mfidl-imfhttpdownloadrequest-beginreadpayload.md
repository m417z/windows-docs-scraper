# IMFHttpDownloadRequest::BeginReadPayload

## Description

Invoked by Microsoft Media Foundation to receive the message body of the response to a previously sent HTTP or HTTPS request. Media Foundation invokes this method only after having successfully invoked the [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse) method. Since the size of the message body may be large, or unknown, Media Foundation may invoke this method multiple times to retrieve the message body in piecemeal fashion.

## Parameters

### `pb` [out]

Pointer to a buffer that receives the data.

### `cb` [in]

Specifies the size of the *pb* buffer, in bytes.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object that is implemented by Microsoft Media Foundation.

### `punkState`

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a state object, defined by Microsoft Media Foundation. This parameter can be NULL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully started the asynchronous operation. |

## Remarks

Microsoft Media Foundation never invokes **BeginReadPayload** while a previous call to **BeginReadPayload** has not yet completed.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)