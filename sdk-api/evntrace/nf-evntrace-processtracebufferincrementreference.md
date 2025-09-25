# ProcessTraceBufferIncrementReference function

## Description

Called during the [BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) on the provided Buffer to prevent it from being freed until the caller is done with it.

## Parameters

### `TraceHandle`

The processing session that this *Buffer* came from.

### `Buffer`

The buffer to reference. This buffer must have been obtained by a call to the [PETW_BUFFER_CALLBACK](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) callback.

## Return value

Win32 Error Code. Possible codes may include ERROR_INVALID_PARAMETER and ERROR_OUTOFMEMORY.

## Remarks

If **ProcessTraceBufferIncrementReference** is not called on a Buffer during the [PETW_BUFFER_CALLBACK](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) then the memory is no longer accessible after the [PETW_BUFFER_CALLBACK](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-petw_buffer_callback) returns.

The caller is responsible for calling **ProcessTraceBufferDecrementReference** on the Buffer once they are done with it. [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) will not return until this has been done for every buffer that was incremented.

**ProcessTraceBufferIncrementReference** is not supported for buffers provided by a processing session opened by [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream).

## See also