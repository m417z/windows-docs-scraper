# RpcMgmtStatsVectorFree function

## Description

The
**RpcMgmtStatsVectorFree** function frees a statistics vector.

## Parameters

### `StatsVector`

Pointer to a pointer to a statistics vector. On return, the pointer is set to **NULL**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtStatsVectorFree** function to release the memory used to store statistics.

An application obtains a vector of statistics by calling the
[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats) function.

## See also

[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats)