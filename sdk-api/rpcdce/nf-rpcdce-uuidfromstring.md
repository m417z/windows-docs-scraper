# UuidFromString function

## Description

The
**UuidFromString** function converts a string to a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

## Parameters

### `StringUuid`

Pointer to a string representation of a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

The UUID format is **xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx**.

Passing **NULL** results in **GUID_NULL** value in **Uuid**.

### `Uuid`

Returns a pointer to a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) in binary form.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_STRING_UUID** | The string [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**UuidFromString** function to convert a string [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to a binary **UUID**.

## See also

[UuidToString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidtostring)