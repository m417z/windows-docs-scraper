# IDebugClient5::AttachProcess

## Description

The **AttachProcess** method connects the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) to a user-modeprocess.

## Parameters

### `Server` [in]

Specifies the process server to use to attach to the process. If *Server* is zero, the engine will connect to a local process without using a process server.

### `ProcessId` [in]

Specifies the process ID of the target process the debugger will attach to.

### `AttachFlags` [in]

Specifies the flags that control how the debugger attaches to the target process. For details on these flags, see Remarks.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only for live user-mode debugging.

**Note** The engine doesn't completely attach to the process until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. Only after the process has generated an event -- for example, the create-process event -- does it become available in the debugger session.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

The DEBUG_ATTACH_*XXX* bit-flags control how the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) attaches to a user-mode process. For the DEBUG_ATTACH_*XXX* options used when attaching to a kernel target, see [AttachKernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachkernel).

The following table describes the possible flag values.

| Constant | Description |
| --- | --- |
| **DEBUG_ATTACH_NONINVASIVE** | Attach to the target noninvasively. For more information about noninvasive debugging, see [Noninvasive Debugging (User Mode)](https://learn.microsoft.com/windows-hardware/drivers/debugger/noninvasive-debugging--user-mode-).<br><br>If this flag is set, then the flags DEBUG_ATTACH_EXISTING, DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK, and DEBUG_ATTACH_INVASIVE_RESUME_PROCESS must not be set. |
| **DEBUG_ATTACH_EXISTING** | Re-attach to an application to which a debugger has already attached (and possibly abandoned). For more information about re-attaching to targets, see [Re-attaching to the Target Application](https://learn.microsoft.com/windows-hardware/drivers/debugger/reattaching-to-the-target-application).<br><br>If this flag is set, then the other DEBUG_ATTACH_*XXX* flags must not be set. |
| **DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND** | Do not suspend the target's threads when attaching noninvasively.<br><br>If this flag is set, then the flag DEBUG_ATTACH_NONINVASIVE must also be set. |
| **DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK** | (Windows XP and later) Do not request an initial break-in when attaching to the target.<br><br>If this flag is set, then the flags DEBUG_ATTACH_NONINVASIVE and DEBUG_ATTACH_EXISTING must not be set. |
| **DEBUG_ATTACH_INVASIVE_RESUME_PROCESS** | If this flag is set, then the flags DEBUG_ATTACH_NONINVASIVE and DEBUG_ATTACH_EXISTING must not be set. |

## See also

[.attach (Attach to Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-attach--attach-to-process-)

[AbandonCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-abandoncurrentprocess)

[AttachKernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachkernel)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)

[debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction)