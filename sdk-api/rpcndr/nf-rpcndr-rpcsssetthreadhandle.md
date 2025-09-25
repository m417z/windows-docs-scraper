# RpcSsSetThreadHandle function

## Description

The
**RpcSsSetThreadHandle** function sets a thread handle for the stub memory–management environment.

## Parameters

### `Id`

Thread handle returned by a call to
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle).

## Remarks

An application calls
**RpcSsSetThreadHandle** to set a thread handle for the stub memory–management environment. A thread used to manage memory for the stub memory–management environment calls
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) to obtain a handle for its memory environment. In this way, another thread that calls
**RpcSsSetThreadHandle** by using this handle can then use the same memory-management environment.

The same thread handle must be used by multiple threads calling
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate) and
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree) in order to manage the same memory. Before spawning new threads to manage the same memory, the thread that established the memory-management environment (parent thread) calls
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) to obtain a thread handle for this environment. Then, the spawned threads call
**RpcSsSetThreadHandle** with the handle provided by the parent thread.

Typically, a thread spawned by a server manager procedure calls
**RpcSsSetThreadHandle**. The stub sets up the memory-management environment for the manager procedure, and the manager calls
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) to obtain a thread handle. Then, each spawned thread calls
**RpcSsGetThreadHandle** to get access to the manager's memory-management environment.

A thread can also call
[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle) and
**RpcSsSetThreadHandle** to save and restore its memory-management environment.

**Note** The
**RpcSsSetThreadHandle** routine raises exceptions, while the
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) routine returns the error code.

## See also

[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree)

[RpcSsGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssgetthreadhandle)