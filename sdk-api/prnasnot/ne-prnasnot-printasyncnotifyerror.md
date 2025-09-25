# PrintAsyncNotifyError enumeration

## Description

Specifies the error code portion of the **HRESULT** returned after an asynchronous notification failure.

An **HRESULT** value consists of a severity code, a facility code, and an error code. Use the **HRESULT_CODE** macro to compare just the error code of an **HRESULT**. For more information about COM error codes, see
[Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Constants

### `CHANNEL_CLOSED_BY_SERVER:0x01`

The Print Spooler-hosted printing system component closed the communication channel.

### `CHANNEL_CLOSED_BY_ANOTHER_LISTENER:0x02`

A listening application, other than the caller, closed the communication channel.

### `CHANNEL_CLOSED_BY_SAME_LISTENER:0x03`

The caller has already closed the communication channel.

### `CHANNEL_RELEASED_BY_LISTENER:0x04`

The caller has already released the communication channel

### `UNIRECTIONAL_NOTIFICATION_LOST:0x05`

One or more listeners did not receive this notification however; at least one listener did receive this notification.

### `ASYNC_NOTIFICATION_FAILURE:0x06`

There was a problem sending this notification. None of the listeners on this channel are configured to receive this notification type or there was a problem allocating the resources necessary to complete this call.

### `NO_LISTENERS:0x07`

Indicates that there are no registered listening applications.

### `CHANNEL_ALREADY_CLOSED:0x08`

The channel has already been closed.

### `CHANNEL_ALREADY_OPENED:0x09`

The channel has already been opened.

### `CHANNEL_WAITING_FOR_CLIENT_NOTIFICATION:0x0a`

A notification cannot be sent because a response to the last notification has not been received.

### `CHANNEL_NOT_OPENED:0x0b`

The channel is not yet open.

### `ASYNC_CALL_ALREADY_PARKED:0x0c`

A notification cannot be sent because the recipient has not consumed the previous notification.

### `NOT_REGISTERED:0x0d`

The listening application is not registered for notifications of the specified type from the specified queue or print server.

### `ALREADY_UNREGISTERED:0x0e`

The listening application has already unregistered.

### `ALREADY_REGISTERED:0x0f`

The listening application has already registered for notifications of the specified type from the specified queue or print server.

### `CHANNEL_ACQUIRED:0x10`

Another listener on this channel has already responded. Only the first respondent can continue the communication with the sender.

### `ASYNC_CALL_IN_PROGRESS:0x11`

The channel is busy with another notification or response.

### `MAX_NOTIFICATION_SIZE_EXCEEDED:0x12`

The maximum size of the notification data has been exceeded. By default, the maximum data size allowed is 10 Megabytes.

### `INTERNAL_NOTIFICATION_QUEUE_IS_FULL:0x13`

The Print Spooler cannot hold any more queued notifications. By default, a maximum number of 10 notifications are allowed to be queued.

### `INVALID_NOTIFICATION_TYPE:0x14`

The specified notification type is invalid.

### `MAX_REGISTRATION_COUNT_EXCEEDED:0x15`

No more applications can register for this type of notification on the specified queue or print server. The maximum number of such registrations is 10,000 by default.

### `MAX_CHANNEL_COUNT_EXCEEDED:0x16`

The print spooler has already created the maximum number of channels and cannot create any more. The maximum number of channels the print spooler can create is 10,000 by default.

### `LOCAL_ONLY_REGISTRATION:0x17`

Registration for local notification was successful. Registration for remote notification was not.

### `REMOTE_ONLY_REGISTRATION:0x18`

Registration for remote notification was successful. Registration for local notification was not.