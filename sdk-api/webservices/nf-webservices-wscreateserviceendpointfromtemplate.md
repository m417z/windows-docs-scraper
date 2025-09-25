# WsCreateServiceEndpointFromTemplate function

## Description

Helper routine for creating a service endpoint ([WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint)) from policy templates.

## Parameters

### `channelType` [in]

A [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration value representing the type of channel hosted by the endpoint.

### `properties` [in]

An array of [WS_SERVICE_ENDPOINT_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_service_endpoint_property) structures containing properties for the service endpoint. (Application should fill in channel properties in the template structure.)

### `propertyCount` [in]

The number of properties in the *properties* array.

### `addressUrl` [in, optional]

The URL address on which the endpoint is to listen.

### `contract` [in]

A [WS_SERVICE_CONTRACT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_contract) structure representing the contract of the endpoint.

### `authorizationCallback` [in]

A [WS_SERVICE_SECURITY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_security_callback) authorization callback for the service endpoint.

### `heap` [in]

The [heap](https://learn.microsoft.com/windows/desktop/wsw/heap) from which memory for the service endpoint is allocated on successful return.

### `templateType` [in]

A [WS_BINDING_TEMPLATE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_binding_template_type) enumeration value representing the type of templates being used to create the service endpoint.

### `templateValue` [in]

Optional template structure to be created and filled in by application.
The template must be consistent with the input template type (passed in the *templateType* parameter). When the *templateValue* parameter is **NULL**,
it is equivalent to the corresponding template structure initialized to zero.

### `templateSize` [in]

The size, in bytes, of the input templateValue structure.

### `templateDescription` [in]

The description of template structure (passed in the *templateValue* parameter). Needs to match templateType.

### `templateDescriptionSize` [in]

The size of the template description.

### `serviceEndpoint` [out]

On success, a pointer that receives the address of the [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) structure representing the new service endpoint.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

**WsCreateServiceEndpointFromTemplate** creates the [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) structure from the specified input policy templates and additional user input.