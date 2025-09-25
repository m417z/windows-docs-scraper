# IDebugControl4::ResetManagedStatus

## Description

Clears and reinitializes the engine's managed code debugging support of the runtime debugging APIs provided by the common language runtime (CLR).

## Parameters

### `Flags` [in]

Flags for the debugging API.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

Managed debugging support relies on debugging functionality provided by the CLR.

## See also

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)