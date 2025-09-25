# IDebugBreakpoint2::SetMatchThreadId

## Description

The **SetMatchThreadId** method sets the engine thread ID of the thread that can trigger a breakpoint.

## Parameters

### `Thread` [in]

The engine thread ID of the thread that can trigger this breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The thread that *Thread* specifies could not be found. |
| **E_INVALIDARG** | The target is in a kernel and the breakpoint is a processor breakpoint. Processor breakpoints cannot be limited to threads in kernel mode. |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

If you have set a thread for the breakpoint, the breakpoint can be triggered only if that thread hits the breakpoint. If you have not set a thread, any thread can trigger the breakpoint.

If you have set a thread, you can remove the setting by setting *Id* to DEBUG_ANY_ID.

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).