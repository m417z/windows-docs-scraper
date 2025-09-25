# RpcNsGroupMbrAddA function

## Description

The
**RpcNsGroupMbrAdd** function adds an entry name to a group. If necessary, it creates the entry.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `GroupNameSyntax`

Syntax of *GroupName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `GroupName`

Pointer to the name of the RPC group to receive a new member.

### `MemberNameSyntax`

Syntax to use in *MemberName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `MemberName`

Pointer to the name of the new RPC group member.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NAME_SYNTAX** | The name syntax is invalid. |
| **RPC_S_UNSUPPORTED_NAME_SYNTAX** | The name syntax is not supported. |
| **RPC_S_INCOMPLETE_NAME** | The name is incomplete. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsGroupMbrAdd** adds a name service–database entry name as a member to the RPC group attribute.

If the *GroupName* entry does not exist,
**RpcNsGroupMbrAdd** tries to create the entry with a group attribute and adds the group member specified by *MemberName*. In this case, the application must have the privilege to create the entry. Otherwise, a management application with the necessary privilege should create the entry by calling
[RpcNsMgmtEntryCreate](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentrycreatea) before the application is run.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsGroupMbrAdd as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsGroupMbrRemove](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrremovea)

[RpcNsMgmtEntryCreate](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentrycreatea)