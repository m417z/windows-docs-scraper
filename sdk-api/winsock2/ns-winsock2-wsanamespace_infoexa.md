# WSANAMESPACE_INFOEXA structure

## Description

The
**WSANAMESPACE_INFOEX** structure contains all registration information for a namespace provider.

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

### `ProviderSpecific`

Type: **BLOB**

A provider-specific data blob associated with namespace entry.

## Remarks

The **WSANAMESPACE_INFOEX** structure is an enhanced version of the [WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structure that is used by the [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and the [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions to return information on available namespace providers. The **WSANAMESPACE_INFOEX** structure contains the provider-specific data blob associated with the namespace entry
passed in the *lpProviderInfo* parameter to the [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) and [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) functions.

 Currently, the only namespace included with Windows that uses information in the **ProviderSpecific** member of the **WSANAMESPACE_INFOEX** structure are namespace providers for the NS_EMAIL namespace. The format of the **ProviderSpecific** member for an NS_EMAIL namespace provider is a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

When UNICODE or _UNICODE is defined, **WSANAMESPACE_INFOEX** is defined to **WSANAMESPACE_INFOEXW**, the Unicode version of this structure and the **lpszIdentifier** string member is defined to the **LPWSTR** data type.

When UNICODE or _UNICODE is not defined, **WSANAMESPACE_INFOEX** is defined to **WSANAMESPACE_INFOEXA**, the ANSI version of this structure and the **lpszIdentifier** string member is defined to the **LPSTR** data type.

The [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) function is a Unicode only function and returns **WSANAMESPACE_INFOEXW** structures.

> [!NOTE]
> The winsock2.h header defines WSANAMESPACE_INFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)