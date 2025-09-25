# UuidEqual function

## Description

An application calls the
**UuidEqual** function to compare two [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s and determine whether they are equal.

## Parameters

### `Uuid1`

Pointer to a
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). This **UUID** is compared with the **UUID** specified in the *Uuid2* parameter.

### `Uuid2`

Pointer to a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). This **UUID** is compared with the **UUID** specified in the *Uuid1* parameter.

### `Status`

Returns RPC_S_OK.

## Return value

| Value | Meaning |
| --- | --- |
| **TRUE** | The *Uuid1* parameter is equal to the *Uuid2* parameter. |
| **FALSE** | The *Uuid1* parameter is not equal to the *Uuid2* parameter. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)