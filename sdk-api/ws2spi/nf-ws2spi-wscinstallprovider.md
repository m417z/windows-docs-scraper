# WSCInstallProvider function

## Description

**Note** Layered Service Providers are deprecated. Starting with Windows 8 and Windows Server 2012, use [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page).

The
**WSCInstallProvider** function installs the specified transport provider into the system configuration database.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider.

### `lpszProviderDllPath` [in]

A pointer to a Unicode string that contains the load path to the provider DLL. This string observes the usual rules for path resolution and can contain embedded environment strings (such as *%SystemRoot%*). Such environment strings are expanded when the Ws2_32.dll must subsequently load the provider DLL on behalf of an application. After any embedded environment strings are expanded, the Ws2_32.dll passes the resulting string to the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function which loads the provider into memory. For more information, see **LoadLibrary**.

### `lpProtocolInfoList` [in]

A pointer to an array of
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structures. Each structure defines a protocol, address family, and socket type supported by the provider.

### `dwNumberOfEntries` [in]

The number of entries in the *lpProtocolInfoList* array.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If **WSCInstallProvider** succeeds, it returns zero. Otherwise, it returns **SOCKET_ERROR**, and a specific error code is returned in the *lpErrno* parameter.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Memory cannot be allocated for buffers. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the provider is already installed, the user lacks the administrative privileges required to write to the Winsock registry, or a failure occurred when creating or installing a catalog entry. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

**WSCInstallProvider** is used to install a single transport service provider. This routine creates the necessary common Windows Sockets 2 configuration information for the specified provider. It is applicable to base protocols, layered protocols, and protocol chains. If a layered service provider is being installed, then [WSCInstallProviderAndChains](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains) should be used. **WSCInstallProviderAndChains** can install a layered protocol and one or more protocol chains with a single function call. To accomplish the same work using **WSCInstallProvider** would require multiple function calls.

Winsock 2 accommodates layered protocols. A layered protocol is one that implements only higher level communications functions while relying on an underlying transport stack for the actual exchange of data with a remote endpoint. An example of a layered protocol would be a security layer that adds a protocol to the connection establishment process in order to perform authentication and to establish a mutually agreed upon encryption scheme. Such a security protocol would generally require the services of an underlying reliable transport protocol such as TCP or SPX. The term base protocol refers to a protocol such as TCP or SPX which is capable of performing data communications with a remote endpoint. The term layered protocol is used to describe a protocol that cannot stand alone. A protocol chain would then be defined as one or more layered protocols strung together and anchored by a base protocol.
A base protocol has the **ChainLen** member of the [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure set to **BASE_PROTOCOL** which is defined to be 1. A layered protocol has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to **LAYERED_PROTOCOL** which is defined to be zero. A protocol chain has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to greater than 1.

The *lpProtocolInfoList* parameter contains a list of protocol entries to install. Callers of **WSCInstallProvider** are responsible for setting up the proper protocol entries. The *lpProtocolInfoList* parameter must not be **NULL**.

Upon successful completion of this call, any subsequent calls to [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) or [WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols) will return the newly-created protocol entries. Be aware that in Windows environments, only instances of Ws_32.dll created by calling [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) after the successful completion of **WSCInstallProvider** will include the new entries when **WSAEnumProtocols** and **WSCEnumProtocols** returns.

**Note** The [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function does not enumerate a layered protocol entry while [WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols) does.

On success, **WSCInstallProvider** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCInstallProvider** function can only be called by a user logged on as a member of the Administrators group. If **WSCInstallProvider** is called by a user that is not a member of the Administrators group, the function call will fail and [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned in the *lpErrno* parameter.
For computers running Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (**RunAs administrator**) for this function to succeed.

Any file installation or service provider-specific configuration must be performed by the caller.

## See also

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSCDeinstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider)

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)