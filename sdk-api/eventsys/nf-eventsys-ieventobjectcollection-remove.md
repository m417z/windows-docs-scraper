# IEventObjectCollection::Remove

## Description

Removes an event object from the collection.

## Parameters

### `objectID` [in]

The ID property of the event object to be removed. For example, if the collection consists of subscription objects, this parameter would contain the SubscriptionID property of the event subscription object to be removed from the collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection)