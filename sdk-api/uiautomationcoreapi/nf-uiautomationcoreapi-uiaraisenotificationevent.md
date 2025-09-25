# UiaRaiseNotificationEvent function

## Description

Called by providers to initiate a notification event.

## Parameters

### `provider` [in]

The provider node where the notification event occurred.

### `notificationKind`

The type of notification, as a [NotificationKind enumeration](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-notificationkind) value.

### `notificationProcessing`

The preferred way to process a notification, as a [NotificationProcessing enumeration](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-notificationprocessing) value.

### `displayString` [in, optional]

A string to display in the notification message.

### `activityId` [in]

A unique non-localized string to identify an action or group of actions. Use this to pass additional information to the event handler.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

If your window uses the [`WS_POPUP`](https://learn.microsoft.com/windows/win32/winmsg/window-styles) style, it must also implement the [Window Control Pattern](https://learn.microsoft.com/windows/win32/winauto/uiauto-implementingwindow) and handle the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message (see [How to Expose a Server-Side UI Automation Provider](https://learn.microsoft.com/windows/win32/winauto/uiauto-howto-expose-serverside-uiautomation-provider) for more details).