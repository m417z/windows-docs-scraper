# IDebugClient4::ConnectSession

## Description

The **ConnectSession** method joins the client to an existing debugger session.

## Parameters

### `Flags` [in]

Specifies a bit-set of option flags for connecting to the session. The possible values of these flags are:

| Flag | Description |
| --- | --- |
| DEBUG_CONNECT_SESSION_NO_VERSION | Do not output the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction)'s version to this client. |
| DEBUG_CONNECT_SESSION_NO_ANNOUNCE | Do not output a message notifying other clients that this client has connected. |

### `HistoryLimit` [in]

Specifies the maximum number of characters from the session's history to send to this client's output upon connection.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When the client object connects to a session, the most recent output from the session is sent to the client. If the session is currently waiting on input, the client object is given the opportunity to provide input. Thus, the client object synchronizes with the session's input and output.

The client becomes a primary client and will appear among the list of clients in the output of the [.clients](https://learn.microsoft.com/windows-hardware/drivers/debugger/-clients--list-debugging-clients-) debugger command.

For more information about debugging clients, see Debugging Server and Debugging Client. For more information about debugger sessions, see [Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model).

## See also

[DebugConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-debugconnect)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OutputServers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-outputservers)

[StartServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startserver)