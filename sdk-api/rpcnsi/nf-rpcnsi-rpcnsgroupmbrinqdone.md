# RpcNsGroupMbrInqDone function

## Description

The
**RpcNsGroupMbrInqDone** function deletes the inquiry context for a group.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Pointer to a name-service handle to free. A value of NULL is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_NS_HANDLE** | The name-service handle is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsGroupMbrInqDone** function frees an inquiry context created by calling the
[RpcNsGroupMbrInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqbegina) function. An application calls
**RpcNsGroupMbrInqDone** after viewing RPC group members using the
[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta) function.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

## See also

[RpcNsGroupMbrInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqbegina)

[RpcNsGroupMbrInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsgroupmbrinqnexta)