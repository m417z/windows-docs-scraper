# IMFHttpDownloadRequest::EndReadPayload

## Description

Invoked by Microsoft Media Foundation to complete the asynchronous operation started by [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload). When this method completes successfully, the payload data will have been written to the buffer that Media Foundation provided when invoking **BeginReadPayload**.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Microsoft Media Foundation will pass in the same pointer that its callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `pqwOffset` [out]

The offset of the first byte written to the buffer, relative to the complete message body of the current HTTP request. For example, when Media Foundation invokes [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload) for the first time on a given [IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest), and specifies a buffer size of 100, the *pqwOffset* parameter will be set to 0. Then, when Media Foundation invokes **BeginReadPayload** for the second time on the same **IMNFHttpDownloadRequest**, the *pqwOffset* parameter will be set to 100.

### `pcbRead` [out]

Specifies the number of bytes written to the buffer that Media Foundation provided when invoking [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload). Note that this value must always be equal to the size of the buffer specified in **BeginReadPayload**, unless the request failed, or unless the end of the message body has been reached.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully wrote data to the buffer provided in [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload). |

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)