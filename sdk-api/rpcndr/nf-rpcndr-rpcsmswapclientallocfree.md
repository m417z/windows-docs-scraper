# RpcSmSwapClientAllocFree function

## Description

The
**RpcSmSwapClientAllocFree** function exchanges the client stub's memory-allocation and memory-freeing mechanisms with those supplied by the client.

## Parameters

### `ClientAlloc`

New memory-allocation function.

### `ClientFree`

New memory-releasing function.

### `OldClientAlloc`

Returns the previous memory-allocation function before the call to this function.

### `OldClientFree`

Returns the previous memory-releasing function before the call to this function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSmSetClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetclientallocfree)