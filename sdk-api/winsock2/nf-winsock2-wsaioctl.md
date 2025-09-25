# WSAIoctl function (winsock2.h)

## Description

The **WSAIoctl** function controls the mode of a socket.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `dwIoControlCode` [in]

The control code of operation to perform. See [Winsock IOCTLs](https://learn.microsoft.com/windows/win32/winsock/winsock-ioctls).

### `lpvInBuffer` [in]

A pointer to the input buffer.

### `cbInBuffer` [in]

The size, in bytes, of the input buffer.

### `lpvOutBuffer` [out]

A pointer to the output buffer.

### `cbOutBuffer` [in]

The size, in bytes, of the output buffer.

### `lpcbBytesReturned` [out]

A pointer to actual number of bytes of output.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure (ignored for non-overlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

**Note** A pointer to the completion routine called when the operation has been completed (ignored for non-overlapped sockets). See Remarks.

## Return value

Upon successful completion, the
**WSAIoctl** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpvInBuffer*, *lpvOutBuffer*, *lpcbBytesReturned*, *lpOverlapped*, or *lpCompletionRoutine* parameter is not totally contained in a valid part of the user address space, or the *cbInBuffer* or *cbOutBuffer* parameter is too small. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *dwIoControlCode* parameter is not a valid command, or a specified input parameter is not acceptable, or the command is not applicable to the type of socket specified. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The function is invoked when a callback is in progress. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor *s* is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified IOCTL command cannot be realized. (For example, the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures specified in **SIO_SET_QOS** or **SIO_SET_GROUP_QOS** cannot be satisfied.) |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as non-blocking and the requested operation would block. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket option is not supported on the specified protocol. For example, an attempt to use the **SIO_GET_BROADCAST_ADDRESS** IOCTL was made on an IPv6 socket or an attempt to use the TCP **SIO_KEEPALIVE_VALS** IOCTL was made on a datagram socket. |

## Remarks

The
**WSAIoctl** function is used to set or retrieve operating parameters associated with the socket, the transport protocol, or the communications subsystem.

If both *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket in this function will be treated as a non-overlapped socket. For a non-overlapped socket, *lpOverlapped* and *lpCompletionRoutine* parameters are ignored, which causes the function to behave like the standard
[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket) function except that the function can block if socket *s* is in blocking mode. If socket *s* is in non-blocking mode, this function can return WSAEWOULDBLOCK when the specified operation cannot be finished immediately. In this case, the application may change the socket to blocking mode and reissue the request or wait for the corresponding network event (such as FD_ROUTING_INTERFACE_CHANGE or FD_ADDRESS_LIST_CHANGE in the case of **SIO_ROUTING_INTERFACE_CHANGE** or **SIO_ADDRESS_LIST_CHANGE**) using a Windows message (using
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect))-based or event (using
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect))-based notification mechanism.

For overlapped sockets, operations that cannot be completed immediately will be initiated, and completion will be indicated at a later time. The **DWORD** value pointed to by the *lpcbBytesReturned* parameter that is returned may be ignored. The final completion status and bytes returned can be retrieved when the appropriate completion method is signaled when the operation
has completed.

Any IOCTL may block indefinitely, depending on the service provider's implementation. If the application cannot tolerate blocking in a
**WSAIoctl** call, overlapped I/O would be advised for IOCTLs that are especially likely to block including:

**SIO_ADDRESS_LIST_CHANGE**

**SIO_FINDROUTE**

**SIO_FLUSH**

**SIO_GET_QOS**

**SIO_GET_GROUP_QOS**

**SIO_ROUTING_INTERFACE_CHANGE**

**SIO_SET_QOS**

**SIO_SET_GROUP_QOS**

Some protocol-specific IOCTLs may also be especially likely to block. Check the relevant protocol-specific annex for any available information.

The prototype for the completion routine pointed to by the *lpCompletionRoutine* parameter is as follows:

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

