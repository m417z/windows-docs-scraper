# RpcNsBindingLookupDone function

## Description

The
**RpcNsBindingLookupDone** function signifies that a client has finished looking for compatible servers and deletes the lookup context.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `LookupContext`

Pointer to the name-service handle to free. The name-service handle *LookupContext* points to is created by calling the
[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina) function.

An argument value of **NULL** is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingLookupDone** function frees a lookup context created by calling the
[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina) function.

Typically, a client application calls
**RpcNsBindingLookupDone** after completing remote procedure calls to a server using a binding handle returned from the
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext) function. However, a client application is responsible for calling
**RpcNsBindingLookupDone** for each created lookup context, regardless of the status returned from the
**RpcNsBindingLookupNext** function or the success in making remote procedure calls.

## See also

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)