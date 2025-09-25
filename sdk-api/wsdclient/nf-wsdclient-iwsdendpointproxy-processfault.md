# IWSDEndpointProxy::ProcessFault

## Description

Processes a SOAP fault retrieved by [GetFaultInfo](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdendpointproxy-getfaultinfo).

## Parameters

### `pFault` [in]

Pointer to a [WSD_SOAP_FAULT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault) structure containing the fault data.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pFault* is **NULL**. |
| **S_FALSE** | The fault was not stored in memory. |

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)