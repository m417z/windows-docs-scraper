# RpcSmFree function

## Description

The
**RpcSmFree** function releases memory allocated by
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate).

## Parameters

### `NodeToFree`

Pointer to memory allocated by
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate) or
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate).

## Return value

The function
**RpcSmFree** returns the following value.

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Applications use
**RpcSmFree** to free memory allocated by
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate). In cases where the stub allocates the memory for the application,
**RpcSmFree** can also be used to release memory. For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management).

To improve performance, the
**RpcSmFree** function only marks memory for release. Memory is not actually released until your application calls the
[RpcSmDisableAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdisableallocate) function. To release memory immediately, invoke the
[midl_user_free](https://learn.microsoft.com/windows/desktop/Rpc/the-midl-user-free-function) function.

Note that the handle of the thread calling
**RpcSmFree** must match the handle of the thread that allocated the memory by calling
[RpcSmAllocate.](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate). Use
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) and
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) to pass handles from thread to thread.

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle)

[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle)

[midl_user_allocate](https://msdn.microsoft.com/)