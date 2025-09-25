# EventDescOrKeyword function

## Description

Adds another keyword to the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor to modify. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Keyword` [in]

New keyword to add to the current keyword bitmask.

## Return value

The modified event descriptor.

## Remarks

This is a convenience macro for setting the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)