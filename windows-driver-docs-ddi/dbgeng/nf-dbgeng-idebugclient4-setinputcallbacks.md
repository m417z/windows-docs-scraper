# IDebugClient4::SetInputCallbacks

## Description

The **SetInputCallbacks** method registers an [input callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) object with the client.

## Parameters

### `Callbacks` [in, optional]

Specifies the interface pointer to the input callbacks object to register with this client.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one [IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks) object registered with it to receive requests for input.

The **IDebugInputCallbacks** interface extends the COM interface **IUnknown**. **SetInputCallbacks** will call the **IUnknown::AddRef** method of the object specified by *Callbacks*. The **IUnknown::Release** method of this interface will be called the next time **SetInputCallbacks** is called on this client, or when this client is deleted.

## See also

[GetInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getinputcallbacks)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks)