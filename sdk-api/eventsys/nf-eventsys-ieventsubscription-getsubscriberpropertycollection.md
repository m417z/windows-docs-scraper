# IEventSubscription::GetSubscriberPropertyCollection

## Description

Retrieves a collection of properties and values stored in the subscriber property bag.

## Parameters

### `collection` [out, retval]

Address of a pointer to the [IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection) interface on an event object collection. This parameter cannot be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_POINTER, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

A property bag is used to store information about the events the subscriber needs to be notified about. For example, if a subscriber to a sports ticker is to obtain only baseball scores, it could use the property bag in the subscription object to specify this restriction.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)