# UuidIsNil function

## Description

An application calls the
**UuidIsNil** function to determine whether the specified [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) is a nil-valued **UUID**.

## Parameters

### `Uuid`

[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to test for nil value.

### `Status`

Returns RPC_S_OK.

## Return value

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

This function acts as though the application called
[UuidCreateNil](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreatenil), and then called the
[UuidEqual](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidequal) to compare the returned nil-value [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to the **UUID** specified in the *Uuid* parameter.

Upon completion, one of the following values is returned.

| Returned value | Meaning |
| --- | --- |
| **TRUE** | The *Uuid* parameter is a nil-valued [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). |
| **FALSE** | The *Uuid* parameter is not a nil-valued [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). |

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)