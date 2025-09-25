# _DOT11_SSID structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_SSID structure defines an 802.11 service set identifier (SSID).

## Members

### `uSSIDLength`

The length, in bytes, of the
**ucSSID** array.

### `ucSSID`

The SSID.

## Syntax

```cpp
typedef struct _DOT11_SSID {
  ULONG uSSIDLength;
  UCHAR ucSSID[DOT11_SSID_MAX_LENGTH];
} DOT11_SSID, *PDOT11_SSID;
```

## Remarks

The SSID that is specified by the
**ucSSID** member is not a null-terminated ASCII string. The length of the SSID is determined by the
**uSSIDLength** member.

A
*wildcard SSID* is an SSID whose
**uSSIDLength** member is set to zero. When the desired SSID is set to the wildcard SSID, the 802.11
station can connect to any basic service set (BSS) network.

## See also

[OID_DOT11_DESIRED_SSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-ssid-list)

[NDIS_STATUS_DOT11_CONNECTION_START](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-wlantimedconnectrequest)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)

[NDIS_STATUS_DOT11_ASSOCIATION_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-start)

[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)

[NDIS_STATUS_DOT11_ROAMING_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-start)