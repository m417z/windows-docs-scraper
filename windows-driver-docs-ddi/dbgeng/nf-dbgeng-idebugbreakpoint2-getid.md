# IDebugBreakpoint2::GetId

## Description

The **GetId** method returns a breakpoint ID, which is the engine's unique identifier for a breakpoint.

## Parameters

### `Id` [out]

The breakpoint ID.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The breakpoint ID remains fixed as long as the breakpoint exists. However, after the breakpoint has been removed, you can use its ID for another breakpoint.

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the breakpoint ID.

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).