# ETW_BUFFER_CALLBACK_INFORMATION structure

## Description

Provided to the BufferCallback as the *ConsumerInfo* parameter and provides details on the current processing session.

## Members

### `TraceHandle`

The TraceHandle for this processing session.

### `LogfileHeader`

[TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) structure containing trace processing status (previously-existing structure).

### `BuffersRead`

The count of how many buffers have been processed up to this point.

## Remarks

## See also