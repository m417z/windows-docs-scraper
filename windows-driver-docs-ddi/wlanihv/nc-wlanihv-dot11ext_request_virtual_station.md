# DOT11EXT_REQUEST_VIRTUAL_STATION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtRequestVirtualStation** function to request that the operating system
create a virtual 802.11 station.

## Parameters

### `hDot11PrimaryHandle` [in, optional]

A handle used by the operating system to reference the primary physical wireless LAN (WLAN)
adapter. This handle value was received as the
*hDot11SvcHandle* parameter through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pvReserved`

This parameter is reserved for use by the operating system and should be **NULL**.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtRequestVirtualStation(
  _In_opt_   HANDLE hDot11PrimaryHandle,
  _Reserved_ LPVOID pvReserved
);
```

## Remarks

When this request function completes successfully, the operating system begins to process the request
to create a virtual station. It is possible that the operating system will call the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function to initialize the virtual station before or after the call to
**Dot11ExtRequestVirtualStation** returns.

After the operating system creates the new virtual station, the IHV Extensions DLL should expect to
receive a call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function. In this call, the operating system passes a handle to the new virtual adapter through
the
*hDot11SvcHandle* parameter.

## See also

[Dot11ExtReleaseVirtualStation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_release_virtual_station)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)