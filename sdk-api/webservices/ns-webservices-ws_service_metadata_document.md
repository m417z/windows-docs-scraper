# WS_SERVICE_METADATA_DOCUMENT structure

## Description

Specifies the individual documents that make up the service metadata.

## Members

### `content`

A [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string)* representing the specific XML Schema, WSDL or a Policy document.
The service model expects this to be valid for the lifetime of the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host).

### `name`

The name of the document which will be suffixed to the URL path on which this document is serviced for HTTP GET support
for metadata retrieval. Note that this can be set to **NULL** if the application is only using Ws-MetadataExchange 1.1 for servicing
metadata request.

See [WS_SERVICE_ENDPOINT_PROPERTY_METADATA_EXCHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_endpoint_property_id) service endpoint property to see how to enable HTTP GET support or
WS-MetadataExchange 1.1 for servicing metadata request.