# _DOT11_WFD_DISCOVER_REQUEST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **OID_DOT11_WFD_DISCOVER_REQUEST** structure is the input data for an [OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request) request. The structure contains the parameters for a Wi-Fi Direct device discovery.

## Members

### `Header`

The type, revision, and size of the**OID_DOT11_WFD_DISCOVER_REQUEST** structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to **NDIS_OBJECT_TYPE_DEFAULT**.

#### Revision

This member must be set to **DOT11_WFD_DISCOVER_REQUEST_REVISION_1**.

#### Size

This member must be set to
**sizeof**(**DOT11_SIZEOF_WFD_DISCOVER_REQUEST_REVISION_1**).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `DiscoverType`

The device discovery mode to use.

### `ScanType`

Scanning type used during the scan phase of device discovery.

### `uDiscoverTimeout`

Maximum time, in milliseconds, to complete the discovery operation. A miniport can complete a discovery in less time, however, it should not use any more time than specified by this value. This is the total time allowed for completion of all phases of device discovery.

### `uDeviceFilterListOffset`

The offset to the list of P2P Device filters, which specifies the P2P devices and Group Owners to search for during Wi-Fi Direct device discovery. This offset is specified in bytes and is relative to the start of the buffer that contains the DOT11_WFD_DISCOVER_REQUEST structure. Each entry in the list is formatted as a DOT11_WFD_DISCOVER_DEVICE_FILTER.

When a list entry specifies a non-broadcast MAC address as the Device ID, the driver must use this MAC address in the Device ID Attribute of the P2P IEs it includes in the probe requests.

The offset in the **InformationBuffer** of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) where a list of P2P device identifiers begins. These are the identifiers to for during device discovery.

### `uNumDeviceFilters`

The number of P2P device filters to use during WFD device discovery. The default value for this field is 0.

### `uIEsOffset`

The offset in the **InformationBuffer** of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure where the additional Informational Elements (IEs) begin.

### `uIEsLength`

The length, in bytes, of the additional IEs which the Wi-Fi Direct device port must add to the probe request packet. If this value is 0, the system did not provide any IEs and the miniport must insert the default IEs in the probe request packet. The default IEs are in **DefaultRequestIEs** received earlier with an [OID_DOT11_WFD_ADDITIONAL_IE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-additional-ie) request.

### `bForceScanLegacyNetworks`

When TRUE, the Wi-Fi Direct device must also attempt to discover legacy networks. Otherwise, scanning for legacy networks is not necessary.

## Syntax

```cpp
typedef struct _DOT11_WFD_DISCOVER_REQUEST {
  NDIS_OBJECT_HEADER      Header;
  DOT11_WFD_DISCOVER_TYPE DiscoverType;
  DOT11_WFD_SCAN_TYPE     ScanType;
  ULONG                   uDiscoverTimeout;
  ULONG                   uDeviceFilterListOffset;
  ULONG                   uNumDeviceFilters;
  ULONG                   uIEsOffset;
  ULONG                   uIEsLength;
  BOOLEAN                 bForceScanLegacyNetworks;
} DOT11_WFD_DISCOVER_REQUEST, *PDOT11_WFD_DISCOVER_REQUEST;
```

## Remarks

Each entry in the device identifier list at **uDeviceFilterListOffset** is formatted as a [DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address) structure. When a non-broadcast MAC address is specified in this list, the driver must use this address in the Device ID attribute of the P2P IEs probe requests it transmits

The IEs present at **uIEsOffset**, for the duration of the device discovery, will temporarily replace IEs found at **DefaultRequestIEs** in input structure of the [OID_DOT11_WFD_ADDITIONAL_IE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-additional-ie) request.

## See also

[OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request)

[DOT11_WFD_SCAN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_wfd_scan_type)

[DOT11_WFD_DISCOVER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_wfd_discover_type)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)