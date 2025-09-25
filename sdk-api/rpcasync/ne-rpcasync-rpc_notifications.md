# RPC_NOTIFICATIONS enumeration

## Description

The **RPC_NOTIFICATIONS** enumeration specifies the notifications a server can receive from RPC.

## Constants

### `RpcNotificationCallNone:0`

Do not send a notification.

**Windows Vista:** Currently, this value is not supported for [RpcServerSubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserversubscribefornotification) and [RpcServerUnsubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverunsubscribefornotification).

### `RpcNotificationClientDisconnect:1`

The client has disconnected.

### `RpcNotificationCallCancel:2`

The RPC call has been canceled.

## See also

[RpcServerSubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserversubscribefornotification)

[RpcServerUnsubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverunsubscribefornotification)