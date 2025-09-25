# WSAQUERYSET2A structure

## Description

The
**WSAQUERYSET2** structure provides relevant information about a given service, including service class ID, service name , applicable namespace identifier and protocol information, as well as a set of transport addresses at which the service listens.

## Members

### `dwSize`

Type: **DWORD**

The size, in bytes, of the **WSAQUERYSET2** structure. This member is used as a versioning mechanism since the size of the **WSAQUERYSET2** structure may change on later versions of Windows.

### `lpszServiceInstanceName`

Type: **LPTSTR**

A pointer to an optional **NULL**-terminated string that contains service name. The semantics for using wildcards within the string are not defined, but can be supported by certain namespace providers.

### `lpVersion`

Type: **LPWSAVERSION**

A pointer to an optional desired version number of the namespace provider. This member provides version comparison semantics (that is, the version requested must match exactly, or version must be not less than the value supplied).

### `lpszComment`

Type: **LPTSTR**

This member is ignored for queries.

### `dwNameSpace`

Type: **DWORD**

A namespace identifier that determines which namespace providers are queried. Passing a specific namespace identifier will result in only namespace providers that support the specified namespace being queried. Specifying **NS_ALL** will result in all installed and active namespace providers being queried.

Options for the **dwNameSpace** member are listed in the *Winsock2.h* include file. Several new namespace providers are included with Windows Vista and later. Other namespace providers can be installed, so the following possible values are only those commonly available. Many other values are possible.

| Value | Meaning |
| --- | --- |
| **NS_ALL** | All installed and active namespaces. |
| **NS_BTH** | The Bluetooth namespace. This namespace identifier is supported on Windows Vista and later. |
| **NS_DNS** | The domain name system (DNS) namespace. |
| **NS_EMAIL** | The email namespace. This namespace identifier is supported on Windows Vista and later. |
| **NS_NLA** | The network location awareness (NLA) namespace. This namespace identifier is supported on Windows XP and later. |
| **NS_PNRPNAME** | The peer-to-peer name space for a specific peer name. This namespace identifier is supported on Windows Vista and later. |
| **NS_PNRPCLOUD** | The peer-to-peer name space for a collection of peer names. This namespace identifier is supported on Windows Vista and later. |

### `lpNSProviderId`

Type: **LPGUID**

A pointer to an optional GUID of a specific namespace provider to query in the case where multiple namespace providers are registered under a single namespace such as **NS_DNS**. Passing the GUID for a specific namespace provider will result in only the specified namespace provider being queried. The [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) and [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) functions can be called to retrieve the GUID for a namespace provider.

### `lpszContext`

Type: **LPTSTR**

A pointer to an optional starting point of the query in a hierarchical namespace.

### `dwNumberOfProtocols`

Type: **DWORD**

The size, in bytes, of the protocol constraint array. This member can be zero.

### `lpafpProtocols`

Type: **LPAFPROTOCOLS**

A pointer to an optional array of
[AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols) structures. Only services that utilize these protocols will be returned.

### `lpszQueryString`

Type: **LPTSTR**

A pointer to an optional **NULL**-terminated query string. Some namespaces, such as Whois++, support enriched SQL-like queries that are contained in a simple text string. This parameter is used to specify that string.

### `dwNumberOfCsAddrs`

Type: **DWORD**

This member is ignored for queries.

### `lpcsaBuffer`

Type: **LPCSADDR_INFO**

This member is ignored for queries.

### `dwOutputFlags`

Type: **DWORD**

This member is ignored for queries.

### `lpBlob`

Type: **LPBLOB**

An optional pointer to data that is used to query or set provider-specific namespace information. The format of this information is specific to the namespace provider.

## Remarks

The
**WSAQUERYSET2** structure is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **WSAQUERYSET2** structure can only be used for operations on NS_EMAIL namespace providers.

> [!NOTE]
> The winsock2.h header defines WSAQUERYSET2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSASetService](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetservicea)