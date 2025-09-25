# IWSDServiceProxy::SetEventingStatusCallback

## Description

Sets or clears the eventing status callback.

## Parameters

### `pStatus` [in, optional]

An [IWSDEventingStatus](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdeventingstatus) interface that lets the client know of status changes in event subscriptions. If **NULL**, existing eventing status callbacks are cleared.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)