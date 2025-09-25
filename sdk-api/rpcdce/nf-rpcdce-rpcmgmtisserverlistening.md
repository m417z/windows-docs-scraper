# RpcMgmtIsServerListening function

## Description

The
**RpcMgmtIsServerListening** function tells whether a server is listening for remote procedure calls.

## Parameters

### `Binding`

To determine whether a remote application is listening for remote procedure calls, specify a server binding handle for that application. To determine whether your own (local) application is listening for remote procedure calls, specify a value of **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | Server listening for remote procedure calls. |
| **RPC_S_NOT_LISTENING** | Server not listening for remote procedure calls, or the interface is auto-listening. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

The
**RpcMgmtIsServerListening** function returns correct results only for interfaces that are not auto-listening. If the server application is auto-listening and calls the
**RpcMgmtIsServerListening** function,
**RpcMgmtIsServerListening** returns RPC_SERVER_NOT_LISTENING, yet the server may be listening, and subsequent RPC calls may succeed.

## Remarks

An application calls the
**RpcMgmtIsServerListening** function to determine whether the server specified in the *Binding* parameter is listening for remote procedure calls.

The
**RpcMgmtIsServerListening** function returns a value of **RPC_S_OK** if the server has called
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten).

The server must be listening for remote procedure calls for this function to succeed. If the server is not listening, the function fails.

## See also

[RpcEpResolveBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepresolvebinding)

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)