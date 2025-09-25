# L2_NOTIFICATION_DATA structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-wireless-lan4) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The L2_NOTIFICATION_DATA structure is used by the IHV Extensions DLL to send notifications to any
service or applications that has registered for the notification.

## Members

### `NotificationSource`

This member specifies where the notification comes from. The IHV Extensions DLL must set this
member to L2_NOTIFICATION_SOURCE_WLAN_IHV.

### `NotificationCode`

This member specifies the notification code for the status indication. This notification code must not have the bit 0x10000 set.

### `InterfaceGuid`

The globally unique identifier (GUID) for the wireless LAN (WLAN) adapter.

The operating system passes the GUID and other data related to the WLAN adapter through the
*pDot11Adapter* parameter of the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wlanihv/nc-wlanihv-dot11extihv_init_adapter) function, which the operating system calls when it detects the arrival of
the WLAN adapter. For more information about this operation, see
[802.11 WLAN Adapter
Arrival](https://learn.microsoft.com/windows/desktop/api/l2cmn/ns-l2cmn-l2_notification_data).

### `dwDataSize`

The length, in bytes, of the data within the buffer referenced by the
**pData** member. The IHV Extensions DLL must set this member to zero if additional data is not
required for the notification.

### `pData.unique`

### `pData.size_is`

### `pData.size_is.dwDataSize`

### `pData`

The address of a caller-allocated buffer that contains additional data for the notification. The
format of the data is defined by the independent hardware vendor (IHV).

The IHV Extensions DLL must set this member to **NULL** if additional data is not required for the
notification.

## Remarks

The application or service registers to receive notifications by calling the
**WlanRegisterNotification** Auto Configuration Manager (ACM) function. For more information about this
function, refer to the Microsoft Windows SDK documentation.

The IHV Extensions DLL sends notifications to registered services or applications by calling the
[Dot11ExtSendNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wlanihv/nc-wlanihv-dot11ext_send_notification) function. The service or application must register to receive
notifications from a source of L2_NOTIFICATION_SOURCE_WLAN_IHV.

## See also

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtSendNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wlanihv/nc-wlanihv-dot11ext_send_notification)