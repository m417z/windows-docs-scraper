# RpcNsBindingSelect function

## Description

The
**RpcNsBindingSelect** function returns a binding handle from a list of compatible binding handles.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `BindingVec`

Pointer to the vector of client-compatible server binding handles from which a binding handle is selected. The returned binding vector no longer references the selected binding handle, which is returned separately in the *Binding* parameter.

### `Binding`

Pointer to a selected binding handle.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_MORE_BINDINGS** | No more bindings. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Each time the client calls the
**RpcNsBindingSelect** function, the function operation returns another binding handle from the vector.

When all of the binding handles have been returned from the vector, the function returns a status of RPC_S_NO_MORE_BINDINGS and returns a *Binding* value of **NULL**.

The [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)
operation allocates storage for the data referenced by the returned *Binding* parameter. When a client finishes with the binding handle, it should call the
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) function to deallocate the storage. Each call to
**RpcNsBindingSelect** requires a corresponding call to the
**RpcBindingFree** function.

Clients can create their own select routines implementing application-specific selection criteria. In this case,
[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse) provides access to the fields of a binding.

## See also

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)