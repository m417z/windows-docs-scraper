# IFiringControl::FireSubscription

## Description

Fires an event to a single subscriber.

## Parameters

### `subscription` [in]

A pointer to the [IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription) interface on a subscription object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The **FireSubscription** method fires an event to the subscriber associated with the subscription object identified by the *subscription* parameter. A publisher filter typically iterates through a filtered list of subscriptions and calls **FireSubscription** for each associated subscriber. All standard delivery processing is done by the event object for the subscription, including the following:

* Any standard parameter filtering.
* Activating the subscriber object (optional, for persistent subscriptions).
* Depending on parameter filtering, invoking the event method that originally caused entry into the publisher filter on the subscriber.

## See also

[IFiringControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ifiringcontrol)