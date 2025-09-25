# RpcServerListen function

## Description

The
**RpcServerListen** function signals the RPC run-time library to listen for remote procedure calls. This function will not affect auto-listen interfaces; use
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) if you need that functionality.

## Parameters

### `MinimumCallThreads`

Hint to the RPC run time that specifies the minimum number of call threads that should be created and maintained in the given server. This value is only a hint and is interpreted differently in different versions of Windows. In Windows XP, this value is the number of previously created threads in each thread pool that the RPC run time creates. An application should specify one for this parameter, and defer thread creation decisions to the RPC run time.

### `MaxCalls`

Recommended maximum number of concurrent remote procedure calls the server can execute. To allow efficient performance, the RPC run-time libraries interpret the *MaxCalls* parameter as a suggested limit rather than as an absolute upper bound.

Use RPC_C_LISTEN_MAX_CALLS_DEFAULT to specify the default value.

### `DontWait`

Flag controlling the return from
**RpcServerListen**. A value of nonzero indicates that
**RpcServerListen** should return immediately after completing function processing. A value of zero indicates that
**RpcServerListen** should not return until the
[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) function has been called and all remote calls have completed.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_ALREADY_LISTENING** | The server is already listening. |
| **RPC_S_NO_PROTSEQS_REGISTERED** | There are no protocol sequences registered. |
| **RPC_S_MAX_CALLS_TOO_SMALL** | The maximum calls value is too small. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server calls
**RpcServerListen** when the server is ready to process remote procedure calls. RPC allows a server to simultaneously process multiple calls. The *MaxCalls* parameter recommends the maximum number of concurrent remote procedure calls the server should execute.

The *MaxCalls* value should not be zero, and should be larger than *MinimumCallThreads*. Values larger than 0x7FFFFFFF are set to 0x7FFFFFFF without notice.

**Windows XP/2000:** Setting the *MaxCalls* parameter to RPC_C_LISTEN_MAX_CALLS_DEFAULT removes the limit on concurrent remote procedure calls, rather than setting it to the constant-defined value of 1234. Removing the limit on maximum concurrent calls allows as many concurrent remote procedure calls as the computer can handle. This behavior enables increased efficiency in the RPC run time.

A server application is responsible for concurrency control between the server manager routines because each routine executes in a separate thread.

When the *DontWait* parameter has a value of zero, the RPC run-time library continues listening for remote procedure calls (that is, the routine does not return to the server application) until one of the following events occurs:

* One of the server application's manager routines calls
  [RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening).
* A client calls a remote procedure provided by the server that directs the server to call
  [RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening).
* A client calls
  [RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) with a binding handle to the server.

After it receives a stop-listening request, the RPC run-time library stops accepting new remote procedure calls for all registered interfaces. Executing calls are allowed to complete, including callbacks. After all calls complete,
**RpcServerListen** returns to the caller.

When the *DontWait* parameter has a nonzero value,
**RpcServerListen** returns to the server immediately after processing all the instructions associated with the function. You can use the
[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten) function to perform the wait operation usually associated with
**RpcServerListen**.

**Note** The Microsoft RPC implementation of
**RpcServerListen** includes two additional parameters that do not appear in the DCE specification: *DontWait* and *MinimumCallThreads*.

## See also

[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening)

[RpcMgmtWaitServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtwaitserverlisten)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)