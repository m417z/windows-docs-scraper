## Description

Sets the maximum size of a coalesced message set on a UDP socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a UDP socket.

### `MaxCoalescedMsgSize` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum coalesced message size to be set on the socket for UDP receive coalescing.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

UDP receive coalescing is supported through the [UDP_RECV_MAX_COALESCED_SIZE](https://learn.microsoft.com/windows/win32/winsock/ipproto-udp-socket-options) socket option. **WSASetUdpRecvMaxCoalescedSize** is a type-safe wrapper for setting this socket option, and we recommend it over [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt).

## See also