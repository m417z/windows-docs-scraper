# RpcNsBindingUnexportA function

## Description

The
**RpcNsBindingUnexport** function removes the binding handles for an interface and objects from an entry in the name-service database.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the entry name from which to remove binding handles and object UUIDs.

### `IfSpec`

Interface specification for the binding handles to be removed from the name service database. A null parameter value indicates not to unexport any binding handles (only object UUIDs are to be unexported).

### `ObjectUuidVec`

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
**RpcNsBindingUnexport** function allows a server application to remove the binding handles and object UUIDs of resources from a name service database entry. A server application can unexport the specified interface and objects in a single call to
**RpcNsBindingUnexport**, or it can unexport them separately. Only the binding handles that match the interface UUID and the major and minor interface version numbers found in the *IfSpec* parameter are unexported. Use the
[RpcNsMgmtBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtbindingunexporta) function to remove multiple versions of an interface.

Effective with Windows 2000, the RPC run-time environment uses the Active Directory as its name-service database. This means that an authorized unexported entries will be removed both from the local cache and from the Active Directory. Unauthorized unexports will only be removed from the local cache. See
[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) in the Security section of the Platform Software Development Kit (SDK) for more information on authorization and Access Control Lists.

If
**RpcNsBindingUnexport** does not find any binding handles for the specified interface, the function returns an RPC_S_INTERFACE_NOT_FOUND status code and does not unexport the object UUIDs, if any were specified.

If one or more binding handles for the specified interface are found and unexported without error,
**RpcNsBindingUnexport** unexports the specified object UUIDs, if any.

If any of the specified object UUIDs were not found,
**RpcNsBindingUnexport** returns the RPC_S_NOT_ALL_OBJS_UNEXPORTED status code.

In addition to calling
**RpcNsBindingUnexport**, a server should also call the
[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister) function to unregister the endpoints the server previously registered with the local endpoint-map database.

Once created, a server entry persists, even when all of the binding handles and UUIDs are removed. A server entry must have at least one binding handle to exist. As a result, exporting only UUIDs to a nonexisting entry has no effect, and unexporting all binding handles deletes the entry.

Use
**RpcNsBindingUnexport** judiciously. To keep an automatically activated server available, you must leave its binding handles in the name-service database between the times when server processes are activated. However, with dynamic bindings, if you do not unexport binding handles, the Active Directory can become so large as to be unmanageable.

Therefore, before you call this function, keep in mind how long you expect the server to be unavailable, and the type of binding in use. If you are using static bindings, reserve this function for when you expect a server to be unavailable for an extended time—for example, when it is being permanently removed from service.

**Note** Name-service databases are designed to be relatively stable. In replicated name-service databases, frequent use of the
[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta) and
**RpcNsBindingUnexport** functions causes the name-service database to repeatedly remove and replace the same entry and can cause performance problems.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingUnexport as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)