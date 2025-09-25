# IDebugClient5::GetNumberEventCallbacks

## Description

The **GetNumberEventCallbacks** method returns the number of event callbacks that are interested in the given [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events).

## Parameters

### `EventFlags` [in]

Specifies a set of events used to filter out some of the event callbacks; only event callbacks that have indicated an interest in one of the events in *EventFlags* will be counted. See [DEBUG_EVENT_XXX](https://learn.microsoft.com/previous-versions/ff541478(v=vs.85)) for a list of the events.

### `Count` [out]

Receives the number of event callbacks that are interested in at least one of the events in *EventFlags*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one event callback registered with it. When a callback is registered with a client, its [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask) method is called to allow the client to specify which events it is interested in.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[GetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-geteventcallbacks)

[GetNumberInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberinputcallbacks)

[GetNumberOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberoutputcallbacks)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbacks)

[SetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-seteventcallbacks)