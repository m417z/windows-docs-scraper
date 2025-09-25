# WEB_SOCKET_ACTION_QUEUE enumeration

## Description

The **WEB_SOCKET_ACTION_QUEUE** enumeration specifies the action types returned by [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction).

## Constants

### `WEB_SOCKET_SEND_ACTION_QUEUE:0x1`

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) will return only send-related actions.

### `WEB_SOCKET_RECEIVE_ACTION_QUEUE:0x2`

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) will return receive-related actions as well as internal send actions (reply to a ping frame).

### `WEB_SOCKET_ALL_ACTION_QUEUE`

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) will return all actions.

## See also

[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)

[WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)