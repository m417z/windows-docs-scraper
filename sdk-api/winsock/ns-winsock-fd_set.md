## Description

The **fd_set** structure is used by various Windows Sockets functions and service providers, such as the
[select](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-select) function, to place sockets into a "set" for various purposes, such as testing a given socket for readability using the *readfds* parameter of the
**select** function.

## Members

### `fd_count`

The number of sockets in the set.

### `fd_array`

An array of sockets that are in the set. The variable **FD_SETSIZE** defaults to 64.

## Remarks

Be careful not to confuse the **FD_SET** typedef of the **fd_set** structure with the [FD_SET](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-fd_set) macro. That said, the **FD_SET** macro and the **fd_set** structure are related, and often used in conjunction.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaeventselect)

[select](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-select)