# IWSDEndpointProxy::GetErrorInfo

## Description

Retrieves information on the last error.

## Parameters

### `ppszErrorInfo` [out]

Pointer to a buffer containing the data for the last recorded error.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszErrorInfo* is **NULL**. |

## Remarks

**Note** The error information returned in *ppszErrorInfo* must be released with [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) when it is no longer required for use.

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)