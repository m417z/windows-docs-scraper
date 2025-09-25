# WS_ENDPOINT_POLICY_EXTENSION structure

## Description

This structure is used to specify an endpoint policy extension.

## Members

### `policyExtension`

The base policy extension that this policy extension derives from.

### `assertionName`

Name of the assertion to be retrieved as an extension.

### `assertionNs`

Namespace of the assertion to be retrieved as an extension.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
fields of this structure will be filled out as follows:

### `out.assertionValue`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR and if the specified assertion is found in the policy alternative, **assertionValue** returns the read-only content. Returned buffer should not be modified or freed. If not found, it is set to NULL.

## Remarks

This extension can be used to specify a custom assertion or an assertion that is
supported by this library so that the application can
retrieve the original XML form of the assertion. If one of the supported assertions
is specified as an extension, the corresponding constraint should not be specified.
For example, if http://schemas.xmlsoap.org/ws/2005/07/securitypolicy:TransportBinding
is specified as an endpoint extension, [WS_SSL_TRANSPORT_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_ssl_transport_security_binding_constraint) cannot be specified as a constraint.

The following assertions are not allowed as policy extension because they might affect constraint
matching result if the assertion is handled as assertion.

``` syntax
<wsa09p:UsingAddressing.../>
<wsa10p:UsingAddressing.../>
<binp:BinaryEncoding.../>
<mtomp:OptimizedMimeSerialization.../>
```