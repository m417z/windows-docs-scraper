# RpcMgmtInqStats function

## Description

The
**RpcMgmtInqStats** function returns RPC run-time statistics.

## Parameters

### `Binding`

To receive statistics about a remote application, specify a server binding handle for that application. To receive statistics about your own (local) application, specify a value of **NULL**.

### `Statistics`

Returns a pointer to a pointer to the statistics about the server specified by the *Binding* parameter. Each statistic is an **unsigned long** value.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtInqStats** function to obtain statistics about the specified server from the RPC run-time library.

Each array element in the returned statistics vector contains an **unsigned long** value. The following table describes the statistics indexed by the specified constant.

| Statistic | Description |
| --- | --- |
| RPC_C_STATS_CALLS_IN | Number of remote procedure calls received by the RPC server specified by the binding handle. |
| RPC_C_STATS_CALLS_OUT | Number of remote procedure calls initiated by the RPC server specified by the binding handle. |
| RPC_C_STATS_PKTS_IN | Number of network packets received by the RPC server specified by the binding handle. |
| RPC_C_STATS_PKTS_OUT | Number of network packets sent by the RPC server specified by the binding handle. |

The RPC run-time library allocates memory for the statistics vector. The application is responsible for calling the
[RpcMgmtStatsVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstatsvectorfree) function to release the memory used by the statistics vector.

The server must be listening for remote procedure calls for this function to succeed. If the server is not listening, the function fails.

## See also

[RpcEpResolveBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepresolvebinding)

[RpcMgmtStatsVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstatsvectorfree)