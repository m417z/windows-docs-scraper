# IMFHttpDownloadRequest::QueryHeader

## Description

Invoked by Microsoft Media Foundation to retrieve the values of specified HTTP headers from the response to a previously sent HTTP or HTTPS request. Media Foundation invokes this method only after having successfully invoked the [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse) method.

## Parameters

### `szHeaderName` [in]

The name of the HTTP header for which the value is being queried.

### `dwIndex` [in]

The index number of the specified header, for the case where the response contains multiple headers with the same name. A value of 0 indicates that the value of the first header with the specified name is requested, 1 indicates that the second header is requested, and so on.

### `ppszHeaderValue` [out]

Set to the value of the requested header, not including the carriage return or line feed characters. The memory for *ppszHeaderValue* must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and will be freed by Media Foundation with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully returned the value of the specified header with the specified index. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **E_POINTER** | The *ppszHeaderValue* parameter is an invalid pointer. |
| **MF_E_OUT_OF_RANGE** | The *dwIndex* parameter value is out of range. |

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)