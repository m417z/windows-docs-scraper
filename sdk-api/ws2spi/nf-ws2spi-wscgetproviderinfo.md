# WSCGetProviderInfo function

## Description

**Note** Layered Service Providers are deprecated. Starting with Windows 8 and Windows Server 2012, use [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page).

The
**WSCGetProviderInfo** function retrieves the data associated with an information class for a layered service provider (LSP).

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider.

### `InfoType` [in]

The information class that is requested for this LSP protocol entry.

### `Info` [out]

A pointer to a buffer to receive the information class data for the requested LSP protocol entry. If this parameter is **NULL**, then **WSCGetProviderInfo** returns failure and the size required for this buffer is returned in the *InfoSize* parameter.

### `InfoSize` [in, out]

The size, in bytes, of the buffer pointed to by the *Info*  parameter. If the Info parameter is **NULL**, then **WSCGetProviderInfo** returns failure and the *InfoSize* parameter will receive the size of the required buffer.

### `Flags` [in]

The flags used to modify the behavior of the **WSCGetProviderInfo** function call.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If no error occurs, **WSCGetProviderInfo** returns **ERROR_SUCCESS** (zero). Otherwise, it returns **SOCKET_ERROR**, and a specific error code is returned in the *lpErrno* parameter.

| Error code | Meaning |
| --- | --- |
| **ERROR_CALL_NOT_IMPLEMENTED** | The call is not implemented. This error is returned if **ProviderInfoAudit** is specified in the *InfoType* parameter. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. |
| **[WSAEINVALIDPROVIDER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The protocol entry could not be found for the specified *lpProviderId*. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the user lacks the administrative privileges required to access the Winsock registry, or a failure occurred when opening a Winsock catalog entry. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

**WSCGetProviderInfo** is used to retrieve information class data for a layered service provider. When the *InfoType* parameter is set to **ProviderInfoLspCategories**, on success **WSCGetProviderInfo** returns with the *Info* parameter set with appropriate LSP category flags implemented by the LSP.

Winsock 2 accommodates layered protocols. A layered protocol is one that implements only higher level communications functions, while relying on an underlying transport stack for the actual exchange of data with a remote endpoint. An example of a layered protocol or layered service provider would be a security layer that adds protocol to the connection establishment process in order to perform authentication and to establish a mutually agreed upon encryption scheme. Such a security protocol would generally require the services of an underlying reliable transport protocol such as TCP or SPX. The term base protocol refers to a protocol such as TCP or SPX which is capable of performing data communications with a remote endpoint. The term layered protocol is used to describe a protocol that cannot stand alone. A protocol chain would then be defined as one or more layered protocols strung together and anchored by a base protocol.
A base protocol has the **ChainLen** member of the [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure set to **BASE_PROTOCOL** which is defined to be 1. A layered protocol has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to **LAYERED_PROTOCOL** which is defined to be zero. A protocol chain has the **ChainLen** member of the **WSAPROTOCOL_INFO** structure set to greater than 1.

During LSP initialization, the LSP must provide pointers to a number of Winsock SPI functions. These functions will be called during normal processing by the layer directly above the LSP (either another LSP or Ws2_32.DLL).

An LSP that implements an installable file system (IFS) can selectively choose to provide pointers to functions which are implemented by itself, or pass back the pointers provided by the layer directly below the LSP. Non-IFS LSPs, because they provide their own handles, must implement all of the Winsock SPI functions. This is because each SPI will require the LSP to map all of the socket handles it created to the socket handle of the lower provider (either another LSP or the base protocol).

However, all LSPs perform their specific work by doing extra processing on only a subset of the Winsock SPI functions.

It is possible to define LSP categories based upon the subset of SPI functions an LSP implements and the nature of the extra processing performed for each of those functions.

By classifying LSPs, as well as classifying applications which use Winsock sockets, it becomes possible to selectively determine if an LSP should be involved in a given process at runtime.

On Windows Vista and later, an LSP can be classified based on how it interacts with Windows Sockets calls and data. An LSP category is an identifiable group of behaviors on a subset of Winsock SPI functions. For example, an HTTP content filter would be categorized as a data inspector (the LSP_INSPECTOR category). The LSP_INSPECTOR category will inspect (but not alter) parameters to data transfer SPI functions. An application can query for the category of an LSP and choose to not load the LSP based on the LSP category and the application's set of permitted LSP categories.

The following table lists categories into which an LSP can be classified.

| LSP Category | Description |
| --- | --- |
| **LSP_CRYPTO_COMPRESS** | The LSP is a cryptography or data compression provider. |
| **LSP_FIREWALL** | The LSP is a firewall provider. |
| **LSP_LOCAL_CACHE** | The LSP is a local cache provider. |
| **LSP_INBOUND_MODIFY** | The LSP modifies inbound data. |
| **LSP_INSPECTOR** | The LSP inspects or filters data. |
| **LSP_OUTBOUND_MODIFY** | The LSP modifies outbound data. |
| **LSP_PROXY** | The LSP acts as a proxy and redirects packets. |
| **LSP_REDIRECTOR** | The LSP is a network redirector. |
| **LSP_SYSTEM** | The LSP is acceptable for use in services and system processes. |

An LSP may belong to more than one category. For example, a firewall/security LSP could belong to both the inspector (**LSP_INSPECTOR**) and firewall (**LSP_FIREWALL**) categories.

If an LSP does not have a category set, it is considered to be in the All Other category. This LSP category will not be loaded in services or system processes (for example, lsass, winlogon, and many svchost processes).

## See also

[Categorizing Layered Service Providers and Applications](https://learn.microsoft.com/windows/desktop/WinSock/categorizing-layered-service-providers-and-applications)

[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSCGetApplicationCategory](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetapplicationcategory)

[WSCSetApplicationCategory](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetapplicationcategory)

[WSCSetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo)

[WSC_PROVIDER_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ne-ws2spi-wsc_provider_info_type)