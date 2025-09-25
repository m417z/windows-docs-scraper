# IDebugBreakpoint2::SetOffsetExpressionWide

## Description

The **SetOffsetExpressionWide** methods set an expression string that evaluates to the location that triggers a breakpoint.

## Parameters

### `Expression` [in]

The expression string that evaluates to the location on the target that triggers the breakpoint. If the engine cannot evaluate the expression (for example, if the expression contains a symbol that cannot be interpreted), the breakpoint is flagged as deferred. (For more information about deferred breakpoints, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).) For more information about the expression syntax, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).

## Return value

 This method might return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).