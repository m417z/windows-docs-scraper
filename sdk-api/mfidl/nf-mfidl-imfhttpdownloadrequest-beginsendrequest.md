# IMFHttpDownloadRequest::BeginSendRequest

## Description

Invoked by Microsoft Media Foundation to send a HTTP or HTTPS request

## Parameters

### `pbPayload` [in]

Pointer to a buffer that contains the message payload to send in the request. This parameter is used for POST requests. GET requests do not carry a message payload and therefore *pbPayload* is NULL.

### `cbPayload` [in]

The size of the *pbPayload* buffer, in bytes.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object that is implemented by Microsoft Media Foundation.

### `punkState`

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a state object, defined by Microsoft Media Foundation. This parameter can be NULL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully started the asynchronous operation. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## Remarks

The implementation of **BeginWrite** does not need to make a private copy of the memory pointed to by *pbPayload*, as Microsoft Media Foundation will not reallocate, free, or write to the buffer while an asynchronous write is still pending.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)