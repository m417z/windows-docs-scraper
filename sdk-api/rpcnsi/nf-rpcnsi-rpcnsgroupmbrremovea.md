# RpcNsGroupMbrRemoveA function

## Description

The
**RpcNsGroupMbrRemove** function removes an entry name from a group.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `GroupNameSyntax`

Syntax of *GroupName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `GroupName`

Pointer to the name of the RPC group from which to remove the member name.

### `MemberNameSyntax`

Syntax to use in the *MemberName* parameter.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `MemberName`

Pointer to the name of the member to remove from the RPC group attribute in the entry *GroupName*.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_ENTRY_NOT_FOUND** | The name-service entry was not found. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |
| **RPC_S_GROUP_MEMBER_NOT_FOUND** | The group member was not found. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsGroupMbrRemove** function removes a member from the RPC group attribute in the *GroupName* parameter.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsGroupMbrRemove as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsGroupMbrAdd](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbradda)