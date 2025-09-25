# RpcNsBindingUnexportPnPA function

## Description

The
**RpcNsBindingUnexportPnP** function removes the binding handles for Plug and Play interfaces and objects from an entry in the name-service database.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the entry name from which to remove binding handles and object UUIDs.

### `IfSpec`

Interface specification for the binding handles to be removed from the name service database. A null parameter value indicates not to unexport any binding handles (only object UUIDs are to be unexported).

### `ObjectVector`

Pointer to a vector of object UUIDs that the server no longer wants to offer. The application constructs this vector. A null value indicates there are no object UUIDs to unexport (only binding handles are to be unexported).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_VERS_OPTION** | The version option is invalid. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is unsupported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_INTERFACE_NOT_FOUND** | The interface was not found. |
| **RPC_S_NOT_ALL_OBJS_UNEXPORTED** | Not all objects unexported. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingUnexportPnP** function allows a server application to remove the binding handles and object UUIDs of Plug and Play-compatible resources from a name service database entry. A server application can unexport the specified interface and objects in a single call to
**RpcNsBindingUnexportPnP**, or it can unexport them separately. Only the binding handles that match the interface UUID and the major and minor interface version numbers found in the *IfSpec* parameter are unexported.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingUnexportPnP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsBindingExportPnP](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexportpnpa)

[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta)