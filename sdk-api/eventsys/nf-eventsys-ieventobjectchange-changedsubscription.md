# IEventObjectChange::ChangedSubscription

## Description

Indicates that a subscription object has been added, modified, or deleted.

## Parameters

### `changeType` [in]

The type of change to the subscription object. Values are taken from the EOC_ChangeType enumeration.

### `bstrSubscriptionID` [in]

The SubscriptionID property of the subscription object that changed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IEventObjectChange](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectchange)