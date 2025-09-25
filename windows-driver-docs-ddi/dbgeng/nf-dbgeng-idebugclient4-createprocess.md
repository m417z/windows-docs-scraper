# IDebugClient4::CreateProcess

## Description

The **CreateProcess** method creates a process from the specified command line.

## Parameters

### `Server` [in]

Specifies the process server to use to attach to the process. If *Server* is zero, the engine will create a local process without using a process server.

### `CommandLine` [in]

Specifies the command line to execute to create the new process.

### `CreateFlags` [in]

Specifies the flags to use when creating the process. For details on these flags, see the **CreateFlags** member of the [DEBUG_CREATE_PROCESS_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options) structure.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only for live user-mode debugging.

If *CreateFlags* contains either of the flags DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS, the engine will also attach to the newly created process; this is similar to the behavior of [CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2) with its argument *ProcessId* set to zero.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.create (Create Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-create--create-process-)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)