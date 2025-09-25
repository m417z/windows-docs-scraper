# RpcStringFree function

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

## See also

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)