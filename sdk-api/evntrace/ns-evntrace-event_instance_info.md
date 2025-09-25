# EVENT_INSTANCE_INFO structure

## Description

The **EVENT_INSTANCE_INFO** structure maps a unique transaction identifier to a
registered event trace class for
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance).

## Members

### `RegHandle`

Handle to a registered event trace class.

### `InstanceId`

Unique transaction identifier that maps an event to a specific transaction.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

## See also

[CreateTraceInstanceId](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-createtraceinstanceid)

[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)