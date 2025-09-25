## Description

The **RIOCloseCompletionQueue** function closes an existing completion queue used for I/O completion notification by send and receive requests with the Winsock registered I/O extensions.

## Parameters

### `CQ`

A descriptor identifying an existing completion queue.

## Remarks

The **RIOCloseCompletionQueue** function closes an existing completion queue used for I/O completion. The [**RIO\_CQ**](https://learn.microsoft.com/windows/win32/winsock/riocqueue) passed in the *CQ* parameter is locked for writing by the kernel. The completion queue is marked as invalid, so that new completions cannot be added. Any new completions to be added are silently dropped. The application is expected to tracking any pending send or receive operations.

If an invalid completion queue is passed in the *CQ* parameter (**RIO\_INVALID\_CQ**, for example), this is ignored by the **RIOCloseCompletionQueue** function.

> [!Note]
> The function pointer to the **RIOCloseCompletionQueue** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_MULTIPLE\_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the [**RIO\_EXTENSION\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/api/mswsock/ns-mswsock-rio_extension_function_table) structure that contains pointers to the Winsock registered I/O extension functions. The **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** IOCTL is defined in the *Ws2def.h* header file. The **WSAID\_MULTIPLE\_RIO** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also