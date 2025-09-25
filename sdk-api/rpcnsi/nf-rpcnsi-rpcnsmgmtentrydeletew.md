# RpcNsMgmtEntryDeleteW function

## Description

The
**RpcNsMgmtEntryDelete** function deletes a name service–database entry.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `EntryNameSyntax`

Syntax of *EntryName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `EntryName`

Pointer to the name of the entry to delete.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_NOT_RPC_ENTRY** | Not an RPC entry. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Management applications use the
**RpcNsMgmtEntryDelete** function only when an entry is no longer needed—for example, when a server is being permanently removed from service.

Because name-service databases are designed to be relatively stable, frequent use of
**RpcNsMgmtEntryDelete** in client or server applications can result in performance problems. Creating and deleting entries in client or server applications causes the name-service database to repeatedly remove and replace the same entry. This can lead to performance problems in replicated name-service databases.

> [!NOTE]
> The rpcnsi.h header defines RpcNsMgmtEntryDelete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsMgmtEntryCreate](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentrycreatea)