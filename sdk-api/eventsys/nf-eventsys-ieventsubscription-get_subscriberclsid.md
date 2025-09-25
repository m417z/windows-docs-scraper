# IEventSubscription::get_SubscriberCLSID

## Description

The CLSID of the subscriber component (for a persistent subscription).

This property is read/write.

## Parameters

## Remarks

If not empty, the subscription is persistent and the [SubscriberInterface](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_subscriberinterface) property must be **NULL**. This property works in conjunction with the [MachineName](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_machinename) property in a persistent subscription.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)