# PETW_BUFFER_CALLBACK callback function

## Description

Function definition for the BufferCallback that will be invoked by [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace).

## Parameters

### `Buffer`

Pointer to the raw buffer data, which begins with an [ETW_BUFFER_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_buffer_header) struct and is followed by event data.

By default this buffer is available only until the callback returns. To use the buffer after the callback returns, call [ProcessTraceBufferIncrementReference](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtracebufferincrementreference). This will keep the buffer available until you call [ProcessTraceBufferDecrementReference](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtracebufferdecrementreference) on it.

ProcessTrace will not return until all such Buffer references have been decremented.

### `BufferSize`

Size of the provided *Buffer*.

### `ConsumerInfo`

Contains information on the current state of the processing session.

### `CallbackContext`

User-provided context from [ETW_OPEN_TRACE_OPTIONS.BufferCallbackContext](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_open_trace_options).

## Return value

If **TRUE**, the processing will continue. If **FALSE**, trace processing will stop and [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) will return.

## Remarks

## See also