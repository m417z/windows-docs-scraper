# ONEX_RESULT_UPDATE_DATA structure

## Description

The **ONEX_RESULT_UPDATE_DATA** structure contains information on a status change to 802.1X authentication.

## Members

### `oneXStatus`

Specifies the current 802.1X authentication status. For more information, see the [ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status) structure.

### `BackendSupport`

Indicates if the configured EAP method on the supplicant is supported on the 802.1X authentication server.

EAP permits the use of a backend
authentication server, which may implement some or all authentication
methods, with the authenticator acting as a pass-through for some or
all methods and peers. For more information, see RFC 3748 published by the IETF and the [ONEX_EAP_METHOD_BACKEND_SUPPORT](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_eap_method_backend_support) enumeration.

### `fBackendEngaged`

Indicates if a response was received from the 802.1X authentication server.

### `fOneXAuthParams`

Indicates if the **ONEX_RESULT_UPDATE_DATA** structure contains 802.1X authentication parameters in the **authParams** member.

### `fEapError`

Indicates if the **ONEX_RESULT_UPDATE_DATA** structure contains an EAP error in the **eapError** member.

### `authParams`

The 802.1X authentication parameters. This member contains an embedded [ONEX_AUTH_PARAMS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params) structure starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fOneXAuthParams** bitfield member is set.

### `eapError`

An EAP error value. This member contains an embedded [ONEX_EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_eap_error) structure starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fEapError** bitfield member is set.

## Remarks

The **ONEX_RESULT_UPDATE_DATA** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The **ONEX_RESULT_UPDATE_DATA** contains information on a status change to 802.1X authentication.This structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_AUTH_PARAMS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params)

[ONEX_EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_eap_error)

[ONEX_EAP_METHOD_BACKEND_SUPPORT](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_eap_method_backend_support)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status)

[ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)