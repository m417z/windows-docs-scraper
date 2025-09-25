# IWSDDeviceProxy::GetServiceProxyById

## Description

Retrieves a generic [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) service proxy by service ID. Service IDs can be obtained by examining the service host metadata.

## Parameters

### `pszServiceId` [in]

The service ID.

### `ppServiceProxy` [out]

Pointer to an [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) object for the specified service proxy.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppServiceProxy* is **NULL**. |
| **E_INVALIDARG** | The length in characters of *pszServiceId* exceeds WSD_MAX_TEXT_LENGTH (8192), or there is no metadata associated with the service specified by *pszServiceId*. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | There is no endpoint associated with the service proxy. |

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)