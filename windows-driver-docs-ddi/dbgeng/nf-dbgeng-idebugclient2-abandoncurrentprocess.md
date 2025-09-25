# IDebugClient2::AbandonCurrentProcess

## Description

The **AbandonCurrentProcess** method removes the [current process](https://learn.microsoft.com/windows-hardware/drivers/debugger/c) from the debugger engine's process list without detaching or terminating the process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available for live user-mode debugging. The target must be running on Windows XP or a later version of Windows.

Windows will continue to consider this process as being debugged, and so the process will remain suspended. This method allows the debugger to be shut down and a new debugger to attach to the process. See [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets) and [Re-attaching to the Target Application](https://learn.microsoft.com/windows-hardware/drivers/debugger/reattaching-to-the-target-application) for more information.

## See also

[.abandon (Abandon Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-abandon--abandon-process-)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)