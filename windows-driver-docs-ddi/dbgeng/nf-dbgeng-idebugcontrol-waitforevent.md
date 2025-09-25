# IDebugControl::WaitForEvent

## Description

 The **WaitForEvent** method waits for an event that breaks into the debugger engine application.

## Parameters

### `Flags` [in]

Set to zero. There are currently no flags that can be used in this parameter.

### `Timeout` [in]

Specifies how many milliseconds to wait before this method will return. If *Timeout* is INFINITE, this method will not return until an event that breaks into the debugger engine application occurs or an exit interrupt is issued. If the current session has a live kernel target, *Timeout* must be set to INFINITE.

## Return value

This method may return other error values and the above error values may have additional meanings. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The time-out expired. |
| **E_PENDING** | An exit interrupt was issued. The target is not available. |
| **E_UNEXPECTED** | Either there is an outstanding request for input, or none of the targets could generate events. |
| **E_FAIL** | The engine is already waiting for an event. |

## Remarks

The method can be called only from the thread that started the debugger session.

When an event occurs, the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) will process the event and call the event callbacks. If one of these callbacks indicates that the event should break into the debugger engine application (by returning DEBUG_STATUS_BREAK), this method will return; otherwise, it will continue waiting for an event. The event filters can also specify that an event should break into the debugger engine application. For more information about event filters, see [Controlling Exceptions and Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-exceptions-and-events).

This method is not re-entrant. Once it has been called, it cannot be called again on any client until it has returned. In particular, it cannot be called from the event callbacks, including extensions and commands executed by the callbacks.

If none of the targets are capable of generating events -- for example, all the targets have exited -- this method will end the current session, discard the targets, and then return E_UNEXPECTED.

The constant INFINITE is defined in Winbase.h.

For more information about using **WaitForEvent** to control the execution flow of the debugger application and targets, see [Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model). For details on the event callbacks, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)