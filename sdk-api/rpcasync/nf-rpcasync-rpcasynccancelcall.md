# RpcAsyncCancelCall function

## Description

The client calls the
**RpcAsyncCancelCall** function to cancel an asynchronous call.

## Parameters

### `pAsync`

Pointer to the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that contains asynchronous call information.

### `fAbort`

If **TRUE**, the call is canceled immediately. If **FALSE**, wait for the server to complete the call.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The cancellation request was processed. |
| **RPC_S_INVALID_ASYNC_HANDLE** | The asynchronous handle is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

There are two ways for a client to request cancellation of an asynchronous call—**abortive** and **nonabortive**. In an abortive cancel (*fAbortCall* is **TRUE**), the
**RpcAsyncCancelCall** function sends a cancel notification to the server and client side and the asynchronous call is canceled immediately, without waiting for a response from the server. Note that in a multithreaded application, an async call can only be canceled by the client after the thread that originated the call has returned from it with success. This is necessary to ensure that the call will not be canceled asynchronously by another thread after it has failed synchronously while being issued. In general, if an async call fails synchronously it should not be canceled asynchronously. The client application must ensure this behavior if calls may be issued and canceled on different threads.

The server checks for cancel requests from the client by calling
[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel). Depending on the state of the call at the time the cancel request was issued and how often the server checks for cancels, the call may or may not complete normally. The client application must call
[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall) to complete the call and the return value will indicate whether the call completed, failed, or was canceled. However, the client must still wait for the original call to complete before calling **RpcAsyncCompleteCall**.

In a nonabortive cancel (*fAbortCall* is **FALSE**) the
**RpcAsyncCancelCall** function notifies the server of the cancel and the client waits for the server to complete the call. There is no built-in time-out mechanism. If you want the call to time out, the client should first issue a nonabortive cancel using its own time-out mechanism. If the call times out, then the client can issue an abortive cancel.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)