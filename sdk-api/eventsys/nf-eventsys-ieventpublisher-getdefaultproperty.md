# IEventPublisher::GetDefaultProperty

## Description

Retrieves a named property and its value from the property bag associated with the event publisher.

## Parameters

### `bstrPropertyName` [in]

The name of the property whose value is to be retrieved.

### `propertyValue` [out, retval]

A pointer to the variable that receives the property.

## Return value

The possible return values include E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

An [EventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher) object includes a property bag that can contain name and value pairs. Objects in the event system, including subscribers, can add, modify, and read these properties.

## See also

[IEventPublisher](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventpublisher)