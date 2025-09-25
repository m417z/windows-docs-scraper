## Description

Information about enabling and disabling types of metadata exchange.

## Constants

### `WS_METADATA_EXCHANGE_TYPE_NONE:0`

Disables WS-MetadataExchange/HTTP GET servicing on the [endpoint](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).
This is the default value of [WS_SERVICE_ENDPOINT_PROPERTY_METADATA_EXCHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_endpoint_property_id) property.

### `WS_METADATA_EXCHANGE_TYPE_MEX:1`

Enables servicing of WS-MetadataExchange 1.1 request servicing on the [endpoint](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint).

### `WS_METADATA_EXCHANGE_TYPE_HTTP_GET:2`

Enables servicing of HTTP GET request servicing on the [endpoint](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) for metadata
retrieval.