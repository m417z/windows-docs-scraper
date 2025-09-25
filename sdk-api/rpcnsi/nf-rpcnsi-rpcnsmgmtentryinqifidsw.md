# RpcNsMgmtEntryInqIfIdsW function

## Description

The
**RpcNsMgmtEntryInqIfIds** function returns the list of interfaces exported to a name service–database entry. It also returns an interface-identification vector containing the interfaces of binding handles exported by a server to *EntryName*. This function uses an expiration age of 0, causing an immediate update of the local copy of name-service data.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the name service–database entry name for which an interface-identification vector is returned.

### `IfIdVec`

Returns an address of a pointer to the interface-identification vector.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsMgmtEntryInqIfIds** function returns an interface-identification vector containing the interfaces of binding handles exported by a server to *EntryName*. This function uses an expiration age of 0, causing an immediate update of the local copy of name-service data. The calling application is responsible for calling the
[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree) function to release memory used by the vector.

> [!NOTE]
> The rpcnsi.h header defines RpcNsMgmtEntryInqIfIds as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree)

[RpcIfInqId](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifinqid)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)