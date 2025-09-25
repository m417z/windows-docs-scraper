# IWSDAsyncResult::GetEndpointProxy

## Description

Retrieves the endpoint proxy for the asynchronous operation.

## Parameters

### `ppEndpoint` [out]

An [IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy) interface that implements an endpoint proxy.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppEndpoint* is **NULL**. |

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)