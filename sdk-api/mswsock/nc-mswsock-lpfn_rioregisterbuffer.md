## Description

The **RIORegisterBuffer** function registers a [**RIO\_BUFFERID**](https://learn.microsoft.com/windows/win32/winsock/rio-bufferid), a registered buffer descriptor, with a specified buffer for use with the Winsock registered I/O extensions.

## Parameters

### `DataBuffer`

A pointer to the beginning of the memory buffer to register.

### `DataLength`

The length, in bytes, in the buffer to register.

## Return value

If no error occurs, the **RIORegisterBuffer** function returns a registered buffer descriptor. Otherwise, a value of **RIO\_INVALID\_BUFFERID** is returned, and a specific error code can be retrieved by calling the [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaefault)**

| The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if an invalid buffer pointer is passed in *DataBuffer* parameter.<br> |
|

**[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeinval)**

| An invalid parameter was passed to the function. <br> This error is returned if the *DataLength* parameter is zero.<br> |

## Remarks

The **RIORegisterBuffer** function creates a registered buffer identifier for a specified buffer. When a buffer is registered, the virtual memory pages containing the buffer will be locked into physical memory.

If several small, non-contiguous buffers are registered, the physical memory footprint for the buffers may effectively be as large as an entire memory page per registration. In these cases it may be beneficial to allocate multiple request buffers together.

There is also a small amount of overhead in physical memory used for the buffer registration itself. So if there are many allocations aggregated into single larger allocation, the physical memory footprint may be reduced further by aggregating the buffer registrations as well. In this case the application may need to take extra care to ensure that the buffers are eventually deregistered, but not while any send or receive requests are outstanding.

A portion of a registered buffer is passed to the [**RIOSend**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend), [**RIOSendEx**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosendex), [**RIOReceive**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive), and [**RIOReceiveEx**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex) functions in the *pData* parameter for sending or receiving data.

When the buffer identifier is no longer needed, call the [**RIODeregisterBuffer**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioderegisterbuffer) function to deregister the buffer identifier.

> [!Note]
> The function pointer to the **RIORegisterBuffer** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_MULTIPLE\_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the [**RIO\_EXTENSION\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/api/mswsock/ns-mswsock-rio_extension_function_table) structure that contains pointers to the Winsock registered I/O extension functions. The **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** IOCTL is defined in the *Ws2def.h* header file. The **WSAID\_MULTIPLE\_RIO** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also