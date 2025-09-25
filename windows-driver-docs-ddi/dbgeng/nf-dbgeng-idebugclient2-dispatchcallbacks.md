# IDebugClient2::DispatchCallbacks

## Description

The **DispatchCallbacks** method lets the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) use the current thread for callbacks.

## Parameters

### `Timeout` [in]

Specifies how many milliseconds to wait before this method will return. If *Timeout* is INFINITE, this method will not return until [ExitDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-exitdispatch) is called or an error occurs.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful (**ExitDispatch** was used). |
| **S_FALSE** | *Timeout* milliseconds elapsed. |

## Remarks

This method returns when *Timeout* milliseconds have elapsed, [ExitDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-exitdispatch) is called, or an error occurs.

Almost all client methods must be called from the thread in which the client was created; [callback objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/callback-objects) registered with the client are also called from this thread. When **DispatchCallbacks** is called the engine can use the current thread to make callback calls.

Client threads should call this method whenever possible to allow the callbacks to be called, unless the thread was the same thread used to start the debugger session, in which case the callbacks are called when [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) is called.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[ExitDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-exitdispatch)

[FlushCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-flushcallbacks)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent)