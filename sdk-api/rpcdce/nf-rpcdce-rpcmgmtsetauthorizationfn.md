# RpcMgmtSetAuthorizationFn function

## Description

The
**RpcMgmtSetAuthorizationFn** function establishes an authorization function for processing remote calls to a server's management functions.

## Parameters

### `AuthorizationFn`

Specifies an authorization function. The RPC server run-time library automatically calls this function whenever the server run-time receives a client request to execute one of the remote management functions. The server must implement this function. Applications specify a value of **NULL** to unregister a previously registered authorization function. After such a call, default authorizations are used.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Server applications call the
**RpcMgmtSetAuthorizationFn** function to establish an authorization function that controls access to the server's remote management functions. When a server has not called
**RpcMgmtSetAuthorizationFn**, or calls with a **null** value for *AuthorizationFn*, the server run-time library uses the following default authorizations.

| Remote function | Default authorization |
| --- | --- |
| [RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids) | Enabled |
| [RpcMgmtInqServerPrincName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqserverprincname) | Enabled |
| [RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats) | Enabled |
| [RpcMgmtIsServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtisserverlistening) | Enabled |
| [RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) | Disabled |

In the preceding table, "Enabled" indicates that all clients can execute the remote function, and "Disabled" indicates that all clients are prevented from executing the remote function.

## See also

[RPC_MGMT_AUTHORIZATION_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_mgmt_authorization_fn)

[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats)

[RpcMgmtIsServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtisserverlistening)

[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening)

[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten)