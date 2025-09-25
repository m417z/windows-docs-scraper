# IDebugBreakpoint2::GetOffsetExpressionWide

## Description

The **GetOffsetExpressionWide** method returns the expression string that evaluates to the location that triggers a breakpoint.

## Parameters

### `Buffer` [out, optional]

The expression string that evaluates to the location on the target that triggers the breakpoint. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

The size, in characters, of the buffer that *Buffer* points to.

### `ExpressionSize` [out, optional]

The size, in characters, of the expression string. If *ExpressionSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful, but the buffer was not large enough to hold the expression string and so the string was truncated to fit. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The expression is evaluated every time that a module is loaded or unloaded. If the debugger cannot evaluate the expression (for example, if the expression contains a symbol that cannot be interpreted), the breakpoint is flagged as deferred. (For more information about deferred breakpoints, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).)

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the size of the expression string that specifies the location that triggers the breakpoint, *ExpressionSize*.

For more information about how to use breakpoints, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).