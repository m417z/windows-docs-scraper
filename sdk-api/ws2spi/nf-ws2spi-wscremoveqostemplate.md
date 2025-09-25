# WSCRemoveQOSTemplate function

## Description

[ This function is not supported in Windows Vista and subsequent versions of the operating system.]

The
**WSCRemoveQOSTemplate** function removes the specified QoS template from the system configuration database.

## Parameters

### `Guid` [in]

The globally unique identifier (GUID) for the quality of service (QoS) provider.

### `QosName` [in]

A pointer to a [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure that contains the QoS name of the template to remove.

## Return value

If
**WSCRemoveQOSTemplate** function succeeds, the return value is zero. Otherwise, it returns one of the following error codes.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. This error is returned if the if QoS provider specified in the *Guid* parameter is invalid or the QoS template name specified in the *QosName* parameter is invalid. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Memory cannot be allocated for buffers. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the provider is already installed, the user lacks the administrative privileges required to write to the Winsock registry, or a failure occurred when creating or installing a catalog entry. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## See also

[WSCInstallQOSTemplate](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallqostemplate)