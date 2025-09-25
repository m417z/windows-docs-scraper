# WSARevertImpersonation function

## Description

The **WSARevertImpersonation** function terminates the impersonation of a socket peer. This must be called after calling [WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer) and finishing any access checks.

## Return value

If the function succeeds, the return value is zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Some possible error codes are listed below.

| Error code | Meaning |
| --- | --- |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |

## Remarks

The **WSARevertImpersonation** function causes the calling thread to discontinue
the impersonation of a socket peer. If the thread is not currently
impersonating a socket peer, no action is taken.

The **WSARevertImpersonation** function should be called after calling [WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer) and all access checks are finished.

## See also

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSADeleteSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsadeletesocketpeertargetname)

[WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)