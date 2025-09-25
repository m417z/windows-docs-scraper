## Description

The **LPWSPCloseSocket** function closes a socket.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPCloseSocket** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK)** | Socket is marked as nonblocking and SO_LINGER is set to a nonzero time-out value. |

## Remarks

This function closes a socket. More precisely, it releases the socket descriptor *s*, so further references to *s* should fail with the error [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK). If this is the last reference to an underlying socket, the associated naming information and queued data are discarded. Any blocking or asynchronous calls pending on the socket (issued by any thread in this process) are canceled without posting any notification messages. Any pending overlapped operations issued by any thread in this process are also canceled. Whatever completion action was specified for these overlapped operations is performed (for example, event, completion routine, or completion port). In this case, the pending overlapped operations fail with the error status [WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsa_operation_aborted). FD_CLOSE will not be posted after **LPWSPCloseSocket** is called.

**LPWSPCloseSocket** behavior is summarized as follows:

- If SO_DONTLINGER is enabled (the default setting), **LPWSPCloseSocket** returns immediately and connection is gracefully closed in the background.
- If SO_LINGER is enabled with a zero time-out, **LPWSPCloseSocket** returns immediately and the connection is reset/terminated.

 or

- If SO_LINGER is enabled with a nonzero time-out with a blocking socket, **LPWSPCloseSocket** blocks until all data is sent or the time-out expires.
- If SO_LINGER is enabled with a nonzero time-out with a nonblocking socket, **LPWSPCloseSocket** returns immediately, thus indicating failure.

The semantics of **LPWSPCloseSocket** are affected by the socket options SO_LINGER and SO_DONTLINGER as follows.

| Option | Interval | Type of close | Wait for close? |
|----------------|-------------|---------------|-----------------|
| SO_DONTLINGER | Do not care | Graceful | No |
| SO_LINGER | Zero | Hard | No |
| SO_LINGER | Nonzero | Graceful | Yes |

If SO_LINGER is set (that is, the **l_onoff** member of the linger structure is nonzero) and the time-out interval, **l_linger**, is zero, **LPWSPCloseSocket** is not blocked even if queued data has not yet been sent or acknowledged. This is called a hard or abortive close, because the socket's virtual circuit is reset immediately, and any unsent data is lost. Any **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** call on the remote side of the circuit will fail with [WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET).

If SO_LINGER is set with a nonzero time-out interval on a blocking socket, the **LPWSPCloseSocket** call blocks on a blocking socket until the remaining data has been sent or until the time-out expires. This is called a graceful disconnect. If the time-out expires before all data has been sent, the service provider should terminate the connection before **LPWSPCloseSocket** returns.

Enabling SO_LINGER with a nonzero time-out interval on a nonblocking socket is not recommended. In this case, the call to **LPWSPCloseSocket** will fail with an error of [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK) if the close operation cannot be completed immediately. If **LPWSPCloseSocket** fails with WSAEWOULDBLOCK, the socket handle is still valid and a disconnect is not initiated.

The Winsock SPI client must call **LPWSPCloseSocket** again to close the socket, although **LPWSPCloseSocket** can continue to fail unless the Winsock SPI client does one of the following:

- Disables SO_DONTLINGER.
- Enables SO_LINGER with a zero time-out.
- Calls **[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)** to initiate closure.

If SO_DONTLINGER is set on a stream socket (that is, the **l_onoff** member of the linger structure is zero), the **LPWSPCloseSocket** call will return immediately and does not get WSAEWOULDBLOCK, whether the socket is blocking or nonblocking. However, any data queued for transmission will be sent if possible before the underlying socket is closed. This is called a graceful disconnect and is the default behavior.

Note that in this case the Winsock provider is allowed to retain any resources associated with the socket until such time as the graceful disconnect has completed or the provider terminates the connection due to an inability to complete the operation in a provider-determined amount of time. This can affect Winsock clients that expect to use all available sockets. This is the default behavior; SO_DONTLINGER is set by default.

## See also

[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)

[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)

[WSPSetSockOpt](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566318(v=vs.85))

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)