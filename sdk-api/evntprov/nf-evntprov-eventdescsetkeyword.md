# EventDescSetKeyword function

## Description

Sets the **Keyword** member of the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor to modify. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Keyword` [in]

Keyword that is a bitmask that further defines the category of events to which
the event belongs.

## Return value

The modified event descriptor.

## Remarks

This is a convenience macro for setting the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)