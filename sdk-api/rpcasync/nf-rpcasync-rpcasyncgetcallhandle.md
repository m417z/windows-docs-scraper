# RpcAsyncGetCallHandle macro

## Syntax

```cpp
void RpcAsyncGetCallHandle(
    PRPC_ASYNC_STATE pAsync
);
```

## Description

The **RpcAsyncGetCallHandle** macro returns the
binding handle on an asynchronous remote procedure call.

## Parameters

### `pAsync`

Pointer to the [RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that
contains asynchronous call information.

## Remarks

Given an asynchronous handle, it returns the corresponding binding handle. For example, the
[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel) function uses the
*pAsync* parameter of
**RpcAsyncGetCallHandle** as a parameter to test for
cancel requests.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC Macros](https://learn.microsoft.com/windows/desktop/Rpc/rpc-macros)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)