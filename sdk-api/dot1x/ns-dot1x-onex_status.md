# ONEX_STATUS structure

## Description

The **ONEX_STATUS** structure contains the current 802.1X authentication status.

## Members

### `authStatus`

The current status of the 802.1X authentication process. Any error that may have occurred during authentication is indicated below by the value of the **dwReason** and **dwError** members of the **ONEX_STATUS** structure. For more information, see the [ONEX_AUTH_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_auth_status) enumeration.

### `dwReason`

If an error occurred during 802.1X authentication, this member contains the reason for the error specified as a value from the [ONEX_REASON_CODE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_reason_code) enumeration. This member is normally **ONEX_REASON_CODE_SUCCESS**
when 802.1X authentication is successful and no error occurs.

### `dwError`

If an error occurred during 802.1X authentication, this member contains the error. This member is normally NO_ERROR, except when an EAPHost error occurs.

## Remarks

The **ONEX_STATUS** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

The **oneXStatus** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure contains an **ONEX_STATUS** structure.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_REASON_CODE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_reason_code)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)