# _DOT11_BSS_LIST structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_BSS_LIST structure identifies a list of one or more IEEE 802.11 Beacon and Probe Response
frames.

## Members

### `uNumOfBytes`

The length, in bytes, of the data within the buffer referenced by the
**pucBuffer** member.

### `pucBuffer`

A pointer to a buffer that contains a list of
[DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry) structures. Each
DOT11_BSS_ENTRY structure specifies a single 802.11 Beacon and Probe Response frame.

The DOT11_BSS_ENTRY structure has a variable length. However, each entry within the list of
DOT11_BSS_ENTRY structures does not contain padding for the alignment of the next entry in the
list.

## Syntax

```cpp
typedef struct _DOT11_BSS_LIST {
  ULONG  uNumOfBytes;
  PUCHAR pucBuffer;
} DOT11_BSS_LIST, *PDOT11_BSS_LIST;
```

## Remarks

The 802.11 Beacon and Probe Response frames within the
**pucBuffer** member were received from the underlying 802.11 station during its previous scan
operation. For more information about this operation, see
[Native 802.11 Scan
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

## See also

[DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry)

[Dot11ExtIhvPerformCapabilityMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_capability_match)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[Dot11ExtIhvCreateDiscoveryProfiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_create_discovery_profiles)