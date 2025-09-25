# EventDescSetVersion function

## Description

Sets the **Version** member of the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor to modify. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Version` [in]

Version that identifies the revision level of the event definition. The first
version of an event is zero.

## Return value

The modified event descriptor.

## Remarks

This is a convenience macro for setting the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)