# WS_REQUEST_SECURITY_TOKEN_PROPERTY_CONSTRAINT structure

## Description

This structure is used to specify a set of constraints
for a particular request security token property.
Any property constraints that are not specified will use
the default constraints.

## Members

### `id`

The id of the request security token property. The following security
property constraint may be specified:

* [WS_REQUEST_SECURITY_TOKEN_PROPERTY_TRUST_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_property_id)
  This property indicates which WS-Trust versions are acceptable.

  If this property is not specified, then the default constraint value
  of [WS_TRUST_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version) will be used.

  Currently only [WS_TRUST_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version) is supported in policy, so a property constraint containing the
  value **WS_TRUST_VERSION_FEBRUARY_2005** must be specified in
  order for the policy to match.

### `allowedValues`

An array of values which are acceptable. The type of
the values in the array correspond to the type of the values
of the request security token property. See the documentation for
a particular request security token property to determine the type of the
property.

### `allowedValuesSize`

The total size of the allowedValues array, in bytes. This
size must be a multiple of the size of the type of the value
of the property.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
entire contents of this structure will be filled out.

### `out.requestSecurityTokenProperty`