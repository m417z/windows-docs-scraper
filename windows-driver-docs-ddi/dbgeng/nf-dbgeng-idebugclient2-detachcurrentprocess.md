# IDebugClient2::DetachCurrentProcess

## Description

The **DetachCurrentProcess** method detaches the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) from the current process, resuming all its [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The target must be running on Windows XP or a later versions of Windows.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.detach (Detach from Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-detach--detach-from-process-)

[AbandonCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-abandoncurrentprocess)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachProcesses](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachprocesses)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)