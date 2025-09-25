## Description

The **DisconnectEx** function closes a connection on a socket, and allows the socket handle to be reused.

> [!NOTE]
> This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `s`

A handle to a connected, connection-oriented socket.

### `lpOverlapped`

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. If the socket handle has been opened as overlapped, specifying this parameter results in an overlapped (asynchronous) I/O operation.

### `dwFlags`

A set of flags that customizes processing of the function call. When this parameter is set to zero, no flags are set. The *dwFlags* parameter can have the following value.

| Flag | Meaning |
|--|--|
| **TF_REUSE_SOCKET** | Prepares the socket handle to be reused. When the **DisconnectEx** request completes, the socket handle can be passed to the [**AcceptEx**](https://learn.microsoft.com/windows/win32/api/mswsock/nf-mswsock-acceptex) or [**ConnectEx**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_connectex) function. <br> **Note:** The socket level disconnect is subject to the behavior of the underlying transport. For example, a TCP socket may be subject to the TCP TIME_WAIT state, causing the **DisconnectEx** call to be delayed. |

### `dwReserved`

Reserved. Must be zero. If nonzero, [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeinval) is returned.

## Return value

On success, the **DisconnectEx** function returns **TRUE**. On failure, the function returns **FALSE**. Use the [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function to get extended error information. If a call to the **WSAGetLastError** function returns **ERROR\_IO\_PENDING**, the operation initiated successfully and is in progress. Under such circumstances, the call may still fail when the operation completes.

| Error code | Description |
|-|-|
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaefault)** | The system detected an invalid pointer address in attempting to use a pointer argument. This error is returned if an invalid pointer value was passed in the *lpOverlapped* parameter. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeinval)** | The invalid parameter was passed. This error is returned if the *dwFlags* parameter was specified with a zero value other than **TF\_REUSE\_SOCKET**. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeisconn)** | The socket is not connected. This error is returned if the socket *s* parameter was not in a connected state. This error can also be returned if the socket was in the transmit closing state from a previous request and the *dwFlags* parameter was not set to **TF\_REUSE\_SOCKET** to request a reuse of the socket. |

## Remarks

The **DisconnectEx** function does not support datagram sockets. Therefore, the socket specified by *hSocket* must be connection-oriented, such as a SOCK\_STREAM, SOCK\_SEQPACKET, or SOCK\_RDM socket.

> [!NOTE]
> The function pointer for the **DisconnectEx** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_DISCONNECTEX**, a globally unique identifier (GUID) whose value identifies the **DisconnectEx** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **DisconnectEx** function. The **WSAID\_DISCONNECTEX** GUID is defined in the *Mswsock.h* header file.

When *lpOverlapped* is not **NULL**, overlapped I/O might not finish before **DisconnectEx** returns, resulting in the **DisconnectEx** function returning **FALSE** and a call to the [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function returning **ERROR\_IO\_PENDING**. This design enables the caller to continue processing while the disconnect operation completes. Upon completion of the request, Windows sets either the event specified by the **hEvent** member of the [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure, or the socket specified by *hSocket*, to the signaled state.

> [!NOTE]
> All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [**ExitThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

The TIME\_WAIT state determines the time that must elapse before TCP can release a closed connection and reuse its resources. This interval between closure and release is known as the TIME\_WAIT state or 2MSL state. During this time, the connection can be reopened at much less cost to the client and server than establishing a new connection. The TIME\_WAIT behavior is specified in [RFC 793](https://www.ietf.org/rfc/rfc793.txt) which requires that TCP maintains a closed connection for an interval at least equal to twice the maximum segment lifetime (MSL) of the network. When a connection is released, its socket pair and internal resources used for the socket can be used to support another connection.

Windows TCP reverts to a TIME\_WAIT state subsequent to the closing of a connection. While in the TIME\_WAIT state, a socket pair cannot be re-used. The TIME\_WAIT period is configurable by modifying the following DWORD registry setting that represents the TIME\_WAIT period in seconds.

**HKEY\_LOCAL\_MACHINE**\\**System**\\**CurrentControlSet**\\**Services**\\**TCPIP**\\**Parameters**\\**TcpTimedWaitDelay**

By default, the MSL is defined to be 120 seconds. The TcpTimedWaitDelay registry setting defaults to a value 240 seconds, which represents 2 times the maximum segment lifetime of 120 seconds or 4 minutes. However, you can use this entry to customize the interval. Reducing the value of this entry allows TCP to release closed connections faster, providing more resources for new connections. However, if the value is too low, TCP might release connection resources before the connection is complete, requiring the server to use additional resources to re-establish the connection. This registry setting can be set from 0 to 300 seconds.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also