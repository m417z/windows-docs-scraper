# IDebugControl4::OutputContextStackTrace

## Description

The **OutputContextStackTrace** method prints the call stack specified by an array of stack frames and corresponding register contexts.

## Parameters

### `OutputControl` [in]

Specifies where to send the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Frames` [in]

Specifies the array of stack frames to output. The number of elements in this array is *FramesSize*. If *Frames* is **NULL**, the current stack frame is used.

### `FramesSize` [in]

Specifies the number of frames to output.

### `FrameContexts` [in]

Specifies the register context for each frame in the stack. The entries in this array correspond to the entries in the *Frames* array. The type of the thread context is the CONTEXT structure for the target's effective processor.

### `FrameContextsSize` [in]

Specifies the size, in bytes, of the memory pointed to by *FrameContexts*. The number of stack frames must equal the number of contexts, and *FrameContextsSize* must equal *FramesSize* multiplied by *FrameContextsEntrySize*.

### `FrameContextsEntrySize` [in]

Specifies the size, in bytes, of each frame context in *FrameContexts*.

### `Flags` [in]

Specifies bit flags that determine what information to output for each frame. *Flags* can be any combination of values from the following table.

| Flag | Description |
| --- | --- |
| DEBUG_STACK_ARGUMENTS | Displays the first three pieces of stack memory at the frame of each call. On platforms where arguments are passed on the stack, and the code for the frame uses stack arguments, these values will be the arguments to the function. |
| DEBUG_STACK_FUNCTION_INFO | Displays information about the function that corresponds to the frame. This includes calling convention and frame pointer omission (FPO) information. |
| DEBUG_STACK_SOURCE_LINE | Displays source line information for each frame of the stack trace. |
| DEBUG_STACK_FRAME_ADDRESSES | Displays the return address, previous frame address, and other relevant addresses for each frame. |
| DEBUG_STACK_COLUMN_NAMES | Displays column names. |
| DEBUG_STACK_NONVOLATILE_REGISTERS | Displays the non-volatile register context for each frame. This is only meaningful for some platforms. |
| DEBUG_STACK_FRAME_NUMBERS | Displays frame numbers. |
| DEBUG_STACK_PARAMETERS | Displays parameter names and values as given in symbol information. |
| DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY | Displays just the return address in the stack frame addresses. |
| DEBUG_STACK_FRAME_MEMORY_USAGE | Displays the number of bytes that separate the frames. |
| DEBUG_STACK_PARAMETERS_NEWLINE | Displays each parameter and its type and value on a new line. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The array of stack frames can be obtained using [GetContextStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getcontextstacktrace).

## See also

[GetContextStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getcontextstacktrace)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputstacktrace)

[k, kb, kc, kd, kp, kP, kv (Display Stack Backtrace)](https://learn.microsoft.com/windows-hardware/drivers/debugger/k--kb--kc--kd--kp--kp--kv--display-stack-backtrace-)