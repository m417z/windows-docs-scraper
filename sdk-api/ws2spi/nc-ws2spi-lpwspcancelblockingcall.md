## Description

The **LPWSPCancelBlockingCall** function cancels a blocking call that is currently in progress.

## Parameters

### `lpErrno` [out]

Pointer to the error code.

## Return value

The value returned by **LPWSPCancelBlockingCall** is zero if the operation was successfully canceled. Otherwise, the value SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Indicates there is no outstanding blocking call. |

## Remarks

This function cancels any outstanding blocking operation for this thread. It is typically used in two situations:

- A Windows Sockets SPI client is processing a message that has been received while a service provider is implementing pseudoblocking. In this case, [**WSAIsBlocking**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaisblocking) will be true.
- A blocking call is in progress and the Winsock service provider has called back to the Winsock SPI client's blocking hook function (through the callback function retrieved from [**WPUQueryBlockingCallback**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueryblockingcallback)), which in turn is invoking this function. Such a situation might arise, for instance, in implementing a **Cancel** option for an operation that requires an extended time to complete.

In each case, the original blocking call will terminate as soon as possible with the error [WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR). (In the first instance the termination will not take place until Windows message scheduling has caused control to revert back to the pseudo blocking routine in Winsock. In the second instance, the blocking call will be terminated as soon as the blocking hook function completes.)

In the case of a blocking [**LPWSPConnect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) operation, Winsock will terminate the blocking call as soon as possible, but it cannot be possible for the socket resources to be released until the connection has completed (and then been reset) or timed out. This is likely to be noticeable only if the Winsock SPI client immediately tries to open a new socket (if no sockets are available), or to connect to the same peer through a **LPWSPConnect** call.

Canceling a [**LPWSPAccept**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) or a [**LPWSPSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect) call does not adversely impact the sockets passed to these calls. Only the particular call fails; any operation that was legal before the cancel is legal after the cancel, and the state of the socket is not affected in any way.

Canceling any operation other than [**LPWSPAccept**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) and [**LPWSPSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect) can leave the socket in an indeterminate state. If a Winsock SPI client cancels a blocking operation on a socket, the only operation the Winsock SPI client will be able to perform on the socket is a call to [**LPWSPCloseSocket**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket), although other operations can work on some Winsock service providers. If a Winsock SPI client requires maximum portability, it must be careful not to depend on performing operations after a cancel operation. A Winsock SPI client can reset the connection by setting the time-out on SO_LINGER to zero and calling **LPWSPCloseSocket**.

If a cancel operation compromised the integrity of a SOCK_STREAM's data stream in any way, the Winsock provider will reset the connection and fail all future operations other than [**LPWSPCloseSocket**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) with [WSAECONNABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNABORTED).

It is acceptable for **LPWSPCancelBlockingCall** to return successfully if the blocking network operation completes prior to being canceled. In this case, the blocking operation will return successfully as if **LPWSPCancelBlockingCall** had never been called. The only way for the Winsock SPI client to confirm that an operation was actually canceled is to check for a return code of [WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR) from the blocking call.

## See also

[WPUQueryBlockingCallback](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueryblockingcallback)

[WSAIsBlocking](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaisblocking)

[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)

[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)

[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)