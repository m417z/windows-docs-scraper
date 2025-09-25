# _DOT11_MAC_ADDRESS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The **DOT11_MAC_ADDRESS** array defines an IEEE media access control (MAC) address.

## Members

### `ucDot11MacAddress`

The MAC address in unicast, multicast, or broadcast format.

## Syntax

```cpp
typedef struct _DOT11_MAC_ADDRESS {
  UCHAR ucDot11MacAddress[6];
} DOT11_MAC_ADDRESS, *PDOT11_MAC_ADDRESS;
```

## Remarks

A unicast MAC address uniquely identifies a station on a WLAN. A MAC address is defined as a unicast
address if the following is true:

```
(DOT11_MAC_ADDRESS[0] & 0x01 == 0)
```

A multicast MAC address uniquely identifies a group of stations on a WLAN. A MAC address is defined as
a multicast address if the following is true:

```
(DOT11_MAC_ADDRESS[0] & 0x01 == 1)
```

A broadcast MAC address identifies all stations on a WLAN. The broadcast MAC address is
0xFFFFFFFFFFFF.

The PDOT11_MAC_ADDRESS type is defined as a pointer to the DOT11_MAC_ADDRESS type as follows:

```
typedef DOT11_MAC_ADDRESS  *PDOT11_MAC_ADDRESS;
```

## See also

[DOT11_SCAN_REQUEST_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_scan_request_v2)

[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion)

[DOT11_BSS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry)

[OID_DOT11_DESIRED_BSSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bssid-list)

[OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-excluded-mac-address-list)

[OID_DOT11_PMKID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-pmkid-list)

[Dot11ExtIhvStopPostAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_stop_post_associate)

[NDIS_STATUS_DOT11_DISASSOCIATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-disassociation)

[OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request)

[OID_DOT11_STATION_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-station-id)

[OID_DOT11_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-current-address)

[DOT11_CIPHER_DEFAULT_KEY_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_cipher_default_key_value)

[NDIS_STATUS_DOT11_LINK_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-link-quality)

[NDIS_STATUS_DOT11_ASSOCIATION_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-start)

[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list)

[NDIS_STATUS_DOT11_ROAMING_START](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-roaming-start)

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[OID_DOT11_ENUM_ASSOCIATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-association-info)

[DOT11_ASSOCIATION_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)

[DOT11_DISASSOCIATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_disassociation_parameters)

[DOT11_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_port_state)

[NDIS_STATUS_DOT11_CONNECTION_START](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-wlantimedconnectrequest)

[NDIS_STATUS_DOT11_TKIPMIC_FAILURE](https://learn.microsoft.com/previous-versions/windows/embedded/gg157151(v=winembedded.80))

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)

[DOT11_ROAMING_COMPLETION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_roaming_completion_parameters)