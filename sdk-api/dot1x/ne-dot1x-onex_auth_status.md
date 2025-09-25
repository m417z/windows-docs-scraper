# ONEX_AUTH_STATUS enumeration

## Description

The **ONEX_AUTH_STATUS** enumerated type specifies the possible values for the 802.1X authentication status.

## Constants

### `OneXAuthNotStarted`

802.1X authentication was not started.

### `OneXAuthInProgress`

802.1X authentication is in progress.

### `OneXAuthNoAuthenticatorFound`

No 802.1X authenticator was found. The 802.1X authentication was attempted, but no 802.1X peer was found. In this case, either the network does not support or is not configured to support the 802.1X standard.

### `OneXAuthSuccess`

802.1X authentication was successful.

### `OneXAuthFailure`

802.1X authentication was a failure.

### `OneXAuthInvalid`

Indicates the end of the range that specifies the possible values for 802.1X authentication status.

## Remarks

The **ONEX_AUTH_STATUS** enumerated type is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The **ONEX_AUTH_STATUS** specifies the possible values for the 802.1X authentication status. A value from this enumeration is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notifications is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure that contains a [ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status) structure member in the **oneXStatus** structure member. The **ONEX_STATUS** structure contains a **ONEX_AUTH_STATUS** enumeration value in the **authStatus** member.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)