# DOT11EXT_SET_VIRTUAL_STATION_AP_PROPERTIES callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetVirtualStationAPProperties** function to specify the current IHV
profile connection.

## Parameters

### `hDot11SvcHandle` [in, optional]

An optional handle used by the operating system to reference the primary physical wireless LAN
(WLAN) adapter. This handle value was received as the
*hDot11SvcHandle* parameter through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hConnectSession` [in, optional]

The handle used by the operating system to reference the current connection session with the basic
service set (BSS) network. This handle value was received as the
*hConnectSession* parameter through a previous call to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.

### `dwNumProperties` [in]

The number of elements in the array of structures pointed to by the
*pProperties* parameter.

### `pProperties` [in]

A pointer to an array of
[DOT11EXT_VIRTUAL_STATION_AP_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_virtual_station_ap_property) structures that specify the properties of access points (APs)
that the virtual 802.11 station is attempting to host in the current connection session.

### `pvReserved`

This parameter is reserved for use by the operating system and should be **NULL**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetVirtualStationAPProperties(
  _In_opt_   HANDLE                                hDot11SvcHandle,
  _In_opt_   HANDLE                                hConnectSession,
  _In_       DWORD                                 dwNumProperties,
  _In_       PDOT11EXT_VIRTUAL_STATION_AP_PROPERTY pProperties,
  _Reserved_ LPVOID                                pvReserved
);
```

## Remarks

If the current IHV profile connection is an access point (AP), and the IHV Extensions DLL can provide
to the operating system the settings used by the AP, the operating system can provide additional
information to users who request AP-related service from the operating system.

If the IHV Extensions DLL calls
**Dot11ExtSetVirtualStationAPProperties**, it must do so before it calls the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function. If
**Dot11ExtSetVirtualStationAPProperties** is not called before successful
completion of the pre-association operation, the operating system makes no assumptions about the nature
of the IHV profile.

## See also

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11EXT_VIRTUAL_STATION_AP_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_virtual_station_ap_property)