# WS_PROXY_MESSAGE_CALLBACK_CONTEXT structure

## Description

Specifies the callback function and state for an application that wishes
to associate or inspect headers in an input or an output message respectively.

See also, [WS_CALL_PROPERTY_SEND_MESSAGE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_call_property_id) and
**WS_CALL_PROPERTY_RECEIVE_MESSAGE_CONTEXT**.

## Members

### `callback`

application specific callback for handling the message.

### `state`

Application specific state that would be made available to the callback upon its invocation.