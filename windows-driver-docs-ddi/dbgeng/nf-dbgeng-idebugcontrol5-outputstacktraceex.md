# IDebugControl5::OutputStackTraceEx

## Description

The OutputStackTraceEx method outputs either the supplied stack frame or the current stack frames. The OutputStackTraceEx method provides inline frame support. For more information about working with inline functions, see [Debugging Optimized Code and Inline Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-optimized-code-and-inline-functions-external).

## Parameters

### `OutputControl` [in]

Specifies where to send the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Frames` [in, optional]

Specifies the array of stack frames to output. The number of elements in this array is *FramesSize*. If *Frames* is **NULL**, the current stack frames are used.

### `FramesSize` [in]

Specifies the number of frames to output.

### `Flags` [in]

Specifies bit flags that determine what information to output for each frame. *Flags* can be any combination of values from the following table.

| Flag | Description |
| --- | --- |
| DEBUG_STACK_ARGUMENTS | Displays the first three pieces of stack memory at the frame of each call. On platforms where parameters are passed on the stack, and the code for the frame uses stack arguments, these values will be the arguments to the function. |
| DEBUG_STACK_FUNCTION_INFO | Displays information about the function that corresponds to the frame. This includes calling convention and frame pointer omission (FPO) information. |
| DEBUG_STACK_SOURCE_LINE | Displays source line information for each frame of the stack trace. |
| DEBUG_STACK_FRAME_ADDRESSES | Displays the return address, previous frame address, and other relevant addresses for each frame. |
| DEBUG_STACK_COLUMN_NAMES | Displays column names. |
| DEBUG_STACK_NONVOLATILE_REGISTERS | Displays the non-volatile register context for each frame. This is only meaningful for some platforms. |
| DEBUG_STACK_FRAME_NUMBERS | Displays frame numbers. |
| DEBUG_STACK_PARAMETERS | Displays parameter names and values as given in symbol information. |
| DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY | Displays just the return address in stack frame addresses. |
| DEBUG_STACK_FRAME_MEMORY_USAGE | Displays the number of bytes that separate the frames. |
| DEBUG_STACK_PARAMETERS_NEWLINE | Displays each parameter and its type and value on a new line. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The array of stack frames can be obtained using [GetStackTraceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol5-getstacktraceex).

## See also

[GetContextStackTraceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol5-getcontextstacktraceex)

[GetStackTraceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol5-getstacktraceex)

[IDebugControl5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol5)

[k, kb, kc, kd, kp, kP, kv (Display Stack Backtrace)](https://learn.microsoft.com/windows-hardware/drivers/debugger/k--kb--kc--kd--kp--kp--kv--display-stack-backtrace-)