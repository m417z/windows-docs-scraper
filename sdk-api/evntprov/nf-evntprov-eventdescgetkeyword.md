# EventDescGetKeyword function

## Description

Retrieves the keyword from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the keyword. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

Keyword that is a bitmask that further defines the category of events to which
the event belongs.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)