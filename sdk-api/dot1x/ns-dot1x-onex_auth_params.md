# ONEX_AUTH_PARAMS structure

## Description

The **ONEX_AUTH_PARAMS** structure contains 802.1X authentication parameters used for 802.1X authentication.

## Members

### `fUpdatePending`

Indicates if a status update is pending for 802.X authentication.

### `oneXConnProfile`

The 802.1X authentication connection profile. This member contains an embedded [ONEX_CONNECTION_PROFILE](https://learn.microsoft.com/windows/desktop/NativeWiFi/onex-connection-profile) structure starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob).

### `authIdentity`

The identity used for 802.1X authentication status. This member is a value from the [ONEX_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_auth_identity) enumeration.

### `dwQuarantineState`

The quarantine isolation state value of the local computer. The isolation state determines its network connectivity. This member corresponds to a value from the EAPHost [ISOLATION_STATE](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-isolation_state) enumeration.

### `fSessionId`

Indicates if the **ONEX_AUTH_PARAMS** structure contains a session ID in the **dwSessionId** member.

### `fhUserToken`

Indicates if the **ONEX_AUTH_PARAMS** structure contains a user token handle in the **hUserToken** member.

For security reasons, the **hUserToken** member of the **ONEX_AUTH_PARAMS** structure returned in the **authParams** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is always set to **NULL**.

### `fOnexUserProfile`

Indicates if the **ONEX_AUTH_PARAMS** structure contains an 802.1X user profile in the **OneXUserProfile** member.

For security reasons, the **OneXUserProfile** member of the **ONEX_AUTH_PARAMS** structure returned in the **authParams** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is always set to **NULL**.

### `fIdentity`

Indicates if the **ONEX_AUTH_PARAMS** structure contains an 802.1X identity in the **Identity** member.

### `fUserName`

Indicates if the **ONEX_AUTH_PARAMS** structure contains a user name used for 802.1X authentication in the **UserName** member.

### `fDomain`

Indicates if the **ONEX_AUTH_PARAMS** structure contains a domain used for 802.1X authentication in the **Domain** member.

### `dwSessionId`

The session ID of the user currently logged on to the console. This member corresponds to the value returned by the [WTSGetActiveConsoleSessionId](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wtsgetactiveconsolesessionid) function. This member contains a session ID if the **fSessionId** bitfield member is set.

### `hUserToken`

The user token handle used for 802.1X authentication. This member contains a user token handle if the **fhUserToken** bitfield member is set.

For security reasons, the **hUserToken** member of the **ONEX_AUTH_PARAMS** structure returned in the **authParams** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is always set to **NULL**.

### `OneXUserProfile`

The 802.1X user profile used for 802.1X authentication. This member contains an embedded user profile starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fOneXUserProfile** bitfield member is set.

For security reasons, the **OneXUserProfile** member of the **ONEX_AUTH_PARAMS** structure returned in the **authParams** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is always set to **NULL**.

### `Identity`

The 802.1X identity used for 802.1X authentication. This member contains a NULL-terminated Unicode string with the identity starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fIdentity** bitfield member is set.

### `UserName`

The user name used for 802.1X authentication. This member contains a NULL-terminated Unicode string with the user name starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fUserName** bitfield member is set.

### `Domain`

The domain used for 802.1X authentication. This member contains a NULL-terminated Unicode string with the domain starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fDomain** bitfield member is set.

## Remarks

The **ONEX_AUTH_PARAMS** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

If the **fOneXAuthParams** member in the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is set, then the **authParams** member of the **ONEX_RESULT_UPDATE_DATA** structure contains an [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) structure with an **ONEX_AUTH_PARAMS** structure embedded starting at the **dwOffset** member of the **ONEX_VARIABLE_BLOB**.

For security reasons, the **hUserToken** and **OneXUserProfile** members of the **ONEX_AUTH_PARAMS** structure returned in the **authParams** member are always set to **NULL**.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ISOLATION_STATE](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-isolation_state)

[ONEX_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_auth_identity)

**ONEX_EAP_ERROR**

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WTSGetActiveConsoleSessionId](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wtsgetactiveconsolesessionid)

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)