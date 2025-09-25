# RpcServerInqBindingHandle function

## Description

The **RpcServerInqBindingHandle** function obtains the binding handle for RPC calls serviced by the thread in which **RpcServerInqBindingHandle** is called.

## Parameters

### `Binding`

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that, upon success, receives the binding handle for the call serviced by the thread on which **RpcServerInqBindingHandle** is also called.

If the call fails, this parameter is undefined.

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned. This function cannot fail unless it is called on a thread that is not currently servicing an RPC call.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcServerInqBindingHandle** is used to obtain the binding handle for the RPC call that is currently executing on the thread from which this API is also called. Since many RPC APIs require a binding handle as input, this is a convenient way to obtain a binding handle.

Note that all server-side RPC APIs that take a binding handle as a parameter allow you to pass NULL as an accepted value. Passing NULL instead of a binding handle indicates that the binding handle for the RPC call currently executing in the same thread should be used. However, if you call a server-side API from a separate thread, then you will need to supply a non-NULL binding handle to them.

If you use explicit binding handles and do not use thread-specific context handles, the binding handle for the call is the first parameter to your server manager routine. However, if you do not use explicit handles or if you use context handles, **RpcServerInqBindingHandle** is the only way to obtain a binding handle to use in another thread.

This API can be used for both asynchronous and synchronous calls, although it is less useful for asynchronous calls since the binding handle can be obtained as the async state is always the first parameter for all asynchronous RPC calls and the binding handle can be obtained directly from it using [RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle).

## See also

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)