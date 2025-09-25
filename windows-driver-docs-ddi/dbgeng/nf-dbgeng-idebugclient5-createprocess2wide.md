# IDebugClient5::CreateProcess2Wide

## Description

The **CreateProcess2Wide** method executes the specified command to create a new process.

## Parameters

### `Server` [in]

Specifies the process server that will be attached to the process. If *Server* is zero, the engine will create the local process without using a process server.

### `CommandLine` [in]

Specifies the command line to execute to create the new process.

### `OptionsBuffer` [in]

Specifies the process creation options. *OptionsBuffer* is a pointer to a [DEBUG_CREATE_PROCESS_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options) structure.

### `OptionsBufferSize` [in]

Specifies the size of the buffer *OptionsBuffer*. This should be set to **sizeof(DEBUG_CREATE_PROCESS_OPTIONS)**.

### `InitialDirectory` [in, optional]

Specifies the starting directory for the process. If *InitialDirectory* is **NULL**, the current directory for the process server is used.

### `Environment` [in, optional]

Specifies an environment block for the new process. An environment block consists of a null-terminated block of null-terminated strings. Each string is of the form:

```
name=value
```

Note that the last two characters of the environment block are both **NULL**: one to terminate the string and one to terminate the block.

If *Environment* is set to **NULL**, the new process inherits the environment block of the process server. If the DEBUG_CREATE_PROCESS_THROUGH_RTL flag is set in *OptionsBuffer*, then *Environment* must be **NULL**.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only for live user-mode debugging.

If *CreateFlags* contains either of the flags DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS, the engine will also attach to the newly created process. This is similar to the behavior of [CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2) with its argument *ProcessId* set to zero.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.create (Create Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-create--create-process-)

[AbandonCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-abandoncurrentprocess)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)