# MFNET_PROXYSETTINGS enumeration

## Description

Specifies how the default proxy locator will specify the connection settings to a proxy server. The application must set these values in the [MFNETSOURCE_PROXYSETTINGS](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxysettings-property) property.

## Constants

### `MFNET_PROXYSETTING_NONE:0`

The proxy locator bypasses all addresses.

### `MFNET_PROXYSETTING_MANUAL:1`

The proxy locator uses manual settings. The application must set the following properties:

* [MFNETSOURCE_PROXYHOSTNAME](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxyhostname-property)
* [MFNETSOURCE_PROXYPORT](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxyport-property)
* [MFNETSOURCE_PROXYBYPASSFORLOCAL](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxybypassforlocal-property)
* [MFNETSOURCE_PROXYEXCEPTIONLIST](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxyexceptionlist-property)

### `MFNET_PROXYSETTING_AUTO:2`

The proxy locator automatically discovers proxy servers by using the WinInet auto-proxy detection mechanism.

### `MFNET_PROXYSETTING_BROWSER:3`

The proxy locator uses the proxy settings of the browser. By default, the proxy locator sets this value for HTTP.

## See also

[MFCreateProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreateproxylocator)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Proxy Support for Network Sources](https://learn.microsoft.com/windows/desktop/medfound/proxy-support-for-network-sources)