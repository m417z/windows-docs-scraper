# NAPI_PROVIDER_LEVEL enumeration

## Description

The **NAPI_PROVIDER_LEVEL** enumeration specifies the provider authority level of a NS_EMAIL namespace provider for a given domain.

## Constants

### `ProviderLevel_None:0`

The namespace provider does not support the current domain. This value can be used to temporarily turn off the support for a domain without removing it from the list of supported domains.

If **ProviderLevel_None** is set in the **AuthLevel** member of the [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) for a given domain when the provider is installed and registered, the namespace provider will not be called to resolve or register an address in that domain unless the provider registered as a wildcard provider.

There may be multiple NS_EMAIL namespace providers for a domain with a value of **ProviderLevel_None**. If there are namespace providers with this value that also registered as a wildcard provider, the providers are called in the order that they appear in the Winsock catalog.

### `ProviderLevel_Secondary`

The namespace provider is a secondary provider for a domain in the NS_EMAIL namespace. A namespace provider can be a secondary provider in the target domain if the provider can resolve and register NS_EMAIL names for this domain and give the same answer that a primary provider would provide. If **ProviderLevel_Secondary** is set in **AuthLevel** member of the [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) for a given domain when the provider is installed and registered, this provider is called when a primary provider for the domain is not currently available or the primary provider could not resolve or register the address in that domain.

There may be multiple secondary NS_EMAIL namespace providers for a domain with a value of **ProviderLevel_Secondary**. If there are multiple secondary namespace providers, the providers are called in the order that they appear in the Winsock catalog.

### `ProviderLevel_Primary`

The namespace provider is the primary provider for a domain in the NS_EMAIL namespace. A namespace provider can claim to be the primary provider for a domain if it owns all of the NS_EMAIL names for that domain and thus has access to the master data for all such names.

There should be only a single primary NS_EMAIL namespace provider for a domain registered on the local system.

**Note** There should never be two NS_EMAIL namespace providers that claim to be the primary provider for the same domain. If multiple providers try to register as the primary provider for the same domain, the first provider found in the Winsock namespace catalog for the domain as the primary provider will be called. All other provider claims to be the primary provider are ignored.

## Remarks

This enumeration is supported on Windows Vista and later.

The **NAPI_PROVIDER_LEVEL** enumeration is used by the [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) structure to specify the authority level of a NS_EMAIL namespace provider for a domain. Each namespace provider registered in the NS_EMAIL namespace can support multiple domains. The list of supported domains is specified in the provider registration blob as a list of **NAPI_DOMAIN_DESCRIPTION_BLOB** structures. Each supported domain specification contains a **NAPI_PROVIDER_LEVEL** value in the **AuthLevel** member of the **NAPI_DOMAIN_DESCRIPTION_BLOB** that describes the type of support provided by the provider for that domain.

In addition to the specified domain, a NS_EMAIL namespace provider can also register as a wildcard provider to try and support any domain, by specifying the **fSupportsWildCard** member as nonzero in the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) passed when the provider is installed.

Namespace providers are called in the following order to resolve or register an address in a domain. If a namespace provider registered as the primary provider for the domain, then this primary provider is called first. There are two cases depending on whether authoritative results are requested in the namespace query. The default for a query is to request authoritative results.

 When authoritative results are requested in the query, then namespace providers are called as follows. If the primary provider is unavailable or is unable to resolve or register the address, then the first secondary provider in the Winsock catalog is called. If the secondary provider is unavailable or is unable to resolve or register the address, then the next secondary provider in the Winsock catalog is called. If all of the secondary providers are unavailable or are unable to resolve or register the address, then the first wildcard provider in the Winsock catalog is called. If the first wildcard provider is unavailable or is unable to resolve or register the address, then the next wildcard provider in the Winsock catalog is called.

 When non-authoritative results are requested in the query, then namespace providers are called as follows. The primary provider, all secondary providers, and all wildcard providers are called and results from all of the queries are returned. The primary provider is called first. Secondary providers are called next, based on the order in the Winsock catalog. Wildcard providers are called next, based on the order in the Winsock catalog. The results that are returned are based on the order of the queries.

The [NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob) structure is used in the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure to describe a NS_EMAIL namespace provider.

The [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) and [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) functions are used to install a namespace provider for the NS_EMAIL namespace using a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

The [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions are used to enumerate namespace providers for the NS_EMAIL namespace and retrieve the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure for a provider.

## See also

[NAPI_DOMAIN_DESCRIPTION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_domain_description_blob)

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)