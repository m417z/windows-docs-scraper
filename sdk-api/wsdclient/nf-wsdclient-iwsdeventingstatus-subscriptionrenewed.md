# IWSDEventingStatus::SubscriptionRenewed

## Description

Called when the subscription for the specified event action was successfully renewed.

## Parameters

### `pszSubscriptionAction` [in]

URI of the event action.

## Remarks

After an operation is subscribed to, the service proxy will attempt to automatically renew the subscription until the client calls the appropriate **Unsubscribe** method or until the subscription is ended by the service. When the renewal succeeds, **SubscriptionRenewed** will be called to notify the client.

## See also

[IWSDEventingStatus](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdeventingstatus)