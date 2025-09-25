# RpcNsBindingImportNext function

## Description

The
**RpcNsBindingImportNext** function looks up an interface (and optionally an object from a name-service database) and returns a binding handle of a compatible server, if found.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ImportContext`

Name-service handle returned from the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) function.

### `Binding`

Returns a pointer to a client-compatible server binding handle for a server.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_MORE_BINDINGS** | No more bindings. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingImportNext** function returns one client-compatible server binding handle for a server that offers the interface and object UUID specified by the *IfSpec* and *ObjUuid* parameters in the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) function. The function communicates only with the name-service database, not directly with servers.

Effective with Windows 2000, the RPC environment uses the Active Directory as its name-service database and the order in which the run-time environment performs the search is as follows:

* Search in the local cache. If there is no entry,
* Search in the Active Directory. If there is no entry,
* Send broadcast requests to all other directory services in the domain.

  Note that if the entry exists in the Active Directory, but there is no information associated with the entry, the run-time environment does not issue this broadcast request.

The compatible binding handle that is returned always contains an object UUID, the value of which depends on the *ObjUuid* parameter in the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) function. If a non-**null** object UUID was specified, the returned binding handle contains that object UUID. If, however, a **null** object UUID or **null** value was specified, the object UUID that is returned is a result of the following possibilities:

* If the server did not export any object UUIDs, the returned binding handle contains a nil object UUID.
* If the server exported one object UUID, the returned binding handle contains that object UUID.
* If the server exported multiple object UUIDs, the returned binding handle contains one of the object UUIDs. The import-next operation selects the returned object UUID in a non-deterministic fashion. As a result, a different object UUID can be returned for each compatible binding handle from a single server entry.

The
**RpcNsBindingImportNext** function selects and returns one server binding handle from the compatible binding handles found. The client application can use that binding handle to attempt a remote procedure call to the server. If the client fails to establish a relationship with the server, it can call
**RpcNsBindingImportNext** again.

Each time the client calls
**RpcNsBindingImportNext**, the function returns another server binding handle. The returned binding handles are unordered. A client application calls the
[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname) function to obtain the name-service database in the entry name from which the binding handle came.When the search reaches the end of the name-service database,
**RpcNsBindingInqEntryName** returns a status of RPC_S_NO_MORE_BINDINGS and returns a binding parameter value of **NULL**.

The
**RpcNsBindingImportNext** function allocates storage for the data referenced by the returned *Binding* parameter. When a client application finishes with the binding handle, it must call
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) to deallocate the storage. Each call to
**RpcNsBindingImportNext** requires a corresponding call to
**RpcBindingFree**.

The client is responsible for calling the
[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone) function, which deletes the import context. The client also calls
**RpcNsBindingImportDone** before calling
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) to start a new search for compatible servers. Because the order of binding handles returned is different for each new search, the order in which binding handles are returned to an application can be different each time the application is run.

## See also

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingImportDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportdone)

[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname)

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)

[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)

[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect)