# RpcSsSwapClientAllocFree function

## Description

The
**RpcSsSwapClientAllocFree** function exchanges the memory allocation and release mechanisms used by the client stubs with those supplied by the client.

## Parameters

### `ClientAlloc`

New function to allocate memory.

### `ClientFree`

New function to release memory.

### `OldClientAlloc`

Returns the previous memory-allocation function.

### `OldClientFree`

Returns the previous memory-freeing function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcSsSwapClientAllocFree** exchanges the current memory allocation and memory freeing mechanisms with those supplied by the client.

**Note** **RpcSsSwapClientAllocFree** raises exceptions, unlike
[RpcSmSwapClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmswapclientallocfree), which returns the error code.

## See also

[RpcSmSwapClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmswapclientallocfree)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree)

[RpcSsSetClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetclientallocfree)