# WS_ISSUED_TOKEN_MESSAGE_SECURITY_BINDING_CONSTRAINT structure

## Description

A security binding constraint that can be used to extract information
about how to obtain an issued token from an issuing party.

## Members

### `bindingConstraint`

The base binding constraint that this binding constraint derives from.

There are currently no binding-specific properties defined for this binding constraint.

### `bindingUsage`

This specifies how the issued token should be attached to a message.

### `claimConstraints`

This field contains a list of claim types that
are allowed in the policy. Each claim type is
a URI which identifies the type of claim.

### `claimConstraintCount`

The number of elements in the claimConstraints array.

If this value is 0, then the claimConstraints array may be
**NULL**, and any claims are allowed to appear in the policy.

### `requestSecurityTokenPropertyConstraints`

A set of property constraints relating to how to request a security token.

See [WS_REQUEST_SECURITY_TOKEN_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_request_security_token_property_constraint) for more information.

### `requestSecurityTokenPropertyConstraintCount`

The number of elements in the requestSecurityTokenPropertyConstraints array.

If the array has zero elements, the requestSecurityTokenPropertyConstraints field may be **NULL**.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
entire contents of this structure will be filled out.

### `out.issuerAddress`

### `out.requestSecurityTokenTemplate`

## Remarks

The information extracted using this binding constraint can be used
with [WsRequestSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsrequestsecuritytoken) to obtain an issued token.
The issued token can then be used with the
[WS_XML_TOKEN_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_token_message_security_binding) security binding.

This binding constraint is typically used in federated security
scenarios.