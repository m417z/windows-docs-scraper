# RpcAsyncAbortCall function

## Description

The server calls
**RpcAsyncAbortCall** to abort an asynchronous call.

## Parameters

### `pAsync`

Pointer to the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that contains asynchronous call information.

### `ExceptionCode`

A nonzero application-specific exception code. Can be an application-defined error code, or a standard RPC error code. For more information, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | Call cancelation successful. |
| **RPC_S_INVALID_ASYNC_HANDLE** | Asynchronous handle is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The server calls
**RpcAsyncAbortCall** when circumstances require it to abort an asynchronous call before completion. For example, the caller may not have the necessary permissions to make the request, or the server may be too busy to process the call. Use the *ExceptionCode* parameter to specify the reason for the abort. The run-time environment propagates the exception code to the client as a fault.

When an asynchronous call is aborted with
**RpcAsyncAbortCall**, no marshaling of the output arguments is performed, and all input arguments are freed by RPC. When
**RpcAsyncAbortCall** is called, a call to the
**RpcAsyncCompleteCall** function is not necessary. The
**RpcAsyncAbortCall** function should be called only once for any asynchronous call; a second call may crash the process or fail in other unexpected ways.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)