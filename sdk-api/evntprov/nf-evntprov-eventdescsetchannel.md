# EventDescSetChannel function

## Description

Sets the **Channel** member of the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor to modify. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Channel` [in]

Channel that defines the category of events to which this event belongs.

## Return value

The modified event descriptor.

## Remarks

This is a convenience macro for setting the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)