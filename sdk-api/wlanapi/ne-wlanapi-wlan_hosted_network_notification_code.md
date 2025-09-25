# WLAN_HOSTED_NETWORK_NOTIFICATION_CODE enumeration

## Description

The **WLAN_HOSTED_NETWORK_NOTIFICATION_CODE** enumerated type specifies the possible values of the NotificationCode parameter for received notifications on the wireless Hosted Network.

## Constants

### `wlan_hosted_network_state_change`

The Hosted Network state has changed.

### `wlan_hosted_network_peer_state_change`

The Hosted Network peer state has changed.

### `wlan_hosted_network_radio_state_change`

The Hosted Network radio state has changed.

### `v1_enum`

## Remarks

The **WLAN_HOSTED_NETWORK_NOTIFICATION_CODE** enumerated type is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

The **WLAN_HOSTED_NETWORK_NOTIFICATION_CODE** specifies the possible values for the NotificationCode parameter for received notifications when the NotificationSource parameter is WLAN_NOTIFICATION_SOURCE_HNWK on the wireless Hosted Network.

The starting value for the **WLAN_HOSTED_NETWORK_NOTIFICATION_CODE** enumeration is defined as L2_NOTIFICATION_CODE_V2_BEGIN, which is defined in the *l2cmn.h* header file. Note that the *l2cmn.h* header is automatically included by the *wlanapi.h* header file.

The [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function is used by an application to register and unregister notifications on all wireless interfaces. When registering for notifications, an application must provide a callback function pointed to by the *funcCallback* parameter passed to the **WlanRegisterNotification** function. The prototype for this callback function is the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback). This callback function will receive notifications that have been registered in the *dwNotifSource* parameter passed to the **WlanRegisterNotification** function.

The callback function is called with a pointer to a [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure as the first parameter that contains detailed information on the notification. The callback function also receives a second parameter that contains a pointer to the client context passed in the *pCallbackContext* parameter to the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function. This client context can be a **NULL** pointer if that is what was passed to the **WlanRegisterNotification** function.

If the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure received by the callback function is **WLAN_NOTIFICATION_SOURCE_HNWK**, then the received notification is a wireless Hosted Network notification. The **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure passed to the [WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback) function determines the interpretation of the *pData* member of **WLAN_NOTIFICATION_DATA** structure.

| **NotificationCode** | Description |
| --- | --- |
| wlan_hosted_network_state_change | The *pData* member of [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure should be cast to a pointer to a [WLAN_HOSTED_NETWORK_STATE_CHANGE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_state_change) structure and **dwDataSize** member would be at least as large as sizeof(**WLAN_HOSTED_NETWORK_STATE_CHANGE**). |
| wlan_hosted_network_peer_state_change | the *pData* member of [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_data_peer_state_change) structure should be cast to a pointer to a [WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_data_peer_state_change) structure and **dwDataSize** member would be at least as large as sizeof(**WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE**). |
| wlan_hosted_network_radio_state_change | the *pData* member of [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure should be cast to a pointer to a [WLAN_HOSTED_NETWORK_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_radio_state) structure and **dwDataSize** member would be at least as large as sizeof(**WLAN_HOSTED_NETWORK_RADIO_STATE** ). |

## See also

[WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_data_peer_state_change)

[WLAN_HOSTED_NETWORK_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_radio_state)

[WLAN_HOSTED_NETWORK_STATE_CHANGE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_state_change)

[WLAN_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/wlanapi/nc-wlanapi-wlan_notification_callback)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)