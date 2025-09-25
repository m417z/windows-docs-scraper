# RpcNsProfileDeleteA function

## Description

The
**RpcNsProfileDelete** function deletes a profile attribute.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ProfileNameSyntax`

Integer value indicating the syntax of the next parameter, *ProfileName*.

To use the syntax specified in the registry value **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `ProfileName`

Pointer to the name of the profile to delete.

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
**RpcNsProfileDelete** function deletes the profile attribute from the specified name-service entry (*ProfileName*). Neither *ProfileName* nor the entry names included as members in each profile element are deleted.

**Note** Use
**RpcNsProfileDelete** cautiously; deleting a profile can have the unwanted effect of breaking a hierarchy of profiles.

**Note** This DCE function is not supported by Microsoft Locator. Windows NT and Windows 2000 support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsProfileDelete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsProfileEltAdd](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltadda)

[RpcNsProfileEltRemove](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltremovea)