# IDebugClient2::DetachProcesses

## Description

The **DetachProcesses** method detaches the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) from all [processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in all targets, resuming all their [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The targets must be running on Windows XP or a later version of Windows.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.detach (Detach from Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-detach--detach-from-process-)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateProcesses](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminateprocesses)