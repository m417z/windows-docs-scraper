## Description

The **WLAN_NOTIFICATION_CALLBACK** callback function prototype defines the type of notification callback function.

## Parameters

### `unnamedParam1`

A pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure that contains the notification information.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the wlan_notification_acm_connection_complete and wlan_notification_acm_disconnected notifications are available.

### `unnamedParam2`

A pointer to the context information provided by the client when it registered for the notification.

## Remarks

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the **WLAN_NOTIFICATION_CALLBACK**. This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification. The callback function also receives a second parameter that contains a pointer to the client context passed in the *pCallbackContext* parameter to the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function. This client context can be a **NULL** pointer if that is what was passed to the **WlanRegisterNotification** function.

Once registered, the callback function will be called whenever a notification is available until the client unregisters or closes the handle.

Any registration to receive notifications is automatically undone if the calling application closes its calling handle (by calling [WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle) with the *hClientHandle* parameter) used to register for notifications with the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function or if the process ends.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_ACM**, then the received notification is an auto configuration module notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the **WLAN_NOTIFICATION_CALLBACK** function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For more information on these notifications, see the [WLAN_NOTIFICATION_ACM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_acm-r1) enumeration reference.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_hosted_network_notification_code) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_HNWK**, then the received notification is a wireless Hosted Network notification supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the **WLAN_NOTIFICATION_CALLBACK** function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For more information on these notifications, see the [WLAN_HOSTED_NETWORK_NOTIFICATION_CODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_notification_code) enumeration reference.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_IHV**, then the received notification is an independent hardware vendor (IHV) notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the **WLAN_NOTIFICATION_CALLBACK** function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure, which is specific to the IHV.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_ONEX**, then the received notification is an 802.1X module notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the **WLAN_NOTIFICATION_CALLBACK** function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For more information on these notifications, see the [ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type) enumeration reference.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_MSM**, then the received notification is a media specific module (MSM) notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the **WLAN_NOTIFICATION_CALLBACK** function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For more information on these notifications, see the [WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1) enumeration reference.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_SECURITY**, then the received notification is a security notification. No notifications are currently defined for **WLAN_NOTIFICATION_SOURCE_SECURITY**.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Notifications are handled by the Netman service. If the Netman service is disabled or unavailable, notifications will not be received. If a notification is not received within a reasonable period of time, an application should time out and query the current interface state.

## See also

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[WLAN_HOSTED_NETWORK_NOTIFICATION_CODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_hosted_network_notification_code)

[WLAN_NOTIFICATION_ACM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_acm-r1)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1)

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)