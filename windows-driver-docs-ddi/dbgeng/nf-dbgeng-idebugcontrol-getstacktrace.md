# IDebugControl::GetStackTrace

## Description

The **GetStackTrace** method returns the frames at the top of the specified call stack.

## Parameters

### `FrameOffset` [in]

Specifies the location of the stack frame at the top of the stack. If *FrameOffset* is set to zero, the current frame pointer is used instead.

### `StackOffset` [in]

Specifies the location of the current stack. If *StackOffset* is set to zero, the current stack pointer is used instead.

### `InstructionOffset` [in]

Specifies the location of the instruction of interest for the function that is represented by the stack frame at the top of the stack. If *InstructionOffset* is set to zero, the current instruction is used instead.

### `Frames` [out, writes]

Receives the stack frames. The number of elements this array holds is *FrameSize*.

### `FramesSize` [in]

Specifies the number of items in the *Frames* array.

### `FramesFilled` [out, optional]

Receives the number of frames that were placed in the array *Frames*. If *FramesFilled* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | No stack frames were returned. |

## Remarks

The stack trace returned to *Frames* can be printed using [OutputStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputstacktrace).

## See also

[GetContextStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getcontextstacktrace)

[GetFrameOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getframeoffset2)

[GetInstructionOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getinstructionoffset2)

[GetStackOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getstackoffset2)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputStackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputstacktrace)

[StackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_stacktrace_routine)

[k, kb, kc, kd, kp, kP, kv (Display Stack Backtrace)](https://learn.microsoft.com/windows-hardware/drivers/debugger/k--kb--kc--kd--kp--kp--kv--display-stack-backtrace-)