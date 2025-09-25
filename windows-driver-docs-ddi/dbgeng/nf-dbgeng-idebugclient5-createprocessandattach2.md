# IDebugClient5::CreateProcessAndAttach2

## Description

The **CreateProcessAndAttach2** method creates a process from a specified command line, then attaches to that process or another user-mode process.

## Parameters

### `Server` [in]

Specifies the process server to use to attach to the process. If *Server* is zero, the engine will connect to the local process without using a process server.

### `CommandLine` [in, optional]

Specifies the command line to execute to create the new process. If *CommandLine* is **NULL**, no process is created and these methods will use *ProcessId* to attach to an existing process.

### `OptionsBuffer` [in]

Specifies the process creation options. *OptionsBuffer* is a pointer to a [DEBUG_CREATE_PROCESS_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options) structure.

### `OptionsBufferSize` [in]

Specifies the size of the buffer *OptionsBuffer*. This should be set to **sizeof(DEBUG_CREATE_PROCESS_OPTIONS)**.

### `InitialDirectory` [in, optional]

Specifies the starting directory for the process. This parameter is used only if *CommandLine* is not **NULL**. If *InitialDirectory* is **NULL**, the current directory for the process server is used.

### `Environment` [in, optional]

Specifies an environment block for the new process. An environment block consists of a null-terminated block of null-terminated strings. Each string is of the form:

```
name=value
```

Note that the last two characters of the environment block are both **NULL**: one to terminate the string and one to terminate the block.

If *Environment* is set to **NULL**, the new process inherits the environment block of the process server. If the DEBUG_CREATE_PROCESS_THROUGH_RTL flag is set in *OptionsBuffer*, then *Environment* must be **NULL**.

### `ProcessId` [in]

Specifies the process ID of the target process to which the debugger will attach. If *ProcessID* is zero, the debugger will attach to the process it created from *CommandLine*.

### `AttachFlags` [in]

Specifies the flags that control how the debugger attaches to the target process. For details on these flags, see [DEBUG_ATTACH_XXX](https://learn.microsoft.com/previous-versions/ff541454(v=vs.85)).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | This is returned if *CommandLine* is **NULL** and *ProcessId* is zero. |

## Remarks

This method is available only for live user-mode debugging.

If *CommandLine* is not **NULL** and *ProcessId* is not zero, then the engine will create the process in a suspended state. The engine will resume this newly created process after it successfully connects to the process specified in *ProcessId*.

**Note** The engine doesn't completely attach to the process until the [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) method has been called. Only after the process has generated an event -- for example, the create-process event -- does it become available in the debugger session.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[.attach (Attach to Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-attach--attach-to-process-)

[.create (Create Process)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-create--create-process-)

[AbandonCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-abandoncurrentprocess)

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[DetachCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-detachcurrentprocess)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[TerminateCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-terminatecurrentprocess)