# RpcCancelThreadEx function

## Description

The **RpcCancelThreadEx** function stops the execution of a thread. The **RpcCancelThreadEx** function should not be used to stop the execution of an asynchronous RPC call; instead, use the [RpcAsyncCancelCall](https://learn.microsoft.com/windows/win32/api/rpcasync/nf-rpcasync-rpcasynccancelcall) function to stop the execution of an asynchronous RPC call.

## Parameters

### `Thread`

Handle of the thread to cancel.

### `Timeout`

Number of seconds to wait for the thread to be canceled before this function returns. To specify that a client waits an indefinite amount of time, pass the value RPC_C_CANCEL_INFINITE_TIMEOUT.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_ACCESS_DENIED** | Thread handle does not have privilege. Thread handles must have THREAD_SET_CONTEXT set properly for the function to execute properly. |
| **RPC_S_CANNOT_SUPPORT** | Called by an MS-DOS or Windows 3.*x* client. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/win32/Rpc/rpc-return-values).

## Remarks

The **RpcCancelThreadEx** function allows one client thread to cancel an RPC in progress on another client thread. When the function is called, the server run-time is informed of the cancel operation. The server stub can determine if the call has been canceled by calling
[RpcTestCancel](https://learn.microsoft.com/windows/win32/api/rpcdce/nf-rpcdce-rpctestcancel). If the call has been canceled, the server stub should clean up and return control to the client.

Using the *Timeout* parameter, your application can specify the number of seconds to wait for a response. If the server does not return within this interval, the call fails at the client with an RPC_S_CALL_CANCELLED exception. The server stub continues to execute.

If you are using the named pipes protocol, [ncacn_np](https://learn.microsoft.com/windows/win32/midl/ncacn-np), you must specify a finite time-out.

**Note** You can use **RpcCancelThreadEx** with any of the connection-oriented protocols (**ncacn_***) except
[ncacn_http](https://learn.microsoft.com/windows/win32/midl/ncacn-http), and with any of the datagram protocols except
[ncadg_mq](https://learn.microsoft.com/windows/win32/midl/ncadg-mq) and
[ncalrpc](https://learn.microsoft.com/windows/win32/midl/ncalrpc).

## See also

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/win32/api/rpcasync/nf-rpcasync-rpcasynccancelcall)
[RpcCancelThread](https://learn.microsoft.com/windows/win32/api/rpcdce/nf-rpcdce-rpccancelthread)
[RpcTestCancel](https://learn.microsoft.com/windows/win32/api/rpcdce/nf-rpcdce-rpctestcancel)
[ncacn_http](https://learn.microsoft.com/windows/win32/midl/ncacn-http)
[ncacn_np](https://learn.microsoft.com/windows/win32/midl/ncacn-np)
[ncadg_mq](https://learn.microsoft.com/windows/win32/midl/ncadg-mq)
[ncalrpc](https://learn.microsoft.com/windows/win32/midl/ncalrpc)