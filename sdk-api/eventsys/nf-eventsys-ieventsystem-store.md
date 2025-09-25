# IEventSystem::Store

## Description

Creates or modifies an event or subscription object within the event system.

## Parameters

### `ProgID` [in]

The ProgID of the event object to be added. This must be a valid event object class identifier. The possible values are PROGID_EventSubscription and PROGID_EventClass.

### `pInterface` [in]

A pointer to the object to be added. Depending on the object specified by the *ProgID* parameter, this is a pointer to the [IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription) or [IEventClass](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventclass) interface.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **EVENT_E_INVALID_PER_USER_SID** | The owner SID on a per-user subscription does not exist. |

## See also

[IEventSystem](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsystem)