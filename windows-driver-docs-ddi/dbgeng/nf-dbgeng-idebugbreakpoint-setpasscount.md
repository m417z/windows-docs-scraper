# IDebugBreakpoint::SetPassCount

## Description

The **SetPassCount** method sets the number of times that the target must reach the breakpoint location before the breakpoint is triggered.

## Parameters

### `Count` [in]

The number of times that the target must hit the breakpoint before it is triggered. The number of times the target must pass the breakpoint without triggering it is the value of *Count*, minus one.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

Every time that the **SetPassCount** method is called, the number of times that the target must reach the breakpoint location before the breakpoint is triggered is reset.

After the target has hit the breakpoint enough times to trigger the breakpoint, the breakpoint is triggered every time that it is hit, unless **SetPassCount** is called again.

If the debugger executes the code at the breakpoint location while stepping through the code, this execution does not contribute to the number of times that remain before the breakpoint is triggered.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).