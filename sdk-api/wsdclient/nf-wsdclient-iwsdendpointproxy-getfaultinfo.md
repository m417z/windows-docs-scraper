# IWSDEndpointProxy::GetFaultInfo

## Description

Retrieves information on the last received fault.

## Parameters

### `ppFault` [out]

Pointer to a pointer to a [WSD_SOAP_FAULT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault) structure containing the SOAP fault information.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppFault* is **NULL**. |

## Remarks

**Note** The fault information returned in *ppFault* must be released with **WSDFreeLinkedMemory** when it is no longer required for use.

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)