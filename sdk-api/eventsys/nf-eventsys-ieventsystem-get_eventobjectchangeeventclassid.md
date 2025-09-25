# IEventSystem::get_EventObjectChangeEventClassID

## Description

Retrieves the CLSID of an event class object that notifies the caller of changes to the event store.

This property is read-only.

## Parameters

## Remarks

Subscriptions can use the **EventObjectChangeEventClassID** property to obtain a pointer to an event class object that notifies them when subscribers or events are modified or when they are added to or deleted from the event store. Subscribers to these events must implement the [IEventObjectChange](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectchange) interface.

## See also

[IEventSystem](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsystem)