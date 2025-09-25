# RpcNsBindingLookupBeginA function

## Description

The
**RpcNsBindingLookupBegin** function creates a lookup context for an interface and an object.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of the *EntryName* parameter.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to an entry name at which the search for compatible bindings begins.

To use the entry name specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultEntry**, provide a null pointer or an empty string. In this case, the *EntryNameSyntax* parameter is ignored and the run-time library uses the default syntax.

### `IfSpec`

Stub-generated structure indicating the interface to look up. If the interface specification has not been exported or is of no concern to the caller, specify a null value for this parameter. In this case, the bindings returned are only guaranteed to be of a compatible and supported protocol sequence and to contain the specified object UUID. The desired interface might not be supported by the contacted server.

### `ObjUuid`

Pointer to an optional object UUID.

For a nonzero UUID, compatible binding handles are returned from an entry only if the server has exported the specified object UUID.

For a null pointer value or a nil UUID for this parameter, the returned binding handles contain one of the object UUIDs exported by the compatible server. If the server did not export any object UUIDs, the returned compatible binding handles contain a nil object UUID.

### `BindingMaxCount`

Maximum number of bindings to return in the *BindingVec* parameter from the
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext) function.

Specify a value of zero to use the default count of RPC_C_BINDING_MAX_COUNT_DEFAULT.

### `LookupContext`

Returns a pointer to a name-service handle for use with the
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext) and
[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone) functions.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is unsupported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_INVALID_OBJECT** | Invalid object. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingLookupBegin** function creates a lookup context for locating client-compatible binding handles to servers that offer the specified interface and object.

Before calling
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext), the client application must first call
**RpcNsBindingLookupBegin** to create a lookup context. The parameters to this function control the operation of the
**RpcNsBindingLookupNext** function.

Effective with Windows 2000, the RPC environment uses the Active Directory as its name-service database and the order in which the run-time environment performs the search is as follows:

* Search in the local cache.
* If entry not found in local cache, search that machine's Active Directory.
* If entry not found on local machine, send broadcast requests to all other Active Directory services in the domain.

  Note that if the entry exists in the Active Directory, but there is no information associated with the entry, the run-time environment will not issue this broadcast request.

When finished locating binding handles, the client application calls the
[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone) function to delete the lookup context.

> [!NOTE]
> The rpcnsi.h header defines RpcNsBindingLookupBegin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsBindingLookupDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupdone)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)