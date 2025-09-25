# RPC_ASYNC_EVENT enumeration

## Description

The
**RPC_ASYNC_EVENT** enumerated type describes the asynchronous notification events that an RPC application can receive.

## Constants

### `RpcCallComplete`

The remote procedure call has completely executed.

### `RpcSendComplete`

The RPC run-time library finished transmitting some of the data provided by the user. A portion, but not necessarily all of the data being sent, has been transmitted. Only applications using DCE pipes will receive this notification.

### `RpcReceiveComplete`

The RPC run-time library finished receiving data. Only applications using DCE pipes will receive this notification.

### `RpcClientDisconnect`

The RPC client has disconnected from the service.

### `RpcClientCancel`

Windows Vista or later: The RPC client has cancelled the asynchronous procedure call.