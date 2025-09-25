# ETW_BUFFER_CONTEXT structure

## Description

The **ETW_BUFFER_CONTEXT** structure provides context information about the
event. An instance of the **ETW_BUFFER_CONTEXT** structure is included in the
[EVENT_RECORD](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_record) and
[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace) structures.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ProcessorNumber`

The number of the CPU on which the provider process was running. The number is
zero on a single-processor computer.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Alignment`

Alignment between events (always eight).

### `DUMMYUNIONNAME.ProcessorIndex`

### `LoggerId`

Identifier of the session that logged the event.

## See also

[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)

[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace)