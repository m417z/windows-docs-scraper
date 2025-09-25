# IDebugClient5::CreateProcessWide

## Description

The **CreateProcessWide** method creates a process from the specified command line.

## Parameters

### `Server` [in]

Specifies the process server to use when attaching to the process. If *Server* is zero, the engine will create a local process without using a process server.

### `CommandLine` [in]

Specifies the command line to execute to create the new process. The **CreateProcessWide** method might modify the contents of the string that you supply in this parameter. Therefore, this parameter cannot be a pointer to read-only memory (such as a const variable or a literal string). Passing a constant string in this parameter can lead to an access violation.

### `CreateFlags` [in]

Specifies the flags to use when creating the process. For details on these flags, see the **CreateFlags** member of the [DEBUG_CREATE_PROCESS_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options) structure.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only for live user-mode debugging.

If *CreateFlags* contains either of the flags DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS, the engine also attaches to the newly created process. This behavior is similar to that of [CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2) when its argument *ProcessId* is set to zero.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.create (Create Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-create--create-process-)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)