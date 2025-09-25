# RpcNsGroupDeleteW function

## Description

The
**RpcNsGroupDelete** function deletes a group attribute.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `GroupNameSyntax`

Integer value that indicates the syntax of *GroupName*. Can be set to one of the following values:

| Value | Meaning |
| --- | --- |
| **RPC_C_NS_SYNTAX_DEFAULT** | Use the syntax specified in the registry value **HKEY_LOCAL_MACHINE\ Software\Microsoft\Rpc\ NameService\ DefaultSyntax** |
| **RPC_C_NS_SYNTAX_DCE** | Use DCE syntax. |

### `GroupName`

Pointer to the name of the name-service group to delete.

## Return value

This function returns one of the following values:

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
**RpcNsGroupDelete** function deletes the group attribute from the specified name service–database entry.

Neither the specified name service–database entry nor the group members are deleted.

**Note** This DCE function is not supported by Microsoft Locator. Windows NT and Windows 2000 both support the use of this function, but with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsGroupDelete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsGroupMbrAdd](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbradda)

[RpcNsGroupMbrRemove](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrremovea)