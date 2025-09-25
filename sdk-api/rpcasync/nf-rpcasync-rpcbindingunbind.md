# RpcBindingUnbind function

## Description

The **RpcBindingUnbind** function unbinds a binding handle previously bound by [RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind).

## Parameters

### `Binding` [in]

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that contains the binding handle to unbind from the RPC server.

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcBindingUnbind** unbinds a previously bound binding handle from an RPC server. An unbound handle can be modified with calls like [RpcBindingSetOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetoption) and [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa). A binding handle in the unbound state can be bound again and re-used to make calls.

The results of an unbind operation are undefined if it is called on a binding handle that currently has RPC calls in progress at the time of unbinding. It is the responsibility of the caller to ensure that no calls are in progress at the time an unbind operation is attempted.

Note that calling **RpcBindingUnbind** does not necessarily disconnect the client from the server. It will invalidate any cached information used by the binding handle, but actually disconnection is not ensured. To ensure disconnection, free the binding handle with [RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree).

**Windows Vista:** Currently, this function supports only the **ncalrpc** protocol sequence.

## See also

[RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind)

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)