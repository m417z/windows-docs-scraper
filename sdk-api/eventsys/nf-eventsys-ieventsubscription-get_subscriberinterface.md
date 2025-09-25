# IEventSubscription::get_SubscriberInterface

## Description

A marshaled pointer to the event interface on the subscriber (for a transient subscription).

This property is read/write.

## Parameters

## Remarks

If not **NULL**, the subscription is transient and the [SubscriberCLSID](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_subscriberclsid) property must be empty.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)