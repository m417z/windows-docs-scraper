# WSCDeinstallProvider function

## Description

The
**WSCDeinstallProvider** function removes the specified transport provider from the system configuration database.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider. This value is stored within each
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If no error occurs,
**WSCDeinstallProvider** returns zero. Otherwise, it returns **SOCKET_ERROR**, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter does not specify a valid provider. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpErrno* parameter is not in a valid part of the user address space. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the user lacks the administrative privileges required to write to the Windows Sockets registry, or a failure occurred when opening a catalog entry. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

The
**WSCDeinstallProvider** function removes the common Windows Sockets 2 configuration information for the specified provider. After this routine completes successfully, the configuration information stored in the registry will be changed. However, any Ws2_32.dll instances currently in memory will not be able to recognize this change.

On success, **WSCDeinstallProvider** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCDeinstallProvider** function can only be called by a user logged on as a member of the Administrators group. If **WSCDeinstallProvider** is called by a user that is not a member of the Administrators group, the function call will fail and **WSANO_RECOVERY** is returned in the *lpErrno* parameter.

For computers running Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

The caller of this function must remove any additional files or service provider–specific configuration information that is needed to completely uninstall the service provider.

## See also

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider)