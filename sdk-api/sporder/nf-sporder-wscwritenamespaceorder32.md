# WSCWriteNameSpaceOrder32 function

## Description

The
**WSCWriteNameSpaceOrder32** function changes the order of available Windows Sockets (Winsock) 2 namespace providers in a 32-bit catalog. The order of the namespace providers determines the priority of the namespace when enumerated or queried for name resolution.

**Note** This call is a strictly 32-bit version of [WSCWriteNameSpaceOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwritenamespaceorder) for use on 64-bit platforms. It is provided to allow 64-bit processes to reorder the 32-bit namespace provider catalog.

## Parameters

### `lpProviderId` [in]

An array of **NSProviderId** elements as found in the [WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structure. The order of the **NSProviderId** elements is the new
priority ordering for the namespace providers.

### `dwNumberOfEntries` [in]

The number of elements in the **NSProviderId** array.

## Return value

The function returns **ERROR_SUCCESS** (zero) if the routine is successful. Otherwise, it returns a specific error code.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The **NSProviderId** array is not fully contained within process address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Input parameters were invalid, no action was taken. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the Winsock registry could not be opened, the user lacks the administrative privileges required to write to the Winsock registry, or another application is currently writing to the namespace provider catalog. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The function is called by another thread or process. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available to perform the operation. |
| **(other)** | The function may return any registry error code. |

## Remarks

Namespace providers are installed on 64-bit platforms in a 32-bit namespace provider catalog using the [WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32) function. The order in which namespace providers in a 32-bit catalog are initially installed governs the default order in which they are enumerated through
[WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32). More importantly, this order also governs the order in which namespace providers are considered when a client requests name resolution. On 64-bit platforms, the **WSCWriteNameSpaceOrder32** function is provided to allow 64-bit processes to change the order of namespace providers in the 32-bit namespace provider catalog. The order of namespace providers in the native catalog can be changed using the [WSCWriteNameSpaceOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwritenamespaceorder) function.

The current namespace provider catalog is stored in the registry under the following registry key: **HKEY_LOCAL_MACHINE**\**SYSTEM**\**Current Control Set**\**Services**\**Winsock2**\**Parameters**\**NameSpace_Catalog5**

A client request for name resolution uses the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina), [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta), and [WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend) routines. The **dwNameSpace** member of the [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure passed to **WSALookupServiceBegin** is set to the identifier of a single namespace (**NS_DNS**, for example) in which to constrain the search, or **NS_ALL** to include all namespaces. If multiple namespace providers support a specific namespace (for example, **NS_DNS**), then the results from all namespace providers that match the requested **dwNameSpace** are returned unless the **lpNSProviderId**
member is set to a specific namespace provider. The results from all namespace providers is returned if **NS_ALL** is specified for the **dwNameSpace** member. The order that the results are returned depends on the namespace provider order in the catalog.

The Windows SDK includes an application called SpOrder.exe that allows the catalog of installed namespace providers to be displayed. Winsock 2 includes the ws2_32.DLL on 64-bit platforms that exports the **WSCWriteNameSpaceOrder32** function for reordering namespace providers in the 32-bit namespace provider catalog. This interface can be imported by linking with WS2_32.lib. For computers running on Windows XP with Service Pack 2 (SP2) and Windows Server 2003 with Service Pack 1 (SP1) and later, the **netsh.exe winsock show catalog** command will display both the protocol and namespace providers installed. The native 64-bit catalog is displayed first followed by the 32-bit provider catalogs (denoted with a 32 after their name).

**WSCWriteNameSpaceOrder32** can only be called by a user logged on as a member of the Administrators group. If **WSCWriteNameSpaceOrder32** is called by a user that is not a member of the Administrators group, the function call will fail and **WSANO_RECOVERY** is returned in the lpErrno parameter.

For computers running on Windows Vista and Windows Vista, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista and Windows Vista lacks this setting in the manifest file used to build the executable file, a user logged on as a member of the Administrators group other than the Administrator must then be executing the application in an enhanced shell as the Administrator (**RunAs administrator**) for this function to succeed.

The following list describes scenarios in which the
**WSCWriteNameSpaceOrder32** function could fail:

* The *dwNumberOfEntries* parameter is not equal to the number of registered namespace providers.
* The **NSProviderId** array contains an invalid namespace provider identifier.
* The **NSProviderId** array does not contain all valid namespace provider identifiers exactly one time.
* The function is not able to access the registry for some reason (insufficient user permissions, for example).
* Another process, or thread, is currently calling the function.

## See also

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32)

[WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace)

[WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32)

[WSCWriteNameSpaceOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwritenamespaceorder)