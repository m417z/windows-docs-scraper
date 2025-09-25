# WSANSPIoctl function

## Description

The Windows Sockets
**WSANSPIoctl** function enables developers to make I/O control calls to a registered namespace.

## Parameters

### `hLookup` [in]

The lookup handle returned from a previous call to the
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function.

### `dwControlCode` [in]

The control code of the operation to perform.

The values that may be used for the *dwControlCode* parameter are determined by the namespace provider.

The following value is supported by several Microsoft namespace providers including the Network Location Awareness (NS_NLA) namespace provider. This IOCTL is defined in the Winsock2.h header file.

| Value | Meaning |
| --- | --- |
| **SIO_NSP_NOTIFY_CHANGE** | This operation checks if the results returned with previous calls using the *hLookup* parameter are still valid. These previous calls include the initial call to the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function to retrieve the *hLookup* parameter. These previous calls may also include calls to the [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) function using the *hLookup* parameter. |

### `lpvInBuffer` [in]

A pointer to the input buffer.

### `cbInBuffer` [in, out]

The size, in bytes, of the input buffer.

### `lpvOutBuffer` [out]

A pointer to the output buffer.

### `cbOutBuffer` [in]

The size, in bytes, of the output buffer.

### `lpcbBytesReturned` [out]

A pointer to the number of bytes returned.

### `lpCompletion` [in]

A pointer to a [WSACOMPLETION](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsacompletion) structure, used for asynchronous processing. Set *lpCompletion* to **NULL** to force blocking (synchronous) execution.

## Return value

Success returns NO_ERROR. Failure returns SOCKET_ERROR, and a specific error code can be retrieved by calling the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function. The following table describes the error codes.

| Error code | Description |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hLookup* parameter was not a valid query handle returned by [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina). |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpvInBuffer*, *cbInBuffer*, *lpvOutBuffer*, *cbOutBuffer*, or *lpCompletion* argument is not totally contained in a valid part of the user address space. Alternatively, the *cbInBuffer* or *cbOutBuffer* argument is too small, and the argument is modified to reflect the required allocation size. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A supplied parameter is not acceptable, or the operation inappropriately returns results from multiple namespaces when it does not make sense for the specified operation. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. This error can also be returned if the specified *dwControlCode* is an unrecognized command. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not using overlapped I/O (asynchronous processing), yet the *lpCompletion* parameter is non-**NULL**.<br><br>This error is used as a special notification for the SIO_NSP_NOTIFY_CHANGE IOCTL when the *lpCompletion* parameter is **NULL** (a poll) to indicate that a query set remains valid. |

## Remarks

The
**WSANSPIoctl** function is used to set or retrieve operating parameters associated with a query handle to a namespace provider. The *hLookup* parameter is a handle to the namespace provider query previously returned by
the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function (not a socket handle).

Any IOCTL sent to a namespace provider may block indefinitely, depending upon the implementation of the namespace. If an application cannot tolerate blocking in a
**WSANSPIoctl** function call, overlapped I/O should be used and the *lpCompletion* parameter should point to a [WSACOMPLETION](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsacompletion) structure. To make a
**WSANSPIoctl** function call nonblocking and return immediately, set the **Type** member of the **WSACOMPLETION** structure to **NSP_NOTIFY_IMMEDIATELY**.

 If *lpCompletion* is **NULL**, the
**WSANSPIoctl** function executes as a blocking call. The namespace provider should return immediately and should not block. But each namespace is responsible for enforcing this behavior.

The following IOCTL code is supported by several Microsoft name space provider:

**SIO_NSP_NOTIFY_CHANGE**

This operation checks if the results returned with previous calls using the *hLookup* parameter are still valid. These previous calls include the initial call to the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function to retrieve the *hLookup* parameter. These previous calls may also include calls to the [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) function using the *hLookup* parameter.

The Microsoft namespace providers that support this IOCTL include the following

* NS_NLA - The Network Location Awareness (NLA) namespace provider.
* NS_PNRPNAME - The Peer Name Resolution Protocol (PNRP) namespace provider.
* NS_PNRPCLOUD - The Peer Name Resolution Protocol (PNRP) cloud namespace provider.

Other non-Microsoft namespace providers may be installed that also support this IOCTL.

When the *lpCompletion* parameter is **NULL**, this IOCTL implements a special behavior. If the *lpCompletion* parameter is **NULL** for this IOCTL, this operation is a poll and returns immediately. If the query set remains valid,
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned as notification that the query set remains valid. If the query set has changed and is invalid, **NO_ERROR** is returned indicating success in polling for invalidation of the query set.

If the *lpCompletion* parameter is not **NULL** and points to an [WSACOMPLETION](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsacompletion) structure, then the **WSANSPIoctl** function returns [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) if the overlapped operation was successfully initiated and completion will be indicated at a later time. The method specified in the **WSACOMPLETION** structure is used to notify the application if the query set is still valid.

Not all name resolution protocols are able to support this feature, and therefore, this function call may fail with
[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). A query containing data from multiple providers cannot call this IOCTL, and will return
[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The *lpvInBuffer*, *cbInBuffer*, *lpvOutBuffer*, and *cbOutBuffer* parameters are currently ignored by Microsoft namespace providers.

For single-threaded applications, a typical method to use the **WSANSPIoctl** function is as follows. Call the **WSANSPIoctl** function with the *dwControlCode* parameter set to **SIO_NSP_NOTIFY_CHANGE** with no completion routine (the *lpCompletion* parameter set to **NULL**) after every [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) function call to make sure the query data is still valid. If the data becomes invalid, call the [WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend) function to close the query handle. Call the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function to retrieve a new query handle and begin the query again.

For multi-threaded applications, a typical method to use the **WSANSPIoctl** function is as follows. Call the **WSANSPIoctl** function with the *dwControlCode* parameter set to **SIO_NSP_NOTIFY_CHANGE** with a completion routine after the initial call to the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function. The application would use the mechanism for notification specified in the completion routine to be notified when data is no longer valid. One common mechanism is to use an event specified in the completion routine. If the data becomes invalid, call the [WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend) function to close the query handle. Call the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) and the **WSANSPIoctl** functions to retrieve a new query handle and begin the query again.

Some protocols may simply cache the information locally and invalidate it after some time, in which case notification may be issued to indicate the local cache has been invalidated.

For name resolution protocols where changes are infrequent, it is possible for a namespace provider to indicate a global change event that may not be applicable to the query on which change notification was requested and issued.

Immediate poll operations are usually much less expensive since they do not require a notification object. In most cases, this is implemented as a simple Boolean variable check. Asynchronous notification, however, may necessitate the creation of dedicated worker threads and/or inter-process communication channels, depending on the implementation of the namespace provider service, and will incur processing overhead related to the notification object involved with signaling the change event.

To cancel an asynchronous notification request, end the original query with a
[WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend) function call on the affected query handle. Canceling the asynchronous notification for LUP_NOTIFY_HWND will not post any message, however, an overlapped operation will be completed and notification will be delivered with the error
[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[WSACOMPLETION](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsacompletion)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina)

[WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend)

[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)