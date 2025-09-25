# WS_SERVICE_ENDPOINT_PROPERTY_ID enumeration

## Description

Each property represents optional parameters for configuring
the given [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) structure.
This enumeration is used within the [WS_SERVICE_ENDPOINT_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_property) structure that is part of **WS_SERVICE_ENDPOINT**.

## Constants

### `WS_SERVICE_ENDPOINT_PROPERTY_ACCEPT_CHANNEL_CALLBACK:0`

Used with [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).
The value is a pointer to WS_SERVICE_PROPERTY_ACCEPT_CALLBACK structure.

### `WS_SERVICE_ENDPOINT_PROPERTY_CLOSE_CHANNEL_CALLBACK:1`

Used with [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).
The value is a pointer to WS_SERVICE_PROPERTY_CLOSE_CALLBACK structure.

### `WS_SERVICE_ENDPOINT_PROPERTY_MAX_ACCEPTING_CHANNELS:2`

Used with [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint), this specifies the maximum number of concurrent channels service host will have
actively accepting new connections for a given endpoint. When not specified this value is set to 1. If an endpoint specifies a default message handler (See **WS_SERVICE_ENDPOINT**) concurrency
has to be 1.

### `WS_SERVICE_ENDPOINT_PROPERTY_MAX_CONCURRENCY:3`

Used with [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint), this specifies the maximum number of concurrent calls that would be serviced on a session based channel.
When not specified this value is set to 1. If an endpoint specifies a default message handler (See **WS_SERVICE_ENDPOINT** concurrency
has to be 1.

### `WS_SERVICE_ENDPOINT_PROPERTY_BODY_HEAP_MAX_SIZE:4`

Maximum [heap](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) size for body deserialization.

This is the heap available setting used for deserializing the body. This heap is also
available to service operations for allocating out parameters.

Default is 65535 bytes.

### `WS_SERVICE_ENDPOINT_PROPERTY_BODY_HEAP_TRIM_SIZE:5`

[Heap](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) trim size for body deserialization.

This is the heap available setting used for deserializing the body. This heap is also
available to service operations for allocating out parameters.

Default is 4096 bytes.

### `WS_SERVICE_ENDPOINT_PROPERTY_MESSAGE_PROPERTIES:6`

This property allows the user to specify properties of the message
objects used by the endpoint to send and receive messages.

This property may be specified when the service host is created.

The value specified should be of type [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties).

The following message properties may be specified:

* [WS_MESSAGE_PROPERTY_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_XML_READER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_XML_WRITER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
* [WS_MESSAGE_PROPERTY_MAX_PROCESSED_HEADERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)

### `WS_SERVICE_ENDPOINT_PROPERTY_MAX_CALL_POOL_SIZE:7`

The maximum number of call servicing objects that would be pooled to service a message object, on a given
endpoint. Note that in case of session based channels many call objects can be used on a single
channel if [WS_SERVICE_ENDPOINT_PROPERTY_MAX_CONCURRENCY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_property) is greater than 1.

For sessionless channels this property should ideally be equal to [WS_SERVICE_ENDPOINT_PROPERTY_MAX_CHANNEL_POOL_SIZE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_property).

Default is 100.

### `WS_SERVICE_ENDPOINT_PROPERTY_MAX_CHANNEL_POOL_SIZE:8`

The maximum number of [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) which will be pooled by Service Host on a given
endpoint.

Default is 100.

### `WS_SERVICE_ENDPOINT_PROPERTY_LISTENER_PROPERTIES:9`

Listener properties.

### `WS_SERVICE_ENDPOINT_PROPERTY_CHECK_MUST_UNDERSTAND:10`

Enables or disables must understand header verification on an endpoint. This is 'TRUE' by default.

### `WS_SERVICE_ENDPOINT_PROPERTY_METADATA_EXCHANGE_TYPE:11`

This property can be set to [WS_METADATA_EXCHANGE_TYPE_MEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_exchange_type) to enable
servicing of WS-MetadataExchange requests on the endpoint. In case the application wishes to
expose metadata through HTTP GET, this property can be set to **WS_METADATA_EXCHANGE_TYPE_HTTP_GET**

If not specified, the default value of this property is '[WS_METADATA_EXCHANGE_TYPE_NONE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_exchange_type)'.

Note that this property when set to [WS_METADATA_EXCHANGE_TYPE_HTTP_GET](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_exchange_type) changes the [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) property
[WS_LISTENER_PROPERTY_TRANSPORT_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) and
**WS_LISTENER_PROPERTY_TO_HEADER_MATCHING_OPTIONS** to [WS_MATCH_URL_PREFIX_PATH](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id).

When setting this property to WS_METADATA_EXCHANGE_TYPE_HTTP_GET an application must not specify [WS_MATCH_URL_EXACT_PATH](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id) for the listener
properties [WS_LISTENER_PROPERTY_TRANSPORT_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) and **WS_LISTENER_PROPERTY_TO_HEADER_MATCHING_OPTIONS** for the given [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).

### `WS_SERVICE_ENDPOINT_PROPERTY_METADATA:12`

Specifies the WSDL port name, binding name and binding namespace for the [endpoint](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).

This property must be specified to enable the participation of the [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) in WS-Metadata Exchange.

See [WS_SERVICE_ENDPOINT_METADATA](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_metadata) for more details.

### `WS_SERVICE_ENDPOINT_PROPERTY_METADATA_EXCHANGE_URL_SUFFIX:13`

Specifies the suffix which is concatenated as is to the [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) URL to generate a URL for WS-MetadataExchange v1.1 requests servicing.
The generated URL is used to compare against the 'to' header of the message received. Note that if the message does not contain a 'to' header the requests is not
serviced.

This property must only be specified if [WS_SERVICE_ENDPOINT_PROPERTY_METADATA_EXCHANGE_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_property) is set to [WS_METADATA_EXCHANGE_TYPE_MEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_exchange_type).

Specifying this property is useful in cases where an application wishes to handle WS-Transfer Get requests as well as use the same endpoint to service
WS-MetadataExchange v1.1 requests. The generate URL in this case is used to filter out WS-Transfer Get requests for Ws-MetadataExchange v1.1.

By default no filtering is done for WS-MetadataExchange v1.1 for MEX and all WS-Transfer GET requests will be handled by the endpoint for Ws-MetadataExchange v1.1, if
Ws-MetadataExchange v1.1 is enabled on the endpoint.

Note that this property changes the [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) property [WS_LISTENER_PROPERTY_TRANSPORT_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) and
**WS_LISTENER_PROPERTY_TO_HEADER_MATCHING_OPTIONS** to [WS_MATCH_URL_PREFIX_PATH](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id).

When setting this property an application must not specify [WS_MATCH_URL_EXACT_PATH](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id) for the listener
properties [WS_LISTENER_PROPERTY_TRANSPORT_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) and **WS_LISTENER_PROPERTY_TO_HEADER_MATCHING_OPTIONS**
for the given [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).

### `WS_SERVICE_ENDPOINT_PROPERTY_MAX_CHANNELS:14`

The maximum number of channels that can be serviced on the endpoint.

The default value is 100.