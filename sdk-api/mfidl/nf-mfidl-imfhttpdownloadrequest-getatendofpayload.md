# IMFHttpDownloadRequest::GetAtEndOfPayload

## Description

Invoked by Microsoft Media Foundation to check if it should invoke [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload) to read data from the message body of the response. During the processing of a typical HTTP response, Media Foundation will invoke **BeginReadPayload** multiple times, but once **GetAtEndOfPayload** sets its output parameter to TRUE, Media Foundation will not invoke **BeginReadPayload** again.

## Parameters

### `pfAtEndOfPayload` [out]

Set to FALSE if a call to [BeginReadPayload](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-beginreadpayload) can return one or more bytes of data to Media Foundation. Set to TRUE when there is no more data to return.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully completed the operation. |
| **E_POINTER** | The *pfAtEndOfPayload* parameter is an invalid pointer. |

## Remarks

Microsoft Media Foundation invokes **GetAtEndOfPayload** only after having successfully invoked [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse).

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)