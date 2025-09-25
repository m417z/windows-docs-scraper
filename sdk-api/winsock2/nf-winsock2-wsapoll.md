# WSAPoll function

## Description

The **WSAPoll** function determines status of one or more sockets.

## Parameters

### `fdArray` [in, out]

An array of one or more **POLLFD** structures specifying the set of sockets for which status is requested. The array must contain at least one structure with a valid socket. Upon return, this parameter receives the updated sockets with the **revents** status flags member set on each one that matches the status query criteria.

### `fds` [in]

The number of **WSAPOLLFD** structures in *fdarray*. This is not necessarily the number of sockets for which status is requested.

### `timeout` [in]

A value that specifies the wait behavior, based on the following values.

| Value | Meaning |
| --- | --- |
| Greater than zero | The time, in milliseconds, to wait. |
| Zero | Return immediately. |
| Less than zero | Wait indefinitely. |

## Return value

Returns one of the following values.

| Return value | Description |
| --- | --- |
| Zero | No sockets were in the queried state before the timer expired. |
| Greater than zero | The number of elements in *fdarray* for which an **revents** member of the **POLLFD** structure is nonzero. |
| SOCKET_ERROR | An error occurred. Call the [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function to retrieve the extended error code. |

| Extended Error code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An exception occurred while reading user input parameters. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structures pointed to by the *fdarray* parameter when requesting socket status. This error is also returned if none of the sockets specified in the **fd** member of any of the **WSAPOLLFD** structures pointed to by the *fdarray* parameter were valid. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The function was unable to allocate sufficient memory. |

## Remarks

The **WSAPoll** function is defined on Windows Vista and later.

The [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structures. An application sets the appropriate flags in the **events** member of the **WSAPOLLFD** structure to specify the type of status requested for each corresponding socket. The **WSAPoll** function returns the status of a socket in the **revents** member of the **WSAPOLLFD** structure.

For each socket, a caller can request information on read or write status. Error conditions are always returned, so information on them need not be requested.

The [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure pointed to by the *fdarray* parameter. All sockets that do not meet these criteria and have no error condition will have the corresponding **revents** member set to 0.

A combination of the following flags can be set in the [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure for a given socket when requesting status for that socket:

| Flag | Description |
| --- | --- |
| POLLPRI | Priority data may be read without blocking. This flag is not supported by the Microsoft Winsock provider. |
| POLLRDBAND | Priority band (out-of-band) data may be read without blocking. |
| POLLRDNORM | Normal data may be read without blocking. |
| POLLWRNORM | Normal data may be written without blocking. |

The **POLLIN** flag is defined as the combination of the **POLLRDNORM** and **POLLRDBAND** flag values. The **POLLOUT** flag is defined as the same as the **POLLWRNORM** flag value.

The [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure must only contain a combination of the above flags that are supported by the Winsock provider. Any other values are considered errors and **WSAPoll** will return **SOCKET_ERROR**. A subsequent call to the [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function will retrieve the extended error code of [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). If the **POLLPRI** flag is set on a socket for the Microsoft Winsock provider, the **WSAPoll** function will fail.

When the [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structures pointed to by the *fdarray* parameter to indicate socket status:

| Flag | Description |
| --- | --- |
| POLLERR | An error has occurred. |
| POLLHUP | A stream-oriented connection was either disconnected or aborted. |
| POLLNVAL | An invalid socket was used. |
| POLLPRI | Priority data may be read without blocking. This flag is not returned by the Microsoft Winsock provider. |
| POLLRDBAND | Priority band (out-of-band) data may be read without blocking. |
| POLLRDNORM | Normal data may be read without blocking. |
| POLLWRNORM | Normal data may be written without blocking. |

With regard to TCP and UDP sockets:

* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure as normal data as **POLLRDNORM**.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure, a subsequent [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) operation is guaranteed to complete without blocking.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure by **POLLWRNORM**.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure by **POLLRDNORM**. A subsequent call to [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) is guaranteed to complete without blocking.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure by **POLLRDBAND**.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure when a remote peer shuts down a [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) operation (a TCP FIN was received). A subsequent [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function request will return zero bytes.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure when the remote peer initiates a graceful disconnect.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure returned when a remote peer suddenly disconnects.
* [WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd) structure when the local socket is closed.

The number of elements (not sockets) in *fdarray* is indicated by *nfds*. Members of *fdarray* which have their **fd** member set to a negative value are ignored and their **revents** will be set to **POLLNVAL** upon return. This behavior is useful to an application which maintains a fixed *fdarray* allocation and will not compact the array to remove unused entries or to reallocate memory. It is not necessary to clear **revents** for any element prior to calling **WSAPoll**.

The timeout argument specifies how long the function is to wait before returning. A positive value contains the number of milliseconds to wait before returning. A zero value forces **WSAPoll** to return immediately, and a negative value indicates that **WSAPoll** should wait indefinitely.

**Note** When issuing a blocking Winsock call such as **WSAPoll** with the *timeout* parameter set to a negative number, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Note** As of Windows 10 version 2004, when a TCP socket fails to connect, (POLLHUP \| POLLERR \| POLLWRNORM) is indicated.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAPOLLFD](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsapollfd)