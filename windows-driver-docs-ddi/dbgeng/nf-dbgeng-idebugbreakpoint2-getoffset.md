# IDebugBreakpoint2::GetOffset

## Description

The **GetOffset** method returns the location that triggers a breakpoint.

## Parameters

### `Offset` [out]

The location on the target that triggers the breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The breakpoint is deferred and does not currently specify a location in the target's memory address space. To determine the breakpoint location in this case, call [GetOffsetExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getoffsetexpression). |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the location that triggers a breakpoint.

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).