# RpcNsBindingImportBeginA function

## Description

The
**RpcNsBindingImportBegin** function creates an import context for importing client-compatible binding handles for servers that offer the specified interface and object.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, specify RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to an entry name at which the search for compatible binding handles begins.

To use the entry name specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultEntry**, provide a null pointer or an empty string. In this case, the *EntryNameSyntax* parameter is ignored and the run-time library uses the default syntax.

### `IfSpec`

Stub-generated data structure indicating the interface to import. If the interface specification has not been exported or is of no concern to the caller, specify a null value for this parameter. In this case, the bindings returned are only guaranteed to be of a compatible and supported protocol sequence and to contain the specified object UUID. The contacted server might not support the desired interface.

### `ObjUuid`

Pointer to an optional object UUID.

For a nonzero UUID, compatible binding handles are returned from an entry only if the server has exported the specified object UUID.

When *ObjUuid* has a null pointer value or a nil UUID, the returned binding handles contain one of the object UUIDs exported by the compatible server. If the server did not export any object UUIDs, the returned compatible binding handles contain a nil object UUID.

### `ImportContext`

Name-service handle returned for use with the
[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext) and
[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone) functions.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name exceeds the maximum length. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is unsupported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_INVALID_OBJECT** | Invalid object. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Before calling the
[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext) function, the client application must first call
**RpcNsBindingImportBegin** to create an import context. The parameters to this function control the operation of the
**RpcNsBindingImportNext** function.

When finished importing binding handles, the client application calls the
[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone) function to delete the import context.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingImportBegin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone)

[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)