# WS_SERVICE_METADATA structure

## Description

Specifies the service metadata documents array. This can be a collection of
WSDL/XSD documents represented as an array of WS_STRING.

## Members

### `documentCount`

The count of metadata documents being specified.

### `documents`

A [WS_SERVICE_METADATA_DOCUMENT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_metadata_document)* array where element represents a WS_SERVICE_METADATA_DOCUMENT for each individual XML Schema, WSDL or a Policy document.
The service model expects this to be valid for the lifetime of the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host).

### `serviceName`

Reference to WS_XML_STRING representing the name of the service in the WSDL document. Note that this field must be specified along with the serviceNs field. The service model expects this to be valid for the lifetime
of the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host).

### `serviceNs`

Reference to WS_XML_STRING representing the namespace of the service in the WSDL document. Note that this field must be specified along with the serviceName field.
The service model expects this to be valid for the lifetime of the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host).