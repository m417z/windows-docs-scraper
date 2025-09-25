# IDebugControl2::SetExecutionStatus

## Description

The **SetExecutionStatus** method requests that the debugger engine enter an executable state. Actual execution will not occur until the next time [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) is called.

## Parameters

### `Status` [in]

Specifies the mode for the engine to use when executing. Possible values are those values in the table in [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) whose precedence lies between DEBUG_STATUS_GO and DEBUG_STATUS_STEP_INTO.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | Something prevented the execution of this method. Possible causes include: there is no current target, there is an outstanding request for input, or execution is not supported in the current target. |
| **E_ACCESSDENIED** | The target is already executing. |
| **E_NOINTERFACE** | No target can generate any more events. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetExecutionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexecutionstatus)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)