# RpcObjectSetType function

## Description

The
**RpcObjectSetType** function assigns the type of an object.

## Parameters

### `ObjUuid`

Pointer to an object UUID to associate with the type UUID in the *TypeUuid* parameter.

### `TypeUuid`

Pointer to the type UUID of the *ObjUuid* parameter.

Specify a parameter value of NULL or a nil UUID to reset the object type to the default association of object UUID/nil-type UUID.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_OBJECT** | The object is invalid. |
| **RPC_S_ALREADY_REGISTERED** | The object is already registered. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcObjectSetType** to assign a type UUID to an object UUID. By default, the RPC run-time library automatically assigns all object UUIDs with the nil-type UUID. A server application that contains one implementation of an interface (one manager entry-point vector [EPV]) does not need to call
**RpcObjectSetType** provided that the server registered the interface with the nil-type UUID (see under
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)).

A server application that contains multiple implementations of an interface (multiple manager EPVs—that is, multiple type UUIDs) calls
**RpcObjectSetType** once for each different object UUID/non-nil type UUID association the server supports. Associating each object with a type UUID tells the RPC run-time library which manager EPV (interface implementation) to use when the server receives a remote procedure call for a non-nil object UUID.

The RPC run-time library allows an application to set the type for an unlimited number of objects. To remove the association between an object UUID and its type UUID (established by calling
**RpcObjectSetType**), a server calls
**RpcObjectSetType** again, specifying a null value or a nil UUID for the *TypeUuid* parameter. This resets the object UUID/type UUID association to the default association of object UUID/nil-type UUID. A server cannot assign a type to the nil object UUID. The RPC run-time library automatically assigns the nil object UUID a nil-type UUID.

For detailed information, see
[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces).

## See also

[Registering
Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)