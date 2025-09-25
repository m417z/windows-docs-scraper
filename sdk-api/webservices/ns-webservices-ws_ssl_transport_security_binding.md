# WS_SSL_TRANSPORT_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of SSL/TLS
protocol based transport security.

This security binding is supported only with the
[WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_CERT_FAILURES_TO_IGNORE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_DISABLE_CERT_REVOCATION_CHECK](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_REQUIRE_SSL_CLIENT_CERT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `localCertCredential`

The local certificate credential to be used with this security binding.

Server side: When SSL is used for transport security with [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), the server certificate must be
registered by the application using the httpcfg
tool and this field must be set to **NULL**. In all other cases, the
server SSL certificate must be specified using this field.

Client side: If a client certificate is to be used with SSL, it must
be specified using this field. If no client certificate is to be
used, this field must be set to **NULL**.