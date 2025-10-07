# EtwLogTraceEvent function

Logs an event.

## Parameters

### LoggerHandle [in]

Handle to an event tracing session, or 0. You must specify a non-zero
_SessionHandle_ if _SessionName_ is **NULL**. ETW ignores the handle if
_SessionName_ is not **NULL**.

### EventDescriptor [in]

An [EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_header) structure containing standard event tracing information common to all events written by [TraceEvent](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceevent).

## Return value

A Win32 error code.

## Remarks

This function is not defined in an SDK header and must be declared by the caller. This function is exported from ntdll.dll.