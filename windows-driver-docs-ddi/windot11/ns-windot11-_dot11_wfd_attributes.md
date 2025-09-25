# _DOT11_WFD_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_ATTRIBUTES** structure is returned in an [NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff565926(v=vs.85)) indication. The structure defines the attributes related to Wi-Fi Direct (WFD) operation modes.

## Members

### `Header`

The type, revision, and size of the **DOT11_WFD_ATTRIBUTES** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_ATTRIBUTES_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_ATTRIBUTES_REVISION_1 |

### `uNumConcurrentGORole`

The number of operational Wi-Fi Direct Group Owner (GO) roles simultaneously supported by the miniport driver. This value is the number of ports that can be simultaneously configured in **DOT11_OPERATION_MODE_WFD_GROUP_OWNER** operation mode. This member must be less than or equal to **uNumWFDGroup** in [DOT11_VWIFI_COMBINATION_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v3) returned by the miniport driver.

### `uNumConcurrentClientRole`

The number of operational Wi-Fi Direct Client roles simultaneously supported by the miniport driver. This value is the number of ports that can be simultaneously configured in **DOT11_OPERATION_MODE_WFD_CLIENT** operation mode. This member must be less than or equal to  **uNumWFDGroup** in [DOT11_VWIFI_COMBINATION_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v3) returned by the miniport driver.

### `WPSVersionsSupported`

The Wi-Fi Protected Services (WPS) versions supported by the miniport driver. The miniport driver must be able to interpret WPS Information Elements (IEs) formatted to these supported WPS version specifications.

### `bServiceDiscoverySupported`

If TRUE, the miniport supports sending and responding to WFD Service Discovery Queries. Otherwise, Service Discovery Queries are not supported.

### `bClientDiscoverabilitySupported`

If TRUE, the miniport supports the WFD Client Discoverability. Otherwise, Client Discoverability is not supported.

### `bInfrastructureManagementSupported`

If TRUE, the miniport supports management by the infrastructure network. Otherwise, infrastructure network management is not supported.

### `uMaxSecondaryDeviceTypeListSize`

The maximum number of Secondary Device Types that can be configured on the WFD device.

### `DeviceAddress`

The WFD Peer-to-Peer (P2P) device address. This address is used as a unique identifier to reference the P2P device.

### `uInterfaceAddressListCount`

The number of P2P Interface Addresses supported by the WFD device. This value must be less than or equal to **uNumWFDGroup** in [DOT11_VWIFI_COMBINATION_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v3) returned by the miniport.

### `pInterfaceAddressList`

A pointer to an array of P2P Interface Addresses supported by the WFD device.

### `uNumSupportedCountryOrRegionStrings`

The number of country or region strings supported by the 802.11 station. To support multiple regulatory domains, as specified by the IEEE 802.11d-2001 standard, each country or region string identifies a regulatory domain supported by the 802.11 station.

### `pSupportedCountryOrRegionStrings`

A pointer to an array of 802.11d country or region strings that are supported by the 802.11 station.

### `uDiscoveryFilterListSize`

The maximum number of Discovery Filters supported by the WFD device for discovery operations. This must be at least 2.

The Discovery filters list that the WFD device must apply for device discovery is specified when [OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request) is set.

### `uGORoleClientTableSize`

The maximum number of associations that each WFD GO port supports simultaneously. The miniport must have at least this number of entries in its key-mapping key table.

## Syntax

```cpp
typedef struct _DOT11_WFD_ATTRIBUTES {
  NDIS_OBJECT_HEADER              Header;
  ULONG                           uNumConcurrentGORole;
  ULONG                           uNumConcurrentClientRole;
  ULONG                           WPSVersionsSupported;
  BOOLEAN                         bServiceDiscoverySupported;
  BOOLEAN                         bClientDiscoverabilitySupported;
  BOOLEAN                         bInfrastructureManagementSupported;
  ULONG                           uMaxSecondaryDeviceTypeListSize;
  DOT11_MAC_ADDRESS               DeviceAddress;
  ULONG                           uInterfaceAddressListCount;
  PDOT11_MAC_ADDRESS              pInterfaceAddressList;
  ULONG                           uNumSupportedCountryOrRegionStrings;
  PDOT11_COUNTRY_OR_REGION_STRING pSupportedCountryOrRegionStrings;
  ULONG                           uDiscoveryFilterListSize;
  ULONG                           uGORoleClientTableSize;
} DOT11_WFD_ATTRIBUTES, *PDOT11_WFD_ATTRIBUTES;
```

## See also

[OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request)

[DOT11_VWIFI_COMBINATION_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_vwifi_combination_v3)

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff565926(v=vs.85))