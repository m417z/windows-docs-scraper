# _DOT11_BSS_TYPE enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_BSS_TYPE enumeration defines a basic service set (BSS) network type.

## Constants

### `dot11_BSS_type_infrastructure`

Specifies an infrastructure BSS network.

### `dot11_BSS_type_independent`

Specifies an independent BSS (IBSS) network.

### `dot11_BSS_type_any`

Specifies either infrastructure or IBSS network.

## Syntax

```cpp
typedef enum _DOT11_BSS_TYPE {
  dot11_BSS_type_infrastructure  = 1,
  dot11_BSS_type_independent     = 2,
  dot11_BSS_type_any             = 3
} DOT11_BSS_TYPE, *PDOT11_BSS_TYPE;
```

## Remarks

The
**dot11_BSS_type_any** enumerator is valid only if it is specified when
[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request) is set.
**dot11_BSS_type_any** is used to request a scan for all types of BSSs that are visible to the 802.11
station.

## See also

[DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry)

[NDIS_STATUS_DOT11_CONNECTION_START](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-wlantimedconnectrequest)

[OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)

[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)