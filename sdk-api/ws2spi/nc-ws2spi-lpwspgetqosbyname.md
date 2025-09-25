## Description

The **WSPGetQOSByName** function initializes a **[QOS](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/qos/qos-structures)** structure based on a named template, or retrieves an enumeration of the available template names.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpQOSName` [in, out]

Specifies the QOS template name, or supplies a buffer to retrieve an enumeration of the available template names.

### `lpQOS` [out]

Pointer to the **[QOS](https://learn.microsoft.com/previous-versions/windows/desktop/qos/qos-structures)** structure to be filled.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *lpQOS* argument is not a valid part of the user address space, or the buffer length for *lpQOS* is too small. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | The specified QOS template name is invalid. |

## Remarks

Clients can use *WSPGetQOSByName* to initialize a **[QOS](https://learn.microsoft.com/previous-versions/windows/desktop/qos/qos-structures)** structure to a set of known values appropriate for a particular service class or media type. These values are stored in a template that is referenced by a well-known name. The client may retrieve these values by setting the **buf** member of the **WSABUF** indicated by *lpQOSName* to point to a Unicode string of nonzero length specifying a template name. In this case the usage of *lpQOSName* is IN only, and results are returned through *lpQOS*.

Alternatively, the client may use **LPWSPGetQOSByName** to retrieve an enumeration of available template names. The client may do this by setting the **buf** member of the **WSABUF** indicated by *lpQOSName* to a zero-length null-terminated Unicode string. In this case, the buffer indicated by **buf** is overwritten with a sequence of as many null-terminated Unicode template name strings as are available up to the number of bytes available in **buf** as indicated by the **len** member of the **WSABUF** indicated by *lpQOSName*. The list of names itself is terminated by a zero-length Unicode name string. When **LPWSPGetQOSByName** is used to retrieve template names, the *lpQOS* parameter is ignored.

## See also

**[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

**[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)**