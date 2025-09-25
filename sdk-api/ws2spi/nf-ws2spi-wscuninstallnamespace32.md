# WSCUnInstallNameSpace32 function

## Description

The **WSCUnInstallNameSpace32** function uninstalls a specific 32-bit namespace provider.

**Note** This call is a strictly 32-bit version of [WSCUnInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscuninstallnamespace) for use on 64-bit platforms. It is provided to allow 64-bit processes to access the 32-bit catalogs.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the name-space provider to be uninstalled.

## Return value

If no error occurs,
**WSCUnInstallNameSpace32** returns **NO_ERROR** (zero). Otherwise, it returns **SOCKET_ERROR** if the function fails, and you must retrieve the appropriate error code using the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter points to memory that is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified namespace–provider identifier is invalid. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

**WSCUnInstallNameSpace32** is a strictly 32-bit version of [WSCUnInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscuninstallnamespace). On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

The namespace configuration functions do not affect applications that are already running. Newly installed name-space providers will not be visible to applications nor will the changes in a name-space provider's activation state. Applications launched after the call to
**WSCUnInstallNameSpace32** will recognize the changes.

On success, **WSCUnInstallNameSpace32** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCUnInstallNameSpace32** function can only be called by a user logged on as a member of the Administrators group. If **WSCUnInstallNameSpace32** is called by a user that is not a member of the Administrators group, the function call will fail and **WSANO_RECOVERY** is returned in the *lpErrno* parameter.

For computers running on Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

The caller of this function must remove any additional files or service provider–specific configuration information that is required to completely uninstall the service provider.

## See also

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSCDeinstallProvider32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider32)

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)

[WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32)

[WSCUnInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscuninstallnamespace)