# WEB_SOCKET_ACTION enumeration

## Description

The **WEB_SOCKET_ACTION** enumeration specifies actions to be taken by WebSocket applications.

## Constants

### `WEB_SOCKET_NO_ACTION:0`

There are no actions to process.

### `WEB_SOCKET_SEND_TO_NETWORK_ACTION:1`

Indicates the application should send the buffers to a network.

### `WEB_SOCKET_INDICATE_SEND_COMPLETE_ACTION:2`

Indicates the operation queued by [WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend) is complete. The application context returned by [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction) for this send operation is no longer needed, therefore it should be freed.

### `WEB_SOCKET_RECEIVE_FROM_NETWORK_ACTION:3`

Indicates the application should fill the buffers with data from a network.

### `WEB_SOCKET_INDICATE_RECEIVE_COMPLETE_ACTION:4`

Indicates the operation queued by [WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive) is complete. The application context returned by [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction) for this receive operation is no longer needed, therefore it should be freed.

## See also

[WEB_SOCKET_ACTION_QUEUE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action_queue)

[WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)