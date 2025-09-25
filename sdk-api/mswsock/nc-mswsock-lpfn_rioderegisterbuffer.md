## Description

The **RIODeregisterBuffer** function deregisters a registered buffer used with the Winsock registered I/O extensions.

## Parameters

### `BufferId`

A descriptor identifying a registered buffer.

## Remarks

The **RIODeregisterBuffer** function deregisters a registered buffer. When a buffer is deregistered, the application is indicating that it is done with the buffer identifier passed in the *BufferId* parameter. Any subsequent calls to other functions that try to use this buffer identifier will fail.

If a buffer that is still in use is deregistered, the results are undefined. This is considered a serious error. In the [**RIORESULT**](https://learn.microsoft.com/windows/win32/api/mswsockdef/ns-mswsockdef-rioresult) structure returned by the [**RIODequeueCompletion**](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion) function, the status will be unchanged from the normal status. An application developer can detect this error condition using the Application Verifier tool.

If an invalid buffer identifier is passed in the *BufferId* parameter, this is ignored by the **RIODeregisterBuffer** function.

> [!Note]
> The function pointer to the **RIODeregisterBuffer** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_MULTIPLE\_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the [**RIO\_EXTENSION\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/api/mswsock/ns-mswsock-rio_extension_function_table) structure that contains pointers to the Winsock registered I/O extension functions. The **SIO\_GET\_MULTIPLE\_EXTENSION\_FUNCTION\_POINTER** IOCTL is defined in the *Ws2def.h* header file. The **WSAID\_MULTIPLE\_RIO** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also