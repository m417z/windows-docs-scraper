# EventDescGetOpcode function

## Description

Retrieves the operation code from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the operation code. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

Operation code that identifies the operation being performed at the time the
event was written.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)