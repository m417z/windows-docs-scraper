# IWSDDeviceProxy::GetServiceProxyByType

## Description

Retrieves a generic [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) proxy for a service exposed by the device by port type name.

## Parameters

### `pType` [in]

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies the port type name.

### `ppServiceProxy` [out]

Pointer to the [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) object associated with the specified service.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pType* or *ppServiceProxy* is **NULL**. |
| **E_INVALIDARG** | There is no metadata associated with the service specified by *pType*. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | There is no endpoint associated with the service proxy. |

## Remarks

If the device hosts more than one service of the specified type, a proxy for any one of the services may be returned. In such a case, callers should not depend on any particular service proxy being returned.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)