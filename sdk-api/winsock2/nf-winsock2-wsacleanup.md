# WSACleanup function

## Description

The
**WSACleanup** function terminates use of the Winsock 2 DLL (*Ws2_32.dll*).

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

In a multithreaded environment,
**WSACleanup** terminates Windows Sockets operations for all threads.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |

## Remarks

An application or DLL is required to perform a successful
[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call before it can use Windows Sockets services. When it has completed the use of Windows Sockets, the application or DLL must call
**WSACleanup** to deregister itself from a Windows Sockets implementation and allow the implementation to free any resources allocated on behalf of the application or DLL.

When **WSACleanup** is called, any pending blocking or asynchronous Windows Sockets calls issued by any thread in this process are canceled without posting any notification messages or without signaling any event objects. Any pending overlapped send or receive operations ([WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), or [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom) with an overlapped socket, for example) issued by any thread in this process are also canceled without setting the event object or invoking the completion routine, if one was specified. In this case, the pending overlapped operations fail with the error status **WSA_OPERATION_ABORTED**.

Sockets that were open when
**WSACleanup** was called are reset and automatically deallocated as if
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) were called. Sockets that have been closed with
**closesocket** but that still have pending data to be sent can be affected when
**WSACleanup** is called. In this case, the pending data can be lost if the WS2_32.DLL is unloaded from memory as the application exits. To ensure that all pending data is sent, an application should use
[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) to close the connection, then wait until the close completes before calling
**closesocket** and
**WSACleanup**. All resources and internal state, such as queued unposted or posted messages, must be deallocated so as to be available to the next user.

There must be a call to
**WSACleanup** for each successful call to
[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup). Only the final
**WSACleanup** function call performs the actual cleanup. The preceding calls simply decrement an internal reference count in the WS2_32.DLL.

**Note** **WSACleanup** does not unregister names (peer names, for example) that may have been registered with a Windows Sockets namespace provider such as Peer Name Resolution Protocol (PNRP) namespace provider.

In Windows Sockets 1.1, attempting to call
**WSACleanup** from within a blocking hook and then failing to check the return code was a common programming error. If a Winsock 1.1 application needs to quit while a blocking call is outstanding, the application has to first cancel the blocking call with
[WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall) then issue the
**WSACleanup** call once control has been returned to the application. In Windows Sockets 2, this issue does not exist and the **WSACancelBlockingCall** function has been removed.

The
**WSACleanup** function typically leads to protocol-specific helper DLLs being unloaded. As a result, the
**WSACleanup** function should not be called from the DllMain function in a application DLL. This can potentially cause deadlocks. For more information, please see the [DLL Main Function](https://learn.microsoft.com/windows/win32/dlls/dllmain).

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[PNRP Namespace Provider API](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-namespace-provider-api)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown)