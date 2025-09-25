# _DOT11EXT_IHV_SSID_LIST structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_SSID_LIST structure specifies a list of 802.11 service set identifiers
(SSIDs).

## Members

### `SSIDs[*]`

The number of SSIDs in the list.

### `SSIDs[1]`

An SSID of type
[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid). This is the first SSID in the
list.

## Remarks

An SSID is a string that identifies a set of interconnected basic service sets (BSSs).

## See also

[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid)