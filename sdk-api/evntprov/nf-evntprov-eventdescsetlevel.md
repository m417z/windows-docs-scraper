# EventDescSetLevel function

## Description

Sets the **Level** member of the event descriptor.

## Parameters

### `EventDescriptor` [in]

Event descriptor to modify. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Level` [in]

Severity level that indicates the verboseness with which to log the event. For
details, see the Level parameter of
[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func).

## Return value

The modified event descriptor.

## Remarks

This is a convenience macro for setting the member of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)