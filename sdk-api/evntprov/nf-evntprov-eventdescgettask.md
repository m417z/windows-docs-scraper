# EventDescGetTask function

## Description

Retrieves the task from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the task. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

Task that identifies the logical component of the application whose events you
want to enable.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)