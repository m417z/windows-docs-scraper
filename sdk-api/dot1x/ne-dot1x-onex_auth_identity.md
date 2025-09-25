# ONEX_AUTH_IDENTITY enumeration

## Description

The **ONEX_AUTH_IDENTITY** enumerated type specifies the possible values of the identity used for 802.1X authentication status.

## Constants

### `OneXAuthIdentityNone`

No identity is specified in the profile used for 802.1X authentication.

### `OneXAuthIdentityMachine`

The identity of the local machine account is used for 802.1X authentication.

### `OneXAuthIdentityUser`

The identity of the logged-on user is used for 802.1X authentication.

### `OneXAuthIdentityExplicitUser`

The identity of an explicit user as specified in the profile is used for 802.1X authentication. This value is used when performing single signon or when credentials are saved with the profile.

### `OneXAuthIdentityGuest`

The identity of the Guest account as specified in the profile is used for 802.1X authentication.

### `OneXAuthIdentityInvalid`

The identity is not valid as specified in the profile used for 802.1X authentication.

## Remarks

The **ONEX_AUTH_IDENTITY** enumerated type is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The **ONEX_AUTH_IDENTITY** specifies the possible values of the identity used for 802.1X authentication. The **ONEX_AUTH_IDENTITY** is a function of the
802.1X authentication mode selected and various system triggers (user logon and logoff operations, for example).

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

If the **fOneXAuthParams** member in the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is set, then the **authParams** member of the **ONEX_RESULT_UPDATE_DATA** structure contains an [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) structure with an [ONEX_AUTH_PARAMS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params) structure embedded starting at the **dwOffset** member of the **ONEX_VARIABLE_BLOB**. This **ONEX_AUTH_PARAMS** structure that contains a value from the **ONEX_AUTH_IDENTITY** enumeration in the **authIdentity** member.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_AUTH_PARAMS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)