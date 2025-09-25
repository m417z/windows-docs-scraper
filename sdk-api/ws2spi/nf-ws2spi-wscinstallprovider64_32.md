# WSCInstallProvider64_32 function

## Description

[**WSCInstallProvider64_32** is no longer available for use as of Windows Vista. Instead, use [WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider) or [WSCInstallProviderAndChains](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains).]

The **WSCInstallProvider64_32** function installs the specified transport service provider into the 32-bit and 64-bit system configuration databases on a 64-bit computer.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider.

### `lpszProviderDllPath` [in]

A pointer to a Unicode string that contains the load path to the provider 64-bit DLL. This string observes the usual rules for path resolution and can contain embedded environment strings (such as %SystemRoot%). Such environment strings are expanded when the Ws2_32.dll must subsequently load the provider DLL on behalf of an application. After any embedded environment strings are expanded, the Ws2_32.dll passes the resulting string to the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function which loads the provider into memory. For more information, see **LoadLibrary**.

### `lpProtocolInfoList` [in]

A pointer to an array of
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structures. Each structure defines a protocol, address family, and socket type supported by the provider.

### `dwNumberOfEntries` [in]

The number of entries in the *lpProtocolInfoList* array.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If **WSCInstallProvider64_32** succeeds, it returns zero. Otherwise, it returns **SOCKET_ERROR**, and a specific error code is returned in the *lpErrno* parameter.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Memory could not be allocated for buffers. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the provider is already installed, the user lacks the administrative privileges required to write to the Winsock registry, or a failure occurred when creating or installing a catalog entry. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

**WSCInstallProvider64_32** is a basic version of the [WSCInstallProviderAndChains64_32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains64_32) function that only installs a single transport service provider. **WSCInstallProvider64_32** can be used to install a base protocol, a layered protocol, or a protocol chain. If a layered service provider is being installed, then **WSCInstallProviderAndChains64_32** should be used because this function allows a layered protocol and one or more protocol chains to be installed with a single function call. To accomplish the same work using **WSCInstallProvider64_32** would require multiple function calls to install each service provider component.

Windows Sockets (Winsock) 2 accommodates the notion of a layered protocol. A layered protocol is one that implements only higher level communications functions while relying on an underlying transport stack for the actual exchange of data with a remote endpoint. An example of a layered protocol would be a security layer that adds a protocol to the connection establishment process to perform authentication and to establish a mutually agreed upon encryption scheme. Such a security protocol would generally require the services of an underlying reliable transport protocol such as TCP or SPX. The term base protocol refers to a protocol such as TCP or SPX which is fully capable of performing data communications with a remote endpoint. The term layered protocol is used to describe a protocol that cannot stand alone. A protocol chain would then be defined as one or more layered protocols strung together and anchored by a base protocol.
A base protocol has the **ChainLen** member of the [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure set to **BASE_PROTOCOL** which is defined to be 1. A layered protocol has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to **LAYERED_PROTOCOL** which is defined to be zero. A protocol chain has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to greater than 1.

**WSCInstallProvider64_32** is the 64-bit version of [WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider) that installs the provider into both the 32-bit and 64-bit catalogs on 64-bit platforms. That is, on 64-bit platforms, two Winsock catalogs are maintained, and both 32-bit and 64-bit processes are able to load the transport provider installed with this function. On 64-bit platforms, **WSCInstallProvider** installs only to the 64-bit Winsock catalog.

On a 64-bit computer, all calls not specifically designed for 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use **WSCInstallProvider64_32** to operate on both the 32-bit catalog as well as the 64-bit catalog, preserving compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

This routine creates the necessary common Winsock 2 configuration information for the specified provider. It is applicable to base protocols, layered protocols, and protocol chains.

The *lpProtocolInfoList* parameter contains a list of protocol entries to install. Callers of **WSCInstallProvider64_32** are responsible for setting up the proper protocol entries. The *lpProtocolInfoList* parameter must not be **NULL**.

After this routine completes successfully, the protocol information provided in *lpProtocolInfoList* will be returned by [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa), [WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols), or [WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32). Be aware that in Windows, only instances of the Ws2_32.dll created by calling [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) after a successful completion of this function will include the new entries in
**WSAEnumProtocols**, **WSCEnumProtocols**, and **WSCEnumProtocols32**.

**Note** The [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function does not enumerate a layered protocol entry while [WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols) and [WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32) do.

On success, **WSCInstallProvider64_32** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCInstallProvider64_32** function can only be called by a user logged on as a member of the Administrators group. If **WSCInstallProvider64_32** is called by a user that is not a member of the Administrators group, the function call will fail and [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned in the *lpErrno* parameter.
For computers running Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (**RunAs administrator**) for this function to succeed.

Any file installation or service provider-specific configuration must be performed by the calling application.

If the [WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider) or [WSCInstallProviderAndChains](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains) function is used, the function must be called once to install the provider in the 32-bit catalog and once to install the provider in the 64-bit catalog on a 64-bit platform.

## See also

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[Transport Configuration and Installation](https://learn.microsoft.com/windows/desktop/WinSock/transport-configuration-and-installation-2)

[Transport Service Providers](https://learn.microsoft.com/windows/desktop/WinSock/transport-service-providers-2)

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSCDeinstallProvider32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscdeinstallprovider32)

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)

[WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider)

[WSCInstallProviderAndChains](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains)

[WSCInstallProviderAndChains64_32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallproviderandchains64_32)