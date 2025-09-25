# WS_SECURITY_PROPERTY_CONSTRAINT structure

## Description

This structure is used to specify a set of constraints
for a particular security property.
Any property constraints that are not specified will use
the default constraints.

## Members

### `id`

The id of the security property. The following security
property constraints may be specified:

* [WS_SECURITY_PROPERTY_TIMESTAMP_USAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id)
  This property constraint may be specified when any
  of the following security bindings are specified:

  + [WS_USERNAME_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_username_message_security_binding_constraint)
  + [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding_constraint)
  + [WS_CERT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_cert_message_security_binding_constraint)
  + [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_context_message_security_binding_constraint)If this property is not specified, then the default constraint value
  of [WS_SECURITY_TIMESTAMP_USAGE_ALWAYS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_timestamp_usage) will be used.
* [WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id)
  This property constraint may be specified when any
  of the following security bindings are specified:

  + [WS_SSL_TRANSPORT_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_ssl_transport_security_binding_constraint)
  + [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_tcp_sspi_transport_security_binding_constraint)
  + [WS_HTTP_HEADER_AUTH_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_http_header_auth_security_binding_constraint)If this property is not specified, then the default constraint value
  of [WS_PROTECTION_LEVEL_SIGN_AND_ENCRYPT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_protection_level) will be used.
  **WS_SECURITY_PROPERTY_SECURITY_HEADER_LAYOUT** This property constraint may be specified when any
  of the following security bindings are specified:

  + [WS_USERNAME_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_username_message_security_binding_constraint)
  + [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding_constraint)
  + [WS_CERT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_cert_message_security_binding_constraint)
  + [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_context_message_security_binding_constraint)If this property is not specified, then the default constraint value
  of [WS_SECURITY_HEADER_LAYOUT_STRICT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_header_layout) will be used.
  **WS_SECURITY_PROPERTY_SECURITY_HEADER_VERSION**This property constraint may be specified when any
  of the following security bindings are specified:

  + [WS_USERNAME_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_username_message_security_binding_constraint)
  + [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding_constraint)
  + [WS_CERT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_cert_message_security_binding_constraint)
  + [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_context_message_security_binding_constraint)If this property is not specified, then the default constraint value
  of [WS_SECURITY_HEADER_VERSION_1_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_header_version) will be used.
  **WS_SECURITY_PROPERTY_ALGORITHM_SUITE_NAME**This property constraint may be specified when any
  of the following security bindings are specified:

  + [WS_USERNAME_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_username_message_security_binding_constraint)
  + [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding_constraint)
  + [WS_CERT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_cert_message_security_binding_constraint)
  + [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_context_message_security_binding_constraint)If this property is not specified, then the default constraint value
  of [WS_SECURITY_ALGORITHM_SUITE_NAME_BASIC256](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_algorithm_suite_name) will be used.

### `allowedValues`

An array of values which are acceptable. The type of
the values in the array correspond to the type of the values
of the security property. See the documentation for
a particular security property to determine the type of the
property.

### `allowedValuesSize`

The total size of the allowedValues array, in bytes. This
size must be a multiple of the size of the type of the value
of the property.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
entire contents of this structure will be filled out.

### `out.securityProperty`