# RpcSsContextLockExclusive function

## Description

The
**RpcSsContextLockExclusive** function enables an application to begin using a context handle in exclusive mode. The
**RpcSsContextLockExclusive** function enables methods declared as nonserialized (shared) in the IDL or ACF file to be dynamically changed to access a context handle in serialized (exclusive) mode.

## Parameters

### `ServerBindingHandle` [in]

Binding handle on the server that represents a binding to a client. The server impersonates the client indicated by this handle. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

### `UserContext` [in]

Pointer passed to the manager or server routine by RPC. See Remarks.

For out-only context handles, the
**RpcSsContextLockExclusive** function performs no operation.

## Return value

Returns RPC_S_OK upon successful execution, indicating the thread now has access to the context handle in exclusive mode. Returns ERROR_MORE_WRITES when multiple threads attempt an exclusive lock on the context handle. See Remarks.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Modifying whether a context handle is serialized or nonserialized can be useful to applications that determine whether to close a context handle based on conditions detected upon execution. To change a context handle from serialized (exclusive) to nonserialized (shared), use the
[RpcSsContextLockShared](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockshared) function.

For the *UserContext* parameter, if the manager routine receives a pointer to a context handle, it must pass the
**RpcSsContextLockExclusive** function the same pointer it received from RPC. If the manager routine receives the context handle itself, which is typical for [in] only context handles, it must pass the context handle itself to the
**RpcSsContextLockExclusive** function. The following code example demonstrates this:

```cpp
void _UseShared(
    /* [in] */ handle_t Binding,
    //...
    /* [in] */ TestContextHandleShared *Ctx,
    //...
    )
{
    //...
    RpcStatus = RpcSsContextLockExclusive(Binding, Ctx);
    //...
}

```

If a manager routine takes multiple [in, out] context handles as an argument, RPC gives the manager routine a pointer to the context handle, not the context handle itself. The pointer is guaranteed to be unique, and therefore passing it to the
**RpcSsContextLockExclusive** function is unambiguous. However, if a function takes multiple [in] only context handles, RPC gives the manager routine the context handle itself. Therefore, the context handle may not be unique. In this case, RPC executes this function on the first context handle with the given value.

Methods should not modify a context handle when in shared mode. Calling the
**RpcSsContextLockExclusive** function does not eliminate a reader lock on the specified context handle; this ensures an unchanged context handle for applications that do not modify context handles in shared mode. If two threads attempt to obtain an exclusive lock on the same context handle by calling the
**RpcSsContextLockExclusive** function at the same time, one arbitrarily chosen thread is returned RPC_S_OK, and the other is returned ERROR_MORE_WRITES. The thread that is returned ERROR_MORE_WRITES receives an exclusive lock, but its reader lock on the context handle is lost upon return. A caller receiving ERROR_MORE_WRITES must assume nothing about the context handle upon return of the
**RpcSsContextLockExclusive** function, as it may have been destroyed.

Asynchronous calls must not use the
**RpcSsContextLockExclusive** function on the same call object from more than one thread at a time.

The
**RpcSsContextLockExclusive** function can fail due to out-of-memory conditions, and RPC servers must therefore be prepared to handle such errors.

## See also

[RpcSsContextLockShared](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockshared)

[context_handle](https://learn.microsoft.com/windows/desktop/Midl/context-handle)

[context_handle_noserialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-noserialize)

[context_handle_serialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-serialize)