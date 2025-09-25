# IDebugClient::CreateClient

## Description

The **CreateClient** method creates a new client object for the current thread.

## Parameters

### `Client` [out]

Receives an interface pointer for the new client.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method creates a client that may be used in the current thread.

Clients are specific to the thread that created them. Calls from other threads fail immediately. The **CreateClient** method is a notable exception; it allows creation of a new client for a new thread.

All callbacks for a client are made in the thread with which the client was created.

For more information about client objects and how they are used in the debugger engine, see [Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects).

## See also

[DebugCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-debugcreate)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)