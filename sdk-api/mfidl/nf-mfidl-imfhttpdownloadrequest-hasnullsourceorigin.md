# IMFHttpDownloadRequest::HasNullSourceOrigin

## Description

Invoked by Microsoft Media Foundation to detect the case when a HTTP or HTTPS request has been redirected to a different server of different "origin".

## Parameters

### `pfNullSourceOrigin` [out]

Set to TRUE if the current request has a “null” source origin. The source origin would become “null” if the HTTP request was redirected from one server to another, and the two servers have different origins.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully completed the operation. |
| **E_POINTER** | The *pfNullSOurceOrigin* parameter is an invalid pointer. |

## Remarks

The *pfNullSourceOrigin* parameter should be set to TRUE if **HasNullSourceOrigin** is invoked before [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse) has been invoked. For more information about the concept of origin in HTTP, see [RFC-6454](https://tools.ietf.org/html/rfc6454).

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)