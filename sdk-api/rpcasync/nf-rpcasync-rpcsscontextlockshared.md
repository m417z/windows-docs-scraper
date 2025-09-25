# RpcSsContextLockShared function

## Description

The
**RpcSsContextLockShared** function enables an application to begin using a context handle in shared mode.

## Parameters

### `ServerBindingHandle` [in]

Binding handle on the server that represents a binding to a client. The server impersonates the client indicated by this handle. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

### `UserContext` [in]

Pointer passed to the manager or server routine by RPC. See Remarks for more information.

For [out] only context handles, the
**RpcSsContextLockShared** function performs no operation.

## Return value

Returns RPC_S_OK upon successful execution, indicating the thread now has access to the context handle in shared mode.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Modifying whether a context handle is serialized or nonserialized can be useful to applications that determine whether to close a context handle based on conditions detected upon execution. To change a context handle from nonserialized (shared) to serialized (exclusive), use the
[RpcSsContextLockExclusive](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockexclusive) function.

For the *UserContext* parameter, if the manager routine receives a pointer to a context handle, it must pass the
**RpcSsContextLockShared** function the same pointer it received from RPC. If the manager routine receives the context handle itself, which is typical for [in] only context handles, it must pass the context handle itself to the
**RpcSsContextLockShared** function. The following code example demonstrates this:

``` syntax
UseExclusive (..., /* [in] */ TestContextHandleExclusive *Ctx, ...)
{
    ...
    // we decided that we're done changing the context handle exclusively
    // and that we have extensive processing ahead - downgrade the exclusive
    // lock to shared, and do the processing allowing other readers in
    RpcSsContextLockShared (NULL,    // use the explicit context
        Ctx
        );
    ...
}
```

If a manager routine takes multiple [in, out] context handles as an argument, RPC gives the manager routine a pointer to the context handle, not the context handle itself. The pointer is guaranteed to be unique, and therefore passing it to the
**RpcSsContextLockShared** function is unambiguous. However, if a function takes multiple [in] only context handles, RPC gives the manager routine the context handle itself. Therefore, the context handle may not be unique. In this case, RPC executes this function on the first context handle with the given value.

Methods should not modify a context handle when in shared mode. Calling the
**RpcSsContextLockShared** function does not eliminate a writer lock on the specified context handle; this ensures the context handle will not be changed by another thread.

Asynchronous calls must not use the
**RpcSsContextLockShared** function on the same call object from more than one thread at a time.

The
**RpcSsContextLockShared** function can fail due to out-of-memory conditions, and RPC servers must therefore be prepared to handle such errors.

## See also

[RpcSsContextLockExclusive](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcsscontextlockexclusive)

[context_handle](https://learn.microsoft.com/windows/desktop/Midl/context-handle)

[context_handle_noserialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-noserialize)

[context_handle_serialize](https://learn.microsoft.com/windows/desktop/Midl/context-handle-serialize)