# IDebugClient2::AddProcessOptions

## Description

The **AddProcessOptions** method adds the process options to those options that affect the [current process](https://learn.microsoft.com/windows-hardware/drivers/debugger/c).

## Parameters

### `Options` [in]

Specifies the process options to add to those affecting the current process. For details on these process options, see [DEBUG_PROCESS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-process-xxx).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is available only in [live user-mode debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/l).

Some of the process options are global options, others are specific to the current process.

If any process options are modified, the engine will notify the [event callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/e) by calling their [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) method with the DEBUG_CES_PROCESS_OPTIONS flag set.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[DEBUG_PROCESS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-process-xxx)

[GetProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getprocessoptions)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[RemoveProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-removeprocessoptions)

[SetProcessOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setprocessoptions)