# RpcSsFree function

## Description

The
**RpcSsFree** function releases memory allocated by
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate).

## Parameters

### `NodeToFree`

Pointer to memory allocated by
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate) or
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate).

## Remarks

An application uses
**RpcSsFree** to free memory that was allocated with
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate). In cases where the stub allocates the memory for the environment,
**RpcSsFree** can also be used to release memory. For more information, see
[Memory Management](https://learn.microsoft.com/windows/desktop/Rpc/memory-management).

Note that the handle of the thread calling
**RpcSsFree** must match the handle of the thread that allocated the memory by calling
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate). Use
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) and
[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle) to pass handles from thread to thread.

## See also

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle)

[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle)