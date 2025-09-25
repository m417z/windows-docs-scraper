# IWSDEndpointProxy::SendTwoWayRequest

## Description

Sends a two-way request message using a synchronous call pattern.

## Parameters

### `pBody` [in]

The body of the message.

### `pOperation` [in]

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation to perform.

### `pResponseContext` [in, optional]

 Reference to a [WSD_SYNCHRONOUS_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_synchronous_response_context) structure or other context structure that specifies the context for handling the response to the request.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pOperation* is **NULL**. |

## Remarks

This method is normally only called by generated proxy code.

[WSD_SYNCHRONOUS_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_synchronous_response_context) is used for the *responseContext* value when a synchronous call pattern is used.

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)