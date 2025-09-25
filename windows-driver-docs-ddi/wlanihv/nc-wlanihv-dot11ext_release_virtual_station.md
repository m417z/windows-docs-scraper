# DOT11EXT_RELEASE_VIRTUAL_STATION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtReleaseVirtualStation** function to release a prior
[Dot11ExtRequestVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_request_virtual_station) request to create an 802.11 virtual station.

## Parameters

### `hDot11PrimaryHandle` [in, optional]

The handle used by the operating system to reference the primary physical wireless LAN (WLAN)
adapter. This handle value was received as the
*hDot11SvcHandle* parameter through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function. It is also the
*hDot11PrimaryHandle* parameter that the IHV Extension DLL used in a previous call to
[Dot11ExtRequestVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_request_virtual_station).

### `pvReserved`

This parameter is reserved for use by the operating system and should be **NULL**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtReleaseVirtualStation(
  _In_opt_   HANDLE hDot11PrimaryHandle,
  _Reserved_ LPVOID pvReserved
);
```

## Remarks

The operating system can ignore a call to the
**Dot11ExtReleaseVirtualStation** function if the virtual 802.11 station is
still needed, or if the operating system is already processing a request to remove the virtual
station.

When this release function completes successfully, the virtual station has been deleted, or the operating system is in the process of deleting the virtual station.

A call to
**Dot11ExtReleaseVirtualStation** informs the operating system that the
virtual station is no longer requested by the IHV Extensions DLL. However, the IHV Extensions DLL should
not uninitialize any data that is specific to the virtual station until it receives a call to the
[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) IHV
Handler function.

## See also

[Dot11ExtRequestVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_request_virtual_station)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)