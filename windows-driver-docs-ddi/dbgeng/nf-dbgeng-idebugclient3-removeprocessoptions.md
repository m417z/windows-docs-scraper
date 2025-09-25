# IDebugClient3::RemoveProcessOptions

## Description

The **RemoveProcessOptions** method removes process options from those options that affect the current process.

## Parameters

### `Options` [in]

Specifies the process options to remove from those affecting the current process. For details on these options, see [DEBUG_PROCESS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-process-xxx).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is available only in live user-mode debugging.

Some of the process options are global options, others are specific to the current process.

If any process options are modified, the engine will notify the event callbacks by calling their [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) method with the DEBUG_CES_PROCESS_OPTIONS flag set.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[AddProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-addprocessoptions)

[DEBUG_PROCESS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-process-xxx)

[GetProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getprocessoptions)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[SetProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setprocessoptions)