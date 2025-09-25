# IDebugControl4::GetContextStackTrace

## Description

The **GetContextStackTrace** method returns the frames at the top of the call stack, starting with an arbitrary [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts) and returning the reconstructed register context for each stack frame.

## Parameters

### `StartContext` [in, optional]

Specifies the register context for the top of the stack.

### `StartContextSize` [in]

Specifies the size, in bytes, of the *StartContext* register context.

### `Frames` [out, optional]

Receives the stack frames. The number of elements this array holds is *FrameSize*. If *Frames* is **NULL**, this information is not returned.

### `FramesSize` [in]

Specifies the number of items in the array *Frames*.

### `FrameContexts` [out, optional]

Receives the reconstructed register context for each frame in the stack. The entries in this array correspond to the entries in the *Frames* array. The type of the thread context is the CONTEXT structure for the target's effective processor. If *FrameContexts* is **NULL**, this information is not returned.

### `FrameContextsSize` [in]

Specifies the size, in bytes, of the memory pointed to by *FrameContexts*. The number of stack frames returned equals the number of contexts returned, and *FrameContextsSize* must equal *FramesSize* times *FrameContextsEntrySize*.

### `FrameContextsEntrySize` [in]

Specifies the size, in bytes, of each frame context in *FrameContexts*.

### `FramesFilled` [out, optional]

Receives the number of frames that were placed in the array *Frames* and contexts in *FrameContexts*. If *FramesFilled* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The stack trace returned to *Frames* and *FrameContexts* can be printed using [OutputContextStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-outputcontextstacktrace).

It is common for stack unwinds to restore only a subset of the registers. For example, stack unwinds will not always restore the volatile register state because the volatile registers are scratch registers and code does not need to preserve them. Registers that are not restored on unwind are left as the last value restored, so care should be taken when using the register state that might not be restored by an unwind.

## See also

[GetStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getstacktrace)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputContextStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-outputcontextstacktrace)

[k, kb, kc, kd, kp, kP, kv (Display Stack Backtrace)](https://learn.microsoft.com/windows-hardware/drivers/debugger/k--kb--kc--kd--kp--kp--kv--display-stack-backtrace-)