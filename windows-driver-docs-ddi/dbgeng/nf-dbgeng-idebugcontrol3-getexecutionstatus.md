# IDebugControl3::GetExecutionStatus

## Description

The **GetExecutionStatus** method returns information about the execution status of the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

## Parameters

### `Status` [out]

Receives the execution status. This will be set to one of the values in the following table. Note that the description of these values differs slightly from the description in [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx).

| Value | Description |
| --- | --- |
| DEBUG_STATUS_NO_DEBUGGEE | The engine is not attached to a target. |
| DEBUG_STATUS_STEP_OVER | The target is currently executing a single instruction. If that instruction is a subroutine call, the entire call will be executed. |
| DEBUG_STATUS_STEP_INTO | The target is currently executing a single instruction. |
| DEBUG_STATUS_STEP_BRANCH | The target is currently running until it encounters a branch instruction. |
| DEBUG_STATUS_GO | The target is currently running normally. It will continue normal execution until an event occurs. |
| DEBUG_STATUS_BREAK | The target is not running. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExecutionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexecutionstatus)