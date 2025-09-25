# WSANAMESPACE_INFOA structure

## Description

The
**WSANAMESPACE_INFO** structure contains all registration information for a namespace provider.

## Members

### `NSProviderId`

Type: **GUID**

A unique GUID for this namespace provider.

### `dwNameSpace`

Type: **DWORD**

The namespace supported by this provider.

Possible values for the **dwNameSpace** member are listed in the *Winsock2.h* include file. Several namespace providers are included with Windows Vista and later. Other namespace providers can be installed, so the following possible values are only those commonly available. Many other values are possible.

| Value | Meaning |
| --- | --- |
| **NS_BTH** | The Bluetooth namespace. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_DNS** | The domain name system (DNS) namespace. |
| **NS_EMAIL** | The email namespace. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_NLA** | The network location awareness (NLA) namespace. <br><br>This namespace identifier is supported on Windows XP and later. |
| **NS_NTDS** | The Windows NT directory service (NTDS) namespace. |
| **NS_PNRPNAME** | The peer-to-peer name space for a specific peer name. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_PNRPCLOUD** | The peer-to-peer name space for a collection of peer names. <br><br>This namespace identifier is supported on Windows Vista and later. |

### `fActive`

Type: **BOOL**

If **TRUE**, indicates that this namespace provider is active. If **FALSE**, the namespace provider is inactive and is not accessible for queries, even if the query specifically references this namespace provider.

### `dwVersion`

Type: **DWORD**

The version number of the namespace provider.

### `lpszIdentifier`

Type: **LPTSTR**

A display string that identifies the namespace provider.

## Remarks

The **WSANAMESPACE_INFO** structure is used by the [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) and [WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32) functions to return information on available namespace providers. The **WSANAMESPACE_INFO** structure contains the provider-specific information on the namespace entry
passed to the [WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace) and [WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32) functions when the namespace provider was installed.

When UNICODE or _UNICODE is defined, **WSANAMESPACE_INFO** is defined to **WSANAMESPACE_INFOW**, the Unicode version of this data structure and the **lpszIdentifier** string member is defined to the **LPWSTR** data type.

When UNICODE or _UNICODE is not defined, **WSANAMESPACE_INFO** is defined to **WSANAMESPACE_INFOA**, the ANSI version of this data structure and the **lpszIdentifier** string member is defined to the **LPSTR** data type.

On Windows Vista and later, [WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw), an enhanced version of the **WSANAMESPACE_INFO** structure, is returned by calls to the [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions

> [!NOTE]
> The winsock2.h header defines WSANAMESPACE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw)

[WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace)

[WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32)