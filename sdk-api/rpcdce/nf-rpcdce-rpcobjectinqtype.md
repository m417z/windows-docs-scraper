# RpcObjectInqType function

## Description

The
**RpcObjectInqType** function returns the type of an object.

## Parameters

### `ObjUuid`

Pointer to the object UUID whose associated type UUID is returned.

### `TypeUuid`

Returns a pointer to the type UUID of the *ObjUuid* parameter.

Specify a parameter value of **NULL** to prevent the return of a type UUID. In this way, an application can determine (from the returned status) whether *ObjUuid* is registered without specifying an output type UUID variable.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OBJECT_NOT_FOUND** | Object not found. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcObjectInqType** to obtain the type UUID of an object. If the object was registered with the RPC run-time library using the
[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype) function, the registered type is returned.

Optionally, an application can privately maintain an object/type registration. In this case, if the application has provided an object inquiry function (see under
[RpcObjectSetInqFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsetinqfn)). The RPC run-time library uses that function to determine an object's type.

The
**RpcObjectInqType** function obtains the type UUID as described in the following table.

| Object UUID  registered | Inquiry function  registered | Return  value |
| --- | --- | --- |
| Yes ( [RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype)) | Ignored | The object's registered type UUID. |
| No | Yes ( [RpcObjectSetInqFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsetinqfn)) | The type UUID returned from the inquiry function. |
| No | No | The nil UUID. |

## See also

[RpcObjectSetInqFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsetinqfn)

[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype)