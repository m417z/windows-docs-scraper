# PETW_BUFFER_COMPLETION_CALLBACK callback function

## Description

Function definition for the callback that will be fired when [ProcessTraceAddBufferToBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtraceaddbuffertobufferstream) is finished with a buffer. This callback should typically free the buffer as appropriate

## Parameters

### `Buffer`

Pointer to the raw ETW buffer

### `CallbackContext`

User defined context passed in as BufferCompletionContext to [OpenTraceFromBufferStream](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracefrombufferstream).

## Remarks

## See also