# IWSDServiceMessaging::FaultRequest

## Description

Sends a fault matching a given request context. This method should be called only from [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Parameters

### `pRequestHeader` [in]

Pointer to a [WSD_SOAP_HEADER](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_header) structure that contains the SOAP header of the original request that caused the fault.

### `pMessageParameters` [in]

Pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) object that contains the message parameters for the original request that caused the fault.

### `pFault` [in, optional]

Pointer to a [WSD_SOAP_FAULT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault) structure that describes the fault to serialize and send. If this parameter is omitted, a fault of type **wsa:EndpointUnavailable** will be sent.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | *pRequestHeader* or *pMessageParameters* is **NULL**. |
| **E_ABORT** | The method could not be completed. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWSDServiceMessaging](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsdservicemessaging)