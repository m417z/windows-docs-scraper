# IDebugClient6::SetEventContextCallbacks

## Description

Registers an event callbacks object with this client.

## Parameters

### `Callbacks` [in, optional]

The interface pointer to the event callbacks object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

This event interface replaces the use of [IDebugClient::SetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-seteventcallbacks).

## See also

[IDebugClient6](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient6)

[IDebugClient::SetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-seteventcallbacks)