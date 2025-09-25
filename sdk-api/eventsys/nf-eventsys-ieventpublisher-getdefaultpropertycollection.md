# IEventPublisher::GetDefaultPropertyCollection

## Description

Creates a collection object that enumerates the properties contained in the property bag associated with the event publisher object.

## Parameters

### `collection` [out, retval]

A pointer to an [IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection) interface pointer on an event object collection. This parameter cannot be **NULL**.

## Return value

The possible return values include E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

An [EventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher) object includes a property bag that can contain name and value pairs. Objects in the event system, including subscribers, can add, modify, and read these properties.

## See also

[IEventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher)