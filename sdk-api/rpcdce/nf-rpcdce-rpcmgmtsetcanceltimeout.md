# RpcMgmtSetCancelTimeout function

## Description

The
**RpcMgmtSetCancelTimeout** function sets the lower bound on the time to wait before timing out after forwarding a cancel.

## Parameters

### `Timeout`

Seconds to wait for a server to acknowledge a cancel command. To specify that a client waits an indefinite amount of time, supply the value RPC_C_CANCEL_INFINITE_TIMEOUT.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_CANNOT_SUPPORT** | Called from an MS-DOS or Windows 3.*x* client. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtSetCancelTimeout** function to reset the amount of time the run-time library waits for a server to acknowledge a cancel. The application specifies either to wait forever or to wait a specified length of time in seconds. If the value of *Seconds* is 0 (zero), the call is immediately abandoned upon a cancel command and control returns to the client application. The default value is RPC_C_CANCEL_INFINITE_TIMEOUT, which specifies waiting indefinitely for the call to complete.

The value for the cancel command time-out applies to all remote procedure calls made in the current thread. To change the time-out value, a multithreaded client must call this function in each thread of execution.