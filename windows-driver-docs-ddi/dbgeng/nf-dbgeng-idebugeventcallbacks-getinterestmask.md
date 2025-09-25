# IDebugEventCallbacks::GetInterestMask

## Description

The **GetInterestMask** callback method is called to determine which [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events) the **IDebugEventCallbacks** object is interested in. The engine calls **GetInterestMask** when the object is registered with a client by using [SetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-seteventcallbacks).

## Parameters

### `Mask` [out]

Receives a bitmask that indicates which events the object is interested in. The engine will call only those methods that correspond to the bit flags set by **GetInterestMask**. For a description of the bit flags and their corresponding methods, see [DEBUG_EVENT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-event-xxx).

## Return value

The return value S_OK indicates the method was successful. All other return values indicate an error occurred, in which case the **SetEventCallbacks** call will fail and the callback object will not be used nor will it receive events.

## Remarks

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).