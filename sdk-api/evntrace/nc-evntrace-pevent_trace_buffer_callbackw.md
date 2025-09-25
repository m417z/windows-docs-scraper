## Description

ETW event consumers implement this function to receive statistics about each
buffer of events that ETW delivers during a trace processing session. ETW calls
this function after the events for each buffer are delivered.

The **PEVENT_TRACE_BUFFER_CALLBACK** type defines a pointer to this callback
function. **BufferCallback** is a placeholder for the application-defined
function name.

## Parameters

### `Logfile`

Pointer to an
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilew)
structure that contains information about the buffer.

## Return value

To continue processing events, return **TRUE**. Otherwise, return **FALSE**.
Returning **FALSE** will terminate the
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) function.

## Remarks

To specify the function that ETW calls to deliver the buffer statistics, set the
**BufferCallback** member of the
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilew)
structure that you pass to the
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracew) function.

## Examples

For an example implementation of a **BufferCallback** function, see
[Retrieving Event Data Using MOF](https://learn.microsoft.com/windows/desktop/ETW/retrieving-event-data-using-mof).

> [!NOTE]
> The evntrace.h header defines PEVENT_TRACE_BUFFER_CALLBACK as an alias
> which automatically selects the ANSI or Unicode version of this function based
> on the definition of the UNICODE preprocessor constant. Mixing usage of the
> encoding-neutral alias with code that not encoding-neutral can lead to
> mismatches that result in compilation or runtime errors. For more information,
> see
> [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilew)

[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracew)

[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace)