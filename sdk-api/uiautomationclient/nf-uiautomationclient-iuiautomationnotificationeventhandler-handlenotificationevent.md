# IUIAutomationNotificationEventHandler::HandleNotificationEvent

## Description

Handles a Microsoft UI Automation notification event.

## Parameters

### `sender` [in]

A pointer to the element that raised the event.

### `notificationKind`

The type of notification.

### `notificationProcessing`

Indicates how to process notifications.

### `displayString`

A string to display in the notification message.

### `activityId`

A unique non-localized string to identify an action or group of actions. This is used to pass additional information to the event handler.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that it has subscribed to by calling [AddNotificationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation5-addnotificationeventhandler).

## See also

[IUIAutomationNotificationEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationnotificationeventhandler)