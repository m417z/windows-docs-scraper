# RpcMgmtWaitServerListen function

## Description

The
**RpcMgmtWaitServerListen** function performs the *wait* operation usually associated with
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | All remote procedure calls are complete. |
| **RPC_S_ALREADY_LISTENING** | Another thread has called **RpcMgmtWaitServerListen** and has not yet returned. |
| **RPC_S_NOT_LISTENING** | The server application must call [RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) before calling **RpcMgmtWaitServerListen**. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

When the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) flag parameter *DontWait* has a nonzero value, the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) function returns to the server application without performing the wait operation. In this case, the wait can be performed by
**RpcMgmtWaitServerListen**.

Applications must call
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) with a nonzero value for the *DontWait* parameter before calling
**RpcMgmtWaitServerListen**. The
**RpcMgmtWaitServerListen** function returns after the server application calls
[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) and all active remote procedure calls complete, or after a fatal error occurs in the RPC run-time library.

**Note** **RpcMgmtWaitServerListen** is a Microsoft extension to the DCE API set.

## See also

[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening)

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)