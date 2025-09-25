# IWSDEndpointProxy::SendOneWayRequest

## Description

Sends a one-way request message.

## Parameters

### `pBody` [in]

 The body of the message.

### `pOperation` [in]

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation to perform.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pOperation* is **NULL**. |

## Remarks

This method is normally only called by generated proxy code.

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)