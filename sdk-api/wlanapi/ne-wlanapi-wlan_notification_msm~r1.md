# WLAN_NOTIFICATION_MSM enumeration

## Description

The **WLAN_NOTIFICATION_MSM** enumerated type specifies the possible values of the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for Media Specific Module (MSM) notifications.

## Constants

### `wlan_notification_msm_start`

The beginning of the range that specifies the possible values for ACM notifications.

### `wlan_notification_msm_associating`

A wireless device is in the process of associating with an access point or a peer station.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_associated`

The wireless device has associated with an access point or a peer station.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_authenticating`

The wireless device is in the process of authenticating.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_connected`

The wireless device is associated with an access point or a peer station, keys have been exchanged, and the wireless device is available to send data.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_roaming_start`

The wireless device is connected to an access point and has initiated roaming to another access point.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_roaming_end`

The wireless device was connected to an access point and has completed roaming to another access point.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_radio_state_change`

The radio state for an adapter has changed. Each physical layer (PHY) has its own radio state. The radio for an adapter is switched off when the radio state of every PHY is off.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) structure that identifies the new radio state.

### `wlan_notification_msm_signal_quality_change`

A signal quality change for the currently associated access point or peer station.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a ULONG WLAN_SIGNAL_QUALITY that identifies the new signal quality.

### `wlan_notification_msm_disassociating`

A wireless device is in the process of disassociating from an access point or a peer station.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_disconnected`

The wireless device is not associated with an access point or a peer station.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information. The **wlanReasonCode** member of the **WLAN_MSM_NOTIFICATION_DATA** structure indicates the reason for the disconnect.

### `wlan_notification_msm_peer_join`

A peer has joined an adhoc network.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_peer_leave`

A peer has left an adhoc network.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_adapter_removal`

A wireless adapter has been removed from the local computer.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a [WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data) structure that contains connection-related information.

### `wlan_notification_msm_adapter_operation_mode_change`

The operation mode of the wireless device has changed.

The **pData** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure points to a ULONG that identifies the new operation mode.

### `wlan_notification_msm_link_degraded`

### `wlan_notification_msm_link_improved`

### `wlan_notification_msm_end`

Indicates the end of the range that specifies the possible values for MSM notifications.

## Remarks

The [WLAN_NOTIFICATION_ACM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_acm-r1) enumerated type is used by the Media Specific Module, the new wireless configuration component supported on Windows Vista and later.

The **WLAN_NOTIFICATION_MSM** specifies the possible values for the **NotificationCode** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure for received notifications when the **NotificationSource** member of the **WLAN_NOTIFICATION_DATA** structure is **WLAN_NOTIFICATION_SOURCE_MSM**.

The starting value for the **WLAN_NOTIFICATION_MSM** enumeration is defined as L2_NOTIFICATION_CODE_PUBLIC_BEGIN in the *l2cmn.h* header file. Note that the *l2cmn.h* header is automatically included by the *wlanapi.h* header file.

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification. The callback function also receives a second parameter that contains a pointer to the client context passed in the *pCallbackContext* parameter to the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function. This client context can be a **NULL** pointer if that is what was passed to the **WlanRegisterNotification** function.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[WLAN_MSM_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_msm_notification_data)

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)