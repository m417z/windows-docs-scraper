# IDebugClient3::CreateProcessAndAttachWide

## Description

The **CreateProcessAndAttachWide** method creates a process from a specified command line, then attach to another user-mode process. The created process is suspended and only allowed to execute when the attach has completed. This allows rough synchronization when debugging both, client and server processes.

## Parameters

### `Server` [in]

Specifies the process server to use to attach to the process. If *Server* is zero, the engine will connect to the local process without using a process server.

### `CommandLine` [in, optional]

Specifies the command line to execute to create the new process. If *CommandLine* is **NULL**, then no process is created and these methods attach to an existing process, as [AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess) does.

### `CreateFlags` [in]

Specifies the flags to use when creating the process. For details on these flags, see [DEBUG_CREATE_PROCESS_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options).**CreateFlags**.

### `ProcessId` [in]

Specifies the process ID of the target process the debugger will attach to. If *ProcessId* is zero, the debugger will attach to the process it created from *CommandLine*.

### `AttachFlags` [in]

Specifies the flags that control how the debugger attaches to the target process. For details on these flags, see [DEBUG_ATTACH_XXX](https://learn.microsoft.com/previous-versions/ff541454(v=vs.85)).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only for live user-mode debugging.

If *CommandLine* is not **NULL** and *ProcessId* is not zero, then the engine will create the process in a suspended state. The engine will resume this newly created process after it successfully connects to the process specified in *ProcessId*.

The engine does not completely attach to the process until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. Only after the process has generated an event -- for example, the create-process event -- does it become available in the debugger session.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.attach (Attach to Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-attach--attach-to-process-)

[.create (Create Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-create--create-process-)

[AbandonCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-abandoncurrentprocess)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)