# RpcNsProfileEltRemoveA function

## Description

The
**RpcNsProfileEltRemove** function removes an element from a profile.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ProfileNameSyntax`

Syntax of *ProfileName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `ProfileName`

Pointer to the name of the profile from which to remove an element.

### `IfId`

Pointer to the interface identification of the profile element to be removed.

Specify a null value to remove the default profile member.

### `MemberNameSyntax`

Syntax of *MemberName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `MemberName`

Pointer to the name service–entry name in the profile element to remove.

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
**RpcNsProfileEltRemove** function removes a profile element from the profile attribute in the *ProfileName* entry. This function requires an exact match of the *MemberName* and *IfId* parameters to remove a profile element. The entry (*MemberName*), included as a member in the profile element, is not deleted.

**Note** Use
**RpcNsProfileEltRemove** cautiously: removing elements from a profile can have the unwanted effect of breaking a hierarchy of profiles.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsProfileEltRemove as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsProfileDelete](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofiledeletea)

[RpcNsProfileEltAdd](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltadda)