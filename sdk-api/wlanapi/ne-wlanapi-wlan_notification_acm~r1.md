# WLAN_NOTIFICATION_ACM enumeration

## Description

The **WLAN_NOTIFICATION_ACM** enumerated type specifies the possible values of the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for Auto Configuration Module (ACM) notifications.

## Constants

### `wlan_notification_acm_start`

Indicates the beginning of the range that specifies the possible values for ACM notifications.

### `wlan_notification_acm_autoconf_enabled`

Autoconfiguration is enabled.

### `wlan_notification_acm_autoconf_disabled`

Autoconfiguration is disabled.

### `wlan_notification_acm_background_scan_enabled`

Background scans are enabled.

### `wlan_notification_acm_background_scan_disabled`

Background scans are disabled.

### `wlan_notification_acm_bss_type_change`

The BSS type for an interface has changed.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) enumeration value that identifies the new basic service set (BSS) type.

### `wlan_notification_acm_power_setting_change`

The power setting for an interface has changed.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_POWER_SETTING](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_power_setting-r1) enumeration value that identifies the new power setting of an interface.

### `wlan_notification_acm_scan_complete`

A scan for networks has completed.

### `wlan_notification_acm_scan_fail`

A scan for connectable networks failed.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) data type value that identifies the reason the WLAN operation failed.

### `wlan_notification_acm_connection_start`

A connection has started to a network in range.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data) structure that identifies the network information for the connection attempt.

### `wlan_notification_acm_connection_complete`

A connection has completed.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data) structure that identifies the network information for the connection attempt that completed. The connection succeeded if the **wlanReasonCode** in **WLAN_CONNECTION_NOTIFICATION_DATA** is **WLAN_REASON_CODE_SUCCESS**. Otherwise, the connection has failed.

### `wlan_notification_acm_connection_attempt_fail`

A connection attempt has failed.

A connection consists of one or more connection attempts. An application may receive zero or more **wlan_notification_acm_connection_attempt_fail**  notifications between receiving the **wlan_notification_acm_connection_start** notification and the **wlan_notification_acm_connection_complete** notification.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data) structure that identifies the network information for the connection attempt that failed.

### `wlan_notification_acm_filter_list_change`

A change in the filter list has occurred, either through group policy or a call to the [WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist) function.

An application can call the [WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist) function to retrieve the new filter list.

### `wlan_notification_acm_interface_arrival`

A wireless LAN interface is been added to or enabled on the local computer.

### `wlan_notification_acm_interface_removal`

A wireless LAN interface is been removed from or disabled on the local computer.

### `wlan_notification_acm_profile_change`

A change in a profile or the profile list has occurred, either through group policy or by calls to Native Wifi functions.

An application can call the [WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist) and [WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile) functions to retrieve the updated profiles. The interface on which the profile list changes is identified by the **InterfaceGuid** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure.

### `wlan_notification_acm_profile_name_change`

A profile name has changed, either through group policy or by calls to Native Wifi functions.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a buffer that contains two NULL-terminated WCHAR strings, the old profile name followed by the new profile name.

### `wlan_notification_acm_profiles_exhausted`

All profiles were exhausted in an attempt to autoconnect.

### `wlan_notification_acm_network_not_available`

The wireless service cannot find any connectable network after a scan.

The interface on which no connectable network is found is identified by identified by the **InterfaceGuid** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure.

### `wlan_notification_acm_network_available`

The wireless service found a connectable network after a scan, the interface was in the disconnected state, and there is no compatible auto-connect profile that the wireless service can use to connect .

The interface on which connectable networks are found is identified by the **InterfaceGuid** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure.

### `wlan_notification_acm_disconnecting`

The wireless service is disconnecting from a connectable network.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data) structure that identifies the network information for the connection that is disconnecting.

### `wlan_notification_acm_disconnected`

The wireless service has disconnected from a connectable network.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data) structure that identifies the network information for the connection that disconnected.

### `wlan_notification_acm_adhoc_network_state_change`

A state change has occurred for an adhoc network.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_ADHOC_NETWORK_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_adhoc_network_state-r1) enumeration value that identifies the new adhoc network state.

### `wlan_notification_acm_profile_unblocked`

This value is supported on Windows 8 and later.

### `wlan_notification_acm_screen_power_change`

The screen power has changed.

The **pData** member points to a **BOOL** value that indicates the value of the screen power change. When this value is **TRUE**, the screen changed to on. When this value is **FALSE**, the screen changed to off.

This value is supported on Windows 8 and later.

### `wlan_notification_acm_profile_blocked`

This value is supported on Windows 8 and later.

### `wlan_notification_acm_scan_list_refresh`

This value is supported on Windows 8 and later.

### `wlan_notification_acm_operational_state_change`

### `wlan_notification_acm_end`

Indicates the end of the range that specifies the possible values for ACM notifications.

## Remarks

The **WLAN_NOTIFICATION_ACM** enumerated type is used by the Auto Configuration Module, the new wireless configuration component supported on Windows Vista and later.

The **WLAN_NOTIFICATION_ACM** specifies the possible values for the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for received notifications when the **NotificationSource** member of the **WLAN_NOTIFICATION_DATA** structure is **WLAN_NOTIFICATION_SOURCE_ACM**.

The starting value for the **WLAN_NOTIFICATION_ACM** enumeration is defined as L2_NOTIFICATION_CODE_V2_BEGIN in the *l2cmn.h* header file. Note that the *l2cmn.h* header is automatically included by the *wlanapi.h* header file.

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification. The callback function also receives a second parameter that contains a pointer to the client context passed in the *pCallbackContext* parameter to the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function. This client context can be a **NULL** pointer if that is what was passed to the **WlanRegisterNotification** function.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_notification_acm_connection_complete** and **wlan_notification_acm_disconnected** notifications are available.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type)

[WLAN_ADHOC_NETWORK_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_adhoc_network_state-r1)

[WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data)

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WLAN_POWER_SETTING](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_power_setting-r1)

[WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist)