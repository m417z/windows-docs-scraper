# PFN_WSK_LISTEN callback function

## Description

 The **WskListen** function enables a stream socket to listen for incoming connections at the socket's bound address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the stream socket that is listening for an incoming connection. This socket must have previously been bound to a local transport address by calling [WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind).

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the listen operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskListen** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The stream socket listened for an incoming connection successfully. The IRP will be completed with success status. |
| **STATUS_PENDING** | The IRP has been queued by the WSK subsystem, which is waiting for an incoming connection on the stream socket. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the **WskListen** function only on a stream socket that the application previously bound to a local transport address by calling the [WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function. Once **WskListen** is successfully called on a stream socket, the socket is committed to a listening socket flow and can no longer call connection-oriented socket functions.

## See also

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)