# IDebugClient2::SetEventCallbacks

## Description

The **SetEventCallbacks** method registers an event callbacks object with this client.

## Parameters

### `Callbacks` [in, optional]

Specifies the interface pointer to the event callbacks object to register with this client.

## Return value

Depending on the implementation of the method [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask) in the object specified by *Callbacks*, other values may be returned, as described in the Remarks section.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If the value of *Callbacks* is not **NULL**, the method **IDebugEventCallbacks::GetInterestMask** is called. If the return value is not S_OK, **SetEventCallbacks** and **SetEventCallbacksWide** have no effect and they return this value.

Each client can have at most one [IDebugEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbacks) or **IDebugEventCallbacksWide** object registered with it for receiving [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events).

The **IDebugEventCallbacks** interface extends the COM interface **IUnknown**. When **SetEventCallbacks** and **SetEventCallbacksWide** are successful, they call the **IUnknown::AddRef** method of the object specified by *Callbacks*. The **IUnknown::Release** method of this object will be called the next time **SetEventCallbacks** or **SetEventCallbacksWide** is called on this client, or when this client is deleted.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[GetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-geteventcallbacks)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbacks)