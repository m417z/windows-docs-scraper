# ProcessTrace function

## Description

The **ProcessTrace** function delivers events from one or more ETW trace
processing sessions to the consumer.

## Parameters

### `HandleArray` [in]

Pointer to an array of trace processing session handles obtained from earlier
calls to the [OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea)
function.

The array can contain up to 64 handles to file processing sessions or it can
contain one handle to a real-time processing session. The array cannot contain
both file processing session handles and real-time processing session handles.

### `HandleCount` [in]

Number of elements in _HandleArray_.

### `StartTime` [in]

Pointer to an optional
[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that
specifies the beginning time period for which you want to receive events. The
function does not deliver events with timestamps prior to _StartTime_.

### `EndTime` [in]

Pointer to an optional
[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that
specifies the ending time period for which you want to receive events. The
function does not deliver events with timestamps after _EndTime_.

**Windows Server 2003:** This value is ignored for real-time event delivery.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following are
some common errors and their causes.

- **ERROR_BAD_LENGTH**

 _HandleCount_ is not valid or the number of handles is greater than 64.

- **ERROR_INVALID_HANDLE**

 An element of _HandleArray_ is not a valid event tracing session handle.

- **ERROR_INVALID_TIME**

 _EndTime_ is less than _StartTime_.

- **ERROR_INVALID_PARAMETER**

 _HandleArray_ is **NULL**, contains both file processing sessions and
real-time processing sessions, or contains more than one real-time processing
session.

- **ERROR_NOACCESS**

 An exception occurred in one of the callback functions that receives the
events.

- **ERROR_CANCELLED**

 Indicates the consumer canceled processing by returning **FALSE** in their
[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka)
function.

- **ERROR_WMI_INSTANCE_NOT_FOUND**

 The trace collection session from which you are trying to consume events in
real time is not running or does not have the real-time trace mode enabled.

## Remarks

Trace consumers call this function to process the events from one or more trace
processing sessions. This function blocks until processing ends.

Before calling **ProcessTrace**, use
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) to open handles
to trace processing sessions.

The **ProcessTrace** function delivers the events from the sessions by invoking
the consumer's
[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka),
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback), and
[EventRecordCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback)
callback functions.

The **ProcessTrace** function attempts to deliver events in order based on the
event's timestamp (i.e. it tries to deliver events oldest to newest). In certain
cases, **ProcessTrace** might deliver events out of order.

- If the clock used for the event timestamps is adjusted backwards during trace
collection, the delivery order of the events is unpredictable. To avoid this
issue, [use the QPC clock](https://learn.microsoft.com/windows/win32/etw/wnode-header) instead of the
system time clock when collecting the trace.
- If multiple events are collected with the same timestamp on different CPUs,
the delivery order of the events is unpredictable.
- If an event has an invalid timestamp (e.g. due to file corruption), the
delivery order of that event and other events in the trace may be
unpredictable.

The **ProcessTrace** function blocks the thread until it delivers all events,
the
[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka)
function returns **FALSE**, or you call
[CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace). In addition,
if the consumer is consuming events in real time, the **ProcessTrace** function
returns after the controller stops the trace session. (Note that there may be a
delay of several seconds before the function returns.)

**Windows Server 2003:** You can call
[CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace) only after
**ProcessTrace** returns.

### Examples

For an example that uses **ProcessTrace**, see
[Using TdhFormatProperty to Consume Event Data](https://learn.microsoft.com/windows/win32/etw/using-tdhformatproperty-to-consume-event-data).

## See also

[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka)

[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)

[EventRecordCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback)

[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea)