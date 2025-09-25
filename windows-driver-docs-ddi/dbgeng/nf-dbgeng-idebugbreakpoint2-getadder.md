# IDebugBreakpoint2::GetAdder

## Description

The **GetAdder** method returns the client that owns the breakpoint.

## Parameters

### `Adder` [out]

An [IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient) interface pointer to the client object that added the breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The client that owns the breakpoint is the client that created the breakpoint by using the [AddBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addbreakpoint) method. A breakpoint might not have an owner. If a breakpoint does not have an owner, *Adder* is set to **NULL**.

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).