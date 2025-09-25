# WS_CHANNEL_PROPERTY_CONSTRAINT structure

## Description

Specifies constraints
for a particular channel property.Any property constraints that are not specified will use
the default constraints.

## Members

### `id`

The ID of the channel property. The following channel
properties constraints may be specified:

* [WS_CHANNEL_PROPERTY_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
  If this property constraint is not specified when using
  [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) the default constraint value
  of [WS_ENCODING_XML_UTF8](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding) will be used.

  If this property constraint is not specified not specified when using
  [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) the default constraint value of
  [WS_ENCODING_XML_BINARY_SESSION_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding) will be used.
* [WS_CHANNEL_PROPERTY_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
  If this property constraint is not specified, the default constraint
  value of [WS_ADDRESSING_VERSION_1_0](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) will be used.
* [WS_CHANNEL_PROPERTY_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
  If this property constraint is not specified, the default constraint of
  value of [WS_ENVELOPE_VERSION_SOAP_1_2](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) will be used.

### `allowedValues`

An array of acceptable values. The type of
the values in the array correspond to the type of the values
of the channel property. See the documentation for
a particular channel property to determine the type of the
property.

### `allowedValuesSize`

The total size of the **allowedValues** array, in bytes. This
size must be a multiple of the size of the type of the value
of the property.

### `out`

When [WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) returns NOERROR, the
entire contents of this structure will be filled out.

### `out.channelProperty`