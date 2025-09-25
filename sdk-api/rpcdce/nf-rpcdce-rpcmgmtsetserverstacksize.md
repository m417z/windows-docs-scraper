# RpcMgmtSetServerStackSize function

## Description

The
**RpcMgmtSetServerStackSize** function specifies the stack size for server threads created by the RPC run time.

## Parameters

### `ThreadStackSize`

Stack size allocated for each thread created by the RPC run time, in bytes. This value is applied to all threads created for the server, but not to threads already created. Select this value based on the stack requirements of the remote procedures offered by the server.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls the
**RpcMgmtSetServerStackSize** function to specify the thread stack size to use when the RPC run-time library creates call threads for executing remote procedure calls.

Servers that know the stack requirements of all the manager functions in the interfaces it offers can call the
**RpcMgmtSetServerStackSize** function to ensure that each call thread has the necessary stack size.

Calling
**RpcMgmtSetServerStackSize** is optional. If a server does not call
**RpcMgmtSetServerStackSize**, the default thread stack size from the executable image is used.

## See also

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)