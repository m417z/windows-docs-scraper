# ONEX_EAP_METHOD_BACKEND_SUPPORT enumeration

## Description

The **ONEX_EAP_METHOD_BACKEND_SUPPORT** enumerated type specifies the possible values for whether the EAP method configured on the supplicant for 802.1X authentication is supported on the authentication server.

## Constants

### `OneXEapMethodBackendSupportUnknown`

It is not known whether the EAP method configured on the supplicant for 802.1X authentication is supported on the authentication server. This value can be returned if the 802.1X authentication process is in the initial state.

### `OneXEapMethodBackendSupported`

The EAP method configured on the supplicant for 802.1X authentication is supported on the authentication server. The 802.1X handshake is used to decide what is an acceptable EAP method to use.

### `OneXEapMethodBackendUnsupported`

The EAP method configured on the supplicant for 802.1X authentication is not supported on the authentication server.

## Remarks

The **ONEX_EAP_METHOD_BACKEND_SUPPORT** enumeration is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

The **BackendSupport** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) struct contains a value from the **ONEX_EAP_METHOD_BACKEND_SUPPORT** enumeration.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)