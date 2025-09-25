# OpenTraceFromFile function

## Description

Creates a trace processing session to process a Tracelog .etl file.

## Parameters

### `LogFileName`

The path of the Tracelog .etl file to process.

### `Options`

Configuration options for this processing session. See [ETW_OPEN_TRACE_OPTIONS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_open_trace_options) for more details.

### `LogFileHeader`

Header information for the log file. See [TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) for more details.

## Return value

A TRACEHANDLE that is used to identify this processing session. Typically passed to [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) to begin processing and to [CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace) to end processing.

## Remarks

Once [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) is called on the returned **TRACEHANDLE**, this will immediately begin processing the file and calling the callbacks specified in *Options*.

## See also