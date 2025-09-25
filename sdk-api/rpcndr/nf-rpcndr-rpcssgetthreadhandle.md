# RpcSsGetThreadHandle function

## Description

The
**RpcSsGetThreadHandle** function returns a thread handle for the stub memory–management environment.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**RpcSsGetThreadHandle** to obtain a thread handle for the stub memory–management environment. A thread used to manage memory for the stub memory–management environment uses
**RpcSsGetThreadHandle** to receive a handle for its memory environment. In this way, another thread that calls
[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle) by using this handle can then use the same memory-management environment.

The same thread handle must be used by multiple threads calling
[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate) and
[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree) to manage the same memory. Before spawning new threads to manage the same memory, the thread that established the memory-management environment (parent thread) calls
**RpcSsGetThreadHandle** to obtain a thread handle for this environment. Then, the spawned threads call
[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle) with the handle provided by the parent thread.

Typically, a server manager procedure calls
**RpcSsGetThreadHandle** before additional threads are spawned. The stub sets up the memory-management environment for the manager procedure, and the manager calls
**RpcSsGetThreadHandle** to make this environment available to the other threads.

A thread can also call
**RpcSsGetThreadHandle** and
[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle) to save and restore its memory-management environment.

**Note** **RpcSsGetThreadHandle** raises exceptions, while
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) returns the error code.

## See also

[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle)

[RpcSsAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssallocate)

[RpcSsFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssfree)

[RpcSsSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsssetthreadhandle)