# IDebugBreakpoint2::RemoveFlags

## Description

The **RemoveFlags** method removes flags from a breakpoint.

## Parameters

### `Flags` [in]

Flags to remove from the breakpoint. *Flags* is a bit field. The new value of the flags in the engine is the old value and not the value of *Flags*. For more information about the flag bit field and an explanation of each flag, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters). You cannot modify the DEBUG_BREAKPOINT_DEFERRED flag in the engine. This bit in *Flags* must always be zero.

## Return value

**RemoveFlags** might return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).