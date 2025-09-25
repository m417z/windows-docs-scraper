# RpcNsProfileEltInqDone function

## Description

The
**RpcNsProfileEltInqDone** function deletes the inquiry context for viewing the elements in a profile.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `InquiryContext`

Pointer to a name-service handle to free. The name-service handle that *InquiryContext* points to is created by calling the
[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina) function.

An argument value of NULL is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsProfileEltInqDone** function frees an inquiry context created by calling
[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina).

An application calls
**RpcNsProfileEltInqDone** after viewing profile elements using the
[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta) function.

**Note** Windows 2000 Active Directory supports this function. Earlier versions of Windows NT support the use of this function with Cell Directory Service (CDS) only.

## See also

[RpcNsProfileEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqbegina)

[RpcNsProfileEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsprofileeltinqnexta)