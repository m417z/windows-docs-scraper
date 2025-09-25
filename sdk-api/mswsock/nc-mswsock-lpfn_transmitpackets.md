# LPFN_TRANSMITPACKETS callback function

## Description

The
**TransmitPackets** function transmits in-memory data or file data over a connected socket. The
**TransmitPackets** function uses the operating system cache manager to retrieve file data, locking memory for the minimum time required to transmit and resulting in efficient, high-performance transmission.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `hSocket`

A handle to the connected socket to be used in the transmission. Although the socket does not need to be a connection-oriented circuit, the default destination/peer should have been established using the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect),
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept),
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept),
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex), or
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf) function.

### `lpPacketArray`

An array of type [TRANSMIT_PACKETS_ELEMENT](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-transmit_packets_element), describing the data to be transmitted.

### `nElementCount`

The number of elements in *lpPacketArray*.

### `nSendSize`

The size, in bytes, of the data block used in the
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) operation. Set *nSendSize* to zero to let the sockets layer select a default
**send** size.

Setting *nSendSize* to 0xFFFFFFF enables the caller to control the size and content of each
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) request, achieved by using the TP_ELEMENT_EOP flag in the
[TRANSMIT_PACKETS_ELEMENT](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-transmit_packets_element) array pointed to in the *lpPacketArray* parameter. This capability is useful for message protocols that place limitations on the size of individual
**send** requests.

### `lpOverlapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. If the socket handle specified in the *hSocket* parameter has been opened as overlapped, use this parameter to achieve asynchronous (overlapped) I/O operation. Socket handles are opened as overlapped by default.

### `dwFlags`

A set of flags used to customize processing of the
**TransmitPackets** function. The following table outlines the use of the *dwFlags* parameter.

| Value | Meaning |
| --- | --- |
| **TF_DISCONNECT** | Starts a transport-level disconnect after all the file data has been queued for transmission. Applies only to connection-oriented sockets. Specifying this flag for sockets that do not support disconnect semantics (such as datagram sockets) results in an error. |
| **TF_REUSE_SOCKET** | Prepares the socket handle to be reused. When the **TransmitPackets** function completes, the socket handle can be passed to the [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function. Valid only when a connection-oriented socket and TF_DISCONNECT are specified.<br><br>**Note** The socket level packet transmit is subject to the behavior of the underlying transport. For example, a TCP socket may be subject to the TCP TIME_WAIT state, causing the **TransmitPackets** call to be delayed. |
| **TF_USE_DEFAULT_WORKER** | Directs Winsock to use the system's default thread to process long **TransmitPackets** requests. Long **TransmitPackets** requests are defined as requests that require more than a single read from the file or a cache; the long request definition therefore depends on the size of the file and the specified length of the send packet. <br><br>The system default thread can be adjusted using the following registry parameter as a REG_DWORD:**HKEY_LOCAL_MACHINE**\**CurrentControlSet**\**Services**\**AFD**\**Parameters**\**TransmitWorker** |
| **TF_USE_SYSTEM_THREAD** | Directs Winsock to use system threads to process long **TransmitPackets** requests. Long **TransmitPackets** requests are defined as requests that require more than a single read from the file or a cache; the long request definition therefore depends on the size of the file and the specified length of the send packet. |
| **TF_USE_KERNEL_APC** | Directs Winsock to use kernel [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APCs) instead of worker threads to process long **TransmitPackets** requests. Long **TransmitPackets** requests are defined as requests that require more than a single read from the file or a cache; the long request definition therefore depends on the size of the file and the specified length of the send packet. See Remarks for more information. |

## Return value

If the
**TransmitPackets** function succeeds, the return value is **TRUE**. Otherwise, the return value is **FALSE**. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). An error code
of [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) or ERROR_IO_PENDING indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur. Applications should handle either ERROR_IO_PENDING or WSA_IO_PENDING in this case.

