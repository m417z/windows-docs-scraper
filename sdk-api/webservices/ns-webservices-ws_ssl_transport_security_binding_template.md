# WS_SSL_TRANSPORT_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of SSL/TLS
protocol based transport security.

See also [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding).

This security binding is supported only with the
[WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Members

### `securityBindingProperties`

Application provided security binding properties that cannot be represented in policy.

### `localCertCredential`

The local certificate credential to be used with this security binding.

Server side: When SSL is used for transport security with [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), the server certificate must be
registered by the application using the [HttpCfg.exe](https://learn.microsoft.com/windows/win32/http/httpcfg-exe) and this field must be set to **NULL**. In all other cases, the
server SSL certificate must be specified using this field.

Client side: If a client certificate is to be used with SSL, it must
be specified using this field. If no client certificate is to be
used, this field must be set to **NULL**.