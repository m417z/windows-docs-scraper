# WSAOVERLAPPED structure

## Description

The
**WSAOVERLAPPED** structure provides a communication medium between the initiation of an overlapped I/O operation and its subsequent completion. The
**WSAOVERLAPPED** structure is compatible with the Windows
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

## Members

### `Internal`

Type: **ULONG_PTR**

Reserved for internal use. The Internal member is used internally by the entity that implements overlapped I/O. For service providers that create sockets as installable file system (IFS) handles, this parameter is used by the underlying operating system. Other service providers (non-IFS providers) are free to use this parameter as necessary.

### `InternalHigh`

Type: **ULONG_PTR**

Reserved. Used internally by the entity that implements overlapped I/O. For service providers that create sockets as IFS handles, this parameter is used by the underlying operating system. NonIFS providers are free to use this parameter as necessary.

### `Offset`

Type: **DWORD**

Reserved for use by service providers.

### `OffsetHigh`

Type: **DWORD**

Reserved for use by service providers.

### `hEvent`

Type: **HANDLE**

If an overlapped I/O operation is issued without an I/O completion routine (the operation's *lpCompletionRoutine* parameter is set to null), then this parameter should either contain a valid handle to a WSAEVENT object or be null. If the *lpCompletionRoutine* parameter of the call is non-null then applications are free to use this parameter as necessary.

#### - Pointer

Type: **PVOID**

Reserved for use by service providers.

## See also

[WSACleanup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacleanup)

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)