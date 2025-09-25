# TRACE_GUID_PROPERTIES structure

## Description

Returned by
[EnumerateTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguids).
Contains information about an event trace provider.

## Members

### `Guid`

Control GUID of the event trace provider.

### `GuidType`

Not used.

### `LoggerId`

Session handle that identifies the event tracing session.

### `EnableLevel`

Value passed as the _EnableLevel_ parameter to the
[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function.

### `EnableFlags`

Value passed as the _EnableFlag_ parameter to the
[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function.

### `IsEnable`

If this member is **TRUE**, the element identified by the **Guid** member is
currently enabled for the session identified by the **LoggerId** member. If this
member is **FALSE**, all other members have no meaning and should be zero.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members or passing to any functions.

## See also

[EnumerateTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguids)