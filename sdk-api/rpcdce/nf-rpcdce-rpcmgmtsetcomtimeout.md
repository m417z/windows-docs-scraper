# RpcMgmtSetComTimeout function

## Description

The
**RpcMgmtSetComTimeout** function sets the binding-communications time-out value in a binding handle.

## Parameters

### `Binding`

Server binding handle whose time-out value is set.

### `Timeout`

Communications time-out value, from zero to 10. These values are not seconds; they represent a relative amount of time on a scale of zero to 10.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_INVALID_TIMEOUT** | The time-out value was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In Windows XP and Windows 2000, during bind the RPC run time uses the shorter of a 15-minute call time-out, and the time-out set using the
**RpcMgmtSetComTimeout** function. In exchanges subsequent to binding, the RPC run time uses only the time-out set in using the
**RpcMgmtSetComTimeout** function. This option is ignored for **ncalrpc** and **ncadg_*** protocol sequences.

A client application calls
**RpcMgmtSetComTimeout** to change the communications time-out value for a server binding handle. Depending on the protocol sequence for the specified binding handle, the time-out value acts only as a hint to the RPC run-time library. Each protocol sequence interprets this setting differently; for **ncacn_ip_tcp**, the value is used to turn on keep-alives for all calls. For example, for **ncacn_ip_tcp**, setting *Timeout* to zero instructs RPC to turn on keep-alives if a response isn't received in 60 seconds (the 60 second interval is implementation-specific and subject to change). In this situation, the client call is not timed out as long as the server us running; however, if the server fails or loses its IP address, RPC fails the call. The TCP time-out hint is used during connection establishment, as well as during request/reply exchanges.

**Note** Using the TCP time-out hint is the best practice for detecting failed servers.

In Windows XP, keep-alives for a given connection are turned off when the server responds.

For convenience, constants are provided for certain values in the time-out range. For a list of the RPC-defined values that an application can use for the time-out argument, see
[Binding Time-out Constants](https://learn.microsoft.com/windows/desktop/Rpc/binding-time-out-constants).

## See also

[RpcMgmtInqComTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqcomtimeout)