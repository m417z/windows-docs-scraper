# UuidToString function

## Description

The
**UuidToString** function converts a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to a string.

## Parameters

### `Uuid` [in]

Pointer to a binary [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

### `StringUuid` [out]

Pointer to the null-terminated string into which the [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) specified in the *Uuid* parameter will be placed.

The UUID format is **xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**UuidToString** to convert a binary [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to a string **UUID**. The RPC run-time library allocates memory for the string returned in the *StringUuid* parameter. The application is responsible for calling
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) to deallocate that memory.

## See also

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)

[UuidFromString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidfromstring)