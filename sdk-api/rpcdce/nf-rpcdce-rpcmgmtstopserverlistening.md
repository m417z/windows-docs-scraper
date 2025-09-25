# RpcMgmtStopServerListening function

## Description

The
**RpcMgmtStopServerListening** function tells a server to stop listening for remote procedure calls. This function will not affect auto-listen interfaces. See
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) for more details.

## Parameters

### `Binding`

To direct a remote application to stop listening for remote procedure calls, specify a server binding handle for that application. To direct your own (local) application to stop listening for remote procedure calls, specify a value of **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtStopServerListening** function to direct a server to stop listening for remote procedure calls. If *DontWait* was **TRUE**, the application should call
[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten) to wait for all calls to complete.

When it receives a stop-listening request, the RPC run-time library stops accepting new remote procedure calls for all registered interfaces. Executing calls are allowed to complete, including callbacks. After all calls complete, this function signals [RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) function that it must stop listening and return to the caller. If the *DontWait* parameter of **RpcServerListen** was set to **TRUE**, the application calls
[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten) for all remaining calls to complete.

**Note** From the client-side,
**RpcMgmtStopServerListening** is disabled by default. To enable this function, create an authorization function in your server application that returns **TRUE** (to allow a remote shutdown) whenever
**RpcMgmtStopServerListening** is called. Use
[RpcMgmtSetAuthorizationFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetauthorizationfn) to give the client access to the management function.

The server must be listening for remote procedure calls for this function to succeed. If the server is not listening, the function fails.

## See also

[RpcEpResolveBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepresolvebinding)

[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten)

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)