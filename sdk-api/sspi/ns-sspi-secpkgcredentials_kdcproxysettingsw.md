# SecPkgCredentials_KdcProxySettingsW structure

## Description

Specifies the Kerberos proxy settings for the credentials.

## Members

### `Version`

Version for the Kerberos proxy settings where KDC_PROXY_SETTINGS_V1 is defined as 1.

### `Flags`

Flags for the Kerberos proxy settings.

### `ProxyServerOffset`

The offset of the proxy server. This member is optional.

### `ProxyServerLength`

Length of the proxy server.

### `ClientTlsCredOffset`

The offset of the client credentials. This member is optional.

### `ClientTlsCredLength`

Length of the client credentials.