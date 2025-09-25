# RpcBindingBind function

## Description

The **RpcBindingBind** function contacts an RPC server and binds to it.

## Parameters

### `pAsync` [in, optional]

Pointer to the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that contains asynchronous call information. This state information contains the completion method used to signal when the bind operation is complete.

### `Binding` [in]

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that contains the binding handle created with a previous call to [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea).

### `IfSpec` [in]

[RPC_IF_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-if-handle) value that specifies the interface on which calls for this binding handle will be made.

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned. For information on these error codes, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

| Return code | Description |
| --- | --- |
| **RPC_S_OK** | The RPC is successfully bound to the server and remote calls can be made. |
| **RPC_S_CANNOT_SUPPORT** | An obsolete feature of RPC was requested for this binding operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcBindingBind** contacts the RPC server and binds to it using the binding handle returned by a previous call to [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea). Binding handles established using this method are referred to as "fast" binding handles.

If the value of the *pAsync* parameter is not **NULL**, then the bind will be asynchronous and calls to [RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall) and [RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus) can be made on the supplied async state. The completion method specified in the async state information wis used to signal the caller that the bind is complete. Upon notification of completion, calls can be made using the newly-bound binding handle.

The bind method does not determine what calls can be made using the binding handle — if the bind is synchronous, asynchronous calls can still be made on the binding handle, and vice versa. The bind method determines how notification for a successful bind is signaled, specifically in the case of asynchronous binds.

Since this API exchanges messages with the RPC server, bind operations can take a long time based on a number of independent factors including network traffic and server blocking. If the binding is synchronous, the bind operation can block if the server is blocked.

After the bind is complete, the semantics of calls made on the binding handle are the same as calls made on any other type of binding handle, but with four notable differences, listed below:

* All calls on this binding handle must be made on the interface specified in *IfSpec*. The binding handle is uniquely tied to this interface. The interface itself can be unloaded before the binding handle is destroyed, but extensive information about the interface is cached in the binding handle, and if a call is made on the same binding handle for a different interface, the results are undefined.
* RPC callbacks are not allowed on a binding handle. If the RPC server attempts to make a callback using a method with the [callback] attribute, the call is rejected with the RPC_S_CANNOT_SUPPORT error status code.
* With classic binding handles, RPC will attempt to transparently reconnect with the server if the connection is dropped. For fast binding handles, RPC will not attempt to transparently reconnect to the server; instead, it will return one of the following errors: RPC_S_SERVER_UNAVAILABLE, RPC_S_CALL_FAILED, and RPC_C_CALL_FAILED_DNE. If the connection is dropped due to rejected credentials, RPC_S_ACCESS_DENIED is returned; and if the server encounters a transient error due to a lack of memory, RPC_S_OUT_OF_MEMORY is returned. Any other connectivity errors are the result of marshaling or unmarshaling errors returned by server routines.In the case of a lost connection, the called must unbind by calling [RpcBindingUnbind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingunbind) and then rebind with another call to **RpcBindingBind**.

If the call to **RpcBindingBind** fails, then the binding handle is not bound to the server and the caller can attempt to bind again with another call to the same API, or it can free the binding handle. Since a failed bind operation does not move the binding handle to the bound state, [RpcBindingUnbind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingunbind) must not be called on it.

Certain functions must not be called until the bind operation has signaled completion, specifically:

* [RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)
* [RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset)
* [RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) and [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa)
* [RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject)
* [RpcBindingSetOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetoption)
* [RpcMgmtSetComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetcomtimeout)

**Note** Currently, this function supports only the **ncalrpc** protocol sequence.

## See also

[RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea)

[RpcBindingUnbind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingunbind)