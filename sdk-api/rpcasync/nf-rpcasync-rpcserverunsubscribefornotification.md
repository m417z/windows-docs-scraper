# RpcServerUnsubscribeForNotification function

## Description

The **RpcServerUnsubscribeForNotification** function unsubscribes the server from RPC notifications.

## Parameters

### `Binding` [in]

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that contains the binding handle for the current RPC call specified in a previous call to [RpcServerSubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserversubscribefornotification). If this function is called on the same thread that RPC has dispatched a call on, this parameter can be set to **NULL**; otherwise, an explicit binding handle must be passed in this parameter.

### `Notification` [in]

A value from the [RPC_NOTIFICATIONS](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_notifications) enumeration that specifies the type of notification requested from RPC by the server. Notifications must be unsubscribed individually, multiple values are not supported.

**Windows Vista:** Currently, only **RpcNotificationClientDisconnect** and **RpcNotificationCallCancel** are supported. If any other value is specified for this parameter, the RPC_S_CANNOT_SUPPORT error code is returned.

### `NotificationsQueued` [out]

A required pointer to a value that receives the number of notifications that the RPC runtime queued for the specified RPC call. The pointer must be supplied; it is not optional.

Your code should keep track of the number of notifications that it receives. When you unsubscribe from RPC notifications, you should check if the number of notifications that the RPC runtime queued matches the number of notifications that you received. If the numbers do not match, some notifications could still be incoming on another thread. You should delay cleaning up the notification state until you receive all incoming notifications.

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcServerUnsubscribeForNotification** must be called for every RPC binding handle that has also had [RpcServerSubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserversubscribefornotification) called on it for the associated RPC call. This API must be called before the associated RPC call is completed; otherwise, the results are undefined and could lead to application instability.

Unretrieved notifications may be retrieved after this API returns.

## See also

[RpcServerSubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserversubscribefornotification)