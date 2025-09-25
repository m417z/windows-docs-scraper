# RpcSsAllocate function

## Description

The
**RpcSsAllocate** function allocates memory within the RPC stub memory-management function, and returns a pointer to the allocated memory or **NULL**.

## Parameters

### `Size`

Size of memory to allocate, in bytes.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcSsAllocate** function allows an application to allocate memory within the RPC stub memory–management function. Prior to calling
**RpcSsAllocate**, the memory-management environment must already be established. For memory management called within the stub, the stub itself usually establishes the necessary environment. For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management). When using
**RpcSsAllocate** to allocate memory not called from the stub, the application must call
[RpcSsEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssenableallocate) to establish the required memory-management environment.

The
**RpcSsAllocate** routine returns a pointer to the allocated memory, if the call was successful. Otherwise, it raises an exception.

When the stub establishes the memory management, it frees any memory allocated by
**RpcSsAllocate**. The application can free such memory before returning to the calling stub by calling
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree).

By contrast, when the application establishes the memory management, it must free any allocated memory. It does so by calling either
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree) or
[RpcSsDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssdisableallocate).

To manage the same memory within the stub memory–management environment, multiple threads can call
**RpcSsAllocate** and
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree). In this case, the threads must share the same stub memory management–thread handle. Applications pass thread handles from thread-to-thread by calling
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) and
[RPCSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle).

**Note** The
**RpcSsAllocate** routine raises exceptions, unlike
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate), which returns the error code.

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSsDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssdisableallocate)

[RpcSsEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssenableallocate)

[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree)

[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle)

[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle)