# WPUQuerySocketHandleContext function

## Description

The
**WPUQuerySocketHandleContext** function queries the context value associated with the specified socket handle.

## Parameters

### `s` [in]

Description that identifies the socket whose context is to be queried.

### `lpContext` [out]

Pointer that will receive the context value.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUQuerySocketHandleContext** returns zero and stores the current context value in *lpContext*. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket created by [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle). |

## Remarks

The
**WPUQuerySocketHandleContext** function queries the current context value associated with the specified socket handle. Service providers typically use this function to retrieve a pointer to provider-specific data associated with the socket. For example, a service provider can use the socket context to store a pointer to a structure containing the socket's state, local and remote transport addresses, and event objects for signaling network events.

Only non-IFS providers use this function, because IFS providers are not able to supply a context value.

## See also

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)