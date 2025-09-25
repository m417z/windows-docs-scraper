# IDebugBreakpoint::GetCurrentPassCount

## Description

The **GetCurrentPassCount** method returns the remaining number of times that the target must reach the breakpoint location before the breakpoint is triggered.

## Parameters

### `Count` [out]

The remaining number of times that the target must hit the breakpoint before it is triggered. The number of times that the target must pass the breakpoint without triggering it is the value that is returned to *Count*, minus one.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The [GetPassCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getpasscount) method returns the number of hits that were originally required to trigger the breakpoint. **GetCurrentPassCount** returns the number of hits that still must occur to trigger the breakpoint. For example, if a breakpoint was created with a pass count of 20, and there have been 5 passes so far, **GetPassCount** returns 20 and **GetCurrentPassCount** returns 15.

After the target has hit the breakpoint enough times to trigger it, the breakpoint is triggered every time that it is hit, unless [SetPassCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-setpasscount) is called again. You can also call **SetPassCount** to change the pass count before the breakpoint has been triggered. This call resets the original pass count and the remaining pass count.

If the debugger executes the code at the breakpoint location while stepping through the code, this execution does not contribute to the number of times that remain before the breakpoint is triggered.

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the information that is returned in *Count*.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).