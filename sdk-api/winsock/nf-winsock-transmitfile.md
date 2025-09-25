# TransmitFile function

## Description

The
**TransmitFile** function transmits file data over a connected socket handle. This function uses the operating system's cache manager to retrieve the file data, and provides high-performance file data transfer over sockets.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `hSocket`

A handle to a connected socket. The
**TransmitFile** function will transmit the file data over this socket. The socket specified by the *hSocket* parameter must be a connection-oriented socket of type **SOCK_STREAM**, **SOCK_SEQPACKET**, or **SOCK_RDM**.

### `hFile`

A handle to the open file that the
**TransmitFile** function transmits. Since the operating system reads the file data sequentially, you can improve caching performance by opening the handle with FILE_FLAG_SEQUENTIAL_SCAN.

The *hFile* parameter is optional. If the *hFile* parameter is **NULL**, only data in the header and/or the tail buffer is transmitted. Any additional action, such as socket disconnect or reuse, is performed as specified by the *dwFlags* parameter.

### `nNumberOfBytesToWrite`

The number of bytes in the file to transmit. The
**TransmitFile** function completes when it has sent the specified number of bytes, or when an error occurs, whichever occurs first.

Set this parameter to zero in order to transmit the entire file.

### `nNumberOfBytesPerSend`

The size, in bytes, of each block of data sent in each send operation. This parameter is used by Windows' sockets layer to determine the block size for send operations. To select the default send size, set this parameter to zero.

The *nNumberOfBytesPerSend* parameter is useful for protocols that have limitations on the size of individual send requests.

### `lpOverlapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. If the socket handle has been opened as overlapped, specify this parameter in order to achieve an overlapped (asynchronous) I/O operation. By default, socket handles are opened as overlapped.

You can use the *lpOverlapped* parameter to specify a 64-bit offset within the file at which to start the file data transfer by setting the **Offset** and **OffsetHigh** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. If *lpOverlapped* is a **NULL** pointer, the transmission of data always starts at the current byte offset in the file.

When the *lpOverlapped* is not **NULL**, the overlapped I/O might not finish before
**TransmitFile** returns. In that case, the
**TransmitFile** function returns **FALSE**, and [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) returns ERROR_IO_PENDING or [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). This enables the caller to continue processing while the file transmission operation completes. Windows will set the event specified by the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, or the socket specified by *hSocket*, to the signaled state upon completion of the data transmission request.

### `lpTransmitBuffers`

A pointer to a
[TRANSMIT_FILE_BUFFERS](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-transmit_file_buffers) data structure that contains pointers to data to send before and after the file data is sent. This parameter should be set to a **NULL** pointer if you want to transmit only the file data.

### `dwReserved`

A set of flags used to modify the behavior of the **TransmitFile** function call. The *dwFlags* parameter can contain a combination of the following options defined in the *Mswsock.h* header file:

