# GetTraceEnableFlags function

## Description

A
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)-based
("Classic") event provider uses the **GetTraceEnableFlags** function to retrieve
the enable flags specified by the trace controller to indicate which category of
events to trace.

Providers call this function from their
[ControlCallback](https://learn.microsoft.com/windows/desktop/ETW/controlcallback) function.

## Parameters

### `TraceHandle` [in]

Handle to an event tracing session, obtained by calling the
[GetTraceLoggerHandle](https://learn.microsoft.com/windows/desktop/ETW/gettraceloggerhandle) function.

## Return value

Returns the value the controller specified in the _EnableFlag_ parameter when
calling the [EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function.

To determine if the function failed or the controller set the enable flags to 0,
follow these steps:

1. Call the
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror)
function to set the last error to **ERROR_SUCCESS**.
1. Call the **GetTraceEnableFlags** function to retrieve the enable flags.
1. If the enable flags value is 0, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
function to retrieve the last known error.
1. If the last known error is **ERROR_SUCCESS**, the controller set the enable
flags to 0; otherwise, the **GetTraceEnableFlags** function failed with the
last known error.

## Remarks

Providers can use this value to control which events that it generates. For
example, a provider can group events into logical categories of events and use
this value to enable or disable their generation.

### Examples

For an example that uses **GetTraceEnableFlags**, see
[Retrieving Event Data Using MOF](https://learn.microsoft.com/windows/desktop/ETW/retrieving-event-data-using-mof).

## See also

[GetTraceEnableLevel](https://learn.microsoft.com/windows/desktop/ETW/gettraceenablelevel)

[GetTraceLoggerHandle](https://learn.microsoft.com/windows/desktop/ETW/gettraceloggerhandle)