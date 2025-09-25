# UuidCompare function

## Description

An application calls the
**UuidCompare** function to compare two [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s and determine their order. The returned value gives the order.

## Parameters

### `Uuid1`

Pointer to a
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). This **UUID** is compared with the **UUID** specified in the *Uuid2* parameter.

### `Uuid2`

Pointer to a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). This **UUID** is compared with the **UUID** specified in the *Uuid1* parameter.

### `Status`

Returns any errors that may occur, and will typically be set by the function to RPC_S_OK upon return.

## Return value

| Value | Meaning |
| --- | --- |
| **–1** | The *Uuid1* parameter is less than the *Uuid2* parameter. |
| **0** | The *Uuid1* parameter is equal to the *Uuid2* parameter. |
| **1** | The *Uuid1* parameter is greater than the *Uuid2* parameter. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)