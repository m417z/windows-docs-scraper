# GetAcceptExSockaddrs function

## Description

The
**GetAcceptExSockaddrs** function parses the data obtained from a call to the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function and passes the local and remote addresses to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `lpOutputBuffer` [in]

A pointer to a buffer that receives the first block of data sent on a connection resulting from an
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) call. Must be the same *lpOutputBuffer* parameter that was passed to the
**AcceptEx** function.

### `dwReceiveDataLength` [in]

The number of bytes in the buffer used for receiving the first data. This value must be equal to the *dwReceiveDataLength* parameter that was passed to the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function.

### `dwLocalAddressLength` [in]

The number of bytes reserved for the local address information. This value must be equal to the *dwLocalAddressLength* parameter that was passed to the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function.

### `dwRemoteAddressLength` [in]

The number of bytes reserved for the remote address information. This value must be equal to the *dwRemoteAddressLength* parameter that was passed to the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function.

### `LocalSockaddr` [out]

A pointer to the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that receives the local address of the connection (the same information that would be returned by the
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function). This parameter must be specified.

### `LocalSockaddrLength` [out]

The size, in bytes, of the local address. This parameter must be specified.

### `RemoteSockaddr` [out]

A pointer to the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that receives the remote address of the connection (the same information that would be returned by the
[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername) function). This parameter must be specified.

### `RemoteSockaddrLength` [out]

The size, in bytes, of the local address. This parameter must be specified.

## Remarks

The
**GetAcceptExSockaddrs** function is used exclusively with the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function to parse the first data that the socket receives into local and remote addresses. The
**AcceptEx** function returns local and remote address information in an internal format. Application developers need to use the **GetAcceptExSockaddrs** function if there is a need for the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structures containing the local or remote addresses.

**Note** The function pointer for the
**GetAcceptExSockaddrs** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_GETACCEPTEXSOCKADDRS**, a globally unique identifier (GUID) whose value identifies the **GetAcceptExSockaddrs** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **GetAcceptExSockaddrs** function. The **WSAID_GETACCEPTEXSOCKADDRS** GUID is defined in the *Mswsock.h* header file.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)