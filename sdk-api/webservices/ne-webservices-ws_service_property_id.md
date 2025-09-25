# WS_SERVICE_PROPERTY_ID enumeration

## Description

The optional parameters for configuring the service host.
This enumeration is used within the [WS_SERVICE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_property) structure when calling [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost) or by itself when calling [WsGetServiceHostProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetservicehostproperty).

## Constants

### `WS_SERVICE_PROPERTY_HOST_USER_STATE:0`

A void pointer
used with [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost). This property
is made available to different callbacks and service operations as part of the [WS_OPERATION_CONTEXT](https://learn.microsoft.com/windows/desktop/wsw/ws-operation-context) structure

### `WS_SERVICE_PROPERTY_FAULT_DISCLOSURE:1`

A [WS_FAULT_DISCLOSURE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_disclosure) value used with [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost).
This property is used to specify the disclosure level of the error object when its converted into a fault. The default is **WS_MINIMAL_FAULT_DISCLOSURE**.

### `WS_SERVICE_PROPERTY_FAULT_LANGID:2`

A LANGID used with [WsGetServiceHostProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetservicehostproperty) to create a fault. If none is specified, the default user locale will be used.

### `WS_SERVICE_PROPERTY_HOST_STATE:3`

A [WS_SERVICE_HOST_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_host_state) value used with [WsGetServiceHostProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetservicehostproperty) that specifies the current state of the service host.

The returned value is a snapshot of the current state, so it is
possible that the state may have changed before the caller has
had a chance to examine the value.

### `WS_SERVICE_PROPERTY_METADATA:4`

A [WS_SERVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_metadata) structure used with [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost) that contains the collection of metadata documents used for WS-MetadataExchange by the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host).

The service name and namespace are used to create a service element inside the WSDL document. The document is identified by means of the service namespace provided as part of [WS_SERVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_metadata) structure.

Note that if a service section is already defined in any of the provided WSDL documents, a service element will not be added on behalf of the application by the runtime.

### `WS_SERVICE_PROPERTY_CLOSE_TIMEOUT:5`

A **ULONG** used with [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost) that specifies the maximum amount of time a service model will wait after [WsCloseServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloseservicehost) is called. Once the timeout expires service host will abort itself.
The default is 5 seconds specified in milliseconds as 5000.