# RpcIfIdVectorFree function

## Description

The
**RpcIfIdVectorFree** function frees the vector and the interface-identification structures contained in the vector.

## Parameters

### `IfIdVector`

Address of a pointer to a vector of interface information. On return, the pointer is set to **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcIfIdVectorFree** function to release the memory used to store a vector of interface identifications.
**RpcIfIdVectorFree** frees memory containing the interface identifications and the vector itself. On return, this function sets the *IfIdVec* parameter to **NULL**.

An application obtains a vector of interface identifications by calling the
[RpcNsMgmtEntryInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentryinqifidsa) and
[RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids) functions.

## See also

[RpcIfInqId](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifinqid)

[RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids)

[RpcNsMgmtEntryInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentryinqifidsa)