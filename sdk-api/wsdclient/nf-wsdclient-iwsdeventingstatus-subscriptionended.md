# IWSDEventingStatus::SubscriptionEnded

## Description

Called when the device terminated the subscription.

## Parameters

### `pszSubscriptionAction` [in]

URI of the event action.

## Remarks

After an operation is subscribed to, the service proxy will listen for SubscriptionEnd messages from the subscription manager. If one is received for a specified subscription, **SubscriptionEnded** will be called to notify the client. **SubscriptionEnded** will not be called if the service proxy unsubscribes from the operation or if the host service goes offline.

## See also

[IWSDEventingStatus](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdeventingstatus)