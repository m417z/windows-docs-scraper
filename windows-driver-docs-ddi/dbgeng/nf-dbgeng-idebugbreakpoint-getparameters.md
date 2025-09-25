# IDebugBreakpoint::GetParameters

## Description

The **GetParameters** method returns the parameters for a breakpoint.

## Parameters

### `Params` [out]

The breakpoint's parameters. For more information about the parameters, see [DEBUG_BREAKPOINT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_breakpoint_parameters).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The **GetParameters** method is a convenience method that returns most of the parameters that the other [IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint) methods return.

For a list of the parameters and flags that this method retrieves, and for other ways to read and write these parameters and flags, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters) and [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).