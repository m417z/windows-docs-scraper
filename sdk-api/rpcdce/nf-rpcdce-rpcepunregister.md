# RpcEpUnregister function

## Description

The
**RpcEpUnregister** function removes server-address information from the local endpoint-map database.

## Parameters

### `IfSpec`

Interface to unregister from the local endpoint-map database.

### `BindingVector`

Pointer to a vector of binding handles to unregister.

### `UuidVector`

Pointer to an optional vector of object UUIDs to unregister. The server application constructs this vector.
**RpcEpUnregister** unregisters all endpoint-map database elements that match the specified *IfSpec* and *BindingVector* parameters and the object UUID(s).

A null parameter value indicates there are no object UUIDs to unregister.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_BINDINGS** | No bindings. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcEpUnregister** function removes elements from the local host's endpoint-map database. A server application calls this function only when the server has previously registered endpoints and the server wants to remove that address information from the endpoint-map database.

Specifically,
**RpcEpUnregister** allows a server application to remove its own endpoint-map database elements (server-address information) based on the interface specification or on both the interface specification and the object UUID(s) of the resource(s) offered.

The server calls the
[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings) function to obtain the required *BindingVector* parameter. To unregister selected endpoints, the server can prune the binding vector prior to calling this function.

**RpcEpUnregister** creates a cross-product from the *IfSpec*, *BindingVector*, and *UuidVector* parameters and removes each element in the cross-product from the endpoint-map database.

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)