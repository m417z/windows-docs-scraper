# EventDescGetChannel function

## Description

Retrieves the channel from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the channel. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

Channel that defines the category of events to which this event belongs.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)