# WsCreateServiceHost function

## Description

Creates a [service host](https://learn.microsoft.com/windows/desktop/wsw/service-host) for the specified endpoints.

## Parameters

### `endpoints`

An array of [WS_SERVICE_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_endpoint) structures representing the service endpoints for which to create the service host.

### `endpointCount` [in]

The number of endpoints in the *endpoints* array.

### `serviceProperties`

An array of [WS_SERVICE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_property) structures containing optional properties for the service host.

The value of this parameter may be **NULL**, in which case, the *servicePropertyCount* parameter must be 0 (zero).

### `servicePropertyCount` [in]

The number of properties in the *serviceProperties* array.

### `serviceHost`

On success, a pointer that receives the address of the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) structure representing the new service host.
When you no longer need this structure, you must free it by calling [WsFreeServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeservicehost).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An invalid argument is specified for creating the service host. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |