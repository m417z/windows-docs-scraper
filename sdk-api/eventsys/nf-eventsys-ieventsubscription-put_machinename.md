# IEventSubscription::put_MachineName

## Description

The name of the computer on which the subscriber should be activated (for a persistent subscription).

This property is read/write.

## Parameters

## Remarks

This information is only meaningful if the [SubscriberCLSID](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_subscriberclsid) property is not empty. This property has no effect on transient subscriptions.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)