# IEventSubscription::RemovePublisherProperty

## Description

Removes a property and its value from the property bag that defines publisher context.

## Parameters

### `bstrPropertyName` [in]

The name of the property whose value is to be removed from the property bag.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

A property bag is used to store information about the events the subscriber needs to be notified about. For example, if a subscriber to a sports ticker is to obtain only baseball scores, it could use the property bag in the subscription object to specify this restriction.

## See also

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[PublisherID](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-get_publisherid)