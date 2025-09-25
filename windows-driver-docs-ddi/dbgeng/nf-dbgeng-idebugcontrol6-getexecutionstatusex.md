# IDebugControl6::GetExecutionStatusEx

## Description

The GetExecutionStatusEx method returns information about the execution status of the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

## Parameters

### `Status` [out]

Receives the extended execution status. This will be set to values described in [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[IDebugControl6](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol6)