| Return code | Description |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An established connection was aborted by the software in your host machine. This error is returned if the virtual circuit was terminated due to a time-out or other failure. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An existing connection was forcibly closed by the remote host. This error is returned for a stream socket when the virtual circuit was reset by the remote side. The application should close the socket as it is no longer usable. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if the *lpPacketArray* or the *lpOverlapped* parameter is not totally contained in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if the *dwFlags* parameter has the **TF_REUSE_SOCKET** flag set, but the **TF_DISCONNECT** flag was not set. This error is also returned if the offset specified in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure pointed to by the *lpOverlapped* is not within the file. This error is also returned if the total number of bytes to be transmitted is a value greater than 2,147,483,646, the maximum value for a 32-bit integer minus 1. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation encountered a dead network.This error is returned if the network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. This error is returned for a stream socket where the connection was broken due to keep-alive activity detecting a failure. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full. This error is also returned if the Windows Sockets provider reports a buffer deadlock. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A request to send or receive data was disallowed because the socket is not connected. This error is returned for a stream socket. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation was attempted on something that is not a socket. This error is returned if the *hSocket* parameter is not a socket. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. This error is returned if a stream socket has been shut down for sending. It is not possible to call [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) on a stream socket after the [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) function has been called on the socket with the *how* parameter set to **SD_SEND** or **SD_BOTH**. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Either the application has not called the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function, or **WSAStartup** failed. A successful **WSAStartup** call must occur before using the [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped I/O operation is in progress. This value is returned if an overlapped I/O operation was successfully initiated and indicates that completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The I/O operation has been aborted because of either a thread exit or an application request. This error is returned if the overlapped operation has been canceled due to the closure of the socket, the execution of the "SIO_FLUSH" command in [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), or the thread that initiated the overlapped request exited before the operation completed.<br><br>**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the asynchronous operations complete. For more information, see [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread). |

## Remarks

The
**TransmitPackets** function is optimized according to the operating system on which it is used:

* On Windows server editions, the
  **TransmitPackets** function is optimized for high performance.
* On Windows client editions, the
  **TransmitPackets** function is optimized for minimum memory and resource utilization.

The maximum number of bytes that can be transmitted using a single call to the **TransmitPackets** function is 2,147,483,646, the maximum value for a 32-bit integer minus 1. If an application needs to transmit data larger than 2,147,483,646 bytes, then multiple calls to the **TransmitPackets** function can be used with each call transferring no more than 2,147,483,646 bytes.

**Note** The function pointer for the
**TransmitPackets** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_TRANSMITPACKETS**, a globally unique identifier (GUID) whose value identifies the **TransmitPackets** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **TransmitPackets** function. The **WSAID_TRANSMITPACKETS** GUID is defined in the *Mswsock.h* header file.

Expect better performance results when using the
**TransmitPackets** function on Windows Server 2003.

When *lpOverlapped* is not **NULL**, overlapped I/O might not finish before the
**TransmitPackets** function returns. When this occurs, the
**TransmitPackets** function returns fails, and a call to the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function returns ERROR_IO_PENDING, allowing the caller to continue processing while the transmission completes.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

When the
**TransmitPackets** function returns **TRUE** or returns **FALSE** and
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) returns ERROR_IO_PENDING, Windows sets the event specified by the **hEvent** member of the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure or the socket specified by *hSocket* to the signaled state, and upon completion, delivers notification to any completion port associated with the socket. Use
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult), or
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) to retrieve final status and number of bytes transmitted.

TransmitPackets and Asynchronous Procedure Calls (APCs)

Use of the TF_USE_KERNEL_APC flag can deliver significant performance benefits. If the thread initiating the
**TransmitPackets** function call is being used for heavy computations, it is possible, though unlikely, that APCs could be prevented from launching.

**Note** There is a difference between kernel and user-mode APCs:

* Kernel APCs launch when a thread is in a wait state.
* User-mode APCs launch when a thread is in an alertable wait state.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[TRANSMIT_PACKETS_ELEMENT](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-transmit_packets_element)

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)