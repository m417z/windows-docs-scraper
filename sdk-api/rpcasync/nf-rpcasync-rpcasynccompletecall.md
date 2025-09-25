# RpcAsyncCompleteCall function

## Description

The client and the server call the
**RpcAsyncCompleteCall** function to complete an asynchronous remote procedure call.

## Parameters

### `pAsync`

Pointer to the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that contains asynchronous call information.

### `Reply`

Pointer to a buffer containing the return value of the remote procedure call.

## Return value

In addition to the following values,
**RpcAsyncCompleteCall** can also return any general RPC or application-specific error.

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call was completed successfully. |
| **RPC_S_INVALID_ASYNC_HANDLE** | The asynchronous call handle is not valid. |
| **RPC_S_ASYNC_CALL_PENDING** | The call has not yet completed. |
| **RPC_S_CALL_CANCELLED** | The call was canceled. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Completes the asynchronous RPC call. Both client and server call this function.

Client: *Reply* points to a buffer that will receive the reply. If the client calls this function before the reply has arrived, the call returns RPC_S_ASYNC_CALL_PENDING. The buffer must be valid and it must be big enough to receive the return value. If this call is successful, the
[[out]](https://learn.microsoft.com/windows/desktop/Midl/out-idl) and the
[[in,](https://learn.microsoft.com/windows/desktop/Midl/in) **out]** parameters are valid. If the call does not return RPC_S_ASYNC_CALL_PENDING, this
**RpcAsyncCompleteCall** invocation is final for the RPC call. After this function call, regardless of success or failure, all resources allocated by the RPC runtime are freed. Subsequent calls to the
**RpcAsyncCompleteCall** or
[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall) functions have undefined results until a new call on the RPC_ASYNC_STATE structure is initiated.

Server: *Reply* points to a buffer that contains the return value that needs to be sent to the client. You only need to set a valid buffer for *Reply* if your function is declared with a return type. Before a call to
**RpcAsyncCompleteCall** is made, the [[out]](https://learn.microsoft.com/windows/desktop/Midl/out-idl) and
[[in,](https://learn.microsoft.com/windows/desktop/Midl/in) **out]** parameters must be updated. These parameters, and the asynchronous handle, should not be touched after the call to
**RpcAsyncCompleteCall** returns. The invocation of **RpcAsyncCompleteCall** on the server is final. If the **RpcAsyncCompleteCall** function call fails, the RPC runtime frees the parameters.

Any [[out]](https://learn.microsoft.com/windows/desktop/Midl/out-idl) parameters, including
[[comm_status]](https://learn.microsoft.com/windows/desktop/Midl/comm-status) and
[[fault_status]](https://msdn.microsoft.com/) parameters, are only valid if the return value of
**RpcAsyncCompleteCall** is RPC_S_OK.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[Error Handling](https://learn.microsoft.com/windows/desktop/Rpc/error-handling)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)