# RpcSmSetClientAllocFree function

## Description

The
**RpcSmSetClientAllocFree** function enables the memory allocation and release mechanisms used by the client stubs.

## Parameters

### `ClientAlloc`

Function used to allocate memory.

### `ClientFree`

Function used to release memory and used with the function specified by *pfnAllocate*.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

By overriding the default routines used by the client stub to manage memory,
**RpcSmSetClientAllocFree** establishes the memory allocation and memory-freeing mechanisms. Note that the default routines are [free](https://learn.microsoft.com/windows/desktop/Rpc/pointers-and-memory-allocation) and **malloc**, unless the remote call occurs within manager code. In this case, the default memory–management functions are
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree) and
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate).

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)