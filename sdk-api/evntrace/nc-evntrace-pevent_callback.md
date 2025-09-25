# PEVENT_CALLBACK callback function

## Description

ETW event consumers implement this callback to receive events from a trace
processing session. This callback should not be used in new code. Instead,
implement
[EventRecordCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback).

The **PEVENT_CALLBACK** type is a pointer to this callback function.
**EventCallback** is a placeholder for the application-defined function name.

## Parameters

### `pEvent` [in]

Pointer to an [EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace)
structure that contains the event information.

## Remarks

> [!Note]
> This callback is obsolete because it receives incomplete information
> about the event and is not compatible with event decoding helper APIs such as
> [TdhGetEventInformation](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhgeteventinformation).
> Instead of implementing **EventCallback**, implement
> [EventRecordCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback).

To specify the function that ETW calls to deliver the events, set the
**EventCallback** member of the
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea)
structure that you pass to the
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) function.

> [!Note]
> If your **EventCallback** function is receiving garbled data from
> **ProcessTrace**, double-check the flags specified in the `ProcessTraceMode`
> field of the `EVENT_TRACE_LOGFILE` structure that was provided to
> **OpenTrace**. `EVENT_TRACE_LOGFILE`'s **EventCallback** and
> **EventRecordCallback** fields are overlapping members of a union. If the
> `ProcessTraceMode` field includes the `PROCESS_TRACE_MODE_EVENT_RECORD` flag,
> **ProcessTrace** will invoke your callback using the **EventRecordCallback**
> function signature. Otherwise, **ProcessTrace** will invoke your callback
> using the **EventCallback** function signature.

After using [OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) to
create the trace processing session, call the
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) function to
begin receiving the events.

When **ProcessTrace** begins processing events from a trace, it may invoke your
callback with one or more synthetic events that contain data about the trace
(metadata) rather than data from logged events. These synthetic events have
**Header.Guid** set to `EventTraceGuid` and **Header.Class.Type** set based on
the content of the synthetic event. For example, the first event from each trace
file will be a synthetic event with type 0 containing
[TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header)
information.

All the other events you receive contain provider-specific event data. You use
the **Header.Guid** and **Header.Class.Type** members of
[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace) to determine
the type of event you received. It is possible to hard-code decoding logic for
well-known event types, but most events will be decoded using MOF schema
information registered on the system in the `\\root\wmi` namespace. For
information on using an event's MOF schema to interpret the event, see
[Consuming Events](https://learn.microsoft.com/windows/win32/etw/consuming-events).

### Examples

For an example implementation of an **EventCallback** function, see
[Retrieving Event Data Using MOF](https://learn.microsoft.com/windows/win32/etw/retrieving-event-data-using-mof).

## See also

[Consuming Events](https://learn.microsoft.com/windows/win32/etw/consuming-events)

[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka)

[EventRecordCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback)

[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea)

[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea)

[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace)