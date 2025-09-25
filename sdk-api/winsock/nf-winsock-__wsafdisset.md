## Description

The **__WSAFDIsSet** function returns a value indicating whether a socket is included in a set of socket descriptors.

## Parameters

### `unnamedParam1`

A file descriptor identifying a socket.

### `unnamedParam2`

A pointer to an [fd_set](https://learn.microsoft.com/windows/win32/api/winsock/ns-winsock-fd_set) structure containing the set of socket descriptors.

## Return value

A non-zero value if the socket specified in *unnamedParam1* is a member of the set specified in *unnamedParam2*; otherwise, 0.

## Remarks

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

The **FD_ISSET** macro expands to a call of function **__WSAFDIsSet**.

## See also

* [WSAAsyncSelect](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsaasyncselect)
* [WSAEventSelect](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaeventselect)
* [fd_set](https://learn.microsoft.com/windows/win32/api/winsock/ns-winsock-fd_set)
* [select](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-select)