# NAPI_PROVIDER_INSTALLATION_BLOB structure

## Description

The
**NAPI_PROVIDER_INSTALLATION_BLOB** structure contains the information required to install a namespace provider for the NS_EMAIL namespace.

## Members

### `dwVersion`

Type: **DWORD**

The version number of the NS_EMAIL namespace provider. This member is specific to the namespace provider.

### `dwProviderType`

Type: **DWORD**

The type of namespace provider for the NS_EMAIL namespace. This member can be one of the values from the [NAPI_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_type) enumeration type defined in the *Nsemail.h* header file.

### `fSupportsWildCard`

Type: **DWORD**

A Boolean value that indicates if this NS_EMAIL namespace provider supports wildcard names. If this member is nonzero, then an NS_EMAIL provider claims to be potentially able to resolve or register any name that does not belong to any domains the provider is specifically registered for as primary or secondary. If this member is nonzero, then the NS_EMAIL provider may be called to resolve or register any address, if no primary or secondary provider for the domain is available.

There may be multiple providers that claim to be able to resolve any address (the **fSupportsWildCard** set to nonzero). If there are namespace providers with this value that also registered as a wildcard provider, the providers are called in the order that they appear in the Winsock namespace catalog.

### `cDomains`

Type: **DWORD**

The number of [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) structures the starting at the **OffsetFirstDomain** member used to describe domains that are supported by this NS_EMAIL namespace provider.

### `OffsetFirstDomain`

Type: **DWORD**

The offset, in bytes, to the first of multiple [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) structures used to describe domains that are supported by this NS_EMAIL namespace provider. This offset must be aligned on a minimum of a four-byte boundary.

## Remarks

This structure is supported on Windows Vista and later.

The
**NAPI_PROVIDER_INSTALLATION_BLOB** structure contains the information required to install a namespace provider for the NS_EMAIL namespace. There may be multiple namespace providers for the NS_EMAIL namespace install on a local system.

Each namespace provider registered in the NS_EMAIL namespace can support multiple domains. As a result, there may be multiple [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) structures in the **NAPI_PROVIDER_INSTALLATION_BLOB** structure for an NS_EMAIL namespace provider. The list of supported domains is specified in the provider registration blob as a list of **NAPI_DOMAIN_DESCRIPTION_BLOB** structures. Each supported domain specification contains a [NAPI_PROVIDER_LEVEL](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_level) value in the **AuthLevel** member of the **NAPI_DOMAIN_DESCRIPTION_BLOB** that describes the level of authority provided by the provider for that domain.

Namespace providers are called in the following order to resolve or register an address in a domain. If a namespace provider registered as the primary provider for the domain, then this primary provider is called first. There are two cases depending on whether authoritative results are requested in the namespace query. The default for a query is to request authoritative results.

 When authoritative results are requested in the query, then namespace providers are called as follows. If the primary provider is unavailable or is unable to resolve or register the address, then the first secondary provider in the Winsock catalog is called. If the secondary provider is unavailable or is unable to resolve or register the address, then the next secondary provider in the Winsock catalog is called. If all of the secondary providers are unavailable or are unable to resolve or register the address, then the first wildcard provider in the Winsock catalog is called. If the first wildcard provider is unavailable or is unable to resolve or register the address, then the next wildcard provider in the Winsock catalog is called.

 When non-authoritative results are requested in the query, then namespace providers are called as follows. The primary provider, all secondary providers, and all wildcard providers are called and results from all of the queries are returned. The primary provider is called first. Secondary providers are called next, based on the order in the Winsock catalog. Wildcard providers are called next, based on the order in the Winsock catalog. The results that are returned are based on the order of the queries.

The [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) and [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) functions are used to install a namespace provider for the NS_EMAIL namespace using a **NAPI_PROVIDER_INSTALLATION_BLOB** structure.

The [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions are used to enumerate all namespace providers (including NS_EMAIL namespace providers) and to retrieve the **NAPI_PROVIDER_INSTALLATION_BLOB** structure for a provider if the provider registered a blob upon installation.

## See also

[NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob)

[NAPI_PROVIDER_LEVEL](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_level)

[NAPI_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_type)

[WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)