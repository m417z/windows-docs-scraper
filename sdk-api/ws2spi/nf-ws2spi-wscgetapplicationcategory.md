# WSCGetApplicationCategory function

## Description

**Note** Layered Service Providers are deprecated. Starting with Windows 8 and Windows Server 2012, use [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page).

The
**WSCGetApplicationCategory** function retrieves the layered service provider (LSP) categories associated with an application.

## Parameters

### `Path` [in]

A pointer to a Unicode string that contains the load path to the executable image for the application. This string observes the usual rules for path resolution and can contain embedded environment strings (such as *%SystemRoot%*).

### `PathLength` [in]

The length, in characters, of the *Path* parameter. This length does not include the terminating **NULL**.

### `Extra` [in]

A pointer to a Unicode string which represents the command line arguments used when starting the application specified in the *Path* parameter. The *Extra* parameter is used to distinguish between multiple, distinct instances of an application when launched with a consistent command line. This is to support different application categorizations for different instances of Svchost.exe or Rundll32.exe. If only the *Path* parameter is required and no command line arguments are needed to further distinguish between instances of an application, then the *Extra* parameter should be set to **NULL**.

### `ExtraLength` [in]

The length, in characters, of the *Extra* parameter. This length does not include the terminating **NULL**.

### `pPermittedLspCategories` [out]

A pointer to a DWORD value of permitted LSP categories which are permitted for all instances of this application. The application is identified by the combination of the values of the *Path* and *Extra* parameters.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If no error occurs, **WSCGetApplicationCategory** returns **ERROR_SUCCESS** (zero). Otherwise, it returns **SOCKET_ERROR**, and a specific error code is returned in the *lpErrno* parameter.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service could not be found based on the *Path* and *Extra* parameters. <br><br>The error can also be returned if the application you are querying does not exist in the registry. In this case, the error indicates that the application is not currently categorized. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the user lacks the administrative privileges required to access the Winsock registry, or a failure occurred when opening a Winsock catalog entry or an application ID entry. |

## Remarks

**WSCGetApplicationCategory** is used to retrieve the LSP category flags associated with an application instance. Applications can determine which LSP behaviors are acceptable within the application's context. Therefore, by specifying permitted LSP categories, an application can permit only those layered service providers which implement acceptable behaviors to be loaded.

The *Extra* parameter is required when the command line is used to distinguish between different instances of an application or service hosted within the same executable. Each instance can have different application categorization needs. Svchost.exe and Rundll32.exe are two examples where the command line is required to differentiate between different process instances. For SvcHost.exe, the **-k \<svcinstance>** switch defines the process instance.

For services, using the Service Name is not sufficient, since the Winsock Catalog is global to a given process, and a process may host several services.

Window sockets determine an application's identity and retrieves the permitted LSP categories during the first call to [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup). This will be the set of permitted LSP categories for the duration of the application instance. Subsequent changes to the permitted LSP categories for a given application identity will not be picked up until the next instance of the application. The permitted LSP categories are not mutable during the lifetime of the application instance.

Winsock 2 accommodates layered protocols. A layered protocol is one that implements only higher level communications functions, while relying on an underlying transport stack for the actual exchange of data with a remote endpoint. An example of a layered protocol or layered service provider would be a security layer that adds protocol to the connection establishment process in order to perform authentication and to establish a mutually agreed upon encryption scheme. Such a security protocol would generally require the services of an underlying reliable transport protocol such as TCP or SPX. The term base protocol refers to a protocol such as TCP or SPX which is capable of performing data communications with a remote endpoint. The term layered protocol is used to describe a protocol that cannot stand alone.

During LSP initialization, the LSP must provide pointers to a number of Winsock SPI functions. These functions will be called during normal processing by the layer directly above the LSP (either another LSP or Ws2_32.DLL).

An LSP that implements an installable file system (IFS) can selectively choose to provide pointers to functions which are implemented by itself, or pass back the pointers provided by the layer directly below the LSP. Non-IFS LSPs, because they provide their own handles, must implement all of the Winsock SPI functions. This is because each SPI will require the LSP to map all of the socket handles it created to the socket handle of the lower provider (either another LSP or the base protocol).

However, all LSPs perform their specific work by doing extra processing on only a subset of the Winsock SPI functions.

It is possible to define LSP categories based upon the subset of SPI functions an LSP implements and the nature of the extra processing performed for each of those functions.

By classifying LSPs, as well as classifying applications which use Winsock sockets, it becomes possible to selectively determine if an LSP should be involved in a given process at runtime.

On Windows Vista and later, an LSP can be classified based on how it interacts with Windows Sockets calls and data. An LSP category is an identifiable group of behaviors on a subset of Winsock SPI functions. For example, an HTTP content filter would be categorized as a data inspector (the LSP_INSPECTOR category). The LSP_INSPECTOR category will inspect (but not alter) parameters to data transfer SPI functions. An application can query for the category of an LSP and choose to not load the LSP based on the LSP category and the application's set of permitted LSP categories.

The following table lists categories that an LSP can be classified into.

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

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSCGetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo)

[WSCGetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderinfo32)

[WSCSetApplicationCategory](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetapplicationcategory)

[WSCSetProviderInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo)

[WSCSetProviderInfo32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscsetproviderinfo32)