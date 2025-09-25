# RpcNsBindingImportDone function

## Description

The
**RpcNsBindingImportDone** function signals that a client has finished looking for a compatible server and deletes the import context.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ImportContext`

Pointer to a name-service handle to free. The name-service handle *ImportContext* points to is created by calling the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) function.

An argument value of **NULL** is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Typically, a client application calls
**RpcNsBindingImportDone** after completing remote procedure calls to a server using a binding handle returned from the
[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext) function. However, a client application is responsible for calling
**RpcNsBindingImportDone** for each import context that was created by calling the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina), regardless of the status returned from
**RpcNsBindingImportNext** or the success in making remote procedure calls.

## See also

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)