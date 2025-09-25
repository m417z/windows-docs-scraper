# DOT11EXTIHV_DEINIT_ADAPTER callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvDeinitAdapter* function to have the IHV Extensions DLL halt all operations for the wireless
LAN (WLAN) adapter, as well as free any resources allocated for the station.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

## Prototype

```cpp
DOT11EXTIHV_DEINIT_ADAPTER Dot11ExtIhvDeinitAdapter;

VOID APIENTRY Dot11ExtIhvDeinitAdapter(
  _In_opt_ HANDLE hIhvExtAdapter
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvDeinitAdapter* function whenever a WLAN adapter becomes unavailable and is disabled for
use, such as when a PCMCIA adapter is removed.

The operating system also calls the
*Dot11ExtIhvDeinitAdapter* function for every adapter managed by the IHV Extensions DLL before the
operating system unloads the DLL. In this situation, the operating system calls the
[Dot11ExtIhvDeinitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_service) IHV
Handler function after the last WLAN adapter has been halted through a call to the
*Dot11ExtIhvDeinitAdapter* function.

For more information about operations that are performed when the WLAN adapter is removed, see
[802.11 WLAN Adapter Removal](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-wlan-adapter-removal).

## See also

[Native 802.11 IHV
Extensibility Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-extensibility-functions)

[Dot11ExtIhvDeinitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_service)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)