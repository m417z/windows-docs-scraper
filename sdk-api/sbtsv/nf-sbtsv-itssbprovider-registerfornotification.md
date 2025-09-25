# ITsSbProvider::RegisterForNotification

## Description

Requests that Remote Desktop Connection Broker (RD Connection Broker) send notifications about specified events.

Plug-ins can use this method to request notifications about events.

## Parameters

### `notificationType` [in]

The type of notification to receive. To receive notifications for more than one type, specify the enumerations by using a logical **OR**.

#### TSSB_NOTIFY_TARGET_CHANGE

The owner plug-in has recognized a change in the target's state.

#### TSSB_NOTIFY_SESSION_CHANGE

The owner plug-in has recognized a change in the session's state.

#### TSSB_NOTIFY_CONNECTION_REQUEST_CHANGE

RD Connection Broker has created a connection, or completed a connection request due to a successful logon, time-out, or connection failure.

### `ResourceToMonitor` [in]

This parameter is reserved.

### `pPluginNotification` [in]

A pointer to an [ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification) plug-in notification object that RD Connection Broker should use for notifications.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)