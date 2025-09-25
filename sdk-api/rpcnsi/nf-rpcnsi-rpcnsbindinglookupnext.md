# RpcNsBindingLookupNext function

## Description

The
**RpcNsBindingLookupNext** function returns a list of compatible binding handles for a specified interface and optionally an object.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `LookupContext`

Name-service handle returned from the
[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina) function.

### `BindingVec`

Returns the address of a pointer to a vector of client-compatible server binding handles.

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
**RpcNsBindingLookupNext** function returns a vector of client-compatible server binding handles for a server offering the interface and object UUID specified by the *IfSpec* and *ObjUuid* parameters in the
[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina) function. (Compare this to
[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext), which returns a single compatible server binding handle.)

The
**RpcNsBindingLookupNext** function communicates only with the name-service database, not directly with servers.

Effective with Windows 2000, the RPC environment uses Active Directory as its name-service database and the order in which the run-time environment performs the search is as follows:

* Search the local cache.
* If entry not found in local cache, search that machine's Active Directory.
* If entry not found on local machine, send broadcast requests to all other Active Directory services in the domain.

  Note that if the entry exists in the Active Directory, but there is no information associated with the entry, the run-time environment will not issue this broadcast request.

On successive calls, the
**RpcNsBindingLookupNext** function traverses name-service database entries, collecting client-compatible server binding handles from each entry.

When Microsoft Active Directory is the name-service database,
**RpcNsBindingLookupNext** traverses the database only if the given entry name is **null** and the default entry (in the registry) is undefined or empty. Also, since mixed entries are not permitted in the Active Directory, the function searches for server entry names only, not group or profile names.

When the DCE Cell Directory Service (CDS) is the name-service database, and the entry at which the search begins contains binding handles in addition to group or profile names,
**RpcNsBindingLookupNext** returns the binding handles from *EntryName* before searching the group or profile. This means that the function can return a partially full vector before processing the members of the group or profile.

The compatible binding handle that is returned always contains an object UUID, the value of which depends on the *ObjUuid* parameter in the
[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) function. If a non-**null** object UUID was specified, the returned binding handle contains that object UUID. If, however, a **null** object UUID or **null** value was specified, the object UUID that is returned is a result of the following possibilities:

* If the server did not export any object UUIDs, the returned binding handle contains a nil object UUID.
* If the server exported one object UUID, the returned binding handle contains that object UUID.
* If the server exported multiple object UUIDs, the returned binding handle contains one of the object UUIDs. The import-next operation selects the returned object UUID in a non-deterministic fashion. As a result, a different object UUID can be returned for each compatible binding handle from a single server entry.

From the returned vector of server binding handles, the client application can employ its own criteria for selecting individual binding handles, or the application can call the
[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect) function to select a binding handle. The
[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding) and
[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse) functions will be helpful to a client creating its own selection criteria.

The client application can use the selected binding handle to attempt to make a remote procedure call to the server. If the client fails to establish a relationship with the server, it can select another binding handle from the vector. When all of the binding handles in the vector have been used, the client application calls
**RpcNsBindingLookupNext** again.

Each time the client calls
**RpcNsBindingLookupNext**, the function returns another vector of binding handles. The binding handles returned in each vector are unordered. The vectors returned from multiple calls to this function are also unordered.

A client calls the
[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname) function to obtain the name-service database server entry name that the binding came from.

When the search reaches the end of the name-service database,
**RpcNsBindingLookupNext** returns a status of RPC_S_NO_MORE_BINDINGS and returns a *BindingVec* value of **NULL**.

The
**RpcNsBindingLookupNext** function allocates storage for the data referenced by the returned *BindingVec* parameter. When a client application finishes with the vector, it must call the
[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree) function to deallocate the storage. Each call to
**RpcNsBindingLookupNext** requires a corresponding call to
**RpcBindingVectorFree**.

The client is responsible for calling the
[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone) function to delete the lookup context, or if you want the application to start a new search for compatible servers.

## See also

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcNsBindingInqEntryName](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnsbindinginqentryname)

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)

[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)