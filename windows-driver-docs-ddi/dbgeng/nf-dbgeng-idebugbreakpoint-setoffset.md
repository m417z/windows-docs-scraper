# IDebugBreakpoint::SetOffset

## Description

The **SetOffset** method sets the location that triggers a breakpoint.

## Parameters

### `Offset` [in]

The location on the target that triggers the breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The breakpoint is deferred. |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).