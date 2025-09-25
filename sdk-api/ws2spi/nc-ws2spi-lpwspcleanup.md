## Description

The **LPWSPCleanup** function terminates use of the Windows Sockets service provider.

## Parameters

### `lpErrno` [out]

Pointer to the error code.

## Return value

The return value is zero if the operation has been successfully initiated. Otherwise, the value SOCKET_ERROR is returned, and a specific error number is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSANOTINITIALISED)** | A successful [**WSPStartup**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Provider identifier given to the name-space provider is not managed by the name-space provider. |

## Remarks

The Windows Sockets 2 SPI client is required to perform a successful [**WSPStartup**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) call before it can use Winsock service providers. When it has completed the use of Winsock service providers, the SPI client will call **LPWSPCleanup** to deregister itself from a Winsock service provider and allow the service provider to free any resources allocated on behalf of the Windows Sockets 2 client. It is permissible for SPI clients to make more than one **WSPStartup** call. For each **WSPStartup** call, a corresponding **LPWSPCleanup** call will also be issued. Only the final **LPWSPCleanup** for the service provider does the actual cleanup; the preceding calls simply decrement an internal reference count in the Winsock service provider.

When the internal reference count reaches zero and actual cleanup operations commence, any pending blocking or asynchronous calls issued by any thread in this process are canceled without posting any notification messages or signaling any event objects. Any pending overlapped send and receive operations ([**LPWSPSend**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend), [**LPWSPSendTo**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto), [**LPWSPRecv**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv), [**LPWSPRecvFrom**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom) with an overlapped socket) issued by any thread in this process are also canceled without setting the event object or invoking the completion routine, if specified. In this case, the pending overlapped operations fail with the error status WSA_OPERATION_ABORTED. Any sockets open when **LPWSPCleanup** is called are reset and automatically deallocated as if [**LPWSPCloseSocket**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) was called; sockets that have been closed with **LPWSPCloseSocket** but still have pending data to be sent are not affected, but the pending data is still sent.

This function should not return until the service provider DLL is prepared to be unloaded from memory. In particular, any data remaining to be transmitted must either already have been sent or be queued for transmission by portions of the transport stack that will not be unloaded from memory along with the service provider's DLL.

A Winsock service provider must be prepared to deal with a process that terminates without invoking **LPWSPCleanup** (for example, as a result of an error). A Winsock service provider must ensure that **LPWSPCleanup** leaves things in a state in which the Ws2_32.dll can immediately invoke [**WSPStartup**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) to reestablish Winsock usage.

## See also

[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)

[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)