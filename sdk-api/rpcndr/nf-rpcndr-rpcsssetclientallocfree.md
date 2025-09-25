# RpcSsSetClientAllocFree function

## Description

The
**RpcSsSetClientAllocFree** function enables the memory allocation and release mechanisms used by the client stubs.

## Parameters

### `ClientAlloc`

Memory-allocation function.

### `ClientFree`

Memory-releasing function used with the memory-allocation function specified by *pfnAllocate*.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

By overriding the default routines used by the client stub to manage memory,
**RpcSsSetClientAllocFree** establishes the memory allocation and memory freeing mechanisms. Note that the default routines are free and malloc, unless the remote call occurs within manager code. In this case, the default memory–management routines are
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree) and
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate).

Note that when
**RpcSsSetClientAllocFree** reclaims the memory resources, it also makes the context handle **NULL**.

**Note** **RpcSsSetClientAllocFree** raises exceptions, unlike
[RpcSmSetClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetclientallocfree), which returns the error code.

## See also

[RpcSmSetClientAllocFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetclientallocfree)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree)