# IDebugBreakpoint2::GetMatchThreadId

## Description

The **GetMatchThreadId** method returns the engine thread ID of the thread that can trigger a breakpoint.

## Parameters

### `Id` [out]

The engine thread ID of the thread that can trigger this breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No specific thread has been set for this breakpoint. Any thread can trigger the breakpoint. |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

If you have set a thread for the breakpoint, the breakpoint can be triggered only if that thread hits the breakpoint. If you have not set a thread , any thread can trigger the breakpoint and *Id* receives **NULL**.

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the engine thread ID of the thread that can trigger the breakpoint.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).