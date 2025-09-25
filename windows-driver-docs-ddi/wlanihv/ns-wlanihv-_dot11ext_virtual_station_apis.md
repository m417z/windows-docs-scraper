# _DOT11EXT_VIRTUAL_STATION_APIS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_VIRTUAL_STATION_APIS structure specifies a list of pointers to the IHV Extensibility
virtual station functions that are supported by the operating system.

## Members

### `Dot11ExtRequestVirtualStation`

A pointer to the
[Dot11ExtRequestVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_request_virtual_station) function.

### `Dot11ExtReleaseVirtualStation`

A pointer to the
[Dot11ExtReleaseVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_release_virtual_station) function.

### `Dot11ExtQueryVirtualStationProperties`

A pointer to the
[Dot11ExtQueryVirtualStationProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_query_virtual_station_properties) function.

### `Dot11ExtSetVirtualStationAPProperties`

A pointer to the
[Dot11ExtSetVirtualStationAPProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_virtual_station_ap_properties) function.

## Syntax

```cpp
typedef struct _DOT11EXT_VIRTUAL_STATION_APIS {
  DOT11EXT_REQUEST_VIRTUAL_STATION           Dot11ExtRequestVirtualStation;
  DOT11EXT_RELEASE_VIRTUAL_STATION           Dot11ExtReleaseVirtualStation;
  DOT11EXT_QUERY_VIRTUAL_STATION_PROPERTIES  Dot11ExtQueryVirtualStationProperties;
  DOT11EXT_SET_VIRTUAL_STATION_AP_PROPERTIES Dot11ExtSetVirtualStationAPProperties;
} DOT11EXT_VIRTUAL_STATION_APIS, *PDOT11EXT_VIRTUAL_STATION_APIS;
```

## Remarks

The IHV Extensibility virtual station functions are not statically or dynamically linked to the IHV
Extensions DLL. Instead, when the operating system calls the
[Dot11ExtIhvInitVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_virtual_station) IHV handler function, it passes the list of pointers to the IHV
Extensibility functions through the
*pDot11ExtVSAPI* parameter.

**Note** The IHV Extensions DLL is allowed to call the virtual station API functions that
the
*pDot11ExtVSAPI* parameter points to only after the
[Dot11ExtIhvInitVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_virtual_station) function returns.

All of the function pointers are required and must not be set to **NULL**.

## See also

[Dot11ExtSetVirtualStationAPProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_virtual_station_ap_properties)

[Dot11ExtReleaseVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_release_virtual_station)

[Dot11ExtRequestVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_request_virtual_station)

[Dot11ExtIhvInitVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_virtual_station)

[Dot11ExtQueryVirtualStationProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_query_virtual_station_properties)