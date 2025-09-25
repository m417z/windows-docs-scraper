# WsCreateServiceProxy function

## Description

Creates a [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy) with the specified properties.

## Parameters

### `channelType` [in]

A [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration value representing the channel type for the service proxy.

### `channelBinding` [in]

A [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) enumeration value representing the channel binding.

### `securityDescription` [in, optional]

A [WS_SECURITY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) structure representing the security description.

### `properties`

An array of [WS_PROXY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_proxy_property) structures containing optional properties for the service proxy.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `channelProperties`

An array of [WS_CHANNEL_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_property) structures containing optional channel properties. The value of this parameter may be **NULL**, in which case, the *channelPropertyCount* parameter must be 0 (zero).

**Note** Be very careful about modifying the default values for these properties.

### `channelPropertyCount` [in]

The number of properties in the *channelProperties* array.

### `serviceProxy`

On success, a pointer that receives the address of the [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure representing the new service proxy.
When you no longer need this structure, you must free it by calling [WsFreeServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeserviceproxy).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |