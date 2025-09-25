# WS_HTTP_REDIRECT_CALLBACK_CONTEXT structure

## Description

Specifies the callback function and state for controlling the HTTP auto redirection behavior.

See also, **WS_HTTP_REDIRECT_CALLBACK_CONTEXT**
and [WS_CHANNEL_PROPERTY_HTTP_REDIRECT_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id).

## Members

### `callback`

Application specific callback for controlling HTTP auto redirections.

### `state`

Application specific state that would be made available to the callback upon its invocation.