# UuidToStringW function

## Description

The
**UuidToString** function converts a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to a string.

## Parameters

### `Uuid` [in]

Pointer to a binary
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

### `StringUuid` [out]

Pointer to the null-terminated string into which the [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) specified in the *Uuid* parameter will be placed.

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

> [!NOTE]
> The rpcdce.h header defines UuidToString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)

[UuidFromString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidfromstring)