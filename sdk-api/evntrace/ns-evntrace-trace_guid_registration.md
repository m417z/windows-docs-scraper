# TRACE_GUID_REGISTRATION structure

## Description

Used with
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
to register event trace classes.

## Members

### `Guid`

Class GUID of an event trace class that you are registering.

### `RegHandle`

Handle to the registered event trace class. The
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function generates this value.

Use this handle when you call the
[CreateTraceInstanceId](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-createtraceinstanceid)
function and to set the **RegHandle** member of
[EVENT_INSTANCE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_instance_header)
when calling the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

## See also

[CreateTraceInstanceId](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-createtraceinstanceid)

[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)