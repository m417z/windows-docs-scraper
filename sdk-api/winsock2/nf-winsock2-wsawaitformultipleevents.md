# WSAWaitForMultipleEvents function

## Description

The
**WSAWaitForMultipleEvents** function returns when one or all of the specified event objects are in the signaled state, when the time-out interval expires, or when an I/O completion routine has executed.

## Parameters

### `cEvents` [in]

The number of event object handles in the array pointed to by *lphEvents*. The maximum number of event object handles is **WSA_MAXIMUM_WAIT_EVENTS**. One or more events must be specified.

### `lphEvents` [in]

A pointer to an array of event object handles. The array can contain handles of objects of different types. It may not contain multiple copies of the same handle if the *fWaitAll* parameter is set to **TRUE**.
If one of these handles is closed while the wait is still pending, the behavior of **WSAWaitForMultipleEvents** is undefined.

The handles must have the **SYNCHRONIZE** access right. For more information, see [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `fWaitAll` [in]

A value that specifies the wait type. If **TRUE**, the function returns when the state of all objects in the *lphEvents* array is signaled. If **FALSE**, the function returns when any of the event objects is signaled. In the latter case, the return value minus **WSA_WAIT_EVENT_0** indicates the index of the event object whose state caused the function to return. If more than one event object became signaled during the call, this is the array index to the signaled event object with the smallest index value of all the signaled event objects.

### `dwTimeout` [in]

The time-out interval, in milliseconds. **WSAWaitForMultipleEvents** returns if the time-out interval expires, even if conditions specified by the *fWaitAll* parameter are not satisfied. If the *dwTimeout* parameter is zero, **WSAWaitForMultipleEvents** tests the state of the specified event objects and returns immediately. If *dwTimeout* is **WSA_INFINITE**, **WSAWaitForMultipleEvents** waits forever; that is, the time-out interval never expires.

### `fAlertable` [in]

A value that specifies whether the thread is placed in an alertable wait state so the system can execute I/O completion routines. If **TRUE**, the thread is placed in an alertable wait state and **WSAWaitForMultipleEvents** can return when the system executes an I/O completion routine. In this case, **WSA_WAIT_IO_COMPLETION** is returned and the event that was being waited on is not signaled yet. The application must call the **WSAWaitForMultipleEvents** function again. If **FALSE**, the thread is not placed in an alertable wait state and I/O completion routines are not executed.

## Return value

If the
**WSAWaitForMultipleEvents** function succeeds, the return value upon success is one of the following values.

| Return Value | Meaning |
| --- | --- |
| **WSA_WAIT_EVENT_0 to (WSA_WAIT_EVENT_0 + cEvents - 1)** | If the *fWaitAll* parameter is **TRUE**, the return value indicates that all specified event objects is signaled. <br><br>If the *fWaitAll* parameter is **FALSE**, the return value minus **WSA_WAIT_EVENT_0** indicates the *lphEvents* array index of the signaled event object that satisfied the wait. If more than one event object became signaled during the call, the return value indicates the *lphEvents* array index of the signaled event object with the smallest index value of all the signaled event objects. |
| **WSA_WAIT_IO_COMPLETION** | The wait was ended by one or more I/O completion routines that were executed. The event that was being waited on is not signaled yet. The application must call the [WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) function again. This return value can only be returned if the *fAlertable* parameter is **TRUE**. |
| **WSA_WAIT_TIMEOUT** | The time-out interval elapsed and the conditions specified by the *fWaitAll* parameter were not satisfied. No I/O completion routines were executed. |

If the **WSAWaitForMultipleEvents** function fails, the return value is **WSA_WAIT_FAILED**. The following table lists values that can be used with [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) to get extended error information.

| Error code | Meaning |
| --- | --- |
| [WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem has failed. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| [WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | Not enough free memory was available to complete the operation. |
| [WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | One or more of the values in the *lphEvents* array is not a valid event object handle. |
| [WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The *cEvents* parameter does not contain a valid handle count. |

## Remarks

The **WSAWaitForMultipleEvents** function determines whether the wait criteria have been met. If the criteria have not been met, the calling thread enters the wait state. It uses no processor time while waiting for the criteria to be met.

The
**WSAWaitForMultipleEvents** function returns when any one or all of the specified objects are in the signaled state, or when the time-out interval elapses.

When the *bWaitAll* parameter is **TRUE**, the wait operation is completed only when the states of all objects have been set to signaled. The function does not modify the states of the specified objects until the states of all objects have been set to signaled.

When *bWaitAll* parameter is **FALSE**, **WSAWaitForMultipleEvents** checks the handles in the *lphEvents* array in order starting with index 0, until one of the objects is signaled. If multiple objects become signaled, the function returns the index of the first handle in the *lphEvents* array whose object was signaled.

This function is also used to perform an alertable wait by setting the *fAlertable* parameter to **TRUE**. This enables the function to return when the system executes an I/O completion routine by the calling thread.

A thread must be in an alertable wait state in order for the system to execute I/O completion routines (asynchronous procedure calls or APCs). So if an application calls **WSAWaitForMultipleEvents** when there are pending asynchronous operations that have I/O completion routines and the *fAlertable* parameter is **FALSE**, then those I/O completion routines will not be executed even if those I/O operations are completed.

If the *fAlertable* parameter is **TRUE** and one of the pending operations completes, the APC is executed and **WSAWaitForMultipleEvents** will return **WSA_IO_COMPLETION**.
The pending event is not signaled yet. The application must call the **WSAWaitForMultipleEvents** function again.

Applications that require an alertable wait state without waiting for any event objects to be signaled should use the Windows
[SleepEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleepex) function.

The current implementation of **WSAWaitForMultipleEvents** calls the [WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex) function.

**Note** Use caution when calling the **WSAWaitForMultipleEvents** with code that directly or indirectly creates windows. If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. A thread that uses **WSAWaitForMultipleEvents** with no time-out limit (the *dwTimeout* parameter set to **WSA_INFINITE**) may cause the system to become deadlocked.

### Example Code

The following code example shows how to use the **WSAWaitForMultipleEvents** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

#define DATA_BUFSIZE 4096

int main()
{
    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData = { 0 };
    int iResult = 0;
    BOOL bResult = TRUE;

    WSABUF DataBuf;
    char buffer[DATA_BUFSIZE];

    DWORD EventTotal = 0;
    DWORD RecvBytes = 0;
    DWORD Flags = 0;
    DWORD BytesTransferred = 0;

    WSAEVENT EventArray[WSA_MAXIMUM_WAIT_EVENTS];
    WSAOVERLAPPED AcceptOverlapped;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET AcceptSocket = INVALID_SOCKET;

    DWORD Index;

    //-----------------------------------------
    // Initialize Winsock
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }
    //-----------------------------------------
    // Create a listening socket bound to a local
    // IP address and the port specified
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error = %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    u_short port = 27015;
    char *ip;
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(port);
    hostent *thisHost;

    thisHost = gethostbyname("");
    if (thisHost == NULL) {
        wprintf(L"gethostbyname failed with error = %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    ip = inet_ntoa(*(struct in_addr *) *thisHost->h_addr_list);

    service.sin_addr.s_addr = inet_addr(ip);

    //-----------------------------------------
    // Bind the listening socket to the local IP address
    // and port number
    iResult = bind(ListenSocket, (SOCKADDR *) & service, sizeof (SOCKADDR));
    if (iResult != 0) {
        wprintf(L"bind failed with error = %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //-----------------------------------------
    // Set the socket to listen for incoming
    // connection requests
    iResult = listen(ListenSocket, 1);
    if (iResult != 0) {
        wprintf(L"listen failed with error = %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    wprintf(L"Listening...\n");

    //-----------------------------------------
    // Accept and incoming connection request
    AcceptSocket = accept(ListenSocket, NULL, NULL);
    if (AcceptSocket == INVALID_SOCKET) {
        wprintf(L"accept failed with error = %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    wprintf(L"Client Accepted...\n");

    //-----------------------------------------
    // Create an event handle and setup an overlapped structure.
    EventArray[EventTotal] = WSACreateEvent();
    if (EventArray[EventTotal] == WSA_INVALID_EVENT) {
        wprintf(L"WSACreateEvent failed with error = %d\n", WSAGetLastError());
        closesocket(AcceptSocket);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    ZeroMemory(&AcceptOverlapped, sizeof (WSAOVERLAPPED));
    AcceptOverlapped.hEvent = EventArray[EventTotal];

    DataBuf.len = DATA_BUFSIZE;
    DataBuf.buf = buffer;

    EventTotal++;

    //-----------------------------------------
    // Call WSARecv to receive data into DataBuf on
    // the accepted socket in overlapped I/O mode
    if (WSARecv(AcceptSocket, &DataBuf, 1, &RecvBytes, &Flags, &AcceptOverlapped, NULL) ==
        SOCKET_ERROR) {
        iResult = WSAGetLastError();
        if (iResult != WSA_IO_PENDING)
            wprintf(L"WSARecv failed with error = %d\n", iResult);
    }
    //-----------------------------------------
    // Process overlapped receives on the socket
    while (1) {

        //-----------------------------------------
        // Wait for the overlapped I/O call to complete
        Index = WSAWaitForMultipleEvents(EventTotal, EventArray, FALSE, WSA_INFINITE, FALSE);

        //-----------------------------------------
        // Reset the signaled event
        bResult = WSAResetEvent(EventArray[Index - WSA_WAIT_EVENT_0]);
        if (bResult == FALSE) {
            wprintf(L"WSAResetEvent failed with error = %d\n", WSAGetLastError());
        }
        //-----------------------------------------
        // Determine the status of the overlapped event
        bResult =
            WSAGetOverlappedResult(AcceptSocket, &AcceptOverlapped, &BytesTransferred, FALSE,
                                   &Flags);
        if (bResult == FALSE) {
            wprintf(L"WSAGetOverlappedResult failed with error = %d\n", WSAGetLastError());
        }
        //-----------------------------------------
        // If the connection has been closed, close the accepted socket
        if (BytesTransferred == 0) {
            wprintf(L"Closing accept Socket %d\n", AcceptSocket);
            closesocket(ListenSocket);
            closesocket(AcceptSocket);
            WSACloseEvent(EventArray[Index - WSA_WAIT_EVENT_0]);
            WSACleanup();
            return 1;
        }
        //-----------------------------------------
        // If data has been received, echo the received data
        // from DataBuf back to the client
        iResult =
            WSASend(AcceptSocket, &DataBuf, 1, &RecvBytes, Flags, &AcceptOverlapped, NULL);
        if (iResult != 0) {
            wprintf(L"WSASend failed with error = %d\n", WSAGetLastError());
        }
        //-----------------------------------------
        // Reset the changed flags and overlapped structure
        Flags = 0;
        ZeroMemory(&AcceptOverlapped, sizeof (WSAOVERLAPPED));

        AcceptOverlapped.hEvent = EventArray[Index - WSA_WAIT_EVENT_0];

        //-----------------------------------------
        // Reset the data buffer
        DataBuf.len = DATA_BUFSIZE;
        DataBuf.buf = buffer;
    }

    closesocket(ListenSocket);
    closesocket(AcceptSocket);
    WSACleanup();

    return 0;
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights)

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)