# GetTraceLoggerHandle function

## Description

A
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)-based
("Classic") event provider uses the **GetTraceLoggerHandle** function to
retrieve the handle of the event tracing session to which it should write
events.

Providers call this function from their
[ControlCallback](https://learn.microsoft.com/windows/desktop/ETW/controlcallback) function.

## Parameters

### `Buffer` [in]

Pointer to a [WNODE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/wnode-header) structure. ETW
passes this structure to the provider's
[ControlCallback](https://learn.microsoft.com/windows/desktop/ETW/controlcallback) function in the _Buffer_
parameter.

The **HistoricalContext** member of
[WNODE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/wnode-header) contains the session's handle.

## Return value

If the function succeeds, it returns the event tracing session handle.

If the function fails, it returns **INVALID_HANDLE_VALUE**. To get extended
error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
function.

## Remarks

You use the handle when calling the
[GetTraceEnableFlags](https://learn.microsoft.com/windows/desktop/ETW/gettraceenableflags) and
[GetTraceEnableLevel](https://learn.microsoft.com/windows/desktop/ETW/gettraceenablelevel) functions to
retrieve the enable flags and level values passed to the
[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function.

### Examples

For an example that uses **GetTraceLoggerHandle**, see
[Retrieving Event Data Using MOF](https://learn.microsoft.com/windows/desktop/ETW/retrieving-event-data-using-mof).

## See also

[GetTraceEnableFlags](https://learn.microsoft.com/windows/desktop/ETW/gettraceenableflags)

[GetTraceEnableLevel](https://learn.microsoft.com/windows/desktop/ETW/gettraceenablelevel)