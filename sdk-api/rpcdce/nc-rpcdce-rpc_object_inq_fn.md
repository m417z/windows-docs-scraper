# RPC_OBJECT_INQ_FN callback function

## Description

The
**RPC_OBJECT_INQ_FN** function is a prototype for a function that facilitates replacement of the default object UUID to type UUID mapping.

## Parameters

### `ObjectUuid`

Pointer to the variable that specifies the object
[UUID](https://msdn.microsoft.com/) that is to be mapped to a type UUID.

### `TypeUuid`

Pointer to the address of the variable that is to contain the type UUID derived from the object UUID. The type UUID is returned by the function.

### `Status`

Pointer to a return value for the function.

## Remarks

You can replace the default mapping function that maps object UUIDs to type UUIDs by calling
[RpcObjectSetInqFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsetinqfn) and supplying a pointer to a function of type RPC_OBJECT_INQ_FN. The supplied function must match the function prototype specified by the type definition: a function with three parameters and the function return value of void.

## See also

[RpcObjectSetInqFn](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsetinqfn)