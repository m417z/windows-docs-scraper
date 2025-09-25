# IMFHttpDownloadRequest::GetRangeEndOffset

## Description

Invoked by Microsoft Media Foundation to retrieve the offset of the last byte in the current response, counted from the start of the resource. This is useful when a request uses the HTTP “Range” header to download only a portion of a resource.

## Parameters

### `pqwRangeEnd` [out]

The offset of the last byte in the current response, counted from the start of the resource, if known. For example, if the request specified the HTTP header, “Range: bytes=1000-“ and the size of the message body in the response is 200 bytes, then *pwqRangeEnd* becomes 1199. If the value is not known, for example, because the server did not specify the size of its response, *pwqRangeEnd* is set to MAX_ULONG (0xFFFFFFFFFFFFFFFF).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully completed the operation. |
| **E_POINTER** | The *qwpRangeEnd* parameter is an invalid pointer. |

## Remarks

Microsoft Media Foundation invokes **GetRangeEndOffset** only after having successfully invoked [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse).

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)