# NAPI_PROVIDER_TYPE enumeration

## Description

The **NAPI_PROVIDER_TYPE** enumeration specifies the type of hosting expected for a namespace provider.

## Constants

### `ProviderType_Application:1`

The namespace provider is expected to be hosted by an application. There may be multiple namespace providers of type **ProviderType_Application** running at the same time on a local system.

There may also be multiple instances of the same namespace provider running at the same time on a local system as long as the following conditions are met. Only one instance of the same namespace provider application can be running in a single user session at the same time on the local system. The Windows Sockets infrastructure will select the particular target instance of a namespace provider based on the identity of the client and the user session where it is running. Clients running as user **MyUser** in a user session will only be able to contact an instance of the same namespace provider running as **MyUser** in the same session.

### `ProviderType_Service`

The namespace provider is expected to be hosted by a service. This hosting model is not currently supported.

## Remarks

This enumeration is supported on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NAPI_PROVIDER_TYPE** enumeration applies only to NS_EMAIL namespace providers. Windows Vista and Windows Server 2008 currently support only namespace providers of type **ProviderType_Application** providers. On Windows Vista and Windows Server 2008, this value should always be set to **ProviderType_Application**.

The **NAPI_PROVIDER_TYPE** enumeration is used by the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure to specify the provide type of an NS_EMAIL namespace provider. Examples of a NS_EMAIL namespace provider of type **ProviderType_Application** would be instant messaging or email clients. An example of a NS_EMAIL namespace provider of type **ProviderType_Service** would be the Peer Name Resolution Protocol (PNRP) namespace provider.

The [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) and [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) functions are used to install a namespace provider for the NS_EMAIL namespace using a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

The [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) and [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) functions are used to enumerate namespace providers for the NS_EMAIL namespace and retrieve the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure for a provider.

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)