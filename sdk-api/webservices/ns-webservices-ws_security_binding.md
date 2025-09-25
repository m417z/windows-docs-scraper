# WS_SECURITY_BINDING structure

## Description

The abstract base type for all security bindings. One or more
concrete subtypes of this are specified in the
[security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) that is
supplied during channel and listener creation. Each concrete subtype
of this corresponds to a security protocol and a way of using it to
provide authentication and/or protection to a channel.

Each security binding subtype instance in the security description
contributes one security token at runtime. Thus, the fields of this
type can be viewed as specifying a security token, how to obtain it,
how to use it for channel security, and how to modify its behavior
using the optional settings.

## Members

### `bindingType`

The [WS_SECURITY_BINDING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_type) of the security binding being described. The type value
indicates how to obtain the security token corresponding to this
security binding.

### `properties`

The array of properties specifying the optional security binding
settings. Each [WS_SECURITY_BINDING_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding_property) in the array is a key-value
pair and must use a key defined in [WS_SECURITY_BINDING_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id). This field can be **NULL**, and if
it is **NULL**, the default value will be used for each security token
setting.

### `propertyCount`

The count of elements in the properties array.