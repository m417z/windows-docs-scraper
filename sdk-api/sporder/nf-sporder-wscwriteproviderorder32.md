# WSCWriteProviderOrder32 function

## Description

The
**WSCWriteProviderOrder32** function is used to reorder the available 32-bit transport providers. The order of the protocols determines the priority of a protocol when being enumerated or selected for use.

**Note** This call is a strictly 32-bit version of [WSCWriteProviderOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwriteproviderorder) for use on 64-bit platforms. It is provided to allow 64-bit processes to modify the 32-bit catalogs.

## Parameters

### `lpwdCatalogEntryId` [in]

A pointer to an array of **CatalogEntryId** elements found in the
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. The order of the **CatalogEntryId** elements is the new priority ordering for the protocols.

### `dwNumberOfEntries` [in]

The number of elements in the *lpwdCatalogEntryId* array.

## Return value

The function returns **ERROR_SUCCESS** (zero) if the routine is successful. Otherwise, it returns a specific error code.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid, no action was taken. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the user lacks the administrative privileges required to write to the Winsock registry, or a failure occurred when opening or writing a catalog entry. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |
| **(other)** | The routine may return any registry error code. |

## Remarks

The **WSCWriteProviderOrder32** function is a strictly 32-bit version of the [WSCWriteProviderOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwriteproviderorder) function. On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

The order in which transport service providers are initially installed governs the order in which they are enumerated through
[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32) at the service provider interface, or through
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) at the application interface. More importantly, this order also governs the order in which protocols and service providers are considered when a client requests creation of a socket based on its address family, type, and protocol identifier.

Windows Sockets 2 includes an application called Sporder.exe that allows the catalog of installed protocols to be reordered interactively after protocols have already been installed. Windows Sockets 2 also includes an auxiliary DLL, *Sporder.dll* that exports this procedural interface for reordering protocols. This interface can be imported by linking with *Sporder.lib*.

The following are scenarios in which the
**WSCWriteProviderOrder32** function could fail:

* The *dwNumberOfEntries* parameter is not equal to the number of registered service providers.
* The *lpwdCatalogEntryId* contains an invalid catalog identifier.
* The *lpwdCatalogEntryId* does not contain all valid catalog identifiers exactly one time.
* The routine is not able to access the registry for some reason (for example, inadequate user permissions).
* Another process (or thread) is currently calling the function.

On success, **WSCWriteProviderOrder32** will attempt to alert all interested applications that have registered for notification of the change by calling [WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange).

The **WSCWriteProviderOrder32** function can only be called by a user logged on as a member of the Administrators group. If **WSCWriteProviderOrder32** is called by a user that is not a member of the Administrators group, the function call will fail and
[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned.
For computers running on Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (**RunAs administrator**) for this function to succeed.

## See also

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSAProviderConfigChange](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaproviderconfigchange)

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)