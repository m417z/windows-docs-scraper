# IEventPublisher::RemoveDefaultProperty

## Description

Removes a named property and its value from the property bag associated with the event publisher object.

## Parameters

### `bstrPropertyName` [in]

The name of the property to be removed.

## Return value

The possible return values include E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

An [EventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher) object includes a property bag that can contain name and value pairs. Objects in the event system, including subscribers, can add, modify, and read these properties.

## See also

[IEventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher)