# WPUModifyIFSHandle function

## Description

The
**WPUModifyIFSHandle** function receives a (possibly) modified IFS handle from Ws2_32.dll.

## Parameters

### `dwCatalogEntryId` [in]

Descriptor identifying the calling service provider.

### `ProposedHandle` [in]

IFS handle allocated by the provider.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUModifyIFSHandle** returns the modified socket handle. Otherwise, it returns INVALID_SOCKET, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The proposed handle is invalid. |

## Remarks

The
**WPUModifyIFSHandle** handle allows the WS2_32.dll to streamline its internal operations by returning a possibly modified version of the supplied IFS handle. The returned handle is guaranteed to be indistinguishable from the proposed handle as far as the operating system is concerned. IFS providers must call this function before returning any newly created socket descriptor to a service provider. The service provider will only use the modified handle for any subsequent socket operations. This routine is only used by IFS providers whose socket descriptors are real IFS handles.

**Layered Service Provider Considerations**

This procedure may also be used by a layered provider that is layered on top of a base IFS provider and wants to expose the base provider's socket handles as its own instead of creating them with a
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) call. A layered provider that wishes to "pass through" the IFS socket handles it receives from the next layer in the chain can call
**WPUModifyIFSHandle**, passing its own catalog entry ID as *dwCatalogEntryId*. This informs the Windows Sockets DLL that this layer, and not the next layer, should be the target for SPI calls involving that socket handle.

There are several limitations a layered provider should observe if it takes this approach.

- The provider should expose base provider entry points for
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) and
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) in the procedure dispatch table it returns at the time of
[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) to make sure the Windows Sockets SPI client's access to these functions is as efficient as possible.
- The provider cannot rely on its
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) and
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) functions being invoked for all I/O, particularly in the case of the I/O system functions [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile). These functions would bypass the layered provider and invoke the base IFS provider's implementation directly even if the layered provider puts its own entry points for these functions into the procedure dispatch table.
- The provider cannot rely on any ability to post-process overlapped I/O using
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend),
[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto),
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv),
[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom), or
[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl). Post-processing notification may happen through completion ports and bypass the layered provider entirely. A layered provider has no way to determine that a completion port was used or determine what port it is. The layered provider has no way to insert itself into the notification sequence.
- The provider should pass through all overlapped I/O requests directly to the base provider using the original overlapped parameters (for example, the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure and completion routine pointer). The provider should expose the base provider entry point for
[WSPGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult). Since some overlapped I/O requests can bypass the layered provider completely, the layered provider cannot reliably mark
**WSAOVERLAPPED** structures to determine which ones it can report results for, and which ones would have to be passed through to the underlying provider's
**WSPGetOverlappedResult**. This effectively means that
[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) has to be a pass-through operation to the underlying provider.

## See also

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSPGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult)

[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)

[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)

[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)