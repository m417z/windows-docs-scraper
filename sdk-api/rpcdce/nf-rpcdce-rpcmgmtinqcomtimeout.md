# RpcMgmtInqComTimeout function

## Description

The
**RpcMgmtInqComTimeout** function returns the binding-communications time-out value in a binding handle.

## Parameters

### `Binding`

Specifies a binding.

### `Timeout`

Returns a pointer to the time-out value from the *Binding* parameter.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A client application calls
**RpcMgmtInqComTimeout** to view the time-out value in a server binding handle. The time-out value specifies the relative amount of time that should be spent to wait for a response from the server before giving up. For a table of the time-out values, see
[Binding Time-out Constants](https://learn.microsoft.com/windows/desktop/Rpc/binding-time-out-constants). For more information on how the COM time-out operates, and when to use it, see
[RPC and the Network](https://learn.microsoft.com/windows/desktop/Rpc/rpc-and-the-network).

A client also calls
[RpcMgmtSetComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetcomtimeout) to change the time-out value.

## See also

[Binding
Time-out Constants](https://learn.microsoft.com/windows/desktop/Rpc/binding-time-out-constants)

[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats)

[RpcMgmtSetComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetcomtimeout)