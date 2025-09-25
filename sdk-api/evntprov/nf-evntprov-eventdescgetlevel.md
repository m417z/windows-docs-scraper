# EventDescGetLevel function

## Description

Retrieves the severity level from the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor from which to retrieve the severity level. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

Severity level that indicates the verboseness with which to log the event.

## Remarks

This is a convenience macro for retrieving the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)