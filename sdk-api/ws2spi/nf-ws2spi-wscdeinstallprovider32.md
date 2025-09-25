# WSCDeinstallProvider32 function

## Description

The **WSCDeinstallProvider32** function removes the specified 32-bit transport provider from the system configuration database.

**Note** This call enables a 64-bit process to manipulate the 32-bit Winsock catalog because [WSCDeinstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider), on 64-bit computers, only manipulates the native 64-bit Windows Sockets catalog.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider. This value is stored within each
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If no error occurs,
**WSCDeinstallProvider32** returns zero. Otherwise, it returns **SOCKET_ERROR**, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter does not specify a valid provider. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpErrno* parameter is not in a valid part of the user address space. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the user lacks the administrative privileges required to write to the Windows Sockets registry, or a failure occurred when opening a catalog entry. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

**WSCDeinstallProvider32** is a strictly 32-bit version of [WSCDeinstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider). On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

The
**WSCDeinstallProvider32** function removes the common Windows Sockets 2 configuration information for the specified 32-bit provider. After this routine completes successfully, the configuration information stored in the registry will be changed. However, any Ws2_32.dll instances currently in memory will not be able to recognize this change.

On success, **WSCDeinstallProvider32** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCDeinstallProvider32** function can only be called by a user logged on as a member of the Administrators group. If **WSCDeinstallProvider32** is called by a user that is not a member of the Administrators group, the function call will fail and **WSANO_RECOVERY** is returned in the *lpErrno* parameter.

For computers running Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

The caller of this function must remove any additional files or service provider–specific configuration information that is needed to completely uninstall the service provider.

## See also

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSCDeinstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider)

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)

[WSCInstallProvider64_32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider64_32)