void CALLBACK CompletionRoutine (
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

The CompletionRoutine is a placeholder for an application-supplied function name. The *dwError* parameter specifies the completion status for the overlapped operation as indicated by *lpOverlapped* parameter. The *cbTransferred* parameter specifies the number of bytes received. The *dwFlags* parameter is not used for this IOCTL. The completion routine does not return a value.

It is possible to adopt an encoding scheme that preserves the currently defined
[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket) opcodes while providing a convenient way to partition the opcode identifier space in as much as the *dwIoControlCode* parameter is now a 32-bit entity. The *dwIoControlCode* parameter is built to allow for protocol and vendor independence when adding new control codes while retaining backward compatibility with the Windows Sockets 1.1 and Unix control codes. The *dwIoControlCode* parameter has the following form.

| I | O | V | T | Vendor/address family | Code |
| --- | --- | --- | --- | --- | --- |
| 3 | 3 | 2 | 2 2 | 2 2 2 2 2 2 2 1 1 1 1 | 1 1 1 1 1 1 |
| 1 | 0 | 9 | 8 7 | 6 5 4 3 2 1 0 9 8 7 6 | 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 |

**Note** The bits in *dwIoControlCode* parameter displayed in the table must be read vertically from top to bottom by column. So the left-most bit is bit 31, the next bit is bit 30, and the right-most bit is bit 0.

I is set if the input buffer is valid for the code, as with **IOC_IN**.

O is set if the output buffer is valid for the code, as with **IOC_OUT**. Control codes using both input and output buffers set both I and O.

V is set if there are no parameters for the code, as with **IOC_VOID**.

T is a 2-bit quantity that defines the type of the IOCTL. The following values are defined:

0 The IOCTL is a standard Unix IOCTL code, as with **FIONREAD** and **FIONBIO**.

1 The IOCTL is a generic Windows Sockets 2 IOCTL code. New IOCTL codes defined for Windows Sockets 2 will have T == 1.

2 The IOCTL applies only to a specific address family.

3 The IOCTL applies only to a specific vendor's provider, as with **IOC_VENDOR**. This type allows companies to be assigned a vendor number that appears in the **Vendor/Address family** parameter. Then, the vendor can define new IOCTLs specific to that vendor without having to register the IOCTL with a clearinghouse, thereby providing vendor flexibility and privacy.

**Vendor/Address family** An 11-bit quantity that defines the vendor who owns the code (if T == 3) or that contains the address family to which the code applies (if T == 2). If this is a Unix IOCTL code (T == 0) then this parameter has the same value as the code on Unix. If this is a generic Windows Sockets 2 IOCTL (T == 1) then this parameter can be used as an extension of the code parameter to provide additional code values.

**Code** The 16-bit quantity that contains the specific IOCTL code for the operation.

The following Unix IOCTL codes (commands) are supported.

The following Windows Sockets 2 commands are supported.

If an overlapped operation completes immediately,
**WSAIoctl** returns a value of zero and the *lpcbBytesReturned* parameter is updated with the number of bytes in the output buffer. If the overlapped operation is successfully initiated and will complete later, this function returns SOCKET_ERROR and indicates error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, *lpcbBytesReturned* is not updated. When the overlapped operation completes the amount of data in the output buffer is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

When called with an overlapped socket, the *lpOverlapped* parameter must be valid for the duration of the overlapped operation. The *lpOverlapped* parameter contains the address of a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

If the *lpCompletionRoutine* parameter is **NULL**, the *hEvent* parameter of *lpOverlapped* is signaled when the overlapped operation completes if it contains a valid event object handle. An application can use
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) to wait or poll on the event object.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

If *lpCompletionRoutine* is not **NULL**, the *hEvent* parameter is ignored and can be used by the application to pass context information to the completion routine. A caller that passes a non-**NULL** *lpCompletionRoutine* and later calls
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) for the same overlapped I/O request may not set the *fWait* parameter for that invocation of
**WSAGetOverlappedResult** to **TRUE**. In this case, the usage of the *hEvent* parameter is undefined, and attempting to wait on the *hEvent* parameter would produce unpredictable results.

The prototype of the completion routine is as follows:

```cpp

void CALLBACK CompletionRoutine(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

This **CompletionRoutine** is a placeholder for an application-defined or library-defined function. The completion routine is invoked only if the thread is in an alertable state. To put a thread into an alertable state, use the [WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents), [WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex), or [WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex) function with the *fAlertable* or *bAlertable* parameter set to **TRUE**.

The *dwError* parameter of **CompletionRoutine** specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. The *cbTransferred* parameter specifies the number of bytes returned. Currently, no flag values are defined and *dwFlags* will be zero. The **CompletionRoutine** function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed.

### Compatibility

The IOCTL codes with T == 0 are a subset of the IOCTL codes used in Berkeley sockets. In particular, there is no command that is equivalent to **FIOASYNC**.

**Note** Some IOCTL codes require additional header files. For example, use of the **SIO_RCVALL** IOCTL requires the Mstcpip.h header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)