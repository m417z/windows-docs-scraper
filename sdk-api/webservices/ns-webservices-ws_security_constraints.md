# WS_SECURITY_CONSTRAINTS structure

## Description

This structure specifies the security related constraints
as part of [WS_POLICY_CONSTRAINTS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_policy_constraints).

## Members

### `securityPropertyConstraints`

An array of security property constraints which override the default
set of constraints. The constraints specified here, combined
with the default set of constraints limits the set of policies
that will be matched.

If a security property constraint is not specified for a given property,
then a default constraint value will be used.
See [WS_SECURITY_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_property_constraint) for the
supported set of properties and their default values.

Note that the defaults constraints for [WS_SECURITY_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_property_constraint)
are the same as the defaults for [WS_SECURITY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_property).

### `securityPropertyConstraintCount`

The number of elements specified in the securityPropertyConstraints
array.

If this value is 0, then the securityPropertyConstraints array may be **NULL**.

### `securityBindingConstraints`

Any array of security binding constraints which taken as a unit specify
the type of security to match in the policy.

The type of each [WS_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_binding_constraint) corresponds
to the types of security that is specified using a [WS_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding) structure. Each security binding specifies one security token, and similarly,
each security binding constraint specifies constraints on one security token.

Specifying zero constraints indicates no security.

### `securityBindingConstraintCount`

The number of elements specified in the securityBindingConstraints
array.

If this value is 0, then the securityBindingConstraints array may be **NULL**.