# _DOT11_IHV_VERSION_INFO structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_IHV_VERSION_INFO structure defines the versions of the IHV Extensibility functions that are
supported by the IHV Extensions DLL.

## Members

### `dwVerMin`

The minimum API version supported by the IHV Extensions DLL.

For the Windows Vista operating system, the minimum API version is zero.

### `dwVerMax`

The maximum API version supported by the IHV Extensions DLL.

For the Windows Vista operating system, the maximum API version is zero.

## Syntax

```cpp
typedef struct _DOT11_IHV_VERSION_INFO {
  DWORD dwVerMin;
  DWORD dwVerMax;
} DOT11_IHV_VERSION_INFO, *PDOT11_IHV_VERSION_INFO;
```

## Remarks

Prior to starting the IHV Extensions DLL through a call to the
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service) IHV
handler function, the operating system queries the API versions supported by the IHV Extensions DLL
through a call to the
[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info) IHV
handler function. The IHV Extensions DLL returns the range of API versions it supports through the
*pDot11IHVVersionInfo* parameter.

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service)

[Dot11ExtIhvGetVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_get_version_info)