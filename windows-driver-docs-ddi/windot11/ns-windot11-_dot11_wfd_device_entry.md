# _DOT11_WFD_DEVICE_ENTRY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_DEVICE_ENTRY** structure contains information about a discovered Wi-Fi Direct (WFD) device, a discovered WFD Group Owner (GO), or a discovered infrastructure access point. This structure is returned from both an [OID_DOT11_WFD_ENUM_DEVICE_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-enum-device-list) and a [NDIS_STATUS_DOT11_WFD_DISCOVER_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-discover-complete) notification.

## Members

### `uPhyId`

The identifier of the PHY the miniport used to detect the device. This identifier is in the index range of the list of supported PHYs returned from an [OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types) query request. This identifier cannot be **DOT_PHY_ID_ANY**.

### `PhySpecificInfo`

The attributes of the PHY identified by **uPhyId**.

### `dot11BSSID`

The MAC address of the device that sent the beacon or probe response packet during a discovery.

### `dot11BSSType`

The BSS network type. This member is set to **dot11_BSS_type_infrastructure** for all discovered WFD devices and WFD GOs.

### `TransmitterAddress`

The MAC address for the transmitter of the device that sent the beacon or probe response packet during a discovery.

### `lRSSI`

The received signal strength indicator value of the discovered device. The units for this value are in decibels referenced to 1 milliwatt (dBm).

### `uLinkQuality`

Link quality value ranging from 0 to 100. A value of 100 indicates highest link quality.

### `usBeaconPeriod`

The value received from the beacon interval field of the most recent beacon or probe response packet.

### `ullTimestamp`

The value received from the timestamp field of the most recent beacon or probe response packet.

### `ullBeaconHostTimestamp`

The timestamp, determined by a value returned from [NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime), recording the time when the beacon packet was received.

### `ullProbeResponseHostTimestamp`

The timestamp, determined by a value returned from [NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime), recording the time when the probe response packet was received.

### `usCapabilityInformation`

The value received from the capability field of the most recent beacon or probe response packet.

### `uBeaconIEsOffset`

The offset, in bytes, from the beginning of this structure of the list of information elements (IEs) from the last beacon packet received from this device. If no beacon packet was received, this value should be 0.

### `uBeaconIEsLength`

The length, in bytes, of the IEs at **uBeaconIEsOffset**. This is an exact length value and contains no padding for alignment. If no beacon packet was received, this value should be 0.

### `uProbeResponseIEsOffset`

The offset, in bytes, from the beginning of this structure of the list of information elements (IEs) from the last probe response packet received from this device. If no beacon packet was received, this value should be 0.

### `uProbeResponseIEsLength`

The length, in bytes, of the IEs at **uProbeResponseIEsOffset**. This is an exact length value and contains no padding for alignment. If no probe response packet was received, this value should be 0.

## Syntax

```cpp
typedef struct _DOT11_WFD_DEVICE_ENTRY {
  ULONG                             uPhyId;
  DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO PhySpecificInfo;
  DOT11_MAC_ADDRESS                 dot11BSSID;
  DOT11_BSS_TYPE                    dot11BSSType;
  DOT11_MAC_ADDRESS                 TransmitterAddress;
  LONG                              lRSSI;
  ULONG                             uLinkQuality;
  USHORT                            usBeaconPeriod;
  ULONGLONG                         ullTimestamp;
  ULONGLONG                         ullBeaconHostTimestamp;
  ULONGLONG                         ullProbeResponseHostTimestamp;
  USHORT                            usCapabilityInformation;
  ULONG                             uBeaconIEsOffset;
  ULONG                             uBeaconIEsLength;
  ULONG                             uProbeResponseIEsOffset;
  ULONG                             uProbeResponseIEsLength;
}  DOT11_WFD_DEVICE_ENTRY, *PDOT11_WFD_DEVICE_ENTRY;
```

## See also

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type)

[NDIS_STATUS_DOT11_WFD_DISCOVER_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-discover-complete)

[OID_DOT11_WFD_ENUM_DEVICE_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-enum-device-list)

[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types)

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)

[DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry_phy_specific_info)

[NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime)