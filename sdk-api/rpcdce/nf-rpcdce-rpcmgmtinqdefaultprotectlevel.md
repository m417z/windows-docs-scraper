# RpcMgmtInqDefaultProtectLevel function

## Description

The
**RpcMgmtInqDefaultProtectLevel** function returns the default authentication level for an authentication service.

## Parameters

### `AuthnSvc`

Authentication service for which to return the default authentication level. Valid values are the constant for any valid security provider.

### `AuthnLevel`

Returns the default authentication level for the specified authentication service. The authentication level determines the degree to which authenticated communications between the client and server are protected. For more information, see
[Authentication Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_UNKNOWN_AUTH_SERVICE** | Unknown authentication service. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtInqDefaultProtectLevel** function to obtain the default authentication level for a specified authentication service.

## See also

[RpcMgmtInqComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqcomtimeout)

[RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids)