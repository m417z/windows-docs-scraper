# RpcNsGroupMbrInqBeginW function

## Description

The
**RpcNsGroupMbrInqBegin** function creates an inquiry context for viewing group members.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `GroupNameSyntax`

Syntax of *GroupName*.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `GroupName`

Pointer to the name of the RPC group to view.

### `MemberNameSyntax`

Syntax of the return parameter, *MemberName*, in the
[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta) function.

To use the syntax specified in the registry value entry **HKEY_LOCAL_MACHINE\Software\Microsoft\Rpc\NameService\DefaultSyntax**, provide a value of RPC_C_NS_SYNTAX_DEFAULT.

### `InquiryContext`

Returns a pointer to a name-service handle for use with the
[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta) and
[RpcNsGroupMbrInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqdone) functions.

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
**RpcNsGroupMbrInqBegin** function creates an inquiry context for viewing the members of an RPC group. Before calling
[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta), the application must first call
**RpcNsGroupMbrInqBegin** to create an inquiry context. When finished viewing the RPC group members, the application calls
[RpcNsGroupMbrInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqdone) to delete the inquiry context.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsGroupMbrInqBegin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsGroupMbrAdd](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbradda)

[RpcNsGroupMbrInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqdone)

[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta)