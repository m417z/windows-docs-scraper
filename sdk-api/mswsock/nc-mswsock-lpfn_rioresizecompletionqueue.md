## Description

The **RIOResizeCompletionQueue** function resizes an I/O completion queue to be either larger or smaller for use with the Winsock registered I/O extensions.

## Parameters

### `CQ`

A descriptor that identifies an existing I/O completion queue to resize.

### `QueueSize`

## Return value

If no error occurs, the **RIOResizeCompletionQueue** function returns **TRUE**. Otherwise, a value of **FALSE** is returned, and a specific error code can be retrieved by calling the [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaefault)** | The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if the completion queue specified in the *CQ* parameter contains an invalid pointer.<br> |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeinval)** | An invalid parameter was passed to the function. This error is returned if the *CQ* parameter is not valid (RIO\_INVALID\_CQ, for example). This error is also returned if the size of the queue specified in the *QueueSize* parameter is greater than **RIO\_CQ\_MAX\_SIZE**.<br> |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaenobufs)** | Sufficient memory could not be allocated. This error is returned if memory could not be allocated for the queue specified in the *QueueSize* parameter.<br> |
| **[WSAETOOMANYREFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaetoomanyrefs)** | There are too many operations that still reference the I/O completion queue. Resizing of this I/O completion queue to be smaller is not possible at this time.<br> |

The **RIOResizeCompletionQueue** function resizes an I/O completion queue to be either larger or smaller. If the I/O completion queue already contains completions, those completions will be copied over to the new completion queue.

I/O completion queues have a required minimum size that is dependent on the number of request queues associated with the completion queue and the number of sends and receives on the request queues. If an application calls the **RIOResizeCompletionQueue** function and tries to set the queue too small for the number of existing completions in the I/O completion queue, the call will fail and the queue will not be resized.

> [!Note]
> The function pointer to the **RIOResizeCompletionQueue** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_MULTIPLE\_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the [**RIO\_EXTENSION\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/api/mswsock/ns-mswsock-rio_extension_function_table) structure that contains pointers to the Winsock registered I/O extension functions. The **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** IOCTL is defined in the *Ws2def.h* header file. The **WSAID\_MULTIPLE\_RIO** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## Thread Safety

If multiple threads attempt to access the same [**RIO\_CQ**](https://learn.microsoft.com/windows/win32/winsock/riocqueue) using the [**RIODequeueCompletion**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion) or **RIOResizeCompletionQueue** function, access must be coordinated by a critical section, slim reader writer lock , or similar mutual exclusion mechanism. If the completion queues are not shared, mutual exclusion is not required.

## Remarks

## See also