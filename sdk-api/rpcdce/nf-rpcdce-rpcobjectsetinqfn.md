# RpcObjectSetInqFn function

## Description

The
**RpcObjectSetInqFn** function registers an object-inquiry function. A null value turns off a previously registered object-inquiry function.

## Parameters

### `InquiryFn`

Object-type inquiry function. See
[RPC_OBJECT_INQ_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_object_inq_fn). When an application calls
[RpcObjectInqType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectinqtype) and the RPC run-time library finds that the specified object is not registered, the run-time library automatically calls
**RpcObjectSetInqFn** to determine the object's type.

## Return value

This function returns the following value.

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcObjectSetInqFn** to override the default mapping function that maps object UUIDs to type UUIDs, which determine an object's type. If an application privately maintains an object/type registration, the specified inquiry function returns the type UUID of an object.

The RPC run-time library automatically calls the inquiry function when the application calls
[RpcObjectInqType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectinqtype) and the object of interest was not previously registered with
[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype). The *TypeUuid* and *Status* values of the
[RPC_OBJECT_INQ_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_object_inq_fn) function are returned as the output from
[RpcObjectInqType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectinqtype).

## See also

[RpcObjectInqType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectinqtype)

[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype)