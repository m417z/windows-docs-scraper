# RpcSmGetThreadHandle function

## Description

The
**RpcSmGetThreadHandle** function returns a thread handle, or **NULL**, for the stub memory–management environment.

## Parameters

### `pStatus`

Pointer to the returned status.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Applications call
**RpcSmGetThreadHandle** to obtain a thread handle for the stub memory–management environment. A thread used to manage memory for the stub memory–management environment uses
**RpcSmGetThreadHandle** to receive a handle for its memory environment. In this way, another thread that calls
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) by using this handle can then use the same memory-management environment.

The same memory management thread handle must be used by multiple threads calling
[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate) and
[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree) in order to manage the same memory. Before spawning new threads to manage the same memory, the thread that established the memory-management environment (parent thread) calls
**RpcSmGetThreadHandle** to obtain a thread handle for this environment. Then, the spawned threads call
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) with the new manager handle provided by the parent thread.

Typically a server manager procedure calls
**RpcSmGetThreadHandle** before additional threads are spawned. The stub sets up the memory-management environment for the manager procedure, and the manager calls
**RpcSmGetThreadHandle** to make this environment available to the other threads.

A thread can also call
**RpcSmGetThreadHandle** and
[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle) to save and restore its memory-management environment.

## See also

[RpcSmAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmallocate)

[RpcSmFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmfree)

[RpcSmSetThreadHandle](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmsetthreadhandle)