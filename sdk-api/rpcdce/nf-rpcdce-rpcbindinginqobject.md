# RpcBindingInqObject function

## Description

The
**RpcBindingInqObject** function returns the object UUID from a binding handle.

## Parameters

### `Binding`

Client or server binding handle.

### `ObjectUuid`

Returns a pointer to the object
[UUID](https://msdn.microsoft.com/) found in the *Binding* parameter. *ObjectUuid* is a unique identifier of an object to which a remote procedure call can be made.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcBindingInqObject** function to see the object
[UUID](https://msdn.microsoft.com/) associated with a client or server binding handle.

## See also

[RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject)