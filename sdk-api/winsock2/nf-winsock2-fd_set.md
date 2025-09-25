## Description

The **FD_SET** macro adds a file descriptor to an [fd_set](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-fd_set). If the file descriptor already exist within the set, a duplicate will not be added.

## Parameters

### `fd`

A descriptor identifying a socket which will be added to the set.

### `set`

A pointer to a **fd_set**.

## Parameters

## Remarks

Be careful not to confuse the **FD_SET** macro with the typedef of the [fd_set](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-fd_set) structure that's also named **FD_SET**. That said, the **FD_SET** macro and the **fd_set** structure are related, and often used in conjunction.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaeventselect)

[select](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-select)