| Flag | Meaning |
| --- | --- |
| **TF_DISCONNECT** | Start a transport-level disconnect after all the file data has been queued for transmission. |
| **TF_REUSE_SOCKET** | Prepare the socket handle to be reused. This flag is valid only if **TF_DISCONNECT** is also specified.<br><br>When the **TransmitFile** request completes, the socket handle can be passed to the function call previously used to establish the connection, such as [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) or [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex). Such reuse is mutually exclusive; for example, if the **AcceptEx** function was called for the socket, reuse is allowed only for subsequent calls to the **AcceptEx** function, and not allowed for a subsequent call to **ConnectEx**. <br><br>**Note** The socket level file transmit is subject to the behavior of the underlying transport. For example, a TCP socket may be subject to the TCP TIME_WAIT state, causing the **TransmitFile** call to be delayed. |
| **TF_USE_DEFAULT_WORKER** | Directs the Windows Sockets service provider to use the system's default thread to process long **TransmitFile** requests. The system default thread can be adjusted using the following registry parameter as a **REG_DWORD**:<br><br>**HKEY_LOCAL_MACHINE**\**CurrentControlSet**\**Services**\**AFD**\**Parameters**\**TransmitWorker** |
| **TF_USE_SYSTEM_THREAD** | Directs the Windows Sockets service provider to use system threads to process long **TransmitFile** requests. |
| **TF_USE_KERNEL_APC** | Directs the driver to use kernel asynchronous procedure calls (APCs) instead of worker threads to process long **TransmitFile** requests. Long **TransmitFile** requests are defined as requests that require more than a single read from the file or a cache; the request therefore depends on the size of the file and the specified length of the send packet.<br><br>Use of TF_USE_KERNEL_APC can deliver significant performance benefits. It is possible (though unlikely), however, that the thread in which context **TransmitFile** is initiated is being used for heavy computations; this situation may prevent APCs from launching. Note that the Winsock kernel mode driver uses normal kernel APCs, which launch whenever a thread is in a wait state, which differs from user-mode APCs, which launch whenever a thread is in an alertable wait state initiated in user mode). |
| **TF_WRITE_BEHIND** | Complete the **TransmitFile** request immediately, without pending. If this flag is specified and **TransmitFile** succeeds, then the data has been accepted by the system but not necessarily acknowledged by the remote end. Do not use this setting with the TF_DISCONNECT and TF_REUSE_SOCKET flags.<br><br>**Note** If the file being sent is not in the file system cache, the request pends. |

## Return value

If the
**TransmitFile** function succeeds, the return value is **TRUE**. Otherwise, the return value is **FALSE**. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). An error code
of [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) or ERROR_IO_PENDING indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur. Applications should handle either ERROR_IO_PENDING or WSA_IO_PENDING in this case.

