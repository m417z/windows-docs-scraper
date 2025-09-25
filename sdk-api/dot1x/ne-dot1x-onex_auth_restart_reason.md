# ONEX_AUTH_RESTART_REASON enumeration

## Description

The **ONEX_AUTH_RESTART_REASON** enumerated type specifies the possible reasons that 802.1X authentication was restarted.

## Constants

### `OneXRestartReasonPeerInitiated`

The EAPHost component (the peer) requested the 802.1x module to restart 802.1X authentication. This results from a [EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) function call that returns an [EapHostPeerResponseAction](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) enumeration value of **EapHostPeerResponseStartAuthentication** in the *pEapOutput* parameter.

### `OneXRestartReasonMsmInitiated`

The Media Specific Module (MSM) initiated the 802.1X authentication restart.

### `OneXRestartReasonOneXHeldStateTimeout`

The 802.1X authentication restart was the result of a state timeout. The timer expiring is the heldWhile timer of the 802.1X supplicant state machine defined in IEEE 802.1X - 2004 standard for Port-Based Network Access Control. The heldWhile timer is used by the supplicant state machine to define periods of time during which it
will not attempt to acquire an authenticator.

### `OneXRestartReasonOneXAuthTimeout`

The 802.1X authentication restart was the result of a state timeout. The timer expiring is the authWhile timer of the 802.1X supplicant port access entity defined in IEEE 802.1X - 2004 standard for Port-Based Network Access Control. The authWhile timer is used by the supplicant port access entity to determine how long to wait for a request from
the authenticator before timing it out.

### `OneXRestartReasonOneXConfigurationChanged`

The 802.1X authentication restart was the result of a configuration change to the current profile.

### `OneXRestartReasonOneXUserChanged`

The 802.1X authentication restart was the result of a change of user. This could occur if the current user logs off and new user logs on to the local computer.

### `OneXRestartReasonQuarantineStateChanged`

The 802.1X authentication restart was the result of receiving a notification from the EAP quarantine enforcement client (QEC) due to a network health change. If an EAPHost supplicant is participating in network access protection (NAP), the supplicant will respond to changes in the state of its network health. If that state changes, the supplicant must then initiate a re-authentication session. For more information, see the [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession) function.

### `OneXRestartReasonAltCredsTrial`

The 802.1X authentication restart was caused by a new authentication attempt with alternate user credentials. EAP methods like MSCHAPv2 prefer to use logged-on user credentials for 802.1X authentication. If these user credentials do not work, then a dialog will be displayed to the user that asks permission to use alternate credentials for 802.1X authentication. For more information, see the [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession) function and EAP_FLAG_PREFER_ALT_CREDENTIALS flag in the *dwflags* parameter.

### `OneXRestartReasonInvalid`

Indicates the end of the range that specifies the possible reasons that 802.1X authentication was restarted.

## Remarks

The **ONEX_AUTH_RESTART_REASON** enumerated type is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The **ONEX_AUTH_RESTART_REASON** specifies the possible values for the reason that 802.1X authentication was restarted. A value from this enumeration is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notifications is **OneXNotificationTypeAuthRestarted**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_AUTH_RESTART_REASON** enumeration value that identifies the reason the authentication was restarted.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession)

[EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerprocessreceivedpacket)

[EapHostPeerResponseAction](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)