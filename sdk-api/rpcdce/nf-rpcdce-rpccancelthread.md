# RpcCancelThread function

## Description

The
**RpcCancelThread** function cancels a thread. The
**RpcCancelThread** function should not be used to cancel asynchronous RPC calls; instead, use the
[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall) function to cancel an asynchronous RPC call.

## Parameters

### `Thread`

Handle of the thread to cancel.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_ACCESS_DENIED** | Thread handle does not have privilege. Thread handles must have THREAD_SET_CONTEXT set properly for the function to execute properly. |
| **RPC_S_CANNOT_SUPPORT** | Called by an MS-DOS or Windows 3.x client. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcCancelThread** function allows one client thread to cancel an RPC in progress on another client thread. When the function is called, the server run-time is informed of the cancel operation. The server stub can determine if the call has been canceled by calling
[RpcTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpctestcancel). If the call has been canceled, the server stub should clean up and return control to the client.

The **RpcCancelThread** function cannot be used to cancel a call that has issued a static callback. Do not cancel remote procedure calls that may call a function declared with the **[callback]** attribute in the IDL-file.

By default, the client waits forever for the server to return control after a cancel. To reduce this time, call
[RpcMgmtSetCancelTimeout](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtsetcanceltimeout), specifying the number of seconds to wait for a response. If the server does not return within this interval, the call fails at the client with an **RPC_S_CALL_FAILED** exception. The server stub continues to run.

If you are using the named pipes protocol, **ncacn_np**, you must specify a finite time-out.

You can use
**RpcCancelThread** with any of the connection-oriented protocols **(ncacn_*)** and with any of the datagram protocols except **ncadg_mq** and **ncalrpc**.

**Note** Windows XP/2000 The **RpcCancelThread** function is not available for **ncacn_http**. The **RpcCancelThread** function supports **ncacn_http** on Windows Server 2003 or later operating systems and Windows XP with Service Pack 1 (SP1) and later.

## See also

[RpcTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpctestcancel)

[ncacn_http](https://learn.microsoft.com/windows/win32/midl/ncacn-http)

[ncadg_mq](https://learn.microsoft.com/windows/win32/midl/ncadg-mq)

[ncalrpc](https://learn.microsoft.com/windows/win32/midl/ncalrpc)