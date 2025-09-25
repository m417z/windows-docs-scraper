# IDebugClient::GetInputCallbacks

## Description

The **GetInputCallbacks** method returns the [input callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) object registered with this client.

## Parameters

### `Callbacks` [out]

Receives an interface pointer for the [IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks) object registered with the client.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one [IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks) object registered with it to receive requests for input.

If no **IDebugInputCallbacks** object is registered with the client, the value of *Callbacks* will be set to **NULL**.

The **IDebugInputCallbacks** interface extends the COM interface **IUnknown**. Before returning the **IDebugInputCallbacks** object specified by *Callbacks*, the engine calls its **IUnknown::AddRef** method. When this object is no longer needed, its **IUnknown::Release** method should be called.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks)

[SetInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setinputcallbacks)