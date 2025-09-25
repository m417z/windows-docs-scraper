# RpcServerTestCancel function

## Description

The server calls
**RpcServerTestCancel** to test for client cancel requests.

## Parameters

### `BindingHandle`

Call to test for cancel commands. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call was canceled by the client. The server must still complete or abort the call. |
| **RPC_S_NO_CALL_ACTIVE** | There is no active call on the current thread. |
| **RPC_S_CALL_IN_PROGRESS** | The call was not canceled. |
| **RPC_S_INVALID_BINDING** | The handle is not valid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The server calls
**RpcServerTestCancel** to find out if the client has requested cancelation of an outstanding call. The
**RpcServerTestCancel** function only indicates whether a client has canceled the call; state is not changed on the server or client. The canceled call must still be completed or aborted by the RPC server, using
[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall) or
[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall) function calls, respectively.

The *BindingHandle* parameter specifies the call on which to test. If the parameter has a value of zero, the call on the current thread is tested. The server can call the
**RpcServerTestCancel(RpcAsyncGetCallHandle(pAsync))** function to test for a cancel message using the asynchronous handle to obtain the binding handle.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)