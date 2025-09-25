# IDebugBreakpoint2::AddFlags

## Description

The **AddFlags** method adds flags to a [breakpoint](https://learn.microsoft.com/windows-hardware/drivers/debugger/b).

## Parameters

### `Flags` [in]

Additional flags to add to the breakpoint. *Flags* is a bit field that is combined together with the existing flags by using a bitwise OR. For more information about the flag bit field and an explanation of each flag, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters). You cannot modify the DEBUG_BREAKPOINT_DEFERRED flag in the [engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/e). This bit in *Flags* must always be zero.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).