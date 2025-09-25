# ONEX_NOTIFICATION_TYPE enumeration

## Description

The **ONEX_NOTIFICATION_TYPE** enumerated type specifies the possible values of the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for 802.1X module notifications.

## Constants

### `OneXPublicNotificationBase:0`

Indicates the beginning of the range that specifies the possible values for 802.1X notifications.

### `OneXNotificationTypeResultUpdate`

Indicates that 802.1X authentication has a status change.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure that contains 802.1X update data.

### `OneXNotificationTypeAuthRestarted`

Indicates that 802.1X authentication restarted.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to an [ONEX_AUTH_RESTART_REASON](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_auth_restart_reason) enumeration value that identifies the reason the authentication was restarted.

### `OneXNotificationTypeEventInvalid`

Indicates the end of the range that specifies the possible values for 802.1X notifications.

### `OneXNumNotifications`

Indicates the end of the range that specifies the possible values for 802.1X notifications.

## Remarks

The **ONEX_NOTIFICATION_TYPE** enumerated type is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The **ONEX_NOTIFICATION_TYPE** specifies the possible values for the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for received notifications when the **NotificationSource** member of the **WLAN_NOTIFICATION_DATA** structure is **WLAN_NOTIFICATION_SOURCE_ONEX**.

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification. The callback function also receives a second parameter that contains a pointer to the client context passed in the *pCallbackContext* parameter to the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function. This client context can be a **NULL** pointer if that is what was passed to the **WlanRegisterNotification** function.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_AUTH_RESTART_REASON](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_auth_restart_reason)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)