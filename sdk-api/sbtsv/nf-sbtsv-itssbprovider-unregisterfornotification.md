# ITsSbProvider::UnRegisterForNotification

## Description

Requests that Remote Desktop Connection Broker (RD Connection Broker) not send notifications about specified events.

## Parameters

### `notificationType` [in]

Specifies the type of notification. To specify more than one type, use a logical **OR**.

#### TSSB_NOTIFY_TARGET_CHANGE

The owner plug-in has recognized a change in the change in the target's state.

#### TSSB_NOTIFY_SESSION_CHANGE

The owner plug-in has recognized a change in the change in the session's state.

#### TSSB_NOTIFY_CONNECTION_REQUEST_CHANGE

RD Connection Broker has created a connection, or completed a connection request due to a successful logon, time-out, or connection failure.

### `ResourceToMonitor` [in]

This parameter is reserved.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins can use the **UnRegisterForNotification** method to cancel previous requests for notifications.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)