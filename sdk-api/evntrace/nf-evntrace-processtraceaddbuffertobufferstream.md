# ProcessTraceAddBufferToBufferStream function

## Description

Provides an ETW trace buffer to a processing session created by [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream).

## Parameters

### `TraceHandle`

The TRACEHANDLE for the processing session to add to.

### `Buffer`

A valid ETW buffer to process.

### `BufferSize`

The ETW buffer size.

## Return value

ERROR_SUCCESS or a Win32 error code to indicate that the buffer is invalid, out of time order, or that the TraceHandle is invalid.

## Remarks

Buffers passed by **ProcessTraceAddBufferToBufferStream** must be in the same order as they were produced by [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace). Incorrect ordering of buffers may cause the function to return an error.

When the buffer is done processing, the *BufferCompletionCallback* specified in [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream) will be called to release it.

## See also