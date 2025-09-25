# IDebugInputCallbacks::StartInput

## Description

The **StartInput** callback method is called by the engine to indicate that it is waiting for a line of input.

## Parameters

### `BufferSize` [in]

Specifies the number of characters requested. Any input longer than this size will be truncated.

## Return value

The return value is ignored by the engine unless it indicates a remote procedure call error; in this case the client, with which this **IDebugEventCallbacks** object is registered, is disabled.

## Remarks

This method indicates that the engine is waiting for a line of input from any client. This can occur if, for example, the [Input](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol-input) method was called on a client.

After calling this method, the engine waits until it receives some input. When it does receive input, it calls [IDebugInputCallbacks::EndInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebuginputcallbacks-endinput) to inform all the **IDebugInputCallbacks** objects that are registered with clients that it is no longer waiting for input.

The **IDebugInputCallbacks** object can provide the engine with a line of input by calling either the [ReturnInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-returninput) or **ReturnInputWide** methods.

For more information about debugger engine input, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).