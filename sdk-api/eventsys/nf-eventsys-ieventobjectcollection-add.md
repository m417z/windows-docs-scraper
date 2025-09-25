# IEventObjectCollection::Add

## Description

Adds an event object to the collection.

## Parameters

### `item` [in]

A pointer to the event object to be added to the collection. This parameter cannot be **NULL**.

### `objectID` [in]

The ID property of the event object to be added. For example, if the collection consists of subscription objects, this parameter would contain the SubscriptionID property of the event subscription object to be added to the collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection)