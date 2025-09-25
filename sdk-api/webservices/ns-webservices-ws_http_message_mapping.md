# WS_HTTP_MESSAGE_MAPPING structure

## Description

Specifies information about how an HTTP request or response should be
represented in a message object.

## Members

### `requestMappingOptions`

Options that control how information in the HTTP request is mapped to the message object.

### `responseMappingOptions`

Options that control how information in the HTTP response is mapped to the message object.

### `requestHeaderMappings`

An array of pointers to mappings which describe which
HTTP headers are mapped to/from headers in the message object
for an HTTP request. The pointers in the array may not be **NULL**.

### `requestHeaderMappingCount`

The number of items in the requestHeaderMappings array.

### `responseHeaderMappings`

An array of pointers to mappings which describe which
HTTP headers are mapped to/from headers in the message object
for an HTTP response. The pointers in the array may not be **NULL**.

### `responseHeaderMappingCount`

The number of items in the responseHeaderMappings array.

## Remarks

A message may contain additional transport-specific information that is
not part of the message envelope. This transport-specific information
can be exposed programmatically as headers of the message object.
These headers are referred to as mapped headers.

Each mapped header is stored as regular header element
in the headers of the message (see [WS_MESSAGE_PROPERTY_HEADER_BUFFER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)).
The empty XML namespace ("") is used for mapped headers.

This structure specifies how the mapping occurs between an HTTP request
or response and the mapped headers of the message object. The structure
can be specified using the [WS_CHANNEL_PROPERTY_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property.

The following diagram shows how HTTP headers are mapped into
the headers of a message.
:::image type="content" source="images/MappedHeaders.png" border="false" alt-text="Diagram showing a Message object with the MyHeader element highlighted and an arrow pointing to the MyHeader line in an HTTP Request.":::

When a message is received, the HTTP channel
will automatically copy the specified HTTP headers from the request
or response to the headers of the message object. The application
can then use [WsGetMappedHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmappedheader) to get the values of
the mapped headers.

Before a message is sent, an application can add mapped headers
to the message object using [WsAddMappedHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddmappedheader).
When the message is sent, the HTTP channel will automatically
remove the specified headers from the headers of message object (so they
do not appear inside the envelope), and add them as HTTP
request or response headers.

The HTTP channel will only perform this mapping for HTTP headers
that have been specified in the requestHeaderMappings or
responseHeaderMappings fields. The [WS_HTTP_HEADER_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_mapping) is used to specify each header, and includes instructions about how
the message header is transformed to/from an HTTP header.

Other information in an HTTP request or response that does not correspond
to HTTP headers can be mapped into header of the message object by setting the
requestMappingOptions or responseMappingOptions. These mapped values can then be
extracted using [WsGetMappedHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmappedheader).
See [WS_HTTP_REQUEST_MAPPING_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_writer_property_id) or [WS_HTTP_RESPONSE_MAPPING_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_canonicalization_property_id)
for information about what information can be mapped into message headers.