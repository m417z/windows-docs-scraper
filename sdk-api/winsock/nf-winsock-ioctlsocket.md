# ioctlsocket function (winsock.h)

## Description

The **ioctlsocket** function controls the I/O mode of a socket.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `cmd` [in]

A command to perform on the socket *s*. See [Winsock IOCTLs](https://learn.microsoft.com/windows/win32/winsock/winsock-ioctls).

### `argp` [in, out]

A pointer to a parameter for *cmd*.

## Return value

Upon successful completion, the
**ioctlsocket** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor *s* is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *argp* parameter is not a valid part of the user address space. |

## Remarks

The
**ioctlsocket** function can be used on any socket in any state. It is used to set or retrieve some operating parameters associated with the socket, independent of the protocol and communications subsystem. Here are the supported commands to use in the *cmd* parameter and their semantics:

The [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)
function is used to set or retrieve operating parameters associated with the socket, the transport protocol, or the communications subsystem.

The **WSAIoctl**
function is more powerful than the **ioctlsocket** function and supports a large number of possible values for the operating parameters to set or retrieve.

### Example Code

The following example demonstrates the use of the **ioctlsocket** function.

```cpp

#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

void main()
{
//-------------------------
// Initialize Winsock
WSADATA wsaData;
int iResult;
u_long iMode = 0;

iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
if (iResult != NO_ERROR)
  printf("Error at WSAStartup()\n");

//-------------------------
// Create a SOCKET object.
SOCKET m_socket;
m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (m_socket == INVALID_SOCKET) {
  printf("Error at socket(): %ld\n", WSAGetLastError());
  WSACleanup();
  return;
}

//-------------------------
// Set the socket I/O mode: In this case FIONBIO
// enables or disables the blocking mode for the
// socket based on the numerical value of iMode.
// If iMode = 0, blocking is enabled;
// If iMode != 0, non-blocking mode is enabled.

iResult = ioctlsocket(m_socket, FIONBIO, &iMode);
if (iResult != NO_ERROR)
  printf("ioctlsocket failed with error: %ld\n", iResult);

}

```

### Compatibility

This
**ioctlsocket** function performs only a subset of functions on a socket when compared to the **ioctl** function found in Berkeley sockets. The
**ioctlsocket** function has no command parameter equivalent to the FIOASYNC of **ioctl**, and SIOCATMARK is the only socket-level command that is supported by
**ioctlsocket**.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)