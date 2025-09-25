# WS_HTTP_HEADER_AUTH_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of HTTP header authentication against a target service or a HTTP proxy server
based on the basic, digest (RFC 2617) and the SPNEGO (RFC4559) protocols.
Since this security binding operates at the HTTP header level, it is supported only with the [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).
By default, this security binding is used for the target service. However [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
security binding property can be specified to use it for a HTTP proxy server. This binding provides client authentication, but not message protection
since the HTTP body is unaffected by this binding. While this security binding can be used alone, such usage is not recommended;
more typically, HTTP header authentication is done in conjunction with transport level security provided by a security binding such as the
[WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding). To use this binding without SSL, the security description property **WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL** must be explicitly set to **WS_PROTECTION_LEVEL_NONE**.

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_BASIC_REALM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)
* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_DIGEST_REALM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)
* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_DIGEST_DOMAIN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `clientCredential`

The Windows Integrated Authentication credential to be used to
authenticate the client. This is required on the client side and must
be **NULL** on the server side.

If the credential used is a [WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_windows_integrated_auth_credential) then
[WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) must be set to
[WS_HTTP_HEADER_AUTH_SCHEME_NONE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type), **WS_HTTP_HEADER_AUTH_SCHEME_NTLM**,
**WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE** or **WS_HTTP_HEADER_AUTH_SCHEME_PASSPORT**.
**WS_HTTP_HEADER_AUTH_SCHEME_PASSPORT** defaults to using the Passport keyring.