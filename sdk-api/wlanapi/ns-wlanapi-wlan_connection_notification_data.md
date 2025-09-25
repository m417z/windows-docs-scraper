# WLAN_CONNECTION_NOTIFICATION_DATA structure

## Description

The **WLAN_CONNECTION_NOTIFICATION_DATA** structure contains information about connection related notifications.

## Members

### `wlanConnectionMode`

A [WLAN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_connection_mode) value that specifies the mode of the connection.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_connection_mode_profile** value is supported.

### `strProfileName`

The name of the profile used for the connection. WLAN_MAX_NAME_LENGTH is 256. Profile names are case-sensitive. This string must be NULL-terminated.

### `dot11Ssid`

A [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that contains the SSID of the association.

### `dot11BssType`

A [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) value that indicates the BSS network type.

### `bSecurityEnabled`

Indicates whether security is enabled for this connection. If **TRUE**, security is enabled.

### `wlanReasonCode`

A [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) that indicates the reason for an operation failure. This field has a value of **WLAN_REASON_CODE_SUCCESS** for all connection-related notifications except **wlan_notification_acm_connection_complete**. If the connection fails, this field indicates the reason for the failure.

### `dwFlags`

A set of flags that provide additional information for the network connection.

This member can be one of the following values defined in the *Wlanapi.h* header file.

| Value | Meaning |
| --- | --- |
| **WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED** | Indicates that an adhoc network is formed. |
| **WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE** | Indicates that the connection uses a per-user profile owned by the console user. Non-console users will not be able to see the profile in their profile list. |

### `strProfileXml`

This field contains the XML presentation of the profile used for discovery, if the connection succeeds.

## Remarks

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_ACM**, then the received notification is an auto configuration module notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback) function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For some of these notifications, a **WLAN_CONNECTION_NOTIFICATION_DATA** structure is returned in the *pData* member of **WLAN_NOTIFICATION_DATA** structure.

For more information on these notifications, see the [WLAN_NOTIFICATION_ACM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_acm-r1) enumeration reference.

## See also

[WLAN_NOTIFICATION_ACM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_acm-r1)

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)