# RpcServerSubscribeForNotification function

## Description

The **RpcServerSubscribeForNotification** function subscribes the server for RPC notifications.

## Parameters

### `Binding` [in]

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that contains the binding handle for the current call. If this function is called on the same thread that RPC has dispatched a call on, this parameter can be set to **NULL**; otherwise, an explicit binding handle must be passed in this parameter.

### `Notification` [in]

Bitwise combination of the [RPC_NOTIFICATIONS](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_notifications) enumeration values that specifies the type of notification requested from RPC by the server.

**Windows Vista:** Currently, only **RpcNotificationClientDisconnect** and **RpcNotificationCallCancel** are supported. If any other value is specified for this parameter, the RPC_S_CANNOT_SUPPORT error code is returned.

### `NotificationType` [in]

[RPC_NOTIFICATION_TYPES](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_notification_types) enumeration value that specifies the method by which RPC will notify the server.

**Windows Vista:** **RpcNotificationTypeNone** is not supported. If this value is specified, the RPC_S_INVALID_ARG error code is returned.

### `NotificationInfo` [in]

Pointer to an [RPC_ASYNC_NOTIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_notification_info) union that contains the specific information necessary for RPC to contact the server for notification. The data contained in this union is specific to the method passed to the *NotificationType* parameter.

If the **RpcNotificationTypeCallback** method is specified in *NotificationTypes*, the **NotificationRoutine** member of the corresponding branch of the union is set to the binding handle for synchronous calls and the async handle for asynchronous calls.

RPC makes a copy of this parameter during a successful call to this function. The caller can free or update this parameter when the API returns.

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

If the caller specifies any notification type other than **RpcNotificationTypeEvent**, it can subscribe to both the **RpcNotificationClientDisconnect** and **RpcNotificationCallCancel** notifications with a single call. For events, two separate calls to this API are required.

The server application must unsubscribe for notification before the RPC call is completed. If the RPC call is synchronous, it is completed when the server sends a return value to RPC. If the RPC call is asynchronous, it is completed when the server calls [RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall) or [RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall), or throws an exception from the manager routine. If the server fails to unsubscribe for call status change notifications, the results are undefined, and the server may crash at a later time. Note that the subscription applies for one RPC call only. If the server application needs to monitor more than one call, it needs to subscribe for each call specifically.

The server application can expect that it will not be signaled for notifications that it hasn't subscribed for. If it has subscribed for more than one notification, each notification is communicated to the completion method if the selected completion method permits it. If it doesn't permit the communication of notifications, the server application can call on of the RPC server APIs to test whether or not the client has canceled or disconnected. The table below indicates how notification type (call cancel or client disconnect) is communicated to each notification method:

| Notification Method | Event/Notification Type |
| --- | --- |
| RpcNotificationTypeNone | Not allowed for subscription. |
| RpcNotificationTypeEvent | The notification type is not available. |
| RpcNotificationTypeApc | The notification type is found in the *Event* parameter of the APC function. |
| RpcNotificationTypeIoc | The notification type is not available. |
| RpcNotificationTypeCallback | The notification type is found in the *Event* parameter of the callback function. |

Note that the table does not imply whether or not a caller can subscribe for notifications using the given notification method; rather, it simply states the information the caller can obtain when the notification is received, such as the notification type.

The caller must synchronize between **RpcServerSubscribeForNotification** and [RpcServerUnsubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverunsubscribefornotification) on the same binding handle. If they are called simultaneously, the results are undefined and could incur lost notifications, extra notifications, an incorrect notification count, process crashes, data corruption, and memory leaks. The same concern applies for threads calling **RpcServerSubscribeForNotification** on the same binding handle.

Calling **RpcServerSubscribeForNotification** and [RpcServerUnsubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverunsubscribefornotification) on the same binding handle is thread safe. For current notifications, RPC will notify the server no more than once per call.

## See also

[RpcServerUnsubscribeForNotification](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverunsubscribefornotification)