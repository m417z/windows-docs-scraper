# WS_CREATE_LISTENER_CALLBACK callback function

## Description

Handles the [WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelType` [in]

The type of channel the listener listens for.

### `listenerParameters`

The pointer to the value that was specified by the
[WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) property when the custom listener is created using [WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener).

If the [WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) property was not specified, the value will be **NULL**.

### `listenerParametersSize` [in]

The size in bytes of the value pointed to by listenerParameters.

If the [WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) property was not specified, the size will be 0.

#### - **listenerInstance

A pointer to an allocated structure that represents
the listener instance. This pointer
will be passed to all the other listener callbacks
for this particular listener instance.

If this callback is successful, then the [WS_FREE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_listener_callback) will be used to free the listener instance.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `listenerInstance`

A pointer to an allocated structure that represents
the listener instance. This pointer
will be passed to all the other listener callbacks
for this particular listener instance.

If this callback is successful, then the [WS_FREE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_listener_callback) will be used to free the listener instance.

## Return value

| Return code | Description |
| --- | --- |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |