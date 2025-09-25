# IWSDServiceProxy::GetEndpointProxy

## Description

Gets the endpoint proxy for the device.

## Parameters

### `ppProxy` [out]

Pointer to an [IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy) interface.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppProxy* is **NULL**. |

## Remarks

The endpoint proxy is provided if a fault was received for a prior request. The client can then call [IWSDEndpointProxy::GetFaultInfo](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdendpointproxy-getfaultinfo) to determine the nature of the error.

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)