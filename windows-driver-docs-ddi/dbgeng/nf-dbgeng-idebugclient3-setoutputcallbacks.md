# IDebugClient3::SetOutputCallbacks

## Description

The **SetOutputCallbacks** method registers an [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) object with this client.

## Parameters

### `Callbacks` [in, optional]

Specifies the interface pointer to the output callbacks object to register with this client.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one [IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks) or **IDebugOutputCallbacks** object registered with it for output.

The **IDebugOutputCallbacks** interface extends the COM interface **IUnknown**. **SetOutputCallbacks** and **SetOutputCAllbacksWide** call the **IUnknown::AddRef** method in the object specified by *Callbacks*. The **IUnknown::Release** method of this interface will be called the next time **SetOutputCallbacks** or **SetOutputCallbacksWide** is called on this client, or when this client is deleted.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[GetOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getoutputcallbacks)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks)