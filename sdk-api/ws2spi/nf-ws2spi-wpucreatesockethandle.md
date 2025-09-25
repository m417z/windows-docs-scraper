# WPUCreateSocketHandle function

## Description

The
**WPUCreateSocketHandle** function creates a new socket handle.

## Parameters

### `dwCatalogEntryId` [in]

Descriptor identifying the calling service provider.

### `dwContext` [in]

Context value to associate with the new socket handle.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUCreateSocketHandle** returns the new socket handle. Otherwise, it returns INVALID_SOCKET, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There are not enough buffers available to create the new socket handle. |

## Remarks

The
**WPUCreateSocketHandle** function creates a new socket handle for the specified provider. The handles created by
**WPUCreateSocketHandle** are indistinguishable from true file system handles. This is significant in two respects. First, the Windows Socket 2 architecture takes care of redirecting the file system functions [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) to this service provider's
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) and
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) functions, respectively. Second, in operating systems that support completion ports, the Windows Sockets 2 architecture supports associating a completion port with the socket handle and using it to report overlapped I/O completion.

**Note** The mechanism for redirecting [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) necessarily involves a user-to-kernel transition to get to the redirector, followed by a kernel-to-user transition to get to
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) or
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend). On return, these transitions are retraced in reverse. This can be a significant performance penalty. Any service provider that uses
**WPUCreateSocketHandle** to create its socket handles should not set XP1_IFS_HANDLES in its
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. Clients should take the absence of XP1_IFS_HANDLES as guidance to avoid the use of **ReadFile** and **WriteFile**.

**Note** There is no exceptional performance penalty for using the completion port mechanism with socket handles created with
**WPUCreateSocketHandle**. A service provider should use
[WPUCompleteOverlappedRequest](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucompleteoverlappedrequest) to announce completion of overlapped I/O operations that may involve a completion port. Clients may freely use operating system functions to create, associate, and use a completion port for completion notification (for example, [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport), [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus), see the relevant operating system documentation for details). Note that completion ports are not integrated with the other asynchronous notification mechanisms offered by Windows Sockets 2. That is, a client can do a multiple-wait that includes multiple events and completion callbacks, but there is no predefined way for the multiple-wait to include completion ports.

**Layered Service Provider Considerations**

This procedure is of particular interest to Layered Service Providers. A layered service provider may use this procedure, instead of
[WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle) to create the socket handles it exposes to its client. The advantage of using this procedure is that all I/O requests involving the socket can be guaranteed to go through this service provider. This is true even if the client assumes that the sockets are file system handles and calls the file system functions [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) (although it would pay a performance penalty for this assumption).

The guarantee that all I/O goes through this layer is a requirement for layers that need to process the I/O stream either before or after the actual I/O operation. Creating socket handles using
**WPUCreateSocketHandle** and specifying an appropriate service provider interface procedure dispatch table at the time of
[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) ensures that the layer has the chance to get involved in starting each I/O operation. When the client requests overlapped I/O operations, this service provider layer will usually have to arrange to get into the path of I/O completion notification as well.

To see why this is true, consider what happens if the client associates a completion port with the socket handle for the purpose of overlapped I/O completion notification. The port is associated with the socket handle exposed by this layer, not the next layer's socket handle. There is no way for this layer to determine if a completion port has been associated or what the port is. When this layer calls the next layer's I/O operation, it uses the next layer's socket handle. The next layer's socket handle will not have the same completion port association. The client's expected completion-port notification will not happen without some extra help.

The usual way a layered service provider takes care of this is to substitute a different overlapped I/O structure and different overlapped I/O parameters when invoking an I/O operation in the next layer. The substitute overlapped I/O structure references the client's stored overlapped structure and parameters. The invocation of the next layer sets up a callback notification. When the callback notification occurs, this layer performs any post-processing desired, retrieves the overlapped I/O information it stored on behalf of the client, discards the substitute structures, and forwards an appropriate completion notification to the client.

## See also

[WPUCloseSocketHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosesockethandle)

[WPUCompleteOverlappedRequest](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucompleteoverlappedrequest)

[WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle)

[WPUQuerySocketHandleContext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuquerysockethandlecontext)

[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)

[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)