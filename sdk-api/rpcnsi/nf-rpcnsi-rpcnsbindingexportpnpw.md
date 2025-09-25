# RpcNsBindingExportPnPW function

## Description

The
**RpcNsBindingExportPnP** function establishes a name-service database entry with multiple binding handles and multiple objects for a server that supports Plug and Play.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the entry name to which binding handles and object UUIDs are exported. You cannot provide a null or empty string.

To use the entry name specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultEntry**, provide a null pointer or an empty string. In this case, the *EntryNameSyntax* parameter is ignored and the run-time library uses the default syntax.

### `IfSpec`

Stub-generated data structure specifying the interface to export. A null value indicates there are no binding handles to export (only object UUIDs are to be exported) and *BindingVec* is ignored.

### `ObjectVector`

Pointer to a vector of object UUIDs offered by the server. The server application constructs this vector. A null value indicates there are no object UUIDs to export (only binding handles are to be exported).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NOTHING_TO_EXPORT** | There was nothing to export. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is unsupported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_NO_NS_PRIVILEGE** | No privilege for name-service operation. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingExportPnP** function allows a server application to publicly offer an interface in the name-service database that supports Plug and Play bindings for use by any client application.

Note that the server application should not explicitly supply the binding vector when exporting Plug and Play bindings. The bindings are automatically updated when there is a change in the bindings due to a Plug and Play event.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingExportPnP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingUnexportPnP](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexportpnpa)