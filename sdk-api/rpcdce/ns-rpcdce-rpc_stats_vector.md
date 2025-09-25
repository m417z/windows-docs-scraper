# RPC_STATS_VECTOR structure

## Description

The
**RPC_STATS_VECTOR** structure contains statistics from the RPC run-time library on a per-server basis.

## Members

### `Count`

Number of statistics values present in the array **Stats**.

### `Stats`

Array of unsigned long integers representing server statistics that contains **Count** elements. Each array element contains an unsigned long value from the following list.

| Constant | Meaning |
| --- | --- |
| **RPC_C_STATS_CALLS_IN** | The number of remote procedure calls received by the server. |
| **RPC_C_STATS_CALLS_OUT** | The number of remote procedure calls initiated by the server. |
| **RPC_C_STATS_PKTS_IN** | The number of network packets received by the server. |
| **RPC_C_STATS_PKTS_OUT** | The number of network packets sent by the server. |

## Remarks

The statistics vector contains a count member (**Count**), followed by an array of statistics. To obtain run-time statistics, an application calls
[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats). The RPC run-time library allocates memory for the statistics vector. The application calls
[RpcMgmtStatsVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstatsvectorfree) to free the statistics vector.

## See also

[RpcMgmtInqStats](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqstats)

[RpcMgmtStatsVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstatsvectorfree)