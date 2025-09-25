# IEventObjectChange::ChangedPublisher

## Description

Indicates a publisher object has been added, modified, or deleted.

## Parameters

### `changeType` [in]

The type of change to the publisher object. Values are taken from the [EOC_ChangeType](https://learn.microsoft.com/windows/desktop/api/eventsys/ne-eventsys-eoc_changetype) enumeration.

### `bstrPublisherID` [in]

The PublisherID property of the publisher object that changed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IEventObjectChange](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectchange)