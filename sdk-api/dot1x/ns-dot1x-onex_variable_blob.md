# ONEX_VARIABLE_BLOB structure

## Description

The **ONEX_VARIABLE_BLOB** structure is used as a member of other 802.1X authentication structures to contain variable-sized members.

## Members

### `dwSize`

The size, in bytes, of this **ONEX_VARIABLE_BLOB** structure.

### `dwOffset`

The offset, in bytes, from the beginning of the containing outer structure (where the **ONEX_VARIABLE_BLOB** structure is a member) to the data contained in the **ONEX_VARIABLE_BLOB** structure.

## Remarks

The **ONEX_VARIABLE_BLOB** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

A number of the nested structure members in the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure contains members of the **ONEX_VARIABLE_BLOB** type.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_AUTH_PARAMS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params)

[ONEX_EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_eap_error)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)