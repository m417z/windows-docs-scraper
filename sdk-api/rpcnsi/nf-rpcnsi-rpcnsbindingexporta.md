# RpcNsBindingExportA function

## Description

The
**RpcNsBindingExport** function establishes a name service–database entry with multiple binding handles and multiple objects for a server.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the entry name to which binding handles and object UUIDs are exported. You cannot provide a null or empty string. The client and the server must both use the same entry name.

### `IfSpec`

Stub-generated data structure specifying the interface to export. A null value indicates there are no binding handles to export (only object UUIDs are to be exported) and *BindingVec* is ignored.

### `BindingVec`

Pointer to server bindings to export. A null value indicates there are no binding handles to export (only object UUIDs are to be exported).

### `ObjectUuidVec`

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
**RpcNsBindingExport** function allows a server application to publicly offer an interface in the name-service database for use by any client application.

Effective with Windows 2000, the RPC run-time environment uses the Active Directory as its name-service database. This means that authorized exported entries persist in the name service, and are visible even after rebooting. Unauthorized exports do not persist. See
[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) in the Security section of the Platform Software Development Kit (SDK) for more information on authorization and Access Control Lists.

To export an interface, the server application calls the
**RpcNsBindingExport** routine with an interface and the server binding handles a client can use to access the server. A server application also calls the
**RpcNsBindingExport** function to publicly offer the object UUID(s) of resource(s) it offers, if any, in the name-service database.

A server can export interfaces and objects in a single call to
**RpcNsBindingExport**, or it can export them separately.If the name-service database entry specified by *EntryName* does not exist,
**RpcNsBindingExport** tries to create it. In this case, the server application must have the privilege to create the entry.In addition to calling
**RpcNsBindingExport**, a server that called the
[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs) or
**RpcServerUseProtseq** function must also register with the local endpoint-map database by calling either
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) or
[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace).

A server is not required to export any of its interfaces to the name-service database. When a server does not export, only clients that privately know that server's binding information can access its interfaces. For example, a client that has the information needed to construct a string binding can call the
[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding) to create a binding handle for making remote procedure calls to a server.

Before calling
**RpcNsBindingExport**, a server must do the following:

* Register one or more protocol sequences with the local RPC run-time library by calling one of the following functions:

  + [RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs),
    [RpcServerUseAllProtseqsEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsex)
  + [RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq),
    [RpcServerUseProtseqEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqex)
  + [RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif),
    [RpcServerUseAllProtseqsIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsifex)
  + [RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif),
    [RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)
  + [RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep),
    [RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)
* Obtain a list of server bindings by calling the
  [RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings) function.

The vector returned from the
[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings) function becomes the *Binding* parameter for
**RpcNsBindingExport**. To prevent a binding from being exported, set the selected vector element to a null value.

If a server exports to the same name-service database entry multiple times, the second and subsequent calls to
**RpcNsBindingExport** add the binding information and object UUIDs when that data is different from the binding information already in the server entry. Existing data is not removed from the entry.

To remove binding handles and object UUIDs from the name-service database, a server application calls the
[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta) function.

A server entry must have at least one binding handle to exist. As a result, exporting only UUIDs to a non-existing entry has no effect, and unexporting all binding handles deletes the entry.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingExport as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)