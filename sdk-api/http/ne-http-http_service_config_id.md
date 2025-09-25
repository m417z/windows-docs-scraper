# HTTP_SERVICE_CONFIG_ID enumeration

## Description

The
**HTTP_SERVICE_CONFIG_ID** enumeration type defines service configuration options.

## Constants

### `HttpServiceConfigIPListenList`

Specifies the IP Listen List used to register IP addresses on which to listen for SSL connections.

### `HttpServiceConfigSSLCertInfo`

Specifies the SSL certificate store.

**Note** If SSL is enabled in the HTTP Server API, TLS 1.0 may be used in place of SSL when the client application specifies TLS.

### `HttpServiceConfigUrlAclInfo`

Specifies the URL reservation store.

### `HttpServiceConfigTimeout`

Configures the HTTP Server API wide connection timeouts.

**Note** Windows Vista and later versions of Windows

### `HttpServiceConfigCache`

Used in the [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) and [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) functions.

**Note** Windows Server 2008 R2 and Windows 7 and later versions of Windows.

### `HttpServiceConfigSslSniCertInfo`

Specifies the SSL endpoint configuration with *Hostname:Port* as key. Used in the [HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration), [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration), [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration), and [HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration) functions

**Note** Windows 8 and later versions of Windows.

### `HttpServiceConfigSslCcsCertInfo`

Specifies that an operation should be performed for the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a Transport Layer Security (TLS) handshake. Used in the [HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration), [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration), [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration), and [HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration) functions

**Note** Windows 8 and later versions of Windows.

### `HttpServiceConfigSetting`

### `HttpServiceConfigMax`

Terminates the enumeration; is not used to define a service configuration option.

## See also

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)