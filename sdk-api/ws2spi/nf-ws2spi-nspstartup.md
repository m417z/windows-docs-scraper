# NSPStartup function

## Description

The
**NSPStartup** function retrieves the dynamic information about a provider, such as the list of the DLL entry points.

This function is called by the client upon initialization.
The **NSPStartup** and
[NSPCleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspcleanup) functions must be called as pairs. All NSP functions must be called from within an **NSPStartup**/**NSPCleanup** pair. It is not required that WSC functions be called from within a **NSPStartup**/**NSPCleanup** pair.

## Parameters

### `lpProviderId` [in]

The desired provider from which to return the entry points.

### `lpnspRoutines` [out]

A pointer to an [NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine) structure that points to provider entry points if the function call is successful.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the function fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Value | Description |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSAEINVALIDPROCTABLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The procedure call table is invalid. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSASYSNOTREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The [NSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-nspstartup) function cannot operate at this time because the underlying system it uses to provide network services is currently unavailable. |

## Remarks

For more information, see the [NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine) structure.

## See also

[NSPCleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspcleanup)

[NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)