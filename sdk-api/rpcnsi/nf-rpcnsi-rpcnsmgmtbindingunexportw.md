# RpcNsMgmtBindingUnexportW function

## Description

The
**RpcNsMgmtBindingUnexport** function removes multiple binding handles and objects from an entry in the name-service database.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the name of the entry from which to remove binding handles and object UUIDs.

### `IfId`

Pointer to an interface identification. A null parameter value indicates that binding handles are not to be unexported—only object UUIDs are to be unexported.

### `VersOption`

Specifies how the
**RpcNsMgmtBindingUnexport** function uses the **VersMajor** and **VersMinor** members of the structure pointed to by the *IfId* parameter.

The following table describes valid values for the *VersOption* parameter.

| VersOption values | Meaning |
| --- | --- |
| **RPC_C_VERS_ALL** | Unexports all bindings for the interface UUID in *IfId*, regardless of the version numbers. For this value, specify 0 for both the major and minor versions in *IfId*. |
| **RPC_C_VERS_IF_ID** | Unexports the bindings for the compatible interface UUID in *IfId* with the same major version and with a minor version greater than or equal to the minor version in *IfId*. |
| **RPC_C_VERS_EXACT** | Unexports the bindings for the interface UUID in *IfId* with the same major and minor versions as in *IfId*. |
| **RPC_C_VERS_MAJOR_ONLY** | Unexports the bindings for the interface UUID in *IfId* with the same major version as in *IfId* (ignores the minor version). For this value, specify 0 for the minor version in *IfId*. |
| **RPC_C_VERS_UPTO** | Unexports the bindings that offer a version of the specified interface UUID less than or equal to the specified major and minor version. (For example, if the *IfId* contained V2.0 and the name service–database entry contained binding handles with the versions 1.3, 2.0, and 2.1, the **RpcNsMgmtBindingUnexport** function would unexport the binding handles with versions 1.3 and 2.0.) |

### `ObjectUuidVec`

Pointer to a vector of object UUIDs that the server no longer wants to offer. The application constructs this vector. A null value indicates there are no object UUIDs to unexport—only binding handles are to be unexported.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_VERS_OPTION** | The version option is invalid. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_INTERFACE_NOT_FOUND** | The interface was not found. |
| **RPC_S_NOT_ALL_OBJS_UNEXPORTED** | Not all objects unexported. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsMgmtBindingUnexport** function allows a management application to remove one of the following from a name service–database entry:

* All the binding handles for a specified interface UUID, qualified by the interface version numbers (major and minor)
* One or more object UUIDs of resources
* Both binding handles and object UUIDs of resources

A management application can unexport interfaces and objects in a single call to
**RpcNsMgmtBindingUnexport**, or it can unexport them separately. If
**RpcNsMgmtBindingUnexport** does not find any binding handles for the specified interface, the function returns an RPC_S_INTERFACE_NOT_FOUND status code and does not unexport the object UUIDs, if any were specified.

If one or more binding handles for the specified interface are found and unexported without error,
**RpcNsMgmtBindingUnexport** unexports any specified object UUIDs. If any of the specified object UUIDs were not found,
**RpcNsMgmtBindingUnexport** returns RPC_S_NOT_ALL_OBJS_UNEXPORTED.

In addition to calling
**RpcNsMgmtBindingUnexport**, a management application should also call the
[RpcMgmtEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepunregister) function to unregister the servers that have registered with the endpoint-map database.

**Note** Name-service databases are designed to be relatively stable. In replicated name services, frequent use of the
[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta) and
[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta) functions causes the name service to repeatedly remove and replace the same entry, which can cause performance problems.

> [!NOTE]
> The rpcnsi.h header defines RpcNsMgmtBindingUnexport as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcMgmtEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepunregister)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta)