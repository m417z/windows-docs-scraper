## Description

The **RIOResizeRequestQueue** function resizes a request queue to be either larger or smaller for use with the Winsock registered I/O extensions.

## Parameters

### `RQ`

A descriptor that identifies an existing registered I/O socket descriptor (request queue) to resize.

### `MaxOutstandingReceive`

The maximum number of outstanding sends allowed on the socket. This value can be larger or smaller than the original number.

This parameter is usually a small number for most applications.

### `MaxOutstandingSend`

The maximum number of outstanding receives allowed on the socket. This value can be larger or smaller than the original number.

## Return value

If no error occurs, the **RIOResizeRequestQueue** function returns **TRUE**. Otherwise, a value of **FALSE** is returned, and a specific error code can be retrieved by calling the [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeinval)** | An invalid parameter was passed to the function. This error is returned if the *RQ* parameter is not valid (RIO\_INVALID\_RQ, for example). This error is also returned if both the *MaxOutstandingReceive* and *MaxOutstandingSend* parameters are zero. <br> |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaenobufs)** | Sufficient memory could not be allocated. This error is returned if memory could not be allocated for the resized request queue.<br> |
| **[WSAETOOMANYREFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaetoomanyrefs)** | There are too many operations that still reference the request queue. Resizing of this request queue to be smaller is not possible at this time.<br> |

## Remarks

The **RIOResizeRequestQueue** function resizes a request queue to be either larger or smaller. If the request queue already contains entries, those entries will be copied over to the new request queue.

A request queue has a required minimum size that is dependent on the current number of entries (number of sends and receives on the request queue). If an application calls the **RIOResizeRequestQueue** function and tries to set the queue too small for the number of existing entries, the call will fail and the queue will not be resized.

> [!Note]
> The function pointer to the **RIOResizeRequestQueue** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_MULTIPLE\_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the [**RIO\_EXTENSION\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/api/mswsock/ns-mswsock-rio_extension_function_table) structure that contains pointers to the Winsock registered I/O extension functions. The **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** IOCTL is defined in the *Ws2def.h* header file. The **WSAID\_MULTIPLE\_RIO** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## Thread Safety

If multiple threads attempt to access the same [**RIO\_RQ**](https://learn.microsoft.com/windows/win32/winsock/riorqueue) using the [**RIODequeueCompletion**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion) or **RIOResizeRequestQueue** function, access must be coordinated by a critical section, slim reader writer lock , or similar mutual exclusion mechanism. If the completion queues are not shared, mutual exclusion is not required.

## See also