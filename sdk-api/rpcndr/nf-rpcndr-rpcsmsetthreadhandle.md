# RpcSmSetThreadHandle function

## Description

The
**RpcSmSetThreadHandle** function sets a thread handle for the stub memory–management environment.

## Parameters

### `Id`

Thread handle returned by a call to
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**RpcSmSetThreadHandle** to set a thread handle for the stub memory–management environment. A thread used to manage memory for the stub memory–management environment calls
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) to obtain a handle for its memory environment. In this way, another thread that calls
**RpcSmSetThreadHandle** by using this handle can then use the same memory-management environment.

The same memory management–thread handle must be used by multiple threads calling
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate) and
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree) to manage the same memory. Before spawning new threads to manage the same memory, the thread that established the memory-management environment (parent thread) calls
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) to obtain a thread handle for this environment. Then, the spawned threads call
**RpcSmSetThreadHandle** with the new manager handle provided by the parent thread.

Note that
**RpcSmSetThreadHandle** is usually called by a thread spawned by a server-manager procedure. The stub sets up the memory-management environment for the manager procedure, and the manager calls
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) to obtain a thread handle. Then, each spawned thread calls
**RpcSmGetThreadHandle** to get access to the manager's memory-management environment.

A thread can also call
[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle) and
**RpcSmSetThreadHandle** to save and restore its memory-management environment.

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSmGetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmgetthreadhandle)