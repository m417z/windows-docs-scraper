# WS_SECURITY_DESCRIPTION structure

## Description

The top-level structure used to specify the security requirements for
a [channel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) (on the client side) or a [listener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener) (on the server side).

## Members

### `securityBindings`

The array of pointers to security bindings. The set of security
bindings supplies determines the kind of security applied to the
channel. Each security binding specifies one security token.

### `securityBindingCount`

The count of elements in the securityBindings array.

### `properties`

The array of properties specifying the optional channel-wide security
settings. Each [WS_SECURITY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_property) in the array is a key-value
pair and must use a key defined in [WS_SECURITY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id). This field can be **NULL**,
and if it is **NULL**, the default value will be used for each security
channel setting.

### `propertyCount`

The count of elements in the properties array.

## Remarks

The figure below illustrates the structure of a security description.

:::image type="content" source="images/SecurityDescription.png" border="false" alt-text="Diagram of the elements in a security description. A Channel-wide Settings Bag, a Security Binding, and the properties of the Security Binding.":::