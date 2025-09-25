# RPC_MGMT_AUTHORIZATION_FN callback function

## Description

The
*RPC_MGMT_AUTHORIZATION_FN* enables server programs to implement custom RPC authorization techniques.

## Parameters

### `ClientBinding`

Client/server binding handle.

### `RequestedMgmtOperation`

The value for *RequestedMgmtOperation* depends on the remote function requested, as shown in the following table.

| Called remote function | Meaning |
| --- | --- |
| **RpcMgmtInqIfIds** | RPC_C_MGMT_INQ_IF_IDS |
| **RpcMgmtInqServerPrincName** | RPC_C_MGMT_INQ_PRINC_NAME |
| **RpcMgmtInqStats** | RPC_C_MGMT_INQ_STATS |
| **RpcMgmtIsServerListening** | RPC_C_MGMT_IS_SERVER_LISTEN |
| **RpcMgmtStopServerListening** | RPC_C_MGMT_STOP_SERVER_LISTEN |

The authorization function must handle all of these values.

### `Status`

If *Status* is either 0 (zero) or RPC_S_OK, the *Status* value RPC_S_ACCESS_DENIED is returned to the client by the remote management function. If the authorization function returns any other value for *Status*, that *Status* value is returned to the client by the remote management function.

## Return value

Returns **TRUE** if the calling client is allowed access to the requested management function. If the authorization function returns **FALSE**, the management function cannot execute. In this case, the function returns a *Status* value to the client:

## Remarks

When a client requests one of the server's remote management functions, the server run-time library calls the authorization function with *ClientBinding* and *RequestedMgmtOperation*. The authorization function uses these parameters to determine whether the calling client can execute the requested management function.

## See also

[Authorization Functions](https://learn.microsoft.com/windows/desktop/Rpc/authorization-functions)

[RpcMgmtSetAuthorizationFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetauthorizationfn)