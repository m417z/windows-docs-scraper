# DOT11EXT_SET_EXCLUDE_UNENCRYPTED callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetExcludeUnencrypted** function to enable or disable the wireless
LAN (WLAN) adapter from excluding unencrypted packets it receives while enabled for cipher
operations.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `bExcludeUnencrypted` [in]

A Boolean value that, if set to **TRUE**, configures the WLAN adapter to exclude unencrypted
packets.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetExcludeUnencrypted(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     BOOL   bExcludeUnencrypted
);
```

## Remarks

If the WLAN adapter is enabled to exclude unencrypted packets, the station must exempt received
packets that match an entry in the station's current EtherType exemption list. The IHV Extensions DLL
specifies the EtherType exemption list through calls to the
[Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling) function.

A call to the
**Dot11ExtSetExcludeUnencrypted** function results in a set request of the
[OID_DOT11_EXCLUDE_UNENCRYPTED](https://learn.microsoft.com/previous-versions/windows/embedded/gg159162(v=winembedded.80)) object identifier (OID) to the Native 802.11 miniport driver that
manages the WLAN adapter.

## See also

[OID_DOT11_EXCLUDE_UNENCRYPTED](https://learn.microsoft.com/previous-versions/windows/embedded/gg159162(v=winembedded.80))

[Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)