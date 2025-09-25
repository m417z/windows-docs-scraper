# EventDescGetId function

## Description

Retrieves the event identifier from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the event identifier. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

The event identifier.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)