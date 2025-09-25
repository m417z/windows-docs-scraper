# IDebugBreakpoint2::SetFlags

## Description

The **SetFlags** method sets the flags for a breakpoint.

## Parameters

### `Flags` [in]

The new flags for the breakpoint. *Flags* is a bit field. It replaces the existing flag bits. For more information about the flag bit field and an explanation of each flag, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters). You cannot change the DEBUG_BREAKPOINT_DEFERRED flag in the engine. This bit in *Flags* must always be zero.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).