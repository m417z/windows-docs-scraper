# IMFHttpDownloadRequest::EndReceiveResponse

## Description

Invoked by Microsoft Media Foundation to complete the asynchronous operation started by [BeginReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreceiveresponse).

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Microsoft Media Foundation will pass in the same pointer that its callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully received the HTTP response and associated headers. |

## Remarks

If the server failed the request but responded with a specific HTTP status code, the **EndReceiveResponse** should still return S_OK. Media Foundation will invoke the [GetHttpStatus](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-gethttpstatus) method to retrieve the HTTP status code.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)