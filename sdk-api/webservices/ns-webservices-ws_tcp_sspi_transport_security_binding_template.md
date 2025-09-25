# WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of Windows SSPI
protocol based transport security.

See also [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_tcp_sspi_transport_security_binding).

## Members

### `securityBindingProperties`

Application provided security binding properties that cannot be represented in policy.

### `clientCredential`

The Windows credential to be used to obtain this security token. This
is required on the client and must not be specified on the server.