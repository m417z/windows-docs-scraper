# IWSDEndpointProxy::AbortAsyncOperation

## Description

Aborts a pending asynchronous operation.

## Parameters

### `pAsyncResult` [in]

Calls the [Abort](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdasyncresult-abort) method to end the asynchronous operation.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pAsyncResult* is **NULL** or *pAsyncResult* does not support the [IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback) interface. |

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)