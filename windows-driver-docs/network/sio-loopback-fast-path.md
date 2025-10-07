# SIO\_LOOPBACK\_FAST\_PATH control code

**Important** The **SIO\_LOOPBACK\_FAST\_PATH** is deprecated and is not recommended to be used in your code.

The **SIO\_LOOPBACK\_FAST\_PATH** socket I/O control code allows a WSK application to configure a TCP socket for faster operations on the loopback interface.

To use this IOCTL, a WSK application calls the [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function with the following parameters.

| Parameter | Value |
| --- | --- |
| *RequestType* | **WskIoctl** |
| *ControlCode* | **SIO_LOOPBACK_FAST_PATH** |
| *Level* | 0 |
| *InputSize* | The size, in bytes, of the input buffer. |
| *InputBuffer* | A pointer to the input buffer. This parameter contains a pointer to a **Boolean** value that indicates if the socket should be configured for fast loopback operations. |
| *OutputSize* | 0 |
| *OutputBuffer* | **NULL** |
| *OutputSizeReturned* | **NULL** |
| Irp | A pointer to an IRP. |

An application can use the **SIO\_LOOPBACK\_FAST\_PATH** IOCTL to improve the performance of loopback operations on a TCP socket. This IOCTL requests that the TCP/IP stack use a special fast path for loopback operations on this socket. The **SIO\_LOOPBACK\_FAST\_PATH** IOCTL can be used only with TCP sockets. This IOCTL must be used on both sides of the loopback session. The TCP loopback fast path is supported using either the IPv4 or IPv6 loopback interface.

The socket that plans to initiate the connection request must apply this IOCTL before making the connection request. The socket that is listening for the connection request must apply this IOCTL before accepting the connection.

Once an application establishes the connection on a loopback interface using the fast path, all packets for the lifetime of the connection must use the fast path.

Applying **SIO\_LOOPBACK\_FAST\_PATH** to a socket which will be connected to a non-loopback path will have no effect.

This TCP loopback optimization results in packets that flow through Transport Layer (TL) instead of the traditional loopback through Network Layer. This optimization improves the latency for loopback packets. Once an applications opts in for a connection level setting to use the loopback fast path, all packets will follow the loopback path. For loopback communications, congestion and packet drop are not expected. The notion of congestion control and reliable delivery in TCP will be unnecessary. This, however, is not true for flow control. Without flow control, the sender can overwhelm the receive buffer, leading to erroneous TCP loopback behavior. The flow control in the TCP optimized loopback path is maintained by placing send requests in a queue. When the receive buffer is full, the TCP/IP stack guarantees that the sends won't complete until the queue is serviced, maintaining flow control.

TCP fast path loopback connections in the presence of a Windows Filtering Platform (WFP) callout for connection data must take the unoptimized slow path for loopback. So WFP filters will prevent this new loopback fast path from being used. When a WFP filter is enabled, the system will use the slow path even if the **SIO\_LOOPBACK\_FAST\_PATH** IOCTL was set. This ensues that user-mode applications have the full WFP security capability.

By default, **SIO\_LOOPBACK\_FAST\_PATH** is disabled.

Only a subset of the TCP/IP socket options are supported when the **SIO\_LOOPBACK\_FAST\_PATH** IOCTL is used to enable the loopback fast path on a socket. The list of supported options includes the following:

- IP\_TTL
- IP\_UNICAST\_IF
- IPV6\_UNICAST\_HOPS
- IPV6\_UNICAST\_IF
- IPV6\_V6ONLY
- [**SO\_CONDITIONAL\_ACCEPT**](https://learn.microsoft.com/windows/desktop/WinSock/so-conditional-accept)
- [SO\_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse)
- [**SO\_PORT\_SCALABILITY**](https://learn.microsoft.com/windows/desktop/WinSock/so-port-scalability)
- SO\_RCVBUF
- SO\_REUSEADDR
- TCP\_BSDURGENT

A WSK application must specify a pointer to an IRP and a completion routine when calling the [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function for this type of request. The application must not release the buffer till the WSK subsystem has completed the IRP. When it completes the IRP, the subsystem invokes the completion routine. In the completion routine, the application must check the IRP status and release all resources that it had previously allocated for the request.

For more information about WSK IRP handling, see [Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

When completing the IRP, the subsystem will set *Irp->IoStatus.Status* to **STATUS\_SUCCESS** if the request is successful. Otherwise, *Irp->IoStatus.Status* will be set to **STATUS\_INVALID\_BUFFER\_SIZE** or **STATUS\_NOT\_SUPPORTED** if the call is not successful.

## Return value

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 8 |
| Minimum supported server | Windows Server 2012 |
| Header | Mstcpip.h |
| IRQL | PASSIVE_LEVEL |

## See also

[**SIO\_LOOPBACK\_FAST\_PATH (SDK)**](https://learn.microsoft.com/windows/win32/winsock/sio-loopback-fast-path)

[Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions)

