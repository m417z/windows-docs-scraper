# RpcNsGroupMbrInqNextW function

## Description

The
**RpcNsGroupMbrInqNext** function returns one entry name from a group at a time.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Name service handle.

### `MemberName`

Returns the address of a pointer to an RPC group member name. The syntax of the returned name was specified by the *MemberNameSyntax* parameter in the
[RpcNsGroupMbrInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqbegina) function.

Specify a null value to prevent
**RpcNsGroupMbrInqNext** from returning the *MemberName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NS_HANDLE** | The name-service handle is invalid. |
| **RPC_S_NO_MORE_MEMBERS** | No more members. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsGroupMbrInqNext** function returns one member of the RPC group specified by the *GroupName* parameter in
[RpcNsGroupMbrInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqbegina). An application can view all the members of an RPC group set by repeatedly calling
**RpcNsGroupMbrInqNext**. When all the group members have been viewed, this function returns an RPC_S_NO_MORE_MEMBERS status code. The returned group members are unordered.

On each call to
**RpcNsGroupMbrInqNext** that returns a member name, the RPC run-time library allocates memory for the returned *MemberName*. The application is responsible for calling
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) for each returned *MemberName* string. After viewing the RPC group's members, the application must call
[RpcNsGroupMbrInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqdone) to release the inquiry context.

The order in which group members are returned can be different for each viewing of a group. This means that the order in which group members are returned to an application can be different each time the application is run.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

> [!NOTE]
> The rpcnsi.h header defines RpcNsGroupMbrInqNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNsGroupMbrInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqbegina)

[RpcNsGroupMbrInqDone](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqdone)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)