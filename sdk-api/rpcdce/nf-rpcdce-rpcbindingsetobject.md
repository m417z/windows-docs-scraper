# RpcBindingSetObject function

## Description

The
**RpcBindingSetObject** function sets the object UUID value in a binding handle.

## Parameters

### `Binding`

Server binding into which the *ObjectUuid* is set.

### `ObjectUuid`

Pointer to the
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) of the object serviced by the server specified in the *Binding* parameter. *ObjectUuid* is a unique identifier of an object to which a remote procedure call can be made.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcBindingSetObject** function to associate an object
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) with a server binding handle. The set-object operation replaces the previously associated object UUID with the UUID in the *ObjectUuid* parameter.

To set the object
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to the nil UUID, specify a null value or the nil UUID for the *ObjectUuid* parameter.

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingInqObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqobject)