# WS_SECURITY_BINDING_CONSTRAINT structure

## Description

The base class for all security binding constraint structures.

## Members

### `type`

This value depends on which type of security binding constraint that is used.

### `propertyConstraints`

A set of binding-specific security property constraints.

See [WS_SECURITY_BINDING_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_binding_property_constraint) for more information.

### `propertyConstraintCount`

The number of elements in the propertyConstraints array.

If the array has zero elements, the propertyConstraints field may be **NULL**.