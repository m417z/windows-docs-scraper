# IEventObjectChange::ChangedEventClass

## Description

Indicates that an event class object has been added, modified, or deleted.

## Parameters

### `changeType` [in]

The type of change to the event class object. Values are taken from the [EOC_ChangeType](https://learn.microsoft.com/windows/desktop/api/eventsys/ne-eventsys-eoc_changetype) enumeration.

### `bstrEventClassID` [in]

The EventClassID property of the event class object that changed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IEventObjectChange](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectchange)