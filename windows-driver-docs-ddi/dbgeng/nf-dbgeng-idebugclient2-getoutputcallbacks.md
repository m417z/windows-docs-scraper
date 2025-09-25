# IDebugClient2::GetOutputCallbacks

## Description

The **GetOutputCallbacks** method returns the [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) object registered with the client.

## Parameters

### `Callbacks` [out]

Receives an interface pointer to the [IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks) object registered with the client.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one [IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks) or **IDebugOutputCallbacksWide** object registered with it for output.

If no output callbacks object is registered with the client, the value of *Callbacks* will be set to **NULL**.

The **IDebugOutputCallbacks** interface extends the COM interface **IUnknown**. Before returning the **IDebugOutputCallbacks** object specified by *Callbacks*, the engine calls its **IUnknown::AddRef** method. When this object is no longer needed, its **IUnknown::Release** method should be called.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks)

[SetOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setoutputcallbacks)