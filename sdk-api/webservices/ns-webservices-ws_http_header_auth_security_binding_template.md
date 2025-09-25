# WS_HTTP_HEADER_AUTH_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of HTP header authentication
protocol based security.

See also [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding)

## Members

### `securityBindingProperties`

Application provided security binding properties that cannot be represented in policy.

### `clientCredential`

The Windows credential to be used to obtain this security token. This
is required on the client side and must be **NULL** on the server side.