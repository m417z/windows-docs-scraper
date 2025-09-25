# OpenTraceFromBufferStream function

## Description

Creates a trace processing session that is not directly attached to any file or active session.

## Parameters

### `Options`

Configuration options for this processing session. See [ETW_OPEN_TRACE_OPTIONS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_open_trace_options) for more details

### `BufferCompletionCallback`

When the processing session is done with a buffer passed in from [ProcessTraceAddBufferToBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtraceaddbuffertobufferstream), it will invoke this callback to allow for any freeing or other cleanup that may be required for that buffer.

### `BufferCompletionContext`

User-provided context that will be passed to the [BufferCompletionCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_completion_callback).

## Return value

A TRACEHANDLE that is used to identify this processing session. Typically passed to [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) to begin processing and to [CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace) to end processing.

## Remarks

The caller is expected to supply the data for the trace by calling [ProcessTraceAddBufferToBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtraceaddbuffertobufferstream). This is typically used for remote real-time trace processing: a remote system uses [OpenTraceFromRealTimeLogger](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromrealtimelogger) and [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) with a [BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) that sends buffers over the network to a local system, then the local system calls [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream) and [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace), receives buffers from the network and feeds them to the local trace processor using [ProcessTraceAddBufferToBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtraceaddbuffertobufferstream).

This processing mode requires that the buffers be provided in the same order that the buffers were received from [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) (for example, the first buffer contains header information and subsequent buffers are ordered by flush time). The only supported means to generate buffers in this way is from the [BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) from another [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream), [OpenTraceFromFile](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromfile), [OpenTraceFromRealTimeLogger](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromrealtimelogger), [OpenTraceFromRealTimeLoggerWithAllocationOptions](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefromrealtimeloggerwithallocationoptions) processing session.

## See also