# WSAEnumNetworkEvents function

## Description

The
**WSAEnumNetworkEvents** function discovers occurrences of network events for the indicated socket, clear internal network event records, and reset event objects (optional).

## Parameters

### `s` [in]

A descriptor identifying the socket.

### `hEventObject` [in]

An optional handle identifying an associated event object to be reset.

### `lpNetworkEvents` [out]

A pointer to a
[WSANETWORKEVENTS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanetworkevents) structure that is filled with a record of network events that occurred and any associated error codes.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One of the specified parameters was invalid. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpNetworkEvents* parameter is not a valid part of the user address space. |

## Remarks

The
**WSAEnumNetworkEvents** function is used to discover which network events have occurred for the indicated socket since the last invocation of this function. It is intended for use in conjunction with
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect), which associates an event object with one or more network events. The recording of network events commences when
**WSAEventSelect** is called with a nonzero *lNetworkEvents* parameter and remains in effect until another call is made to
**WSAEventSelect** with the *lNetworkEvents* parameter set to zero, or until a call is made to
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect).

**WSAEnumNetworkEvents** only reports network activity and errors nominated through
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect). See the descriptions of
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) and
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) to find out how those functions report network activity and errors.

The socket's internal record of network events is copied to the structure referenced by *lpNetworkEvents*, after which the internal network events record is cleared. If the *hEventObject* parameter is not **NULL**, the indicated event object is also reset. The Windows Sockets provider guarantees that the operations of copying the network event record, clearing it and resetting any associated event object are atomic, such that the next occurrence of a nominated network event will cause the event object to become set. In the case of this function returning SOCKET_ERROR, the associated event object is not reset and the record of network events is not cleared.

The **lNetworkEvents** member of the
[WSANETWORKEVENTS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanetworkevents) structure indicates which of the FD_XXX network events have occurred. The **iErrorCode** array is used to contain any associated error codes with the array index corresponding to the position of event bits in **lNetworkEvents**. Identifiers such as FD_READ_BIT and FD_WRITE_BIT can be used to index the **iErrorCode** array. Note that only those elements of the **iErrorCode** array are set that correspond to the bits set in *lNetworkEvents* parameter. Other parameters are not modified (this is important for backward compatibility with the applications that are not aware of new FD_ROUTING_INTERFACE_CHANGE and FD_ADDRESS_LIST_CHANGE events).

The following error codes can be returned along with the corresponding network event.

**Event: FD_CONNECT**

| Error code | Meaning |
| --- | --- |
| [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | Addresses in the specified family cannot be used with this socket. |
| [WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The attempt to connect was forcefully rejected. |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network cannot be reached from this host at this time. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | No buffer space is available. The socket cannot be connected. |
| [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | An attempt to connect timed out without establishing a connection |

**Event: FD_CLOSE**

| Error code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem has failed. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The connection was reset by the remote side. |
| [WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The connection was terminated due to a time-out or other failure. |

**Event: FD_ACCEPT**

**Event: FD_ADDRESS_LIST_CHANGE**

**Event: FD_GROUP_QOS**

**Event: FD_QOS**

**Event: FD_OOB**

**Event: FD_READ**

**Event: FD_WRITE**

| Error code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem has failed. |

**Event: FD_ROUTING_INTERFACE_CHANGE**

| Error code | Meaning |
| --- | --- |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The specified destination is no longer reachable. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem has failed. |

### Example Code

The following example demonstrates the use of the WSAEnumNetworkEvents function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{
//-------------------------
// Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    SOCKET SocketArray[WSA_MAXIMUM_WAIT_EVENTS], ListenSocket;
    WSAEVENT EventArray[WSA_MAXIMUM_WAIT_EVENTS];
    WSANETWORKEVENTS NetworkEvents;
    sockaddr_in InetAddr;
    DWORD EventTotal = 0;
    DWORD Index;
    DWORD i;

    HANDLE NewEvent = NULL;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

//-------------------------
// Create a listening socket
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %d\n", WSAGetLastError() );
        return 1;
    }

    InetAddr.sin_family = AF_INET;
    InetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    InetAddr.sin_port = htons(27015);

//-------------------------
// Bind the listening socket
    iResult = bind(ListenSocket, (SOCKADDR *) & InetAddr, sizeof (InetAddr));
    if (iResult != 0) {
        wprintf(L"bind failed with error: %d\n", WSAGetLastError() );
        return 1;
    }

//-------------------------
// Create a new event
    NewEvent = WSACreateEvent();
    if (NewEvent == NULL) {
        wprintf(L"WSACreateEvent failed with error: %d\n", GetLastError() );
        return 1;
    }

//-------------------------
// Associate event types FD_ACCEPT and FD_CLOSE
// with the listening socket and NewEvent
    iResult = WSAEventSelect(ListenSocket, NewEvent, FD_ACCEPT | FD_CLOSE);
    if (iResult != 0) {
        wprintf(L"WSAEventSelect failed with error: %d\n", WSAGetLastError() );
        return 1;
    }

//-------------------------
// Start listening on the socket
    iResult = listen(ListenSocket, 10);
    if (iResult != 0) {
        wprintf(L"listen failed with error: %d\n", WSAGetLastError() );
        return 1;
    }

//-------------------------
// Add the socket and event to the arrays, increment number of events
    SocketArray[EventTotal] = ListenSocket;
    EventArray[EventTotal] = NewEvent;
    EventTotal++;

//-------------------------
// Wait for network events on all sockets
    Index = WSAWaitForMultipleEvents(EventTotal, EventArray, FALSE, WSA_INFINITE, FALSE);
    Index = Index - WSA_WAIT_EVENT_0;

//-------------------------
// Iterate through all events and enumerate
// if the wait does not fail.
    for (i = Index; i < EventTotal; i++) {
        Index = WSAWaitForMultipleEvents(1, &EventArray[i], TRUE, 1000, FALSE);
        if ((Index != WSA_WAIT_FAILED) && (Index != WSA_WAIT_TIMEOUT)) {
            WSAEnumNetworkEvents(SocketArray[i], EventArray[i], &NetworkEvents);
        }
    }

//...
    return 0;

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)