| Return code | Description |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An established connection was aborted by the software in your host machine. This error is returned if the virtual circuit was terminated due to a time-out or other failure. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An existing connection was forcibly closed by the remote host. This error is returned for a stream socket when the virtual circuit was reset by the remote side. The application should close the socket as it is no longer usable. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if the *lpTransmitBuffers* or *lpOverlapped* parameter is not totally contained in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if the *hSocket* parameter specified a socket of type **SOCK_DGRAM** or **SOCK_RAW**. This error is returned if the *dwFlags* parameter has the **TF_REUSE_SOCKET** flag set, but the **TF_DISCONNECT** flag was not set. This error is also returned if the offset specified in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure pointed to by the *lpOverlapped* is not within the file. This error is also returned if the *nNumberOfBytesToWrite* parameter is set to a value greater than 2,147,483,646, the maximum value for a 32-bit integer minus 1. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation encountered a dead network.This error is returned if the network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full. This error is also returned if the Windows Sockets provider reports a buffer deadlock. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A request to send or receive data was disallowed because the socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation was attempted on something that is not a socket. This error is returned if the *hSocket* parameter is not a socket. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. This error is returned if the socket has been shut down for sending. It is not possible to call [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) on a socket after the [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) function has been called on the socket with the *how* parameter set to **SD_SEND** or **SD_BOTH**. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Either the application has not called the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function, or **WSAStartup** failed. A successful **WSAStartup** call must occur before using the [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped I/O operation is in progress. This value is returned if an overlapped I/O operation was successfully initiated and indicates that completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The I/O operation has been aborted because of either a thread exit or an application request. This error is returned if the overlapped operation has been canceled due to the closure of the socket, the execution of the "SIO_FLUSH" command in [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), or the thread that initiated the overlapped request exited before the operation completed.<br><br>**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the asynchronous operations complete. For more information, see [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread). |

## Remarks

The **TransmitFile** function uses the operating system's cache manager to retrieve the file data, and provide high-performance file data transfer over sockets.

The **TransmitFile** function only supports connection-oriented sockets of type **SOCK_STREAM**, **SOCK_SEQPACKET**, and **SOCK_RDM**. Sockets of type **SOCK_DGRAM** and **SOCK_RAW** are not supported. The [TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets) function can be used with sockets of type **SOCK_DGRAM**.

The maximum number of bytes that can be transmitted using a single call to the **TransmitFile** function is 2,147,483,646, the maximum value for a 32-bit integer minus 1. The maximum number of bytes to send in a single call includes any data sent before or after the file data pointed to by the *lpTransmitBuffers* parameter plus the value specified in the *nNumberOfBytesToWrite* parameter for the length of file data to send. If an application needs to transmit a file larger than 2,147,483,646 bytes, then multiple calls to the **TransmitFile** function can be used with each call transferring no more than 2,147,483,646 bytes. Setting the *nNumberOfBytesToWrite* parameter to zero for a file larger than 2,147,483,646 bytes will also fail since in this case the **TransmitFile** function will use the size of the file as the value for the number of bytes to transmit.

**Note** The function pointer for the
**TransmitFile** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_TRANSMITFILE**, a globally unique identifier (GUID) whose value identifies the **TransmitFile** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **TransmitFile** function. The **WSAID_TRANSMITFILE** GUID is defined in the *Mswsock.h* header file.

**Note** **TransmitFile** is not functional on transports that perform their own buffering. Transports with the TDI_SERVICE_INTERNAL_BUFFERING flag set, such as ADSP, perform their own buffering. Because
**TransmitFile** achieves its performance gains by sending data directly from the file cache. Transports that run out of buffer space on a particular connection are not handled by
**TransmitFile**, and as a result of running out of buffer space on the connection,
**TransmitFile** returns STATUS_DEVICE_NOT_READY.

The **TransmitFile** function was primarily added to Winsock for use by high-performance server applications (web and ftp servers, for example).

Workstation and client versions of Windows optimize the **TransmitFile** function for minimum memory and resource utilization by limiting the number of concurrent **TransmitFile** operations allowed on the system to a maximum of two. On Windows Vista, Windows XP,
Windows 2000 Professional, and
Windows NT Workstation 3.51 and later only two outstanding **TransmitFile** requests are handled simultaneously; the third request will wait until one of the previous requests is completed.

Server versions of Windows optimize the
**TransmitFile** function for high performance. On server versions, there are no default limits placed on the number of concurrent **TransmitFile** operations allowed on the system. Expect better performance results when using
**TransmitFile** on server versions of Windows. On server versions of Windows, it is possible to set a limit on the maximum number of concurrent **TransmitFile** operations by creating a registry entry and setting a value for the following **REG_DWORD**:

**HKEY_LOCAL_MACHINE**\**CurrentControlSet**\**Services**\**AFD**\**Parameters**\**MaxActiveTransmitFileCount**

If the **TransmitFile** function is called with TCP socket (protocol of IPPROTO_TCP) with both the **TF_DISCONNECT** and **TF_REUSE_SOCKET** flags specified, the call will not complete until the two following conditions are met.

* All pending receive data sent by remote side (received prior to a FIN from the remote side) on the TCP socket has been read.
* The remote side has closed the connection (completed the graceful TCP connection closure).

If the **TransmitFile** function is called with the *lpOverlapped* parameter set to **NULL**, the operation is executed as synchronous I/O. The function will not complete until the file has been sent.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

### Notes for QoS

The
**TransmitFile** function allows the setting of two flags, TF_DISCONNECT or TF_REUSE_SOCKET, that return the socket to a "disconnected, reusable" state after the file has been transmitted. These flags should not be used on a socket where quality of service has been requested, since the service provider may immediately delete any quality of service associated with the socket before the file transfer has completed. The best approach for a QoS-enabled socket is to simply call the
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function when the file transfer has completed, rather than relying on these flags.

## See also

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[TRANSMIT_FILE_BUFFERS](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-transmit_file_buffers)

[TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)