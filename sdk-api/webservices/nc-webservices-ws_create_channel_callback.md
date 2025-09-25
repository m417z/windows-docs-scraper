# WS_CREATE_CHANNEL_CALLBACK callback function

## Description

Handles the [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelType` [in]

The message exchange pattern of the channel.

If the type of channel is not supported by the custom
channel implementation, **E_INVALIDARG** should be returned.

### `channelParameters`

The pointer to the value that was specified by the
[WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property when the custom channel is created using [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel).

If the [WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property was not specified, the value will be **NULL**.

### `channelParametersSize` [in]

The size in bytes of the value pointed to by channelParameters.

If the [WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property was not specified, the size will be 0.

#### - **channelInstance

A pointer to a structure allocated by the callback
that contains the data specific to this channel instance. This pointer
will be passed to all the other channel callbacks
for this particular channel instance.

If this callback is successful, then the [WS_FREE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_channel_callback) will be used to free the channel instance returned
in this parameter.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `channelInstance`

A pointer to a structure allocated by the callback
that contains the data specific to this channel instance. This pointer
will be passed to all the other channel callbacks
for this particular channel instance.

If this callback is successful, then the [WS_FREE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_free_channel_callback) will be used to free the channel instance returned
in this parameter.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |