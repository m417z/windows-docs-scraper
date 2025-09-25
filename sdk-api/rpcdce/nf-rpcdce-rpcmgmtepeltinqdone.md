# RpcMgmtEpEltInqDone function

## Description

The
**RpcMgmtEpEltInqDone** function deletes the inquiry context for viewing the elements in an endpoint map.

## Parameters

### `InquiryContext`

Inquiry context to delete and returns the value **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcMgmtEpEltInqDone** function deletes an inquiry context created by
[RpcMgmtEpEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqbegin). An application calls this function after viewing local endpoint-map elements using
[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext).

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcMgmtEpEltInqBegin](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqbegin)

[RpcMgmtEpEltInqNext](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtepeltinqnext)