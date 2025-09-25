## Description

Sets the segmentation message size on a UDP socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a UDP socket.

### `MsgSize` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The message size to be set on the socket for UDP segmentation.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

UDP send segmentation is supported through the [UDP_SEND_MSG_SIZE](https://learn.microsoft.com/windows/win32/winsock/ipproto-udp-socket-options) socket option. **WSASetUdpSendMessageSize** is a type-safe wrapper for setting this socket option, and we recommend it over [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt).

## See also