# WS_SSL_TRANSPORT_SECURITY_BINDING_CONSTRAINT structure

## Description

A security binding constraint that corresponds to the
[WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding).

## Members

### `bindingConstraint`

The base binding constraint that this binding constraint derives from.

There are no binding-specific properties are defined for this binding constraint
at this time.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
entire contents of this structure will be filled out.

### `out.clientCertCredentialRequired`