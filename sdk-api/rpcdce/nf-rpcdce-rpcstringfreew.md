# RpcStringFreeW function

## Description

The
**RpcStringFree** function frees a character string allocated by the RPC run-time library.

## Parameters

### `String`

Pointer to a pointer to the character string to free.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application is responsible for calling
**RpcStringFree** once for each character string allocated and returned by calls to other RPC run-time library routines.

> [!NOTE]
> The rpcdce.h header defines RpcStringFree as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)