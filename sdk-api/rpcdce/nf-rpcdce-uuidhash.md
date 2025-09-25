# UuidHash function

## Description

An application calls the
**UuidHash** function to generate a hash value for a specified [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

## Parameters

### `Uuid`

[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) for which a hash value is created.

### `Status`

Returns RPC_S_OK.

## Return value

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**UuidHash** to generate a hash value for a specified [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). The hash value returned is implementation dependent and may vary from implementation to implementation.

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)