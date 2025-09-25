# NAPI_DOMAIN_DESCRIPTION_BLOB structure

## Description

The
**NAPI_DOMAIN_DESCRIPTION_BLOB** structure describes a domain handled by a namespace provider for the NS_EMAIL namespace.

## Members

### `AuthLevel`

The authority level of the namespace provider for this domain. This member can be one of the values from the [NAPI_PROVIDER_LEVEL](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_level) enumeration type defined in the *Nsemail.h* header file.

### `cchDomainName`

The length, in Unicode characters, of the Unicode string that contains the domain name represented by the **OffsetThisDomainName** member. The **NULL** terminator is not counted when calculating the length.

### `OffsetNextDomainDescription`

The offset, in bytes, to the next **NAPI_DOMAIN_DESCRIPTION_BLOB** structure in the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

### `OffsetThisDomainName`

The offset, in bytes, to a Unicode string that contains a domain name handled by this namespace provider for the NS_EMAIL namespace. The domain name must be at least **cchDomainName** Unicode characters in length. **NULL**-termination of the Unicode string that contains the domain name is recommended, but not required. This offset must be aligned on a minimum of a two-byte boundary.

## Remarks

This structure is supported on Windows Vista and later.

The
**NAPI_DOMAIN_DESCRIPTION_BLOB** structure describes a domain handled by a namespace provider for the NS_EMAIL namespace. A typical domain name represented by the **OffsetThisDomainName** member in this structure might be msn.com or yahoo.com.

Each namespace provider registered in the NS_EMAIL namespace can support multiple domains. The list of supported domains is specified in the provider registration blob as a list of **NAPI_DOMAIN_DESCRIPTION_BLOB** structures. Each supported domain specification contains a [NAPI_PROVIDER_LEVEL](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_level) value in the **AuthLevel** member of the **NAPI_DOMAIN_DESCRIPTION_BLOB** that describes the type of support provided by the provider for that domain.

The **NAPI_DOMAIN_DESCRIPTION_BLOB** structure is a member of the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure used to describe and register a NS_EMAIL namespace provider. There may be multiple **NAPI_DOMAIN_DESCRIPTION_BLOB** structures in the **NAPI_PROVIDER_INSTALLATION_BLOB** structure for an NS_EMAIL namespace provider.

The [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) and [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) functions are used to install a namespace provider for the NS_EMAIL namespace using a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

The [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions are used to enumerate all namespace providers (including NS_EMAIL namespace providers) and to retrieve the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure for a provider if the provider registered a blob upon installation.

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[NAPI_PROVIDER_LEVEL](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_level)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)