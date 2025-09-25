# WLAN_MSM_NOTIFICATION_DATA structure

## Description

The **WLAN_MSM_NOTIFICATION_DATA** structure contains information about media specific module (MSM) connection related notifications.

## Members

### `wlanConnectionMode`

A [WLAN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_connection_mode) value that specifies the mode of the connection.

### `strProfileName`

The name of the profile used for the connection. WLAN_MAX_NAME_LENGTH is 256. Profile names are case-sensitive. This string must be NULL-terminated.

### `dot11Ssid`

A [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that contains the SSID of the association.

### `dot11BssType`

A [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) value that indicates the BSS network type.

### `dot11MacAddr`

A [DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-mac-address-type) that specifies the MAC address of the peer or access point.

### `bSecurityEnabled`

Indicates whether security is enabled for this connection. If **TRUE**, security is enabled.

### `bFirstPeer`

Indicates whether the peer is the first to join the ad hoc network created by the machine. If **TRUE**, the peer is the first to join.

After the first peer joins the network, the interface state of the machine that created the ad hoc network changes from wlan_interface_state_ad_hoc_network_formed to wlan_interface_state_connected.

### `bLastPeer`

Indicates whether the peer is the last to leave the ad hoc network created by the machine. If **TRUE**, the peer is the last to leave. After the last peer leaves the network, the interface state of the machine that created the ad hoc network changes from wlan_interface_state_connected to wlan_interface_state_ad_hoc_network_formed.

### `wlanReasonCode`

A [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) that indicates the reason for an operation failure. If the operation succeeds, this field has a value of **WLAN_REASON_CODE_SUCCESS**. Otherwise, this field indicates the reason for the failure.

## Remarks

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_MSM**, then the received notification is a media specific module (MSM) notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback) function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure. For some of these notifications, a **WLAN_MSM_NOTIFICATION_DATA** structure is returned in the *pData* member of **WLAN_NOTIFICATION_DATA** structure.

For more information on these notifications, see the [WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1) enumeration reference.

## See also

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1)

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)