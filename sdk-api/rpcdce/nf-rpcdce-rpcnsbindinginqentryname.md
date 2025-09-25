# RpcNsBindingInqEntryName function

## Description

The
**RpcNsBindingInqEntryName** function returns the entry name from which the binding handle came.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `Binding`

Binding handle whose name-service database entry name is returned.

### `EntryNameSyntax`

Syntax used in *EntryName*.

To use the syntax specified in the registry value entry

**HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Returns the address of a pointer to the name of the name-service database entry in which *Binding* was found.

Specify a null value to prevent
**RpcNsBindingInqEntryName** from returning the *EntryName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_NO_ENTRY_NAME** | No entry name for binding. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is unsupported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsBindingInqEntryName** function returns the name of the name service–database entry name from which a client compatible–binding handle came.

The RPC run-time library allocates memory for the string returned in the *EntryName* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function to deallocate that memory.

An entry name is associated only with binding handles returned from the
[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext),
[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext), and
[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect) functions.

If the binding handle specified in the *Binding* parameter was not returned from a name-service database entry (for example, if the binding handle was created by calling
[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)),
**RpcNsBindingInqEntryName** returns an empty string ("\0") and an RPC_S_NO_ENTRY_NAME status code.

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcNsBindingImportNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportnext)

[RpcNsBindingLookupNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupnext)

[RpcNsBindingSelect](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingselect)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)