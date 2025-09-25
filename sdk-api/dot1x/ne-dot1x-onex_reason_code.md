# ONEX_REASON_CODE enumeration

## Description

The **ONEX_REASON_CODE** enumerated type specifies the possible values that indicate the reason that 802.1X authentication failed.

## Constants

### `ONEX_REASON_CODE_SUCCESS:0`

Indicates the 802.1X authentication was a success.

### `ONEX_REASON_START`

Indicates the start of the range that specifies the possible values for 802.1X reason code.

### `ONEX_UNABLE_TO_IDENTIFY_USER`

The 802.1X module was unable to identify a set of credentials to be used. An example is when the authentication mode is set to user, but no user is logged on.

### `ONEX_IDENTITY_NOT_FOUND`

The EAP module was unable to acquire an identity for the user. Thus value is not currently used. All EAP-specific errors are returned as **ONEX_EAP_FAILURE_RECEIVED**.

### `ONEX_UI_DISABLED`

To proceed with 802.1X authentication, the system needs to request user input, but the user interface is disabled. On Windows Vista and on Windows Server 2008, this value can be returned if an EAP method requested user input for a profile for Guest or local machine authentication. On Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed, this value should not be returned.

### `ONEX_UI_FAILURE`

The 802.1X authentication module was unable to return the requested user input. On Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed, this value can be returned if an EAP method requested user input, but the UI could not be displayed (the network icon was configured to not show in the taskbar, for example).

### `ONEX_EAP_FAILURE_RECEIVED`

The EAP module returned an error code. The [ONEX_EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_eap_error) structure may contain additional information about the specific EAP error (a certificate not found, for example).

### `ONEX_AUTHENTICATOR_NO_LONGER_PRESENT`

The peer with which the 802.1X module was negotiating is no longer present or is not responding (a laptop client moved out of range of the wireless access point, for example).

### `ONEX_NO_RESPONSE_TO_IDENTITY`

No response was received to an EAP identity response packet. This value indicates a problem with the infrastructure (a link between the wireless access point and the authentication server is not functioning, for example).

### `ONEX_PROFILE_VERSION_NOT_SUPPORTED`

The 802.1X module does not support this version of the profile.

### `ONEX_PROFILE_INVALID_LENGTH`

The length member specified in the 802.1X profile is invalid.

### `ONEX_PROFILE_DISALLOWED_EAP_TYPE`

The EAP type specified in the 802.1X profile is not allowed for this media. An example is when the keyed MD5 algorithm is used for wireless transmission.

### `ONEX_PROFILE_INVALID_EAP_TYPE_OR_FLAG`

The EAP type or EAP flags specified in the 802.1X profile are not valid. An example is when EAP type is not installed on the system.

### `ONEX_PROFILE_INVALID_ONEX_FLAGS`

The 802.1X flags specified in the 802.1X profile are not valid.

### `ONEX_PROFILE_INVALID_TIMER_VALUE`

One or more timer values specified in the 802.1X profile is out of its valid range.

### `ONEX_PROFILE_INVALID_SUPPLICANT_MODE`

The supplicant mode specified in the 802.1X profile is not valid.

### `ONEX_PROFILE_INVALID_AUTH_MODE`

The authentication mode specified in the 802.1X profile is not valid.

### `ONEX_PROFILE_INVALID_EAP_CONNECTION_PROPERTIES`

The EAP connection properties specified in the 802.1X profile are not valid.

### `ONEX_UI_CANCELLED`

User input was canceled. This value can be returned if an EAP method requested user input, but the user hit the Cancel button or dismissed the user input dialog.

This value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

### `ONEX_PROFILE_INVALID_EXPLICIT_CREDENTIALS`

The saved user credentials are not valid. This value can be returned if a profile was saved with bad credentials (an incorrect password, for example), since the credentials are not tested until the profile is actually used to establish a connection.

This value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

### `ONEX_PROFILE_EXPIRED_EXPLICIT_CREDENTIALS`

The saved user credentials have expired. This value can be returned if a profile was saved with credentials and the credentials subsequently expired (password expiration after some period of time, for example).

This value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

### `ONEX_UI_NOT_PERMITTED`

User interface is not permitted. On Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed, this value can be returned if an EAP method requested user input and the profile is configured with user credentials saved by another user and not the currently logged in user.

This value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

## Remarks

The **ONEX_REASON_CODE** enumerated type is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

The **oneXStatus** member of the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure contains an [ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status) structure. If an error occurred during 802.1X authentication, the dwReason member of this **ONEX_STATUS** structure contains the reason for the error specified as a value from the **ONEX_REASON_CODE** enumeration.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[ONEX_STATUS](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_status)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)