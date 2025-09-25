# DOT11EXT_SEND_NOTIFICATION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSendNotification** function to send notifications to any service or
application that has registered for the notification.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pNotificationData` [in]

A pointer to an
[L2_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/l2cmn/ns-l2cmn-l2_notification_data) structure.

**Note** The IHV Extensions DLL must not pass a **NULL** value for this parameter.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSendNotification(
  _In_opt_ HANDLE                hDot11SvcHandle,
  _In_     PL2_NOTIFICATION_DATA pNotificationData
);
```

## Remarks

A service or application registers to receive the notification by calling the
**WlanRegisterNotification** Auto Configuration Manager (ACM) function. For more information about this
function, refer to the Microsoft Windows SDK documentation.

If the IHV Extensions DLL allocated memory for the notification data referenced by the
*pNotificationData* parameter, the DLL can free the memory after the call to
**Dot11ExtSendNotification** returns.

## See also

[L2_NOTIFICATION_DATA](https://learn.microsoft.com/windows/win32/api/l2cmn/ns-l2cmn-l2_notification_data)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)