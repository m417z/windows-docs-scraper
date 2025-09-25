## Description

The **WSPPROC_TABLE** structure contains a table of pointers to service provider functions.

## Members

```C++
} WSPPROC_TABLE, FAR * LPWSPPROC_TABLE;
```

### `lpWSPAccept`

A pointer to the **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)** function.

### `lpWSPAddressToString`

A pointer to the [**LPWSPAddressToString**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaddresstostring) function.

### `lpWSPAsyncSelect`

A pointer to the **[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)** function.

### `lpWSPBind`

A pointer to the **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)** function.

### `lpWSPCancelBlockingCall`

A pointer to the **[LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)** function.

### `lpWSPCleanup`

A pointer to the [**WSPCleanup**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcleanup) function.

### `lpWSPCloseSocket`

A pointer to the **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** function.

### `lpWSPConnect`

A pointer to the **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** function.

### `lpWSPDuplicateSocket`

A pointer to the [**WSPDuplicateSocket**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket) function.

### `lpWSPEnumNetworkEvents`

A pointer to the [**WSPEnumNetworkEvents**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspenumnetworkevents) function.

### `lpWSPEventSelect`

A pointer to the [**LPWSPEventSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspenumnetworkevents) function.

### `lpWSPGetOverlappedResult`

A pointer to the [**LPWSPGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) function.

### `lpWSPGetPeerName`

A pointer to the function.

### `lpWSPGetSockName`

A pointer to the [**WSPGetSockName**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname) function.

### `lpWSPGetSockOpt`

A pointer to the **[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)** function.

### `lpWSPGetQOSByName`

A pointer to the [**WSPGetQOSByName**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetqosbyname) function.

### `lpWSPIoctl`

A pointer to the **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)** function.

### `lpWSPJoinLeaf`

A pointer to the **[LPWSPJoinLeaf](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspjoinleaf)** function.

### `lpWSPListen`

A pointer to the **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)** function.

### `lpWSPRecv`

A pointer to the **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** function.

### `lpWSPRecvDisconnect`

A pointer to the [**WSPRecvDisconnect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvdisconnect) function.

### `lpWSPRecvFrom`

A pointer to the **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)** function.

### `lpWSPSelect`

A pointer to the [**LPWSPSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect) function.

### `lpWSPSend`

A pointer to the **[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)** function.

### `lpWSPSendDisconnect`

A pointer to the [**WSPSendDisconnect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsenddisconnect) function.

### `lpWSPSendTo`

A pointer to the **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** function.

### `lpWSPSetSockOpt`

A pointer to the **[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)** function.

### `lpWSPShutdown`

A pointer to the **[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)** function.

### `lpWSPSocket`

A pointer to the [LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket) function.

### `lpWSPStringToAddress`

A pointer to the [LPWSPStringToAddress](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspstringtoaddress) function.

## Remarks

The **WSPPROC_TABLE** structure contains a table of pointers to service provider functions that are returned by the [WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) function.

## See also

**[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**

**[LPWSPStringToAddress](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspstringtoaddress)**

**[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)**

**[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**

**[LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)**

**[LPWSPCleanup](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcleanup)**

**[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)**

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

**[LPWSPDuplicateSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket)**

**[LPWSPEnumNetworkEvents](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspenumnetworkevents)**

**[LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult)**

**[LPWSPGetQOSByName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetqosbyname)**

**[LPWSPGetSockName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname)**

**[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)**

**[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**

**[LPWSPJoinLeaf](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspjoinleaf)**

**[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)**

**[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**

**[LPWSPRecvDisconnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvdisconnect)**

**[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)**

**[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**

**[LPWSPSendDisconnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsenddisconnect)**

**[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)**

**[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)**

**[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)

[WSAStringToAddress](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsastringtoaddressa)**