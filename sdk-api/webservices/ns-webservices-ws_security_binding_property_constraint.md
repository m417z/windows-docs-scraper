# WS_SECURITY_BINDING_PROPERTY_CONSTRAINT structure

## Description

This structure is used to specify a set of constraints
for a particular security binding property.
Any property constraints that are not specified will use
the default constraints.

## Members

### `id`

The id of the security binding property. The following security
binding property constraints may be specified:

* [WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
  This property constraint may be specified when the
  [WS_HTTP_HEADER_AUTH_SECURITY_BINDING_CONSTRAINT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_constraint_type) security binding is specified.

  + [WS_HTTP_HEADER_AUTH_SECURITY_BINDING_CONSTRAINT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_constraint_type)If this property is not specified, then the default constraint value
  of [WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type) will be used.

### `allowedValues`

An array of values which are acceptable. The type of
the values in the array correspond to the type of the values
of the security binding property. See the documentation for
a particular security binding property to determine the type of the
property.

### `allowedValuesSize`

The total size of the allowedValues array, in bytes. This
size must be a multiple of the size of the type of the value
of the property.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
fields of the property structure will be filled out as follows:

### `out.securityBindingProperty`