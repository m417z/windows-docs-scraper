# IWSDServiceProxy::BeginGetMetadata

## Description

Initiates an asynchronous metadata exchange request with the remote service.

## Parameters

### `ppResult` [out]

An [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) interface that you use to poll for the result, register a callback object, or configure an event to be signaled when the response is received.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppResult* is **NULL**. |
| **E_ABORT** | The method could not be completed. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## Remarks

Call [IWSDServiceProxy::EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdserviceproxy-endgetmetadata) to complete the asynchronous operation and to retrieve the metadata.

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)