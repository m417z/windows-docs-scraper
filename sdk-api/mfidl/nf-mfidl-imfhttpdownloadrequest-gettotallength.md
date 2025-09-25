# IMFHttpDownloadRequest::GetTotalLength

## Description

Invoked by Microsoft Media Foundation to retrieve the total length of the resource that is being downloaded, if known.

## Parameters

### `pqwTotalLength` [out]

The total length, in bytes, of the resource being downloaded, if known. If not known, set to **MAX_ULONG** (0xFFFFFFFFFFFFFFFF).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully completed the operation. |
| **E_POINTER** | The *pqwTotalLength* parameter is an invalid pointer. |

## Remarks

Microsoft Media Foundation invokes **GetTotalLength** only after having successfully invoked [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse). The total length of the resource may be larger than the amount of data returned by the server in the current response. For example, if the request included the HTTP “Range” header, the data returned in the response may be less than total length of the resource. The [GetRangeEndOffset](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-getrangeendoffset) method can be used to calculate how much data is returned in the current response.

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)