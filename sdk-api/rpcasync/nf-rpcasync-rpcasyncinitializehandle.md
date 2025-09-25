# RpcAsyncInitializeHandle function

## Description

The client calls the
**RpcAsyncInitializeHandle** function to initialize the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure to be used to make an asynchronous call.

## Parameters

### `pAsync`

Pointer to the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure that contains asynchronous call information.

### `Size`

Size of the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The size is either too small or too large. |
| **RPC_S_INVALID_ASYNC_HANDLE** | *pAsync* points to invalid memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The client creates a new
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure and a pointer to that structure and calls
**RpcAsyncInitializeHandle** with the pointer as an input parameter. The
**RpcAsyncInitializeHandle** function initializes the fields that it uses to maintain the state of an asynchronous remote call. When the call to
**RpcAsyncInitializeHandle** returns successfully, the client can set the notification type and any fields related to that notification type in the
**RPC_ASYNC_STATE** structure. The client application uses a pointer to this structure to make an asynchronous call.

The client should not attempt to alter the **Size**, **Signature**, **Lock**, and **StubInfo** members of the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure; doing so will invalidate the handle.

**Note** In Windows 2000, after an asynchronous call is completed, the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure must be reinitialized prior to being used for another asynchronous call. In Windows XP and later, the
**RPC_ASYNC_STATE** structure is ready for immediate re-use subsequent to a completed asynchronous call.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)