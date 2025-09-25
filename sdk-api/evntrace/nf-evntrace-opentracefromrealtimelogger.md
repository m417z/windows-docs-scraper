# OpenTraceFromRealTimeLogger function

## Description

Creates a trace processing session attached to an active real-time ETW session.

## Parameters

### `LoggerName`

Name of the real-time event tracing session, or **NULL** if processing data from a log file. Specify a value for this member if you are calling **OpenTraceFromRealTimeLogger** to consume data from a real-time session.

When calling **OpenTraceFromRealTimeLogger**, if _LogFileHeader_ is non-**NULL** then _LoggerName_ must be **NULL**.

You can only consume events in real time if the trace controller has set the **LogFileMode** member of [EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_properties) to include the **EVENT_TRACE_REAL_TIME_MODE** flag.

Only users with administrative privileges, users in the Performance Log Users group, and applications running as LocalSystem, LocalService, NetworkService can consume events in real time. To grant a restricted user the ability to consume events in real time, add them to the Performance Log Users group or call [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol).

### `Options`

Configuration options for this processing session. See [ETW_OPEN_TRACE_OPTIONS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_open_trace_options) for more details.

### `LogFileHeader`

Header information for the log file. See [TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) for more details.

## Return value

A TRACEHANDLE that is used to identify this processing session. Typically passed to [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) to begin processing and to [CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace) to end processing.

## Remarks

Once [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) is called on the returned **TRACEHANDLE**, this will receive buffers from the ETW session as they are flushed and immediately begin processing them and calling the callbacks specified in the *Options*.

## See also