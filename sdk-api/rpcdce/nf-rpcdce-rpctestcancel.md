# RpcTestCancel function

## Description

The
**RpcTestCancel** function checks for a cancel indication.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call has been canceled. |
| **Other values** | The call has not been canceled. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

It is not unusual for the
**RpcTestCancel** function to return the value ERROR_ACCESS_DENIED. This indicates that the remote procedure call has not been canceled.

## Remarks

An application server stub calls
**RpcTestCancel** to determine whether a call has been canceled. If the call has been canceled, RPC_S_OK is returned; otherwise, another value is returned.

This function should be called periodically by the server stub so that it can respond to cancels in a timely fashion. If the function returns RPC_S_OK, the stub should clean up its data structures and return to the client.

## See also

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)