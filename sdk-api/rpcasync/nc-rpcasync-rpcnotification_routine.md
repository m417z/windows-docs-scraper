# RPCNOTIFICATION_ROUTINE callback function

## Description

The
**RPCNOTIFICATION_ROUTINE** function provides programs that utilize asynchronous RPC with the ability to customize responses to asynchronous events.

## Parameters

### `pAsync`

Pointer to a structure that contains the current state of the asynchronous RPC run-time library. For more information, see
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state).

### `Context`

Reserved for future use. Windows 2000 currently sets this parameter to **NULL**.

### `Event`

A value from the
[RPC_ASYNC_EVENT](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_async_event) enumerated type that identifies the current asynchronous event.

## Remarks

For each
[asynchronous remote procedure call](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc) that a client program executes, it can specify an
[asynchronous procedure call (APC)](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls). The RPC run-time library will invoke the APC when the asynchronous remote procedure call completes. The APC function must match the prototype specified by
**RPCNOTIFICATION_ROUTINE**.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)