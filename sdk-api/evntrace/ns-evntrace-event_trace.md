# EVENT_TRACE structure

## Description

The **EVENT_TRACE** structure is used to deliver event information to an event
trace consumer.

## Members

### `Header`

An
[EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_header)
structure that contains standard event tracing information.

### `InstanceId`

Instance identifier. Contains valid data when the provider calls the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function to generate the event. Otherwise, the value is zero.

### `ParentInstanceId`

Instance identifier for a parent event. Contains valid data when the provider
calls the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function to generate the event. Otherwise, the value is zero.

### `ParentGuid`

Class GUID of the parent event. Contains valid data when the provider calls the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function to generate the event. Otherwise, the value is zero.

### `MofData`

Pointer to the beginning of the event-specific data for this event.

### `MofLength`

Number of bytes to which **MofData** points.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ClientContext`

Reserved.

### `DUMMYUNIONNAME.BufferContext`

Provides information about the event such as the session identifier and
processor number of the CPU on which the provider process ran. For details, see
the
[ETW_BUFFER_CONTEXT](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_buffer_context)
structure.

**Prior to Windows Vista:** Not supported.

## Remarks

[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) passes this
structure to the consumer's
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)
callback function.

## See also

[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)