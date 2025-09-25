# IWSDServiceMessaging::SendResponse

## Description

Sends a response message matching a given request context. This method should be called only from [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Parameters

### `pBody` [in]

Pointer to the message body to send in the response message.

### `pOperation` [in]

Pointer to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that contains the type of response to send.

### `pMessageParameters` [in]

Pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) object that contains the message parameters from the original request message.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | *pOperation* or *pMessageParameters* is **NULL**. |
| **E_ABORT** | The method could not be completed. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWSDServiceMessaging](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsdservicemessaging)