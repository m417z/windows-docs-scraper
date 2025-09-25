# IDebugAdvanced3::Request

## Description

The **Request** method performs a variety of different operations.

## Parameters

### `Request` [in]

Specifies which operation to perform. **Request** can be one of the values in the following table. Details of each operation can be found by following the link in the "Request" column.

| Request | Action |
| --- | --- |
| [DEBUG_REQUEST_SOURCE_PATH_HAS_SOURCE_SERVER](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-source-path-has-source-server) | Check the source path for a source server. |
| [DEBUG_REQUEST_TARGET_EXCEPTION_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-context) | Return the [thread context](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups) for the stored event in a user-mode minidump file. |
| [DEBUG_REQUEST_TARGET_EXCEPTION_THREAD](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-thread) | Return the operating system thread ID for the stored event in a user-mode minidump file. |
| [DEBUG_REQUEST_TARGET_EXCEPTION_RECORD](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-record) | Return the exception record for the stored event in a user-mode minidump file. |
| [DEBUG_REQUEST_GET_ADDITIONAL_CREATE_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-additional-create-options) | Return the default process creation options. |
| [DEBUG_REQUEST_SET_ADDITIONAL_CREATE_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-set-additional-create-options) | Set the default process creation options. |
| [DEBUG_REQUEST_GET_WIN32_MAJOR_MINOR_VERSIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-win32-major-minor-versions) | Return the version of Windows that is currently running on the target. |
| [DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM](https://learn.microsoft.com/previous-versions/ff541575(v=vs.85)) | Read a stream from a user-mode minidump target. |
| [DEBUG_REQUEST_TARGET_CAN_DETACH](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-can-detach) | Check to see if it is possible for the debugger engine to detach from the current process (leaving the process running but no longer being debugged). |
| [DEBUG_REQUEST_SET_LOCAL_IMPLICIT_COMMAND_LINE](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-set-local-implicit-command-line) | Set the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction)'s implicit command line. |
| [DEBUG_REQUEST_GET_CAPTURED_EVENT_CODE_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-captured-event-code-offset) | Return the current event's instruction pointer. |
| [DEBUG_REQUEST_READ_CAPTURED_EVENT_CODE_STREAM](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-read-captured-event-code-stream) | Return up to 64 bytes of memory at the current event's instruction pointer. |
| [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi) | Perform a variety of different operations that aid in the interpretation of typed data. |

### `InBuffer` [in, optional]

Specifies the input to this method. The type and interpretation of the input depends on the *Request* parameter.

### `InBufferSize` [in]

Specifies the size of the input buffer *InBuffer*. If the request requires no input, *InBufferSize* should be set to zero.

### `OutBuffer` [out, optional]

Receives the output from this method. The type and interpretation of the output depends on the *Request* parameter. If *OutBuffer* is **NULL**, the output is not returned.

### `OutBufferSize` [in]

Specifies the size of the output buffer *OutBufferSize*. If the type of the output returned to *OutBuffer* has a known size, *OutBufferSize* is usually expected to be exactly that size, even if *OutBuffer* is set to **NULL**.

### `OutSize` [out, optional]

Receives the size of the output returned in the output buffer *OutBuffer*. If *OutSize* is **NULL**, this information is not returned.

## Return value

The interpretation of the return value depends on the value of the *Request* parameter. Unless otherwise stated, the following values may be returned.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the output would not fit in the output buffer *OutBuffer*, so truncated output was returned. |
| **E_INVALIDARG** | The size of the input buffer *InBufferSize* or the size of the output buffer *OutBufferSize* was not the expected value. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## See also

[DEBUG_REQUEST_GET_ADDITIONAL_CREATE_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-additional-create-options)

[DEBUG_REQUEST_GET_CAPTURED_EVENT_CODE_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-captured-event-code-offset)

[DEBUG_REQUEST_GET_WIN32_MAJOR_MINOR_VERSIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-get-win32-major-minor-versions)

[DEBUG_REQUEST_READ_CAPTURED_EVENT_CODE_STREAM](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-read-captured-event-code-stream)

[DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM](https://learn.microsoft.com/previous-versions/ff541575(v=vs.85))

[DEBUG_REQUEST_SET_ADDITIONAL_CREATE_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-set-additional-create-options)

[DEBUG_REQUEST_SET_LOCAL_IMPLICIT_COMMAND_LINE](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-set-local-implicit-command-line)

[DEBUG_REQUEST_SOURCE_PATH_HAS_SOURCE_SERVER](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-source-path-has-source-server)

[DEBUG_REQUEST_TARGET_CAN_DETACH](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-can-detach)

[DEBUG_REQUEST_TARGET_EXCEPTION_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-context)

[DEBUG_REQUEST_TARGET_EXCEPTION_RECORD](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-record)

[DEBUG_REQUEST_TARGET_EXCEPTION_THREAD](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-target-exception-thread)

[IDebugAdvanced2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced2)

[IDebugAdvanced3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced3)