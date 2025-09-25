# RpcSmAllocate function

## Description

The
**RpcSmAllocate** function allocates memory within the RPC stub memory management function and returns a pointer to the allocated memory or **NULL**.

## Parameters

### `Size`

Size of memory to allocate, in bytes.

### `pStatus`

Pointer to the returned status.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcSmAllocate** routine allows an application to allocate memory within the RPC stub memory–management environment. Prior to calling
**RpcSmAllocate**, the memory-management environment must already be established. For memory management called within the stub, the server stub itself may establish the necessary environment. For more information, see
[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate). When using
**RpcSmAllocate** to allocate memory not called from the stub, the application must call
**RpcSmEnableAllocate** to establish the required memory-management environment.

The
**RpcSmAllocate** routine returns a pointer to the allocated memory if the call is successful. Otherwise, a **NULL** is returned.

When the stub establishes the memory management, it frees any memory allocated by
**RpcSmAllocate**. The application can free such memory before returning to the calling stub by calling
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree).

By contrast, when the application establishes the memory management, it must free any memory allocated. It does so by calling either
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree) or
[RpcSmDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdisableallocate).

To manage the same memory within the stub memory–management environment, multiple threads can call
**RpcSmAllocate** and
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree). In this case, the threads must share the same stub memory management thread handle. Applications pass thread handles from thread to thread by calling
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) and
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle).

For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management).

## See also

[RpcSmDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdisableallocate)

[RpcSmEnableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmenableallocate)

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle)

[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle)