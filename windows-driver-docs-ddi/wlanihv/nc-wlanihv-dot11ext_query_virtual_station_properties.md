# DOT11EXT_QUERY_VIRTUAL_STATION_PROPERTIES callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtQueryVirtualStationProperties** function to query the properties of a
virtual 802.11 station.

## Parameters

### `hDot11SvcHandle` [in, optional]

A handle used by the operating system to reference the primary physical wireless LAN (WLAN)
adapter. This handle value was received as the
*hDot11SvcHandle* parameter through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pbIsVirtualStation` [out]

A pointer to a Boolean value that indicates whether the primary physical WLAN adapter pointed to
by the
*hDot11SvcHandle* parameter is a virtual station adapter or not. If the value is **TRUE**, the queried
adapter is a virtual station, otherwise it is not a virtual station.

### `pgPrimary` [out]

A pointer to a GUID value that identifies the primary physical WLAN adapter that hosts a virtual
station. This parameter is valid only if
*pbIsVirtualStation* points to a value that is **TRUE**.

### `pvReserved`

This parameter is reserved for use by the operating system and should be **NULL**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtQueryVirtualStationProperties(
  _In_opt_   HANDLE hDot11SvcHandle,
  _Out_      BOOL   *pbIsVirtualStation,
  _Out_      GUID   *pgPrimary,
  _Reserved_ LPVOID pvReserved
);
```

## See also

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)