## Description

Retrieves the maximum size of a received, coalesced message for a UDP socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a UDP socket.

### `MaxCoalescedMsgSize` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a **DWORD**. On success, the function sets the DWORD to the maximum coalesced message size used on the socket for UDP receive coalescing.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

UDP receive coalescing is supported through the [UDP_RECV_MAX_COALESCED_SIZE](https://learn.microsoft.com/windows/win32/winsock/ipproto-udp-socket-options) socket option. **WSAGetUdpRecvMaxCoalescedSize** is a type-safe wrapper for getting this socket option, and we recommend it over [getsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-getsockopt).

## See also