# RpcSmClientFree function

## Description

The
**RpcSmClientFree** function frees memory returned from a client stub.

## Parameters

### `pNodeToFree`

Pointer to memory returned from a client stub.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcSmClientFree** function releases memory allocated and returned from a client stub. The memory management handle of the thread calling this function must match the handle of the thread that made the RPC call. Use
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) and
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) to pass handles from thread to thread.

Note that using
**RpcSmClientFree** allows a function to free dynamically-allocated memory returned by an RPC call without knowing the memory-management environment from which it was called.

## See also

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle)

[RpcSmSetClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetclientallocfree)

[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle)

[RpcSmSwapClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmswapclientallocfree)